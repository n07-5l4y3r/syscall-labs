#include "stdafx.h"

#include <inc.h>

const wchar_t* g_szFilename;
IDiaDataSource* g_pDiaDataSource;
IDiaSession* g_pDiaSession;
IDiaSymbol* g_pGlobalSymbol;
DWORD g_dwMachineType = CV_CFL_80386;

bool LoadDataFromPdb(
    const wchar_t* szFilename,
    IDiaDataSource** ppSource,
    IDiaSession** ppSession,
    IDiaSymbol** ppGlobal);

std::string w2u(const std::wstring& ws)
{
    return std::string(ws.begin(), ws.end());
}

auto _cb = [](IDiaSymbol* pSymbol) {
    HRESULT hResult = S_OK;

    std::cout << "        // ";
    PrintSymbol(pSymbol, 0);

    BSTR bFieldName = NULL;
    if ((hResult = pSymbol->get_undecoratedName(&bFieldName)) != S_OK)
        if ((hResult = pSymbol->get_name(&bFieldName)) != S_OK)
            return;
    
    std::cout << "        const s_field " << std::setw(50) << std::left << w2u(std::wstring(bFieldName)) << " = {" << std::endl;
    DWORD dwLocType = NULL;
    ULONGLONG ulBits = 0;
    DWORD dwBitPos = 0;
    LONG lOffset = NULL;
    //if ((hResult = pSymbol->get_offset(&lOffset)) != S_OK)
    //    return;
    pSymbol->get_offset(&lOffset);
    if ((hResult = pSymbol->get_locationType(&dwLocType)) == S_OK)
    {
        if (dwLocType == LocIsBitField) {
            if ((hResult = pSymbol->get_bitPosition(&dwBitPos)) != S_OK)
                return;
            if ((hResult = pSymbol->get_length(&ulBits)) != S_OK)
                return;
        }
        else
        {
            if (dwLocType == LocIsStatic) {
                if ((hResult = pSymbol->get_relativeVirtualAddress((DWORD*)&lOffset)) != S_OK)
                    return;
            }
        }
    }
    std::cout << "            .byte = " << "0x" << std::setfill(' ') << std::setw(8) << std::left << std::hex << lOffset << ", ";
    IDiaSymbol* pType = NULL;
    ULONGLONG ulLen = 0;
    if ((hResult = pSymbol->get_type(&pType)) == S_OK)
        if ((hResult = pType->get_length(&ulLen)) == S_OK)
        { }
    
    std::cout << ".bytes = " << "0x" << std::setfill(' ') << std::setw(8) << std::left << std::hex << ulLen << ", ";
    std::cout << ".bit = " << "0x" << std::setfill(' ') << std::setw(2) << std::left << std::hex << dwBitPos << ", ";
    std::cout << ".bits = " << "0x" << std::setfill(' ') << std::setw(2) << std::left << std::hex << ulBits << " ";
    std::cout << "};" << std::endl;
};

std::map<std::wstring, IDiaSymbol*> known_symbols = {};
std::vector<std::wstring> sargv = {};
int wmain(int _In_ argc, wchar_t* _In_ argv[])
{
    if (argc < 2)
        return 1;
    else
        g_szFilename = argv[1];

    if (!LoadDataFromPdb(g_szFilename, &g_pDiaDataSource, &g_pDiaSession, &g_pGlobalSymbol))
        return 2;

    if (argc >= 3)
        for (auto i = 2; i < argc; i++)
            sargv.push_back(std::wstring(argv[i]));

    std::cout << "#include \"offset.h\"" << std::endl;
    std::cout << "namespace offset {" << std::endl;

    dia2::EnumChildren(
        g_pGlobalSymbol,
        [](IDiaSymbol* pSymbol) {
            BSTR bstrName = NULL;
            if (pSymbol->get_name(&bstrName) == S_OK)
            {
                auto sName = std::wstring(bstrName);

                if (lstrcmpW(sName.c_str(), L"<anonymous-tag>") == 0)
                    return;

                if (known_symbols.find(sName) != known_symbols.end())
                    return;

                if (!sargv.empty())
                    if (std::find(sargv.begin(), sargv.end(), sName) == sargv.end())
                        return;

                std::cout << "    namespace " << w2u(sName) << " {" << std::endl;
                dia2::EnumChildren(
                    pSymbol,
                    _cb,
                    SymTagData);
                std::cout << "    }" << std::endl;

                known_symbols.insert(std::make_pair(sName, pSymbol));
            }
        },
        SymTagUDT);

    std::cout << "    namespace " << "_PUBLIC" << " {" << std::endl;
    dia2::EnumChildren(
        g_pGlobalSymbol,
        [](IDiaSymbol* pSymbol) {

            BSTR bstrName = NULL;
            if (pSymbol->get_name(&bstrName) == S_OK)
            {
                auto sName = std::wstring(bstrName);

                if (lstrcmpW(sName.c_str(), L"<anonymous-tag>") == 0)
                    return;

                if (known_symbols.find(sName) != known_symbols.end())
                    return;

                if (!sargv.empty())
                    if (std::find(sargv.begin(), sargv.end(), sName) == sargv.end())
                        return;

                DWORD dwLocType = NULL;
                if (pSymbol->get_locationType(&dwLocType) != S_OK)
                    return;

                if (dwLocType != LocIsStatic)
                    return;

                _cb(pSymbol);

                known_symbols.insert(std::make_pair(sName, pSymbol));
            }
            
        },
        SymTagPublicSymbol);
    std::cout << "    }" << std::endl;

    std::cout << "}" << std::endl;

    return 0;
}

std::string GetLastErrorAsString(DWORD errorMessageID)
{
    if (errorMessageID == 0) {
        return std::string(); //No error message has been recorded
    }

    LPSTR messageBuffer = nullptr;

    //Ask Win32 to give us the string version of that message ID.
    //The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

    //Copy the error message into a std::string.
    std::string message(messageBuffer, size);

    //Free the Win32's string's buffer.
    LocalFree(messageBuffer);

    return message;
}

////////////////////////////////////////////////////////////
// Create an IDiaData source and open a PDB file
//
bool LoadDataFromPdb(
    const wchar_t* szFilename,
    IDiaDataSource** ppSource,
    IDiaSession** ppSession,
    IDiaSymbol** ppGlobal)
{
    wchar_t wszExt[MAX_PATH];
    const wchar_t* wszSearchPath = L"SRV**\\\\symbols\\symbols"; // Alternate path to search for debug data
    DWORD dwMachType = 0;

    HRESULT hr = CoInitialize(NULL);

    HMODULE p_symsrv = LoadLibrary(L"symsrv.dll");
    if (!p_symsrv)
    {
        DWORD errorCode = GetLastError();
        hr = HRESULT_FROM_WIN32(errorCode);
        printf("LoadLibrary symsrv.dll failed\n");
        printf(" - DWORD   = %d\n", errorCode);
        printf(" - HRESULT = %08X\n", hr);
        printf(" - ERROR   = %s\n", GetLastErrorAsString(errorCode).c_str());
        return false;
    }

    HMODULE p_msdia140 = LoadLibrary(L"msdia140.dll");
    if (!p_msdia140)
    {
        DWORD errorCode = GetLastError();
        hr = HRESULT_FROM_WIN32(errorCode);
        printf("LoadLibrary msdia140.dll failed\n");
        printf(" - DWORD   = %d\n", errorCode);
        printf(" - HRESULT = %08X\n", hr);
        printf(" - ERROR   = %s\n", GetLastErrorAsString(errorCode).c_str());
        return false;
    }

    using PDLLGETCLASSOBJECT_ROUTINE = HRESULT(WINAPI*)(REFCLSID, REFIID, LPVOID);
    auto DllGetClassObject = reinterpret_cast<PDLLGETCLASSOBJECT_ROUTINE>(GetProcAddress(p_msdia140, "DllGetClassObject"));

    if (!DllGetClassObject)
    {
        hr = HRESULT_FROM_WIN32(GetLastError());
        printf("GetProcAddress failed - HRESULT = %08X\n", hr);
        return hr;
    }

    CComPtr<IClassFactory> ClassFactory;
    hr = DllGetClassObject(__uuidof(DiaSource), __uuidof(IClassFactory), &ClassFactory);

    if (FAILED(hr))
    {
        printf("DllGetClassObject failed - HRESULT = %08X\n", hr);
        return false;
    }

    // Obtain access to the provider
    /*
    hr = CoCreateInstance(__uuidof(DiaSource),
                          NULL,
                          CLSCTX_INPROC_SERVER,
                          __uuidof(IDiaDataSource),
                          (void **) ppSource);
    */
    hr = ClassFactory->CreateInstance(NULL, __uuidof(IDiaDataSource), (void**)ppSource);

    if (FAILED(hr)) {
        printf("ClassFactory->CreateInstance failed - HRESULT = %08X\n", hr);

        return false;
    }

    _wsplitpath_s(szFilename, NULL, 0, NULL, 0, NULL, 0, wszExt, MAX_PATH);

    if (!_wcsicmp(wszExt, L".pdb")) {
        // Open and prepare a program database (.pdb) file as a debug data source

        hr = (*ppSource)->loadDataFromPdb(szFilename);

        if (FAILED(hr)) {
            printf("loadDataFromPdb failed - HRESULT = %08X\n", hr);

            return false;
        }
    }

    else {
        CCallback callback; // Receives callbacks from the DIA symbol locating procedure,
                            // thus enabling a user interface to report on the progress of
                            // the location attempt. The client application may optionally
                            // provide a reference to its own implementation of this
                            // virtual base class to the IDiaDataSource::loadDataForExe method.
        callback.AddRef();

        // Open and prepare the debug data associated with the executable

        hr = (*ppSource)->loadDataForExe(szFilename, wszSearchPath, &callback);

        if (FAILED(hr)) {
            printf("loadDataForExe failed - HRESULT = %08X\n", hr);

            return false;
        }
    }

    // Open a session for querying symbols

    hr = (*ppSource)->openSession(ppSession);

    if (FAILED(hr)) {
        printf("openSession failed - HRESULT = %08X\n", hr);

        return false;
    }

    // Retrieve a reference to the global scope

    hr = (*ppSession)->get_globalScope(ppGlobal);

    if (hr != S_OK) {
        printf("get_globalScope failed\n");

        return false;
    }

    // Set Machine type for getting correct register names

    if ((*ppGlobal)->get_machineType(&dwMachType) == S_OK) {
        switch (dwMachType) {
        case IMAGE_FILE_MACHINE_I386: g_dwMachineType = CV_CFL_80386; break;
        case IMAGE_FILE_MACHINE_IA64: g_dwMachineType = CV_CFL_IA64; break;
        case IMAGE_FILE_MACHINE_AMD64: g_dwMachineType = CV_CFL_AMD64; break;
        }
    }

    return true;
}
#include "offset.h"
namespace offset {
    namespace _TEB {
        // Data           : this+0x0, Member, Type: struct _NT_TIB, NtTib
        const s_field NtTib                                              = {
            .byte = 0x0       , .bytes = 0x38      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x38, Member, Type: void *, EnvironmentPointer
        const s_field EnvironmentPointer                                 = {
            .byte = 0x38      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x40, Member, Type: struct _CLIENT_ID, ClientId
        const s_field ClientId                                           = {
            .byte = 0x40      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x50, Member, Type: void *, ActiveRpcHandle
        const s_field ActiveRpcHandle                                    = {
            .byte = 0x50      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x58, Member, Type: void *, ThreadLocalStoragePointer
        const s_field ThreadLocalStoragePointer                          = {
            .byte = 0x58      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x60, Member, Type: struct _PEB *, ProcessEnvironmentBlock
        const s_field ProcessEnvironmentBlock                            = {
            .byte = 0x60      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x68, Member, Type: unsigned long, LastErrorValue
        const s_field LastErrorValue                                     = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x6C, Member, Type: unsigned long, CountOfOwnedCriticalSections
        const s_field CountOfOwnedCriticalSections                       = {
            .byte = 0x6c      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x70, Member, Type: void *, CsrClientThread
        const s_field CsrClientThread                                    = {
            .byte = 0x70      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x78, Member, Type: void *, Win32ThreadInfo
        const s_field Win32ThreadInfo                                    = {
            .byte = 0x78      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x80, Member, Type: unsigned long[0x1A], User32Reserved
        const s_field User32Reserved                                     = {
            .byte = 0x80      , .bytes = 0x68      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xE8, Member, Type: unsigned long[0x5], UserReserved
        const s_field UserReserved                                       = {
            .byte = 0xe8      , .bytes = 0x14      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x100, Member, Type: void *, WOW32Reserved
        const s_field WOW32Reserved                                      = {
            .byte = 0x100     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x108, Member, Type: unsigned long, CurrentLocale
        const s_field CurrentLocale                                      = {
            .byte = 0x108     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x10C, Member, Type: unsigned long, FpSoftwareStatusRegister
        const s_field FpSoftwareStatusRegister                           = {
            .byte = 0x10c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x110, Member, Type: void *[0x10], ReservedForDebuggerInstrumentation
        const s_field ReservedForDebuggerInstrumentation                 = {
            .byte = 0x110     , .bytes = 0x80      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x190, Member, Type: void *[0x1E], SystemReserved1
        const s_field SystemReserved1                                    = {
            .byte = 0x190     , .bytes = 0xf0      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x280, Member, Type: char, PlaceholderCompatibilityMode
        const s_field PlaceholderCompatibilityMode                       = {
            .byte = 0x280     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x281, Member, Type: unsigned char, PlaceholderHydrationAlwaysExplicit
        const s_field PlaceholderHydrationAlwaysExplicit                 = {
            .byte = 0x281     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x282, Member, Type: char[0xA], PlaceholderReserved
        const s_field PlaceholderReserved                                = {
            .byte = 0x282     , .bytes = 0xa       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x28C, Member, Type: unsigned long, ProxiedProcessId
        const s_field ProxiedProcessId                                   = {
            .byte = 0x28c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x290, Member, Type: struct _ACTIVATION_CONTEXT_STACK, _ActivationStack
        const s_field _ActivationStack                                   = {
            .byte = 0x290     , .bytes = 0x28      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2B8, Member, Type: unsigned char[0x8], WorkingOnBehalfTicket
        const s_field WorkingOnBehalfTicket                              = {
            .byte = 0x2b8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2C0, Member, Type: long, ExceptionCode
        const s_field ExceptionCode                                      = {
            .byte = 0x2c0     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2C4, Member, Type: unsigned char[0x4], Padding0
        const s_field Padding0                                           = {
            .byte = 0x2c4     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2C8, Member, Type: struct _ACTIVATION_CONTEXT_STACK *, ActivationContextStackPointer
        const s_field ActivationContextStackPointer                      = {
            .byte = 0x2c8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2D0, Member, Type: unsigned __int64, InstrumentationCallbackSp
        const s_field InstrumentationCallbackSp                          = {
            .byte = 0x2d0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2D8, Member, Type: unsigned __int64, InstrumentationCallbackPreviousPc
        const s_field InstrumentationCallbackPreviousPc                  = {
            .byte = 0x2d8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2E0, Member, Type: unsigned __int64, InstrumentationCallbackPreviousSp
        const s_field InstrumentationCallbackPreviousSp                  = {
            .byte = 0x2e0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2E8, Member, Type: unsigned long, TxFsContext
        const s_field TxFsContext                                        = {
            .byte = 0x2e8     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2EC, Member, Type: unsigned char, InstrumentationCallbackDisabled
        const s_field InstrumentationCallbackDisabled                    = {
            .byte = 0x2ec     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2ED, Member, Type: unsigned char, UnalignedLoadStoreExceptions
        const s_field UnalignedLoadStoreExceptions                       = {
            .byte = 0x2ed     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2EE, Member, Type: unsigned char[0x2], Padding1
        const s_field Padding1                                           = {
            .byte = 0x2ee     , .bytes = 0x2       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2F0, Member, Type: struct _GDI_TEB_BATCH, GdiTebBatch
        const s_field GdiTebBatch                                        = {
            .byte = 0x2f0     , .bytes = 0x4e8     , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7D8, Member, Type: struct _CLIENT_ID, RealClientId
        const s_field RealClientId                                       = {
            .byte = 0x7d8     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7E8, Member, Type: void *, GdiCachedProcessHandle
        const s_field GdiCachedProcessHandle                             = {
            .byte = 0x7e8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7F0, Member, Type: unsigned long, GdiClientPID
        const s_field GdiClientPID                                       = {
            .byte = 0x7f0     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7F4, Member, Type: unsigned long, GdiClientTID
        const s_field GdiClientTID                                       = {
            .byte = 0x7f4     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7F8, Member, Type: void *, GdiThreadLocalInfo
        const s_field GdiThreadLocalInfo                                 = {
            .byte = 0x7f8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x800, Member, Type: unsigned __int64[0x3E], Win32ClientInfo
        const s_field Win32ClientInfo                                    = {
            .byte = 0x800     , .bytes = 0x1f0     , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9F0, Member, Type: void *[0xE9], glDispatchTable
        const s_field glDispatchTable                                    = {
            .byte = 0x9f0     , .bytes = 0x748     , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1138, Member, Type: unsigned __int64[0x1D], glReserved1
        const s_field glReserved1                                        = {
            .byte = 0x1138    , .bytes = 0xe8      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1220, Member, Type: void *, glReserved2
        const s_field glReserved2                                        = {
            .byte = 0x1220    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1228, Member, Type: void *, glSectionInfo
        const s_field glSectionInfo                                      = {
            .byte = 0x1228    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1230, Member, Type: void *, glSection
        const s_field glSection                                          = {
            .byte = 0x1230    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1238, Member, Type: void *, glTable
        const s_field glTable                                            = {
            .byte = 0x1238    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1240, Member, Type: void *, glCurrentRC
        const s_field glCurrentRC                                        = {
            .byte = 0x1240    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1248, Member, Type: void *, glContext
        const s_field glContext                                          = {
            .byte = 0x1248    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1250, Member, Type: unsigned long, LastStatusValue
        const s_field LastStatusValue                                    = {
            .byte = 0x1250    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1254, Member, Type: unsigned char[0x4], Padding2
        const s_field Padding2                                           = {
            .byte = 0x1254    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1258, Member, Type: struct _UNICODE_STRING, StaticUnicodeString
        const s_field StaticUnicodeString                                = {
            .byte = 0x1258    , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1268, Member, Type: wchar_t[0x105], StaticUnicodeBuffer
        const s_field StaticUnicodeBuffer                                = {
            .byte = 0x1268    , .bytes = 0x20a     , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1472, Member, Type: unsigned char[0x6], Padding3
        const s_field Padding3                                           = {
            .byte = 0x1472    , .bytes = 0x6       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1478, Member, Type: void *, DeallocationStack
        const s_field DeallocationStack                                  = {
            .byte = 0x1478    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1480, Member, Type: void *[0x40], TlsSlots
        const s_field TlsSlots                                           = {
            .byte = 0x1480    , .bytes = 0x200     , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1680, Member, Type: struct _LIST_ENTRY, TlsLinks
        const s_field TlsLinks                                           = {
            .byte = 0x1680    , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1690, Member, Type: void *, Vdm
        const s_field Vdm                                                = {
            .byte = 0x1690    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1698, Member, Type: void *, ReservedForNtRpc
        const s_field ReservedForNtRpc                                   = {
            .byte = 0x1698    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x16A0, Member, Type: void *[0x2], DbgSsReserved
        const s_field DbgSsReserved                                      = {
            .byte = 0x16a0    , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x16B0, Member, Type: unsigned long, HardErrorMode
        const s_field HardErrorMode                                      = {
            .byte = 0x16b0    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x16B4, Member, Type: unsigned char[0x4], Padding4
        const s_field Padding4                                           = {
            .byte = 0x16b4    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x16B8, Member, Type: void *[0xB], Instrumentation
        const s_field Instrumentation                                    = {
            .byte = 0x16b8    , .bytes = 0x58      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1710, Member, Type: struct _GUID, ActivityId
        const s_field ActivityId                                         = {
            .byte = 0x1710    , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1720, Member, Type: void *, SubProcessTag
        const s_field SubProcessTag                                      = {
            .byte = 0x1720    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1728, Member, Type: void *, PerflibData
        const s_field PerflibData                                        = {
            .byte = 0x1728    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1730, Member, Type: void *, EtwTraceData
        const s_field EtwTraceData                                       = {
            .byte = 0x1730    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1738, Member, Type: void *, WinSockData
        const s_field WinSockData                                        = {
            .byte = 0x1738    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1740, Member, Type: unsigned long, GdiBatchCount
        const s_field GdiBatchCount                                      = {
            .byte = 0x1740    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1744, Member, Type: struct _PROCESSOR_NUMBER, CurrentIdealProcessor
        const s_field CurrentIdealProcessor                              = {
            .byte = 0x1744    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1744, Member, Type: unsigned long, IdealProcessorValue
        const s_field IdealProcessorValue                                = {
            .byte = 0x1744    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1744, Member, Type: unsigned char, ReservedPad0
        const s_field ReservedPad0                                       = {
            .byte = 0x1744    , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1745, Member, Type: unsigned char, ReservedPad1
        const s_field ReservedPad1                                       = {
            .byte = 0x1745    , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1746, Member, Type: unsigned char, ReservedPad2
        const s_field ReservedPad2                                       = {
            .byte = 0x1746    , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1747, Member, Type: unsigned char, IdealProcessor
        const s_field IdealProcessor                                     = {
            .byte = 0x1747    , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1748, Member, Type: unsigned long, GuaranteedStackBytes
        const s_field GuaranteedStackBytes                               = {
            .byte = 0x1748    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x174C, Member, Type: unsigned char[0x4], Padding5
        const s_field Padding5                                           = {
            .byte = 0x174c    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1750, Member, Type: void *, ReservedForPerf
        const s_field ReservedForPerf                                    = {
            .byte = 0x1750    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1758, Member, Type: void *, ReservedForOle
        const s_field ReservedForOle                                     = {
            .byte = 0x1758    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1760, Member, Type: unsigned long, WaitingOnLoaderLock
        const s_field WaitingOnLoaderLock                                = {
            .byte = 0x1760    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1764, Member, Type: unsigned char[0x4], Padding6
        const s_field Padding6                                           = {
            .byte = 0x1764    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1768, Member, Type: void *, SavedPriorityState
        const s_field SavedPriorityState                                 = {
            .byte = 0x1768    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1770, Member, Type: unsigned __int64, ReservedForCodeCoverage
        const s_field ReservedForCodeCoverage                            = {
            .byte = 0x1770    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1778, Member, Type: void *, ThreadPoolData
        const s_field ThreadPoolData                                     = {
            .byte = 0x1778    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1780, Member, Type: void * *, TlsExpansionSlots
        const s_field TlsExpansionSlots                                  = {
            .byte = 0x1780    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1788, Member, Type: void *, DeallocationBStore
        const s_field DeallocationBStore                                 = {
            .byte = 0x1788    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1790, Member, Type: void *, BStoreLimit
        const s_field BStoreLimit                                        = {
            .byte = 0x1790    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1798, Member, Type: unsigned long, MuiGeneration
        const s_field MuiGeneration                                      = {
            .byte = 0x1798    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x179C, Member, Type: unsigned long, IsImpersonating
        const s_field IsImpersonating                                    = {
            .byte = 0x179c    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17A0, Member, Type: void *, NlsCache
        const s_field NlsCache                                           = {
            .byte = 0x17a0    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17A8, Member, Type: void *, pShimData
        const s_field pShimData                                          = {
            .byte = 0x17a8    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17B0, Member, Type: unsigned long, HeapData
        const s_field HeapData                                           = {
            .byte = 0x17b0    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17B4, Member, Type: unsigned char[0x4], Padding7
        const s_field Padding7                                           = {
            .byte = 0x17b4    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17B8, Member, Type: void *, CurrentTransactionHandle
        const s_field CurrentTransactionHandle                           = {
            .byte = 0x17b8    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17C0, Member, Type: struct _TEB_ACTIVE_FRAME *, ActiveFrame
        const s_field ActiveFrame                                        = {
            .byte = 0x17c0    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17C8, Member, Type: void *, FlsData
        const s_field FlsData                                            = {
            .byte = 0x17c8    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17D0, Member, Type: void *, PreferredLanguages
        const s_field PreferredLanguages                                 = {
            .byte = 0x17d0    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17D8, Member, Type: void *, UserPrefLanguages
        const s_field UserPrefLanguages                                  = {
            .byte = 0x17d8    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17E0, Member, Type: void *, MergedPrefLanguages
        const s_field MergedPrefLanguages                                = {
            .byte = 0x17e0    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17E8, Member, Type: unsigned long, MuiImpersonation
        const s_field MuiImpersonation                                   = {
            .byte = 0x17e8    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17EC, Member, Type: volatile unsigned short, CrossTebFlags
        const s_field CrossTebFlags                                      = {
            .byte = 0x17ec    , .bytes = 0x2       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x17EC:0x0 len(0x10), Member, Type: unsigned short, SpareCrossTebBits
        const s_field SpareCrossTebBits                                  = {
            .byte = 0x17ec    , .bytes = 0x2       , .bit = 0x0 , .bits = 0x10 };
        // Data           : this+0x17EE, Member, Type: unsigned short, SameTebFlags
        const s_field SameTebFlags                                       = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x17EE:0x0 len(0x1), Member, Type: unsigned short, SafeThunkCall
        const s_field SafeThunkCall                                      = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0x0 , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0x1 len(0x1), Member, Type: unsigned short, InDebugPrint
        const s_field InDebugPrint                                       = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0x1 , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0x2 len(0x1), Member, Type: unsigned short, HasFiberData
        const s_field HasFiberData                                       = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0x2 , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0x3 len(0x1), Member, Type: unsigned short, SkipThreadAttach
        const s_field SkipThreadAttach                                   = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0x3 , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0x4 len(0x1), Member, Type: unsigned short, WerInShipAssertCode
        const s_field WerInShipAssertCode                                = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0x4 , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0x5 len(0x1), Member, Type: unsigned short, RanProcessInit
        const s_field RanProcessInit                                     = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0x5 , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0x6 len(0x1), Member, Type: unsigned short, ClonedThread
        const s_field ClonedThread                                       = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0x6 , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0x7 len(0x1), Member, Type: unsigned short, SuppressDebugMsg
        const s_field SuppressDebugMsg                                   = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0x7 , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0x8 len(0x1), Member, Type: unsigned short, DisableUserStackWalk
        const s_field DisableUserStackWalk                               = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0x8 , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0x9 len(0x1), Member, Type: unsigned short, RtlExceptionAttached
        const s_field RtlExceptionAttached                               = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0x9 , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0xA len(0x1), Member, Type: unsigned short, InitialThread
        const s_field InitialThread                                      = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0xa , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0xB len(0x1), Member, Type: unsigned short, SessionAware
        const s_field SessionAware                                       = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0xb , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0xC len(0x1), Member, Type: unsigned short, LoadOwner
        const s_field LoadOwner                                          = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0xc , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0xD len(0x1), Member, Type: unsigned short, LoaderWorker
        const s_field LoaderWorker                                       = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0xd , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0xE len(0x1), Member, Type: unsigned short, SkipLoaderInit
        const s_field SkipLoaderInit                                     = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0xe , .bits = 0x1  };
        // Data           : this(bf)+0x17EE:0xF len(0x1), Member, Type: unsigned short, SpareSameTebBits
        const s_field SpareSameTebBits                                   = {
            .byte = 0x17ee    , .bytes = 0x2       , .bit = 0xf , .bits = 0x1  };
        // Data           : this+0x17F0, Member, Type: void *, TxnScopeEnterCallback
        const s_field TxnScopeEnterCallback                              = {
            .byte = 0x17f0    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x17F8, Member, Type: void *, TxnScopeExitCallback
        const s_field TxnScopeExitCallback                               = {
            .byte = 0x17f8    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1800, Member, Type: void *, TxnScopeContext
        const s_field TxnScopeContext                                    = {
            .byte = 0x1800    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1808, Member, Type: unsigned long, LockCount
        const s_field LockCount                                          = {
            .byte = 0x1808    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x180C, Member, Type: long, WowTebOffset
        const s_field WowTebOffset                                       = {
            .byte = 0x180c    , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1810, Member, Type: void *, ResourceRetValue
        const s_field ResourceRetValue                                   = {
            .byte = 0x1810    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1818, Member, Type: void *, ReservedForWdf
        const s_field ReservedForWdf                                     = {
            .byte = 0x1818    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1820, Member, Type: unsigned __int64, ReservedForCrt
        const s_field ReservedForCrt                                     = {
            .byte = 0x1820    , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1828, Member, Type: struct _GUID, EffectiveContainerId
        const s_field EffectiveContainerId                               = {
            .byte = 0x1828    , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
    }
    namespace _KPROCESS {
        // Data           : this+0x0, Member, Type: struct _DISPATCHER_HEADER, Header
        const s_field Header                                             = {
            .byte = 0x0       , .bytes = 0x18      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x18, Member, Type: struct _LIST_ENTRY, ProfileListHead
        const s_field ProfileListHead                                    = {
            .byte = 0x18      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x28, Member, Type: unsigned __int64, DirectoryTableBase
        const s_field DirectoryTableBase                                 = {
            .byte = 0x28      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x30, Member, Type: struct _LIST_ENTRY, ThreadListHead
        const s_field ThreadListHead                                     = {
            .byte = 0x30      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x40, Member, Type: unsigned long, ProcessLock
        const s_field ProcessLock                                        = {
            .byte = 0x40      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x44, Member, Type: unsigned long, ProcessTimerDelay
        const s_field ProcessTimerDelay                                  = {
            .byte = 0x44      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x48, Member, Type: unsigned __int64, DeepFreezeStartTime
        const s_field DeepFreezeStartTime                                = {
            .byte = 0x48      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x50, Member, Type: struct _KAFFINITY_EX, Affinity
        const s_field Affinity                                           = {
            .byte = 0x50      , .bytes = 0xa8      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xF8, Member, Type: unsigned __int64[0xC], AffinityPadding
        const s_field AffinityPadding                                    = {
            .byte = 0xf8      , .bytes = 0x60      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x158, Member, Type: struct _LIST_ENTRY, ReadyListHead
        const s_field ReadyListHead                                      = {
            .byte = 0x158     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x168, Member, Type: struct _SINGLE_LIST_ENTRY, SwapListEntry
        const s_field SwapListEntry                                      = {
            .byte = 0x168     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x170, Member, Type: volatile struct _KAFFINITY_EX, ActiveProcessors
        const s_field ActiveProcessors                                   = {
            .byte = 0x170     , .bytes = 0xa8      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x218, Member, Type: unsigned __int64[0xC], ActiveProcessorsPadding
        const s_field ActiveProcessorsPadding                            = {
            .byte = 0x218     , .bytes = 0x60      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x278:0x0 len(0x1), Member, Type: unsigned long, AutoAlignment
        const s_field AutoAlignment                                      = {
            .byte = 0x278     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x1  };
        // Data           : this(bf)+0x278:0x1 len(0x1), Member, Type: unsigned long, DisableBoost
        const s_field DisableBoost                                       = {
            .byte = 0x278     , .bytes = 0x4       , .bit = 0x1 , .bits = 0x1  };
        // Data           : this(bf)+0x278:0x2 len(0x1), Member, Type: unsigned long, DisableQuantum
        const s_field DisableQuantum                                     = {
            .byte = 0x278     , .bytes = 0x4       , .bit = 0x2 , .bits = 0x1  };
        // Data           : this(bf)+0x278:0x3 len(0x1), Member, Type: unsigned long, DeepFreeze
        const s_field DeepFreeze                                         = {
            .byte = 0x278     , .bytes = 0x4       , .bit = 0x3 , .bits = 0x1  };
        // Data           : this(bf)+0x278:0x4 len(0x1), Member, Type: unsigned long, TimerVirtualization
        const s_field TimerVirtualization                                = {
            .byte = 0x278     , .bytes = 0x4       , .bit = 0x4 , .bits = 0x1  };
        // Data           : this(bf)+0x278:0x5 len(0x1), Member, Type: unsigned long, CheckStackExtents
        const s_field CheckStackExtents                                  = {
            .byte = 0x278     , .bytes = 0x4       , .bit = 0x5 , .bits = 0x1  };
        // Data           : this(bf)+0x278:0x6 len(0x1), Member, Type: unsigned long, CacheIsolationEnabled
        const s_field CacheIsolationEnabled                              = {
            .byte = 0x278     , .bytes = 0x4       , .bit = 0x6 , .bits = 0x1  };
        // Data           : this(bf)+0x278:0x7 len(0x3), Member, Type: unsigned long, PpmPolicy
        const s_field PpmPolicy                                          = {
            .byte = 0x278     , .bytes = 0x4       , .bit = 0x7 , .bits = 0x3  };
        // Data           : this(bf)+0x278:0xA len(0x1), Member, Type: unsigned long, VaSpaceDeleted
        const s_field VaSpaceDeleted                                     = {
            .byte = 0x278     , .bytes = 0x4       , .bit = 0xa , .bits = 0x1  };
        // Data           : this(bf)+0x278:0xB len(0x15), Member, Type: unsigned long, ReservedFlags
        const s_field ReservedFlags                                      = {
            .byte = 0x278     , .bytes = 0x4       , .bit = 0xb , .bits = 0x15 };
        // Data           : this+0x278, Member, Type: volatile long, ProcessFlags
        const s_field ProcessFlags                                       = {
            .byte = 0x278     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x27C, Member, Type: unsigned long, ActiveGroupsMask
        const s_field ActiveGroupsMask                                   = {
            .byte = 0x27c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x280, Member, Type: char, BasePriority
        const s_field BasePriority                                       = {
            .byte = 0x280     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x281, Member, Type: char, QuantumReset
        const s_field QuantumReset                                       = {
            .byte = 0x281     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x282, Member, Type: char, Visited
        const s_field Visited                                            = {
            .byte = 0x282     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x283, Member, Type: union _KEXECUTE_OPTIONS, Flags
        const s_field Flags                                              = {
            .byte = 0x283     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x284, Member, Type: unsigned short[0x14], ThreadSeed
        const s_field ThreadSeed                                         = {
            .byte = 0x284     , .bytes = 0x28      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2AC, Member, Type: unsigned short[0xC], ThreadSeedPadding
        const s_field ThreadSeedPadding                                  = {
            .byte = 0x2ac     , .bytes = 0x18      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2C4, Member, Type: unsigned short[0x14], IdealProcessor
        const s_field IdealProcessor                                     = {
            .byte = 0x2c4     , .bytes = 0x28      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2EC, Member, Type: unsigned short[0xC], IdealProcessorPadding
        const s_field IdealProcessorPadding                              = {
            .byte = 0x2ec     , .bytes = 0x18      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x304, Member, Type: unsigned short[0x14], IdealNode
        const s_field IdealNode                                          = {
            .byte = 0x304     , .bytes = 0x28      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x32C, Member, Type: unsigned short[0xC], IdealNodePadding
        const s_field IdealNodePadding                                   = {
            .byte = 0x32c     , .bytes = 0x18      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x344, Member, Type: unsigned short, IdealGlobalNode
        const s_field IdealGlobalNode                                    = {
            .byte = 0x344     , .bytes = 0x2       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x346, Member, Type: unsigned short, Spare1
        const s_field Spare1                                             = {
            .byte = 0x346     , .bytes = 0x2       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x348, Member, Type: volatile union _KSTACK_COUNT, StackCount
        const s_field StackCount                                         = {
            .byte = 0x348     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x350, Member, Type: struct _LIST_ENTRY, ProcessListEntry
        const s_field ProcessListEntry                                   = {
            .byte = 0x350     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x360, Member, Type: unsigned __int64, CycleTime
        const s_field CycleTime                                          = {
            .byte = 0x360     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x368, Member, Type: unsigned __int64, ContextSwitches
        const s_field ContextSwitches                                    = {
            .byte = 0x368     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x370, Member, Type: struct _KSCHEDULING_GROUP *, SchedulingGroup
        const s_field SchedulingGroup                                    = {
            .byte = 0x370     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x378, Member, Type: unsigned long, FreezeCount
        const s_field FreezeCount                                        = {
            .byte = 0x378     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x37C, Member, Type: unsigned long, KernelTime
        const s_field KernelTime                                         = {
            .byte = 0x37c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x380, Member, Type: unsigned long, UserTime
        const s_field UserTime                                           = {
            .byte = 0x380     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x384, Member, Type: unsigned long, ReadyTime
        const s_field ReadyTime                                          = {
            .byte = 0x384     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x388, Member, Type: unsigned __int64, UserDirectoryTableBase
        const s_field UserDirectoryTableBase                             = {
            .byte = 0x388     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x390, Member, Type: unsigned char, AddressPolicy
        const s_field AddressPolicy                                      = {
            .byte = 0x390     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x391, Member, Type: unsigned char[0x47], Spare2
        const s_field Spare2                                             = {
            .byte = 0x391     , .bytes = 0x47      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x3D8, Member, Type: void *, InstrumentationCallback
        const s_field InstrumentationCallback                            = {
            .byte = 0x3d8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x3E0, Member, Type: union <anonymous-tag>, SecureState
        const s_field SecureState                                        = {
            .byte = 0x3e0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x3E8, Member, Type: unsigned __int64, KernelWaitTime
        const s_field KernelWaitTime                                     = {
            .byte = 0x3e8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x3F0, Member, Type: unsigned __int64, UserWaitTime
        const s_field UserWaitTime                                       = {
            .byte = 0x3f0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x3F8, Member, Type: unsigned __int64[0x8], EndPadding
        const s_field EndPadding                                         = {
            .byte = 0x3f8     , .bytes = 0x40      , .bit = 0x0 , .bits = 0x0  };
    }
    namespace _EPROCESS {
        // Data           : this+0x0, Member, Type: struct _KPROCESS, Pcb
        const s_field Pcb                                                = {
            .byte = 0x0       , .bytes = 0x438     , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x438, Member, Type: struct _EX_PUSH_LOCK, ProcessLock
        const s_field ProcessLock                                        = {
            .byte = 0x438     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x440, Member, Type: void *, UniqueProcessId
        const s_field UniqueProcessId                                    = {
            .byte = 0x440     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x448, Member, Type: struct _LIST_ENTRY, ActiveProcessLinks
        const s_field ActiveProcessLinks                                 = {
            .byte = 0x448     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x458, Member, Type: struct _EX_RUNDOWN_REF, RundownProtect
        const s_field RundownProtect                                     = {
            .byte = 0x458     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x460, Member, Type: unsigned long, Flags2
        const s_field Flags2                                             = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x460:0x0 len(0x1), Member, Type: unsigned long, JobNotReallyActive
        const s_field JobNotReallyActive                                 = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x1  };
        // Data           : this(bf)+0x460:0x1 len(0x1), Member, Type: unsigned long, AccountingFolded
        const s_field AccountingFolded                                   = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x1 , .bits = 0x1  };
        // Data           : this(bf)+0x460:0x2 len(0x1), Member, Type: unsigned long, NewProcessReported
        const s_field NewProcessReported                                 = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x2 , .bits = 0x1  };
        // Data           : this(bf)+0x460:0x3 len(0x1), Member, Type: unsigned long, ExitProcessReported
        const s_field ExitProcessReported                                = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x3 , .bits = 0x1  };
        // Data           : this(bf)+0x460:0x4 len(0x1), Member, Type: unsigned long, ReportCommitChanges
        const s_field ReportCommitChanges                                = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x4 , .bits = 0x1  };
        // Data           : this(bf)+0x460:0x5 len(0x1), Member, Type: unsigned long, LastReportMemory
        const s_field LastReportMemory                                   = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x5 , .bits = 0x1  };
        // Data           : this(bf)+0x460:0x6 len(0x1), Member, Type: unsigned long, ForceWakeCharge
        const s_field ForceWakeCharge                                    = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x6 , .bits = 0x1  };
        // Data           : this(bf)+0x460:0x7 len(0x1), Member, Type: unsigned long, CrossSessionCreate
        const s_field CrossSessionCreate                                 = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x7 , .bits = 0x1  };
        // Data           : this(bf)+0x460:0x8 len(0x1), Member, Type: unsigned long, NeedsHandleRundown
        const s_field NeedsHandleRundown                                 = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x8 , .bits = 0x1  };
        // Data           : this(bf)+0x460:0x9 len(0x1), Member, Type: unsigned long, RefTraceEnabled
        const s_field RefTraceEnabled                                    = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x9 , .bits = 0x1  };
        // Data           : this(bf)+0x460:0xA len(0x1), Member, Type: unsigned long, PicoCreated
        const s_field PicoCreated                                        = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0xa , .bits = 0x1  };
        // Data           : this(bf)+0x460:0xB len(0x1), Member, Type: unsigned long, EmptyJobEvaluated
        const s_field EmptyJobEvaluated                                  = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0xb , .bits = 0x1  };
        // Data           : this(bf)+0x460:0xC len(0x3), Member, Type: unsigned long, DefaultPagePriority
        const s_field DefaultPagePriority                                = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0xc , .bits = 0x3  };
        // Data           : this(bf)+0x460:0xF len(0x1), Member, Type: unsigned long, PrimaryTokenFrozen
        const s_field PrimaryTokenFrozen                                 = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0xf , .bits = 0x1  };
        // Data           : this(bf)+0x460:0x10 len(0x1), Member, Type: unsigned long, ProcessVerifierTarget
        const s_field ProcessVerifierTarget                              = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x10, .bits = 0x1  };
        // Data           : this(bf)+0x460:0x11 len(0x1), Member, Type: unsigned long, RestrictSetThreadContext
        const s_field RestrictSetThreadContext                           = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x11, .bits = 0x1  };
        // Data           : this(bf)+0x460:0x12 len(0x1), Member, Type: unsigned long, AffinityPermanent
        const s_field AffinityPermanent                                  = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x12, .bits = 0x1  };
        // Data           : this(bf)+0x460:0x13 len(0x1), Member, Type: unsigned long, AffinityUpdateEnable
        const s_field AffinityUpdateEnable                               = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x13, .bits = 0x1  };
        // Data           : this(bf)+0x460:0x14 len(0x1), Member, Type: unsigned long, PropagateNode
        const s_field PropagateNode                                      = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x14, .bits = 0x1  };
        // Data           : this(bf)+0x460:0x15 len(0x1), Member, Type: unsigned long, ExplicitAffinity
        const s_field ExplicitAffinity                                   = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x15, .bits = 0x1  };
        // Data           : this(bf)+0x460:0x16 len(0x2), Member, Type: unsigned long, ProcessExecutionState
        const s_field ProcessExecutionState                              = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x16, .bits = 0x2  };
        // Data           : this(bf)+0x460:0x18 len(0x1), Member, Type: unsigned long, EnableReadVmLogging
        const s_field EnableReadVmLogging                                = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x18, .bits = 0x1  };
        // Data           : this(bf)+0x460:0x19 len(0x1), Member, Type: unsigned long, EnableWriteVmLogging
        const s_field EnableWriteVmLogging                               = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x19, .bits = 0x1  };
        // Data           : this(bf)+0x460:0x1A len(0x1), Member, Type: unsigned long, FatalAccessTerminationRequested
        const s_field FatalAccessTerminationRequested                    = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x1a, .bits = 0x1  };
        // Data           : this(bf)+0x460:0x1B len(0x1), Member, Type: unsigned long, DisableSystemAllowedCpuSet
        const s_field DisableSystemAllowedCpuSet                         = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x1b, .bits = 0x1  };
        // Data           : this(bf)+0x460:0x1C len(0x2), Member, Type: unsigned long, ProcessStateChangeRequest
        const s_field ProcessStateChangeRequest                          = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x1c, .bits = 0x2  };
        // Data           : this(bf)+0x460:0x1E len(0x1), Member, Type: unsigned long, ProcessStateChangeInProgress
        const s_field ProcessStateChangeInProgress                       = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x1e, .bits = 0x1  };
        // Data           : this(bf)+0x460:0x1F len(0x1), Member, Type: unsigned long, InPrivate
        const s_field InPrivate                                          = {
            .byte = 0x460     , .bytes = 0x4       , .bit = 0x1f, .bits = 0x1  };
        // Data           : this+0x464, Member, Type: unsigned long, Flags
        const s_field Flags                                              = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x464:0x0 len(0x1), Member, Type: unsigned long, CreateReported
        const s_field CreateReported                                     = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x1  };
        // Data           : this(bf)+0x464:0x1 len(0x1), Member, Type: unsigned long, NoDebugInherit
        const s_field NoDebugInherit                                     = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x1 , .bits = 0x1  };
        // Data           : this(bf)+0x464:0x2 len(0x1), Member, Type: unsigned long, ProcessExiting
        const s_field ProcessExiting                                     = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x2 , .bits = 0x1  };
        // Data           : this(bf)+0x464:0x3 len(0x1), Member, Type: unsigned long, ProcessDelete
        const s_field ProcessDelete                                      = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x3 , .bits = 0x1  };
        // Data           : this(bf)+0x464:0x4 len(0x1), Member, Type: unsigned long, ManageExecutableMemoryWrites
        const s_field ManageExecutableMemoryWrites                       = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x4 , .bits = 0x1  };
        // Data           : this(bf)+0x464:0x5 len(0x1), Member, Type: unsigned long, VmDeleted
        const s_field VmDeleted                                          = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x5 , .bits = 0x1  };
        // Data           : this(bf)+0x464:0x6 len(0x1), Member, Type: unsigned long, OutswapEnabled
        const s_field OutswapEnabled                                     = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x6 , .bits = 0x1  };
        // Data           : this(bf)+0x464:0x7 len(0x1), Member, Type: unsigned long, Outswapped
        const s_field Outswapped                                         = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x7 , .bits = 0x1  };
        // Data           : this(bf)+0x464:0x8 len(0x1), Member, Type: unsigned long, FailFastOnCommitFail
        const s_field FailFastOnCommitFail                               = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x8 , .bits = 0x1  };
        // Data           : this(bf)+0x464:0x9 len(0x1), Member, Type: unsigned long, Wow64VaSpace4Gb
        const s_field Wow64VaSpace4Gb                                    = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x9 , .bits = 0x1  };
        // Data           : this(bf)+0x464:0xA len(0x2), Member, Type: unsigned long, AddressSpaceInitialized
        const s_field AddressSpaceInitialized                            = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0xa , .bits = 0x2  };
        // Data           : this(bf)+0x464:0xC len(0x1), Member, Type: unsigned long, SetTimerResolution
        const s_field SetTimerResolution                                 = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0xc , .bits = 0x1  };
        // Data           : this(bf)+0x464:0xD len(0x1), Member, Type: unsigned long, BreakOnTermination
        const s_field BreakOnTermination                                 = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0xd , .bits = 0x1  };
        // Data           : this(bf)+0x464:0xE len(0x1), Member, Type: unsigned long, DeprioritizeViews
        const s_field DeprioritizeViews                                  = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0xe , .bits = 0x1  };
        // Data           : this(bf)+0x464:0xF len(0x1), Member, Type: unsigned long, WriteWatch
        const s_field WriteWatch                                         = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0xf , .bits = 0x1  };
        // Data           : this(bf)+0x464:0x10 len(0x1), Member, Type: unsigned long, ProcessInSession
        const s_field ProcessInSession                                   = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x10, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x11 len(0x1), Member, Type: unsigned long, OverrideAddressSpace
        const s_field OverrideAddressSpace                               = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x11, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x12 len(0x1), Member, Type: unsigned long, HasAddressSpace
        const s_field HasAddressSpace                                    = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x12, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x13 len(0x1), Member, Type: unsigned long, LaunchPrefetched
        const s_field LaunchPrefetched                                   = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x13, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x14 len(0x1), Member, Type: unsigned long, Background
        const s_field Background                                         = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x14, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x15 len(0x1), Member, Type: unsigned long, VmTopDown
        const s_field VmTopDown                                          = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x15, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x16 len(0x1), Member, Type: unsigned long, ImageNotifyDone
        const s_field ImageNotifyDone                                    = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x16, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x17 len(0x1), Member, Type: unsigned long, PdeUpdateNeeded
        const s_field PdeUpdateNeeded                                    = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x17, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x18 len(0x1), Member, Type: unsigned long, VdmAllowed
        const s_field VdmAllowed                                         = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x18, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x19 len(0x1), Member, Type: unsigned long, ProcessRundown
        const s_field ProcessRundown                                     = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x19, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x1A len(0x1), Member, Type: unsigned long, ProcessInserted
        const s_field ProcessInserted                                    = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x1a, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x1B len(0x3), Member, Type: unsigned long, DefaultIoPriority
        const s_field DefaultIoPriority                                  = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x1b, .bits = 0x3  };
        // Data           : this(bf)+0x464:0x1E len(0x1), Member, Type: unsigned long, ProcessSelfDelete
        const s_field ProcessSelfDelete                                  = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x1e, .bits = 0x1  };
        // Data           : this(bf)+0x464:0x1F len(0x1), Member, Type: unsigned long, SetTimerResolutionLink
        const s_field SetTimerResolutionLink                             = {
            .byte = 0x464     , .bytes = 0x4       , .bit = 0x1f, .bits = 0x1  };
        // Data           : this+0x468, Member, Type: union _LARGE_INTEGER, CreateTime
        const s_field CreateTime                                         = {
            .byte = 0x468     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x470, Member, Type: unsigned __int64[0x2], ProcessQuotaUsage
        const s_field ProcessQuotaUsage                                  = {
            .byte = 0x470     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x480, Member, Type: unsigned __int64[0x2], ProcessQuotaPeak
        const s_field ProcessQuotaPeak                                   = {
            .byte = 0x480     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x490, Member, Type: unsigned __int64, PeakVirtualSize
        const s_field PeakVirtualSize                                    = {
            .byte = 0x490     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x498, Member, Type: unsigned __int64, VirtualSize
        const s_field VirtualSize                                        = {
            .byte = 0x498     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4A0, Member, Type: struct _LIST_ENTRY, SessionProcessLinks
        const s_field SessionProcessLinks                                = {
            .byte = 0x4a0     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4B0, Member, Type: void *, ExceptionPortData
        const s_field ExceptionPortData                                  = {
            .byte = 0x4b0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4B0, Member, Type: unsigned __int64, ExceptionPortValue
        const s_field ExceptionPortValue                                 = {
            .byte = 0x4b0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x4B0:0x0 len(0x3), Member, Type: unsigned __int64, ExceptionPortState
        const s_field ExceptionPortState                                 = {
            .byte = 0x4b0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x3  };
        // Data           : this+0x4B8, Member, Type: struct _EX_FAST_REF, Token
        const s_field Token                                              = {
            .byte = 0x4b8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4C0, Member, Type: unsigned __int64, MmReserved
        const s_field MmReserved                                         = {
            .byte = 0x4c0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4C8, Member, Type: struct _EX_PUSH_LOCK, AddressCreationLock
        const s_field AddressCreationLock                                = {
            .byte = 0x4c8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4D0, Member, Type: struct _EX_PUSH_LOCK, PageTableCommitmentLock
        const s_field PageTableCommitmentLock                            = {
            .byte = 0x4d0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4D8, Member, Type: struct _ETHREAD *, RotateInProgress
        const s_field RotateInProgress                                   = {
            .byte = 0x4d8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4E0, Member, Type: struct _ETHREAD *, ForkInProgress
        const s_field ForkInProgress                                     = {
            .byte = 0x4e0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4E8, Member, Type: struct _EJOB * volatile, CommitChargeJob
        const s_field CommitChargeJob                                    = {
            .byte = 0x4e8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4F0, Member, Type: struct _RTL_AVL_TREE, CloneRoot
        const s_field CloneRoot                                          = {
            .byte = 0x4f0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4F8, Member, Type: volatile unsigned __int64, NumberOfPrivatePages
        const s_field NumberOfPrivatePages                               = {
            .byte = 0x4f8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x500, Member, Type: volatile unsigned __int64, NumberOfLockedPages
        const s_field NumberOfLockedPages                                = {
            .byte = 0x500     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x508, Member, Type: void *, Win32Process
        const s_field Win32Process                                       = {
            .byte = 0x508     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x510, Member, Type: struct _EJOB * volatile, Job
        const s_field Job                                                = {
            .byte = 0x510     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x518, Member, Type: void *, SectionObject
        const s_field SectionObject                                      = {
            .byte = 0x518     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x520, Member, Type: void *, SectionBaseAddress
        const s_field SectionBaseAddress                                 = {
            .byte = 0x520     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x528, Member, Type: unsigned long, Cookie
        const s_field Cookie                                             = {
            .byte = 0x528     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x530, Member, Type: struct _PAGEFAULT_HISTORY *, WorkingSetWatch
        const s_field WorkingSetWatch                                    = {
            .byte = 0x530     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x538, Member, Type: void *, Win32WindowStation
        const s_field Win32WindowStation                                 = {
            .byte = 0x538     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x540, Member, Type: void *, InheritedFromUniqueProcessId
        const s_field InheritedFromUniqueProcessId                       = {
            .byte = 0x540     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x548, Member, Type: volatile unsigned __int64, OwnerProcessId
        const s_field OwnerProcessId                                     = {
            .byte = 0x548     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x550, Member, Type: struct _PEB *, Peb
        const s_field Peb                                                = {
            .byte = 0x550     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x558, Member, Type: struct _MM_SESSION_SPACE *, Session
        const s_field Session                                            = {
            .byte = 0x558     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x560, Member, Type: void *, Spare1
        const s_field Spare1                                             = {
            .byte = 0x560     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x568, Member, Type: struct _EPROCESS_QUOTA_BLOCK *, QuotaBlock
        const s_field QuotaBlock                                         = {
            .byte = 0x568     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x570, Member, Type: struct _HANDLE_TABLE *, ObjectTable
        const s_field ObjectTable                                        = {
            .byte = 0x570     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x578, Member, Type: void *, DebugPort
        const s_field DebugPort                                          = {
            .byte = 0x578     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x580, Member, Type: struct _EWOW64PROCESS *, WoW64Process
        const s_field WoW64Process                                       = {
            .byte = 0x580     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x588, Member, Type: void *, DeviceMap
        const s_field DeviceMap                                          = {
            .byte = 0x588     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x590, Member, Type: void *, EtwDataSource
        const s_field EtwDataSource                                      = {
            .byte = 0x590     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x598, Member, Type: unsigned __int64, PageDirectoryPte
        const s_field PageDirectoryPte                                   = {
            .byte = 0x598     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5A0, Member, Type: struct _FILE_OBJECT *, ImageFilePointer
        const s_field ImageFilePointer                                   = {
            .byte = 0x5a0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5A8, Member, Type: unsigned char[0xF], ImageFileName
        const s_field ImageFileName                                      = {
            .byte = 0x5a8     , .bytes = 0xf       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5B7, Member, Type: unsigned char, PriorityClass
        const s_field PriorityClass                                      = {
            .byte = 0x5b7     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5B8, Member, Type: void *, SecurityPort
        const s_field SecurityPort                                       = {
            .byte = 0x5b8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5C0, Member, Type: struct _SE_AUDIT_PROCESS_CREATION_INFO, SeAuditProcessCreationInfo
        const s_field SeAuditProcessCreationInfo                         = {
            .byte = 0x5c0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5C8, Member, Type: struct _LIST_ENTRY, JobLinks
        const s_field JobLinks                                           = {
            .byte = 0x5c8     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5D8, Member, Type: void *, HighestUserAddress
        const s_field HighestUserAddress                                 = {
            .byte = 0x5d8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5E0, Member, Type: struct _LIST_ENTRY, ThreadListHead
        const s_field ThreadListHead                                     = {
            .byte = 0x5e0     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5F0, Member, Type: volatile unsigned long, ActiveThreads
        const s_field ActiveThreads                                      = {
            .byte = 0x5f0     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5F4, Member, Type: unsigned long, ImagePathHash
        const s_field ImagePathHash                                      = {
            .byte = 0x5f4     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5F8, Member, Type: unsigned long, DefaultHardErrorProcessing
        const s_field DefaultHardErrorProcessing                         = {
            .byte = 0x5f8     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x5FC, Member, Type: long, LastThreadExitStatus
        const s_field LastThreadExitStatus                               = {
            .byte = 0x5fc     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x600, Member, Type: struct _EX_FAST_REF, PrefetchTrace
        const s_field PrefetchTrace                                      = {
            .byte = 0x600     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x608, Member, Type: void *, LockedPagesList
        const s_field LockedPagesList                                    = {
            .byte = 0x608     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x610, Member, Type: union _LARGE_INTEGER, ReadOperationCount
        const s_field ReadOperationCount                                 = {
            .byte = 0x610     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x618, Member, Type: union _LARGE_INTEGER, WriteOperationCount
        const s_field WriteOperationCount                                = {
            .byte = 0x618     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x620, Member, Type: union _LARGE_INTEGER, OtherOperationCount
        const s_field OtherOperationCount                                = {
            .byte = 0x620     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x628, Member, Type: union _LARGE_INTEGER, ReadTransferCount
        const s_field ReadTransferCount                                  = {
            .byte = 0x628     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x630, Member, Type: union _LARGE_INTEGER, WriteTransferCount
        const s_field WriteTransferCount                                 = {
            .byte = 0x630     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x638, Member, Type: union _LARGE_INTEGER, OtherTransferCount
        const s_field OtherTransferCount                                 = {
            .byte = 0x638     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x640, Member, Type: unsigned __int64, CommitChargeLimit
        const s_field CommitChargeLimit                                  = {
            .byte = 0x640     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x648, Member, Type: volatile unsigned __int64, CommitCharge
        const s_field CommitCharge                                       = {
            .byte = 0x648     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x650, Member, Type: volatile unsigned __int64, CommitChargePeak
        const s_field CommitChargePeak                                   = {
            .byte = 0x650     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x680, Member, Type: struct _MMSUPPORT_FULL, Vm
        const s_field Vm                                                 = {
            .byte = 0x680     , .bytes = 0x140     , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7C0, Member, Type: struct _LIST_ENTRY, MmProcessLinks
        const s_field MmProcessLinks                                     = {
            .byte = 0x7c0     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7D0, Member, Type: unsigned long, ModifiedPageCount
        const s_field ModifiedPageCount                                  = {
            .byte = 0x7d0     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7D4, Member, Type: long, ExitStatus
        const s_field ExitStatus                                         = {
            .byte = 0x7d4     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7D8, Member, Type: struct _RTL_AVL_TREE, VadRoot
        const s_field VadRoot                                            = {
            .byte = 0x7d8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7E0, Member, Type: void *, VadHint
        const s_field VadHint                                            = {
            .byte = 0x7e0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7E8, Member, Type: unsigned __int64, VadCount
        const s_field VadCount                                           = {
            .byte = 0x7e8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7F0, Member, Type: volatile unsigned __int64, VadPhysicalPages
        const s_field VadPhysicalPages                                   = {
            .byte = 0x7f0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7F8, Member, Type: unsigned __int64, VadPhysicalPagesLimit
        const s_field VadPhysicalPagesLimit                              = {
            .byte = 0x7f8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x800, Member, Type: struct _ALPC_PROCESS_CONTEXT, AlpcContext
        const s_field AlpcContext                                        = {
            .byte = 0x800     , .bytes = 0x20      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x820, Member, Type: struct _LIST_ENTRY, TimerResolutionLink
        const s_field TimerResolutionLink                                = {
            .byte = 0x820     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x830, Member, Type: struct _PO_DIAG_STACK_RECORD *, TimerResolutionStackRecord
        const s_field TimerResolutionStackRecord                         = {
            .byte = 0x830     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x838, Member, Type: unsigned long, RequestedTimerResolution
        const s_field RequestedTimerResolution                           = {
            .byte = 0x838     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x83C, Member, Type: unsigned long, SmallestTimerResolution
        const s_field SmallestTimerResolution                            = {
            .byte = 0x83c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x840, Member, Type: union _LARGE_INTEGER, ExitTime
        const s_field ExitTime                                           = {
            .byte = 0x840     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x848, Member, Type: struct _INVERTED_FUNCTION_TABLE *, InvertedFunctionTable
        const s_field InvertedFunctionTable                              = {
            .byte = 0x848     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x850, Member, Type: struct _EX_PUSH_LOCK, InvertedFunctionTableLock
        const s_field InvertedFunctionTableLock                          = {
            .byte = 0x850     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x858, Member, Type: unsigned long, ActiveThreadsHighWatermark
        const s_field ActiveThreadsHighWatermark                         = {
            .byte = 0x858     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x85C, Member, Type: unsigned long, LargePrivateVadCount
        const s_field LargePrivateVadCount                               = {
            .byte = 0x85c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x860, Member, Type: struct _EX_PUSH_LOCK, ThreadListLock
        const s_field ThreadListLock                                     = {
            .byte = 0x860     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x868, Member, Type: void *, WnfContext
        const s_field WnfContext                                         = {
            .byte = 0x868     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x870, Member, Type: struct _EJOB *, ServerSilo
        const s_field ServerSilo                                         = {
            .byte = 0x870     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x878, Member, Type: unsigned char, SignatureLevel
        const s_field SignatureLevel                                     = {
            .byte = 0x878     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x879, Member, Type: unsigned char, SectionSignatureLevel
        const s_field SectionSignatureLevel                              = {
            .byte = 0x879     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x87A, Member, Type: struct _PS_PROTECTION, Protection
        const s_field Protection                                         = {
            .byte = 0x87a     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x87B:0x0 len(0x3), Member, Type: unsigned char, HangCount
        const s_field HangCount                                          = {
            .byte = 0x87b     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x3  };
        // Data           : this(bf)+0x87B:0x3 len(0x3), Member, Type: unsigned char, GhostCount
        const s_field GhostCount                                         = {
            .byte = 0x87b     , .bytes = 0x1       , .bit = 0x3 , .bits = 0x3  };
        // Data           : this(bf)+0x87B:0x6 len(0x1), Member, Type: unsigned char, PrefilterException
        const s_field PrefilterException                                 = {
            .byte = 0x87b     , .bytes = 0x1       , .bit = 0x6 , .bits = 0x1  };
        // Data           : this+0x87C, Member, Type: unsigned long, Flags3
        const s_field Flags3                                             = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x87C:0x0 len(0x1), Member, Type: unsigned long, Minimal
        const s_field Minimal                                            = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x1 len(0x1), Member, Type: unsigned long, ReplacingPageRoot
        const s_field ReplacingPageRoot                                  = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x1 , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x2 len(0x1), Member, Type: unsigned long, Crashed
        const s_field Crashed                                            = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x2 , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x3 len(0x1), Member, Type: unsigned long, JobVadsAreTracked
        const s_field JobVadsAreTracked                                  = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x3 , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x4 len(0x1), Member, Type: unsigned long, VadTrackingDisabled
        const s_field VadTrackingDisabled                                = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x4 , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x5 len(0x1), Member, Type: unsigned long, AuxiliaryProcess
        const s_field AuxiliaryProcess                                   = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x5 , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x6 len(0x1), Member, Type: unsigned long, SubsystemProcess
        const s_field SubsystemProcess                                   = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x6 , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x7 len(0x1), Member, Type: unsigned long, IndirectCpuSets
        const s_field IndirectCpuSets                                    = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x7 , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x8 len(0x1), Member, Type: unsigned long, RelinquishedCommit
        const s_field RelinquishedCommit                                 = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x8 , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x9 len(0x1), Member, Type: unsigned long, HighGraphicsPriority
        const s_field HighGraphicsPriority                               = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x9 , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0xA len(0x1), Member, Type: unsigned long, CommitFailLogged
        const s_field CommitFailLogged                                   = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0xa , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0xB len(0x1), Member, Type: unsigned long, ReserveFailLogged
        const s_field ReserveFailLogged                                  = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0xb , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0xC len(0x1), Member, Type: unsigned long, SystemProcess
        const s_field SystemProcess                                      = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0xc , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0xD len(0x1), Member, Type: unsigned long, HideImageBaseAddresses
        const s_field HideImageBaseAddresses                             = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0xd , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0xE len(0x1), Member, Type: unsigned long, AddressPolicyFrozen
        const s_field AddressPolicyFrozen                                = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0xe , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0xF len(0x1), Member, Type: unsigned long, ProcessFirstResume
        const s_field ProcessFirstResume                                 = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0xf , .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x10 len(0x1), Member, Type: unsigned long, ForegroundExternal
        const s_field ForegroundExternal                                 = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x10, .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x11 len(0x1), Member, Type: unsigned long, ForegroundSystem
        const s_field ForegroundSystem                                   = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x11, .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x12 len(0x1), Member, Type: unsigned long, HighMemoryPriority
        const s_field HighMemoryPriority                                 = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x12, .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x13 len(0x1), Member, Type: unsigned long, EnableProcessSuspendResumeLogging
        const s_field EnableProcessSuspendResumeLogging                  = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x13, .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x14 len(0x1), Member, Type: unsigned long, EnableThreadSuspendResumeLogging
        const s_field EnableThreadSuspendResumeLogging                   = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x14, .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x15 len(0x1), Member, Type: unsigned long, SecurityDomainChanged
        const s_field SecurityDomainChanged                              = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x15, .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x16 len(0x1), Member, Type: unsigned long, SecurityFreezeComplete
        const s_field SecurityFreezeComplete                             = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x16, .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x17 len(0x1), Member, Type: unsigned long, VmProcessorHost
        const s_field VmProcessorHost                                    = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x17, .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x18 len(0x1), Member, Type: unsigned long, VmProcessorHostTransition
        const s_field VmProcessorHostTransition                          = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x18, .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x19 len(0x1), Member, Type: unsigned long, AltSyscall
        const s_field AltSyscall                                         = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x19, .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x1A len(0x1), Member, Type: unsigned long, TimerResolutionIgnore
        const s_field TimerResolutionIgnore                              = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x1a, .bits = 0x1  };
        // Data           : this(bf)+0x87C:0x1B len(0x1), Member, Type: unsigned long, DisallowUserTerminate
        const s_field DisallowUserTerminate                              = {
            .byte = 0x87c     , .bytes = 0x4       , .bit = 0x1b, .bits = 0x1  };
        // Data           : this+0x880, Member, Type: long, DeviceAsid
        const s_field DeviceAsid                                         = {
            .byte = 0x880     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x888, Member, Type: void *, SvmData
        const s_field SvmData                                            = {
            .byte = 0x888     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x890, Member, Type: struct _EX_PUSH_LOCK, SvmProcessLock
        const s_field SvmProcessLock                                     = {
            .byte = 0x890     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x898, Member, Type: unsigned __int64, SvmLock
        const s_field SvmLock                                            = {
            .byte = 0x898     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8A0, Member, Type: struct _LIST_ENTRY, SvmProcessDeviceListHead
        const s_field SvmProcessDeviceListHead                           = {
            .byte = 0x8a0     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8B0, Member, Type: unsigned __int64, LastFreezeInterruptTime
        const s_field LastFreezeInterruptTime                            = {
            .byte = 0x8b0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8B8, Member, Type: struct _PROCESS_DISK_COUNTERS *, DiskCounters
        const s_field DiskCounters                                       = {
            .byte = 0x8b8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8C0, Member, Type: void *, PicoContext
        const s_field PicoContext                                        = {
            .byte = 0x8c0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8C8, Member, Type: void *, EnclaveTable
        const s_field EnclaveTable                                       = {
            .byte = 0x8c8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8D0, Member, Type: unsigned __int64, EnclaveNumber
        const s_field EnclaveNumber                                      = {
            .byte = 0x8d0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8D8, Member, Type: struct _EX_PUSH_LOCK, EnclaveLock
        const s_field EnclaveLock                                        = {
            .byte = 0x8d8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8E0, Member, Type: unsigned long, HighPriorityFaultsAllowed
        const s_field HighPriorityFaultsAllowed                          = {
            .byte = 0x8e0     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8E8, Member, Type: struct _PO_PROCESS_ENERGY_CONTEXT *, EnergyContext
        const s_field EnergyContext                                      = {
            .byte = 0x8e8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8F0, Member, Type: void *, VmContext
        const s_field VmContext                                          = {
            .byte = 0x8f0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8F8, Member, Type: unsigned __int64, SequenceNumber
        const s_field SequenceNumber                                     = {
            .byte = 0x8f8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x900, Member, Type: unsigned __int64, CreateInterruptTime
        const s_field CreateInterruptTime                                = {
            .byte = 0x900     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x908, Member, Type: unsigned __int64, CreateUnbiasedInterruptTime
        const s_field CreateUnbiasedInterruptTime                        = {
            .byte = 0x908     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x910, Member, Type: unsigned __int64, TotalUnbiasedFrozenTime
        const s_field TotalUnbiasedFrozenTime                            = {
            .byte = 0x910     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x918, Member, Type: unsigned __int64, LastAppStateUpdateTime
        const s_field LastAppStateUpdateTime                             = {
            .byte = 0x918     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x920:0x0 len(0x3D), Member, Type: unsigned __int64, LastAppStateUptime
        const s_field LastAppStateUptime                                 = {
            .byte = 0x920     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x3d };
        // Data           : this(bf)+0x920:0x3D len(0x3), Member, Type: unsigned __int64, LastAppState
        const s_field LastAppState                                       = {
            .byte = 0x920     , .bytes = 0x8       , .bit = 0x3d, .bits = 0x3  };
        // Data           : this+0x928, Member, Type: volatile unsigned __int64, SharedCommitCharge
        const s_field SharedCommitCharge                                 = {
            .byte = 0x928     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x930, Member, Type: struct _EX_PUSH_LOCK, SharedCommitLock
        const s_field SharedCommitLock                                   = {
            .byte = 0x930     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x938, Member, Type: struct _LIST_ENTRY, SharedCommitLinks
        const s_field SharedCommitLinks                                  = {
            .byte = 0x938     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x948, Member, Type: unsigned __int64, AllowedCpuSets
        const s_field AllowedCpuSets                                     = {
            .byte = 0x948     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x950, Member, Type: unsigned __int64, DefaultCpuSets
        const s_field DefaultCpuSets                                     = {
            .byte = 0x950     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x948, Member, Type: unsigned __int64 *, AllowedCpuSetsIndirect
        const s_field AllowedCpuSetsIndirect                             = {
            .byte = 0x948     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x950, Member, Type: unsigned __int64 *, DefaultCpuSetsIndirect
        const s_field DefaultCpuSetsIndirect                             = {
            .byte = 0x950     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x958, Member, Type: void *, DiskIoAttribution
        const s_field DiskIoAttribution                                  = {
            .byte = 0x958     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x960, Member, Type: void *, DxgProcess
        const s_field DxgProcess                                         = {
            .byte = 0x960     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x968, Member, Type: unsigned long, Win32KFilterSet
        const s_field Win32KFilterSet                                    = {
            .byte = 0x968     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x970, Member, Type: volatile union _PS_INTERLOCKED_TIMER_DELAY_VALUES, ProcessTimerDelay
        const s_field ProcessTimerDelay                                  = {
            .byte = 0x970     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x978, Member, Type: volatile unsigned long, KTimerSets
        const s_field KTimerSets                                         = {
            .byte = 0x978     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x97C, Member, Type: volatile unsigned long, KTimer2Sets
        const s_field KTimer2Sets                                        = {
            .byte = 0x97c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x980, Member, Type: volatile unsigned long, ThreadTimerSets
        const s_field ThreadTimerSets                                    = {
            .byte = 0x980     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x988, Member, Type: unsigned __int64, VirtualTimerListLock
        const s_field VirtualTimerListLock                               = {
            .byte = 0x988     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x990, Member, Type: struct _LIST_ENTRY, VirtualTimerListHead
        const s_field VirtualTimerListHead                               = {
            .byte = 0x990     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9A0, Member, Type: struct _WNF_STATE_NAME, WakeChannel
        const s_field WakeChannel                                        = {
            .byte = 0x9a0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9A0, Member, Type: struct _PS_PROCESS_WAKE_INFORMATION, WakeInfo
        const s_field WakeInfo                                           = {
            .byte = 0x9a0     , .bytes = 0x30      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9D0, Member, Type: unsigned long, MitigationFlags
        const s_field MitigationFlags                                    = {
            .byte = 0x9d0     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9D0, Member, Type: struct <anonymous-tag>, MitigationFlagsValues
        const s_field MitigationFlagsValues                              = {
            .byte = 0x9d0     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9D4, Member, Type: unsigned long, MitigationFlags2
        const s_field MitigationFlags2                                   = {
            .byte = 0x9d4     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9D4, Member, Type: struct <anonymous-tag>, MitigationFlags2Values
        const s_field MitigationFlags2Values                             = {
            .byte = 0x9d4     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9D8, Member, Type: void *, PartitionObject
        const s_field PartitionObject                                    = {
            .byte = 0x9d8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9E0, Member, Type: unsigned __int64, SecurityDomain
        const s_field SecurityDomain                                     = {
            .byte = 0x9e0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9E8, Member, Type: unsigned __int64, ParentSecurityDomain
        const s_field ParentSecurityDomain                               = {
            .byte = 0x9e8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9F0, Member, Type: void *, CoverageSamplerContext
        const s_field CoverageSamplerContext                             = {
            .byte = 0x9f0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x9F8, Member, Type: void *, MmHotPatchContext
        const s_field MmHotPatchContext                                  = {
            .byte = 0x9f8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xA00, Member, Type: struct _RTL_AVL_TREE, DynamicEHContinuationTargetsTree
        const s_field DynamicEHContinuationTargetsTree                   = {
            .byte = 0xa00     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xA08, Member, Type: struct _EX_PUSH_LOCK, DynamicEHContinuationTargetsLock
        const s_field DynamicEHContinuationTargetsLock                   = {
            .byte = 0xa08     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xA10, Member, Type: struct _PS_DYNAMIC_ENFORCED_ADDRESS_RANGES, DynamicEnforcedCetCompatibleRanges
        const s_field DynamicEnforcedCetCompatibleRanges                 = {
            .byte = 0xa10     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xA20, Member, Type: unsigned long, DisabledComponentFlags
        const s_field DisabledComponentFlags                             = {
            .byte = 0xa20     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
    }
    namespace _PEB {
        // Data           : this+0x0, Member, Type: unsigned char, InheritedAddressSpace
        const s_field InheritedAddressSpace                              = {
            .byte = 0x0       , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x1, Member, Type: unsigned char, ReadImageFileExecOptions
        const s_field ReadImageFileExecOptions                           = {
            .byte = 0x1       , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2, Member, Type: unsigned char, BeingDebugged
        const s_field BeingDebugged                                      = {
            .byte = 0x2       , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x3, Member, Type: unsigned char, BitField
        const s_field BitField                                           = {
            .byte = 0x3       , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x3:0x0 len(0x1), Member, Type: unsigned char, ImageUsesLargePages
        const s_field ImageUsesLargePages                                = {
            .byte = 0x3       , .bytes = 0x1       , .bit = 0x0 , .bits = 0x1  };
        // Data           : this(bf)+0x3:0x1 len(0x1), Member, Type: unsigned char, IsProtectedProcess
        const s_field IsProtectedProcess                                 = {
            .byte = 0x3       , .bytes = 0x1       , .bit = 0x1 , .bits = 0x1  };
        // Data           : this(bf)+0x3:0x2 len(0x1), Member, Type: unsigned char, IsImageDynamicallyRelocated
        const s_field IsImageDynamicallyRelocated                        = {
            .byte = 0x3       , .bytes = 0x1       , .bit = 0x2 , .bits = 0x1  };
        // Data           : this(bf)+0x3:0x3 len(0x1), Member, Type: unsigned char, SkipPatchingUser32Forwarders
        const s_field SkipPatchingUser32Forwarders                       = {
            .byte = 0x3       , .bytes = 0x1       , .bit = 0x3 , .bits = 0x1  };
        // Data           : this(bf)+0x3:0x4 len(0x1), Member, Type: unsigned char, IsPackagedProcess
        const s_field IsPackagedProcess                                  = {
            .byte = 0x3       , .bytes = 0x1       , .bit = 0x4 , .bits = 0x1  };
        // Data           : this(bf)+0x3:0x5 len(0x1), Member, Type: unsigned char, IsAppContainer
        const s_field IsAppContainer                                     = {
            .byte = 0x3       , .bytes = 0x1       , .bit = 0x5 , .bits = 0x1  };
        // Data           : this(bf)+0x3:0x6 len(0x1), Member, Type: unsigned char, IsProtectedProcessLight
        const s_field IsProtectedProcessLight                            = {
            .byte = 0x3       , .bytes = 0x1       , .bit = 0x6 , .bits = 0x1  };
        // Data           : this(bf)+0x3:0x7 len(0x1), Member, Type: unsigned char, IsLongPathAwareProcess
        const s_field IsLongPathAwareProcess                             = {
            .byte = 0x3       , .bytes = 0x1       , .bit = 0x7 , .bits = 0x1  };
        // Data           : this+0x4, Member, Type: unsigned char[0x4], Padding0
        const s_field Padding0                                           = {
            .byte = 0x4       , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8, Member, Type: void *, Mutant
        const s_field Mutant                                             = {
            .byte = 0x8       , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x10, Member, Type: void *, ImageBaseAddress
        const s_field ImageBaseAddress                                   = {
            .byte = 0x10      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x18, Member, Type: struct _PEB_LDR_DATA *, Ldr
        const s_field Ldr                                                = {
            .byte = 0x18      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x20, Member, Type: struct _RTL_USER_PROCESS_PARAMETERS *, ProcessParameters
        const s_field ProcessParameters                                  = {
            .byte = 0x20      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x28, Member, Type: void *, SubSystemData
        const s_field SubSystemData                                      = {
            .byte = 0x28      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x30, Member, Type: void *, ProcessHeap
        const s_field ProcessHeap                                        = {
            .byte = 0x30      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x38, Member, Type: struct _RTL_CRITICAL_SECTION *, FastPebLock
        const s_field FastPebLock                                        = {
            .byte = 0x38      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x40, Member, Type: union _SLIST_HEADER * volatile, AtlThunkSListPtr
        const s_field AtlThunkSListPtr                                   = {
            .byte = 0x40      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x48, Member, Type: void *, IFEOKey
        const s_field IFEOKey                                            = {
            .byte = 0x48      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x50, Member, Type: unsigned long, CrossProcessFlags
        const s_field CrossProcessFlags                                  = {
            .byte = 0x50      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x50:0x0 len(0x1), Member, Type: unsigned long, ProcessInJob
        const s_field ProcessInJob                                       = {
            .byte = 0x50      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x1  };
        // Data           : this(bf)+0x50:0x1 len(0x1), Member, Type: unsigned long, ProcessInitializing
        const s_field ProcessInitializing                                = {
            .byte = 0x50      , .bytes = 0x4       , .bit = 0x1 , .bits = 0x1  };
        // Data           : this(bf)+0x50:0x2 len(0x1), Member, Type: unsigned long, ProcessUsingVEH
        const s_field ProcessUsingVEH                                    = {
            .byte = 0x50      , .bytes = 0x4       , .bit = 0x2 , .bits = 0x1  };
        // Data           : this(bf)+0x50:0x3 len(0x1), Member, Type: unsigned long, ProcessUsingVCH
        const s_field ProcessUsingVCH                                    = {
            .byte = 0x50      , .bytes = 0x4       , .bit = 0x3 , .bits = 0x1  };
        // Data           : this(bf)+0x50:0x4 len(0x1), Member, Type: unsigned long, ProcessUsingFTH
        const s_field ProcessUsingFTH                                    = {
            .byte = 0x50      , .bytes = 0x4       , .bit = 0x4 , .bits = 0x1  };
        // Data           : this(bf)+0x50:0x5 len(0x1), Member, Type: unsigned long, ProcessPreviouslyThrottled
        const s_field ProcessPreviouslyThrottled                         = {
            .byte = 0x50      , .bytes = 0x4       , .bit = 0x5 , .bits = 0x1  };
        // Data           : this(bf)+0x50:0x6 len(0x1), Member, Type: unsigned long, ProcessCurrentlyThrottled
        const s_field ProcessCurrentlyThrottled                          = {
            .byte = 0x50      , .bytes = 0x4       , .bit = 0x6 , .bits = 0x1  };
        // Data           : this(bf)+0x50:0x7 len(0x1), Member, Type: unsigned long, ProcessImagesHotPatched
        const s_field ProcessImagesHotPatched                            = {
            .byte = 0x50      , .bytes = 0x4       , .bit = 0x7 , .bits = 0x1  };
        // Data           : this(bf)+0x50:0x8 len(0x18), Member, Type: unsigned long, ReservedBits0
        const s_field ReservedBits0                                      = {
            .byte = 0x50      , .bytes = 0x4       , .bit = 0x8 , .bits = 0x18 };
        // Data           : this+0x54, Member, Type: unsigned char[0x4], Padding1
        const s_field Padding1                                           = {
            .byte = 0x54      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x58, Member, Type: void *, KernelCallbackTable
        const s_field KernelCallbackTable                                = {
            .byte = 0x58      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x58, Member, Type: void *, UserSharedInfoPtr
        const s_field UserSharedInfoPtr                                  = {
            .byte = 0x58      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x60, Member, Type: unsigned long, SystemReserved
        const s_field SystemReserved                                     = {
            .byte = 0x60      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x64, Member, Type: unsigned long, AtlThunkSListPtr32
        const s_field AtlThunkSListPtr32                                 = {
            .byte = 0x64      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x68, Member, Type: void *, ApiSetMap
        const s_field ApiSetMap                                          = {
            .byte = 0x68      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x70, Member, Type: unsigned long, TlsExpansionCounter
        const s_field TlsExpansionCounter                                = {
            .byte = 0x70      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x74, Member, Type: unsigned char[0x4], Padding2
        const s_field Padding2                                           = {
            .byte = 0x74      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x78, Member, Type: void *, TlsBitmap
        const s_field TlsBitmap                                          = {
            .byte = 0x78      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x80, Member, Type: unsigned long[0x2], TlsBitmapBits
        const s_field TlsBitmapBits                                      = {
            .byte = 0x80      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x88, Member, Type: void *, ReadOnlySharedMemoryBase
        const s_field ReadOnlySharedMemoryBase                           = {
            .byte = 0x88      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x90, Member, Type: void *, SharedData
        const s_field SharedData                                         = {
            .byte = 0x90      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x98, Member, Type: void * *, ReadOnlyStaticServerData
        const s_field ReadOnlyStaticServerData                           = {
            .byte = 0x98      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xA0, Member, Type: void *, AnsiCodePageData
        const s_field AnsiCodePageData                                   = {
            .byte = 0xa0      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xA8, Member, Type: void *, OemCodePageData
        const s_field OemCodePageData                                    = {
            .byte = 0xa8      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xB0, Member, Type: void *, UnicodeCaseTableData
        const s_field UnicodeCaseTableData                               = {
            .byte = 0xb0      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xB8, Member, Type: unsigned long, NumberOfProcessors
        const s_field NumberOfProcessors                                 = {
            .byte = 0xb8      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xBC, Member, Type: unsigned long, NtGlobalFlag
        const s_field NtGlobalFlag                                       = {
            .byte = 0xbc      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xC0, Member, Type: union _LARGE_INTEGER, CriticalSectionTimeout
        const s_field CriticalSectionTimeout                             = {
            .byte = 0xc0      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xC8, Member, Type: unsigned __int64, HeapSegmentReserve
        const s_field HeapSegmentReserve                                 = {
            .byte = 0xc8      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xD0, Member, Type: unsigned __int64, HeapSegmentCommit
        const s_field HeapSegmentCommit                                  = {
            .byte = 0xd0      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xD8, Member, Type: unsigned __int64, HeapDeCommitTotalFreeThreshold
        const s_field HeapDeCommitTotalFreeThreshold                     = {
            .byte = 0xd8      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xE0, Member, Type: unsigned __int64, HeapDeCommitFreeBlockThreshold
        const s_field HeapDeCommitFreeBlockThreshold                     = {
            .byte = 0xe0      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xE8, Member, Type: unsigned long, NumberOfHeaps
        const s_field NumberOfHeaps                                      = {
            .byte = 0xe8      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xEC, Member, Type: unsigned long, MaximumNumberOfHeaps
        const s_field MaximumNumberOfHeaps                               = {
            .byte = 0xec      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xF0, Member, Type: void * *, ProcessHeaps
        const s_field ProcessHeaps                                       = {
            .byte = 0xf0      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xF8, Member, Type: void *, GdiSharedHandleTable
        const s_field GdiSharedHandleTable                               = {
            .byte = 0xf8      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x100, Member, Type: void *, ProcessStarterHelper
        const s_field ProcessStarterHelper                               = {
            .byte = 0x100     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x108, Member, Type: unsigned long, GdiDCAttributeList
        const s_field GdiDCAttributeList                                 = {
            .byte = 0x108     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x10C, Member, Type: unsigned char[0x4], Padding3
        const s_field Padding3                                           = {
            .byte = 0x10c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x110, Member, Type: struct _RTL_CRITICAL_SECTION *, LoaderLock
        const s_field LoaderLock                                         = {
            .byte = 0x110     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x118, Member, Type: unsigned long, OSMajorVersion
        const s_field OSMajorVersion                                     = {
            .byte = 0x118     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x11C, Member, Type: unsigned long, OSMinorVersion
        const s_field OSMinorVersion                                     = {
            .byte = 0x11c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x120, Member, Type: unsigned short, OSBuildNumber
        const s_field OSBuildNumber                                      = {
            .byte = 0x120     , .bytes = 0x2       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x122, Member, Type: unsigned short, OSCSDVersion
        const s_field OSCSDVersion                                       = {
            .byte = 0x122     , .bytes = 0x2       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x124, Member, Type: unsigned long, OSPlatformId
        const s_field OSPlatformId                                       = {
            .byte = 0x124     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x128, Member, Type: unsigned long, ImageSubsystem
        const s_field ImageSubsystem                                     = {
            .byte = 0x128     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x12C, Member, Type: unsigned long, ImageSubsystemMajorVersion
        const s_field ImageSubsystemMajorVersion                         = {
            .byte = 0x12c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x130, Member, Type: unsigned long, ImageSubsystemMinorVersion
        const s_field ImageSubsystemMinorVersion                         = {
            .byte = 0x130     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x134, Member, Type: unsigned char[0x4], Padding4
        const s_field Padding4                                           = {
            .byte = 0x134     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x138, Member, Type: unsigned __int64, ActiveProcessAffinityMask
        const s_field ActiveProcessAffinityMask                          = {
            .byte = 0x138     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x140, Member, Type: unsigned long[0x3C], GdiHandleBuffer
        const s_field GdiHandleBuffer                                    = {
            .byte = 0x140     , .bytes = 0xf0      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x230, Member, Type: function  *, PostProcessInitRoutine
        const s_field PostProcessInitRoutine                             = {
            .byte = 0x230     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x238, Member, Type: void *, TlsExpansionBitmap
        const s_field TlsExpansionBitmap                                 = {
            .byte = 0x238     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x240, Member, Type: unsigned long[0x20], TlsExpansionBitmapBits
        const s_field TlsExpansionBitmapBits                             = {
            .byte = 0x240     , .bytes = 0x80      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2C0, Member, Type: unsigned long, SessionId
        const s_field SessionId                                          = {
            .byte = 0x2c0     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2C4, Member, Type: unsigned char[0x4], Padding5
        const s_field Padding5                                           = {
            .byte = 0x2c4     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2C8, Member, Type: union _ULARGE_INTEGER, AppCompatFlags
        const s_field AppCompatFlags                                     = {
            .byte = 0x2c8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2D0, Member, Type: union _ULARGE_INTEGER, AppCompatFlagsUser
        const s_field AppCompatFlagsUser                                 = {
            .byte = 0x2d0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2D8, Member, Type: void *, pShimData
        const s_field pShimData                                          = {
            .byte = 0x2d8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2E0, Member, Type: void *, AppCompatInfo
        const s_field AppCompatInfo                                      = {
            .byte = 0x2e0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2E8, Member, Type: struct _UNICODE_STRING, CSDVersion
        const s_field CSDVersion                                         = {
            .byte = 0x2e8     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x2F8, Member, Type: const struct _ACTIVATION_CONTEXT_DATA *, ActivationContextData
        const s_field ActivationContextData                              = {
            .byte = 0x2f8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x300, Member, Type: struct _ASSEMBLY_STORAGE_MAP *, ProcessAssemblyStorageMap
        const s_field ProcessAssemblyStorageMap                          = {
            .byte = 0x300     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x308, Member, Type: const struct _ACTIVATION_CONTEXT_DATA *, SystemDefaultActivationContextData
        const s_field SystemDefaultActivationContextData                 = {
            .byte = 0x308     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x310, Member, Type: struct _ASSEMBLY_STORAGE_MAP *, SystemAssemblyStorageMap
        const s_field SystemAssemblyStorageMap                           = {
            .byte = 0x310     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x318, Member, Type: unsigned __int64, MinimumStackCommit
        const s_field MinimumStackCommit                                 = {
            .byte = 0x318     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x320, Member, Type: void *[0x4], SparePointers
        const s_field SparePointers                                      = {
            .byte = 0x320     , .bytes = 0x20      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x340, Member, Type: unsigned long[0x5], SpareUlongs
        const s_field SpareUlongs                                        = {
            .byte = 0x340     , .bytes = 0x14      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x358, Member, Type: void *, WerRegistrationData
        const s_field WerRegistrationData                                = {
            .byte = 0x358     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x360, Member, Type: void *, WerShipAssertPtr
        const s_field WerShipAssertPtr                                   = {
            .byte = 0x360     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x368, Member, Type: void *, pUnused
        const s_field pUnused                                            = {
            .byte = 0x368     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x370, Member, Type: void *, pImageHeaderHash
        const s_field pImageHeaderHash                                   = {
            .byte = 0x370     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x378, Member, Type: unsigned long, TracingFlags
        const s_field TracingFlags                                       = {
            .byte = 0x378     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x378:0x0 len(0x1), Member, Type: unsigned long, HeapTracingEnabled
        const s_field HeapTracingEnabled                                 = {
            .byte = 0x378     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x1  };
        // Data           : this(bf)+0x378:0x1 len(0x1), Member, Type: unsigned long, CritSecTracingEnabled
        const s_field CritSecTracingEnabled                              = {
            .byte = 0x378     , .bytes = 0x4       , .bit = 0x1 , .bits = 0x1  };
        // Data           : this(bf)+0x378:0x2 len(0x1), Member, Type: unsigned long, LibLoaderTracingEnabled
        const s_field LibLoaderTracingEnabled                            = {
            .byte = 0x378     , .bytes = 0x4       , .bit = 0x2 , .bits = 0x1  };
        // Data           : this(bf)+0x378:0x3 len(0x1D), Member, Type: unsigned long, SpareTracingBits
        const s_field SpareTracingBits                                   = {
            .byte = 0x378     , .bytes = 0x4       , .bit = 0x3 , .bits = 0x1d };
        // Data           : this+0x37C, Member, Type: unsigned char[0x4], Padding6
        const s_field Padding6                                           = {
            .byte = 0x37c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x380, Member, Type: unsigned __int64, CsrServerReadOnlySharedMemoryBase
        const s_field CsrServerReadOnlySharedMemoryBase                  = {
            .byte = 0x380     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x388, Member, Type: unsigned __int64, TppWorkerpListLock
        const s_field TppWorkerpListLock                                 = {
            .byte = 0x388     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x390, Member, Type: struct _LIST_ENTRY, TppWorkerpList
        const s_field TppWorkerpList                                     = {
            .byte = 0x390     , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x3A0, Member, Type: void *[0x80], WaitOnAddressHashTable
        const s_field WaitOnAddressHashTable                             = {
            .byte = 0x3a0     , .bytes = 0x400     , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7A0, Member, Type: void *, TelemetryCoverageHeader
        const s_field TelemetryCoverageHeader                            = {
            .byte = 0x7a0     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7A8, Member, Type: unsigned long, CloudFileFlags
        const s_field CloudFileFlags                                     = {
            .byte = 0x7a8     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7AC, Member, Type: unsigned long, CloudFileDiagFlags
        const s_field CloudFileDiagFlags                                 = {
            .byte = 0x7ac     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7B0, Member, Type: char, PlaceholderCompatibilityMode
        const s_field PlaceholderCompatibilityMode                       = {
            .byte = 0x7b0     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7B1, Member, Type: char[0x7], PlaceholderCompatibilityModeReserved
        const s_field PlaceholderCompatibilityModeReserved               = {
            .byte = 0x7b1     , .bytes = 0x7       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7B8, Member, Type: struct _LEAP_SECOND_DATA *, LeapSecondData
        const s_field LeapSecondData                                     = {
            .byte = 0x7b8     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x7C0, Member, Type: unsigned long, LeapSecondFlags
        const s_field LeapSecondFlags                                    = {
            .byte = 0x7c0     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x7C0:0x0 len(0x1), Member, Type: unsigned long, SixtySecondEnabled
        const s_field SixtySecondEnabled                                 = {
            .byte = 0x7c0     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x1  };
        // Data           : this(bf)+0x7C0:0x1 len(0x1F), Member, Type: unsigned long, Reserved
        const s_field Reserved                                           = {
            .byte = 0x7c0     , .bytes = 0x4       , .bit = 0x1 , .bits = 0x1f };
        // Data           : this+0x7C4, Member, Type: unsigned long, NtGlobalFlag2
        const s_field NtGlobalFlag2                                      = {
            .byte = 0x7c4     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
    }
    namespace _PEB_LDR_DATA {
        // Data           : this+0x0, Member, Type: unsigned long, Length
        const s_field Length                                             = {
            .byte = 0x0       , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x4, Member, Type: unsigned char, Initialized
        const s_field Initialized                                        = {
            .byte = 0x4       , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x8, Member, Type: void *, SsHandle
        const s_field SsHandle                                           = {
            .byte = 0x8       , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x10, Member, Type: struct _LIST_ENTRY, InLoadOrderModuleList
        const s_field InLoadOrderModuleList                              = {
            .byte = 0x10      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x20, Member, Type: struct _LIST_ENTRY, InMemoryOrderModuleList
        const s_field InMemoryOrderModuleList                            = {
            .byte = 0x20      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x30, Member, Type: struct _LIST_ENTRY, InInitializationOrderModuleList
        const s_field InInitializationOrderModuleList                    = {
            .byte = 0x30      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x40, Member, Type: void *, EntryInProgress
        const s_field EntryInProgress                                    = {
            .byte = 0x40      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x48, Member, Type: unsigned char, ShutdownInProgress
        const s_field ShutdownInProgress                                 = {
            .byte = 0x48      , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x50, Member, Type: void *, ShutdownThreadId
        const s_field ShutdownThreadId                                   = {
            .byte = 0x50      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
    }
    namespace _LDR_DATA_TABLE_ENTRY {
        // Data           : this+0x0, Member, Type: struct _LIST_ENTRY, InLoadOrderLinks
        const s_field InLoadOrderLinks                                   = {
            .byte = 0x0       , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x10, Member, Type: struct _LIST_ENTRY, InMemoryOrderLinks
        const s_field InMemoryOrderLinks                                 = {
            .byte = 0x10      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x20, Member, Type: struct _LIST_ENTRY, InInitializationOrderLinks
        const s_field InInitializationOrderLinks                         = {
            .byte = 0x20      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x30, Member, Type: void *, DllBase
        const s_field DllBase                                            = {
            .byte = 0x30      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x38, Member, Type: void *, EntryPoint
        const s_field EntryPoint                                         = {
            .byte = 0x38      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x40, Member, Type: unsigned long, SizeOfImage
        const s_field SizeOfImage                                        = {
            .byte = 0x40      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x48, Member, Type: struct _UNICODE_STRING, FullDllName
        const s_field FullDllName                                        = {
            .byte = 0x48      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x58, Member, Type: struct _UNICODE_STRING, BaseDllName
        const s_field BaseDllName                                        = {
            .byte = 0x58      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x68, Member, Type: unsigned char[0x4], FlagGroup
        const s_field FlagGroup                                          = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x68, Member, Type: unsigned long, Flags
        const s_field Flags                                              = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this(bf)+0x68:0x0 len(0x1), Member, Type: unsigned long, PackagedBinary
        const s_field PackagedBinary                                     = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x1  };
        // Data           : this(bf)+0x68:0x1 len(0x1), Member, Type: unsigned long, MarkedForRemoval
        const s_field MarkedForRemoval                                   = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x1 , .bits = 0x1  };
        // Data           : this(bf)+0x68:0x2 len(0x1), Member, Type: unsigned long, ImageDll
        const s_field ImageDll                                           = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x2 , .bits = 0x1  };
        // Data           : this(bf)+0x68:0x3 len(0x1), Member, Type: unsigned long, LoadNotificationsSent
        const s_field LoadNotificationsSent                              = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x3 , .bits = 0x1  };
        // Data           : this(bf)+0x68:0x4 len(0x1), Member, Type: unsigned long, TelemetryEntryProcessed
        const s_field TelemetryEntryProcessed                            = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x4 , .bits = 0x1  };
        // Data           : this(bf)+0x68:0x5 len(0x1), Member, Type: unsigned long, ProcessStaticImport
        const s_field ProcessStaticImport                                = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x5 , .bits = 0x1  };
        // Data           : this(bf)+0x68:0x6 len(0x1), Member, Type: unsigned long, InLegacyLists
        const s_field InLegacyLists                                      = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x6 , .bits = 0x1  };
        // Data           : this(bf)+0x68:0x7 len(0x1), Member, Type: unsigned long, InIndexes
        const s_field InIndexes                                          = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x7 , .bits = 0x1  };
        // Data           : this(bf)+0x68:0x8 len(0x1), Member, Type: unsigned long, ShimDll
        const s_field ShimDll                                            = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x8 , .bits = 0x1  };
        // Data           : this(bf)+0x68:0x9 len(0x1), Member, Type: unsigned long, InExceptionTable
        const s_field InExceptionTable                                   = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x9 , .bits = 0x1  };
        // Data           : this(bf)+0x68:0xA len(0x2), Member, Type: unsigned long, ReservedFlags1
        const s_field ReservedFlags1                                     = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0xa , .bits = 0x2  };
        // Data           : this(bf)+0x68:0xC len(0x1), Member, Type: unsigned long, LoadInProgress
        const s_field LoadInProgress                                     = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0xc , .bits = 0x1  };
        // Data           : this(bf)+0x68:0xD len(0x1), Member, Type: unsigned long, LoadConfigProcessed
        const s_field LoadConfigProcessed                                = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0xd , .bits = 0x1  };
        // Data           : this(bf)+0x68:0xE len(0x1), Member, Type: unsigned long, EntryProcessed
        const s_field EntryProcessed                                     = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0xe , .bits = 0x1  };
        // Data           : this(bf)+0x68:0xF len(0x1), Member, Type: unsigned long, ProtectDelayLoad
        const s_field ProtectDelayLoad                                   = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0xf , .bits = 0x1  };
        // Data           : this(bf)+0x68:0x10 len(0x2), Member, Type: unsigned long, ReservedFlags3
        const s_field ReservedFlags3                                     = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x10, .bits = 0x2  };
        // Data           : this(bf)+0x68:0x12 len(0x1), Member, Type: unsigned long, DontCallForThreads
        const s_field DontCallForThreads                                 = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x12, .bits = 0x1  };
        // Data           : this(bf)+0x68:0x13 len(0x1), Member, Type: unsigned long, ProcessAttachCalled
        const s_field ProcessAttachCalled                                = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x13, .bits = 0x1  };
        // Data           : this(bf)+0x68:0x14 len(0x1), Member, Type: unsigned long, ProcessAttachFailed
        const s_field ProcessAttachFailed                                = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x14, .bits = 0x1  };
        // Data           : this(bf)+0x68:0x15 len(0x1), Member, Type: unsigned long, CorDeferredValidate
        const s_field CorDeferredValidate                                = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x15, .bits = 0x1  };
        // Data           : this(bf)+0x68:0x16 len(0x1), Member, Type: unsigned long, CorImage
        const s_field CorImage                                           = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x16, .bits = 0x1  };
        // Data           : this(bf)+0x68:0x17 len(0x1), Member, Type: unsigned long, DontRelocate
        const s_field DontRelocate                                       = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x17, .bits = 0x1  };
        // Data           : this(bf)+0x68:0x18 len(0x1), Member, Type: unsigned long, CorILOnly
        const s_field CorILOnly                                          = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x18, .bits = 0x1  };
        // Data           : this(bf)+0x68:0x19 len(0x1), Member, Type: unsigned long, ChpeImage
        const s_field ChpeImage                                          = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x19, .bits = 0x1  };
        // Data           : this(bf)+0x68:0x1A len(0x2), Member, Type: unsigned long, ReservedFlags5
        const s_field ReservedFlags5                                     = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x1a, .bits = 0x2  };
        // Data           : this(bf)+0x68:0x1C len(0x1), Member, Type: unsigned long, Redirected
        const s_field Redirected                                         = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x1c, .bits = 0x1  };
        // Data           : this(bf)+0x68:0x1D len(0x2), Member, Type: unsigned long, ReservedFlags6
        const s_field ReservedFlags6                                     = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x1d, .bits = 0x2  };
        // Data           : this(bf)+0x68:0x1F len(0x1), Member, Type: unsigned long, CompatDatabaseProcessed
        const s_field CompatDatabaseProcessed                            = {
            .byte = 0x68      , .bytes = 0x4       , .bit = 0x1f, .bits = 0x1  };
        // Data           : this+0x6C, Member, Type: unsigned short, ObsoleteLoadCount
        const s_field ObsoleteLoadCount                                  = {
            .byte = 0x6c      , .bytes = 0x2       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x6E, Member, Type: unsigned short, TlsIndex
        const s_field TlsIndex                                           = {
            .byte = 0x6e      , .bytes = 0x2       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x70, Member, Type: struct _LIST_ENTRY, HashLinks
        const s_field HashLinks                                          = {
            .byte = 0x70      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x80, Member, Type: unsigned long, TimeDateStamp
        const s_field TimeDateStamp                                      = {
            .byte = 0x80      , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x88, Member, Type: struct _ACTIVATION_CONTEXT *, EntryPointActivationContext
        const s_field EntryPointActivationContext                        = {
            .byte = 0x88      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x90, Member, Type: void *, Lock
        const s_field Lock                                               = {
            .byte = 0x90      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x98, Member, Type: struct _LDR_DDAG_NODE *, DdagNode
        const s_field DdagNode                                           = {
            .byte = 0x98      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xA0, Member, Type: struct _LIST_ENTRY, NodeModuleLink
        const s_field NodeModuleLink                                     = {
            .byte = 0xa0      , .bytes = 0x10      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xB0, Member, Type: struct _LDRP_LOAD_CONTEXT *, LoadContext
        const s_field LoadContext                                        = {
            .byte = 0xb0      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xB8, Member, Type: void *, ParentDllBase
        const s_field ParentDllBase                                      = {
            .byte = 0xb8      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xC0, Member, Type: void *, SwitchBackContext
        const s_field SwitchBackContext                                  = {
            .byte = 0xc0      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xC8, Member, Type: struct _RTL_BALANCED_NODE, BaseAddressIndexNode
        const s_field BaseAddressIndexNode                               = {
            .byte = 0xc8      , .bytes = 0x18      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xE0, Member, Type: struct _RTL_BALANCED_NODE, MappingInfoIndexNode
        const s_field MappingInfoIndexNode                               = {
            .byte = 0xe0      , .bytes = 0x18      , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0xF8, Member, Type: unsigned __int64, OriginalBase
        const s_field OriginalBase                                       = {
            .byte = 0xf8      , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x100, Member, Type: union _LARGE_INTEGER, LoadTime
        const s_field LoadTime                                           = {
            .byte = 0x100     , .bytes = 0x8       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x108, Member, Type: unsigned long, BaseNameHashValue
        const s_field BaseNameHashValue                                  = {
            .byte = 0x108     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x10C, Member, Type: enum _LDR_DLL_LOAD_REASON, LoadReason
        const s_field LoadReason                                         = {
            .byte = 0x10c     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x110, Member, Type: unsigned long, ImplicitPathOptions
        const s_field ImplicitPathOptions                                = {
            .byte = 0x110     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x114, Member, Type: unsigned long, ReferenceCount
        const s_field ReferenceCount                                     = {
            .byte = 0x114     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x118, Member, Type: unsigned long, DependentLoadFlags
        const s_field DependentLoadFlags                                 = {
            .byte = 0x118     , .bytes = 0x4       , .bit = 0x0 , .bits = 0x0  };
        // Data           : this+0x11C, Member, Type: unsigned char, SigningLevel
        const s_field SigningLevel                                       = {
            .byte = 0x11c     , .bytes = 0x1       , .bit = 0x0 , .bits = 0x0  };
    }
    namespace _PUBLIC {
    }
}

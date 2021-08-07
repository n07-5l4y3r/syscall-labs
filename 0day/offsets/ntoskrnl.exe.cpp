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
    namespace _PUBLIC {
    }
}

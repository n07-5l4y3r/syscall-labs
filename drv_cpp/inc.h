#pragma once

#include <ntifs.h>
#include <ntddk.h>
#include <windef.h>
#include <ntimage.h>
#include <ntstrsafe.h>
#include <intrin.h>
#include <stdarg.h>
#include <wdm.h>

#pragma comment(lib,"ntdll.lib")

#undef ExFreePool

#include "helpers/cpp_class/cpp_class.h"

#include "worker/worker.h"

#include "offsets/offset.h"

#include "helpers/phys_mem/if.h"

#include "func/traces.h"


#include "ipc/ipc_slave.h"
#pragma once

#define PRINTVAR( var, format ) printf("    %s" " : " format "\n", #var, var)

#include <Windows.h>
#include <string>

#include "offsets/offset.h"

#include "../kdmapper/kdmapper/intel_driver.hpp"

#include "ring0_exec/ring0_exec.h"
#include "phys_mem/phys_mem.h"
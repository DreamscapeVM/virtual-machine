#ifndef __INCLUDE_CPU_ISA_SET_H
#define __INCLUDE_CPU_ISA_SET_H

#include <cstdint>
#define GEN(ISA, NAME) ISA##_##NAME

enum class vm_cpu_isa : uint8_t { 
#include <isa/fundamental/cpu_isa.h>
};

#endif


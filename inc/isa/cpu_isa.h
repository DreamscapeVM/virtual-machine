#ifndef __INCLUDE_CPU_ISA_SET_H
#define __INCLUDE_CPU_ISA_SET_H

#include <cstdint>
#if defined(GGEN) || defined(TGEN) || defined(BGEN)
#undef GGEN
#undef TGEN
#undef BGEN
#endif

#define GGEN(ISA, NAME) ISA##_##NAME ,
#define TGEN(ISA, NAME, TYPE) ISA##_##NAME##_##TYPE ,
#define BGEN(ISA, NAME, BIT) ISA##_##NAME##_##BIT ,

enum class vm_cpu_isa : uint8_t { 
#ifdef FUNDAMENTAL_ISA
#include <isa/fundamental/cpu_isa.h>
#endif
};


#endif


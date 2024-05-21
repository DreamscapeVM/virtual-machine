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

using char_t = char;

#ifdef FUNDAMENTAL_ISA
    #define FUNDAMENTAL_OPS_ABLE 0b0001
#else
    #define FUNDAMENTAL_OPS_ABLE 0b0000
#endif

namespace cpu_isa { 
    constexpr uint64_t allowable_list_ops = (0x00LL | FUNDAMENTAL_OPS_ABLE);
}

enum class vm_cpu_isa : uint8_t { 
#ifdef FUNDAMENTAL_ISA
#include <isa/fundamental/cpu_isa.h>
#endif
};


#endif


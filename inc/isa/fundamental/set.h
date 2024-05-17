#ifndef __INCLUDE_ISA_FUNDAMENTAL_SET_H
#define __INCLUDE_ISA_FUNDAMENTAL_SET_H

#include <cstdint>
#include <isa/instruction.h>

#pragma pack(push, 1)

namespace fundamental_isa { 

ISA_NAME(exit) {
};

template<typename T>
ISA_NAME(add) { 
    uint8_t lvalue;
    uint8_t rvalue;
    uint8_t output;
};

template<typename T>
ISA_NAME(load) { 
    static constexpr int size = sizeof(T);
    uint8_t reg;
    uint64_t target;
};

template<typename T>
ISA_NAME(store) { 
    static constexpr int size = sizeof(T);
    uint8_t reg;
    uint64_t target;
};

template<typename T>
ISA_NAME(equal_condition) { 
    static constexpr int size = sizeof(T);
    uint8_t lreg;
    uint8_t rreg;
    uint64_t true_pc;
    uint64_t false_pc;
};


}

#pragma pack(pop)
#endif

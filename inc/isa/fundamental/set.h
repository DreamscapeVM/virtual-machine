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
template<typename T>
ISA_NAME(left_angle_condition) { 
    using type = T;
    uint8_t lreg;
    uint8_t rreg;
    uint64_t true_pc;
    uint64_t false_pc;
};



template<typename T>
ISA_NAME(scan_from_prompt_per_primitive) {
    uint64_t memory_address;
};

template<typename T>
ISA_NAME(print_to_prompt_per_primitive) { 
    uint64_t memory_address;
};

template<typename T>
ISA_NAME(constant_mov_to_reg) { 
    uint8_t reg;
    T data;
};

template<typename T>
ISA_NAME(variable_mov_to_reg) { 
    uint8_t source_reg;
    uint8_t target_reg;
};

template<typename T>
ISA_NAME(constant_mov_to_mem) { 
    uint64_t memory_address;
    T data;
};

}

#pragma pack(pop)
#endif

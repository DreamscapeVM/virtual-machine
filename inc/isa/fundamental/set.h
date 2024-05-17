#ifndef __INCLUDE_ISA_FUNDAMENTAL_SET_H
#define __INCLUDE_ISA_FUNDAMENTAL_SET_H

#include <cstdint>
#include <isa/instruction.h>

#pragma pack(push, 1)

template<typename T>
struct add : public instruction { 
    T lvalue;
    T rvalue;
    T output;
};

template<typename T>
struct mov : public instruction { 
    T value;
    T target;
};

struct load : public instruction { 
    uint8_t reg;
    uint64_t target;
};

struct store : public instruction { 
    uint8_t reg;
    uint64_t mem;
};

#pragma pack(pop)

#endif

#ifndef __INCLUDE_ISA_FUNDAMENTAL_SET_H
#define __INCLUDE_ISA_FUNDAMENTAL_SET_H

#include <cstdint>
#include <isa/instruction.h>

#pragma pack(push, 1)

template<typename T>
struct Add : public instriction { 
    T lvalue;
    T rvalue;
    T output;
};

#pragma pack(pop)

#endif

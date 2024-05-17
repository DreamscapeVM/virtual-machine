#ifndef __INCLUDE_ISA_INSTUCTION_H
#define __INCLUDE_ISA_INSTUCTION_H

#include <cstdint>
// #include <array>
// need to consider array.
// template<typename T>
// struct from_mem_to_value { 
//     static const T* get(const uint8_t* const mem, uint64_t pos) { 
//         return (fundamental_type<T>::type)mem[pos];
//     }
//     static const void set(const uint8_t* mem, uint64_t pos, const T value) { 
//         for (int i = 0; i < sizeof(T); i++) {
//             mem[pos + i] = ((uint8_t*)&value)[i];
//         }
//     }
// };

template<typename T>
struct size_of_instruction { 
    static constexpr uint8_t size = sizeof(T);
};

struct instriction { 
    uint8_t id;
    void execute() {}
};

struct isa_operator {
    
};


#endif

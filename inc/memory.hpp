#ifndef __INCLUDE_MEMORY_CHACHA
#define __INCLUDE_MEMORY_CHACHA

#include "type.hpp"

class memory { 
private:
    uint8_t* mem;
    uint8_t max_memory_index = 0;

public:
    void init(uint64_t size) {
        mem = new uint8_t[size];
        max_memory_index = size;
    }
    void deinit() { 
        delete[] mem;
        mem = nullptr;
    }

    void* read(uint64_t index, uint64_t size) {
        if (max_memory_index >= index + size) { 
            return nullptr;
        }

        return (void*)(&mem[size]);
    }
    
    [[nodiscard]]
    void* write(uint64_t index, uint64_t size, uint8_t* value) { 
        if (max_memory_index >= index + size) { 
            return nullptr;
        }
        for (int i = 0; i < size; i++) {
            mem[index + i] = value[i];
        }   
    }
};

#endif

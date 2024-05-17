#ifndef __INCLUDE_MEMORY_CHACHA
#define __INCLUDE_MEMORY_CHACHA

#include <stdint.h>

class memory { 
private:
    uint8_t* mem;
    uint8_t max_memory_index = 0;

public:
    void init(uint64_t size);
    void deinit();
    uint8_t* read(uint64_t index) const;

    template<typename T>
    void pwrite(uint64_t index, const T* const value) { 

        for (int i = 0; i < sizeof(T); i++) {
            mem[index + i] = ((uint8_t*)(value))[i];
        }   
    }

    template<typename T>
    void write(uint64_t index, T value) {
        for (int i = 0; i < sizeof(T); i++) {
            mem[index + i] = ((uint8_t*)&value)[i];
        }   
    }
};



#endif

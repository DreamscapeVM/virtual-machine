#ifndef __INCLUDE_MEMORY_CHACHA
#define __INCLUDE_MEMORY_CHACHA

#include <stdint.h>

class memory { 
private:
    uint64_t max_memory_size = 0;
    uint8_t* mem;
public:
    const uint64_t get_memory_size() const;
    const uint8_t* get_memory() const;
    void init(uint64_t size);
    void deinit();
};



#endif

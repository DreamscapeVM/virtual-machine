#include <system/memory.h>

const uint64_t memory::get_memory_size() const { 
    return max_memory_size;
}
uint8_t* const memory::get_memory() const {
    return mem;
}

void memory::init(uint64_t size) {
    mem = new uint8_t[size];
    max_memory_size = size;
}
void memory::deinit() { 
    delete[] mem;
    mem = nullptr;
}

#include <system/memory.h>

void memory::init(uint64_t size) {
    mem = new uint8_t[size];
    max_memory_index = size;
}
void memory::deinit() { 
    delete[] mem;
    mem = nullptr;
}

uint8_t* memory::read(uint64_t index) const {
    return (&mem[index]);
}




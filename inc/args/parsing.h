#ifndef __INCLUDE__ARGS_STRUCTURE_H
#define __INCLUDE__ARGS_STRUCTURE_H

#include <cstdint>

namespace args {
    constexpr uint64_t KB = 1024;
    constexpr uint64_t MB = 1024 * KB;
    constexpr uint64_t GB = 1024 * MB;
    constexpr uint64_t TB = 1024 * GB;

    struct arguments { 
        uint64_t max_memory_size;
        uint64_t insturction_per_seconds;
    };
    
    const args::arguments parse_argument(int argc, char** argv);
}

#endif

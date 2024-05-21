#ifndef __INCLUDE__ARGS_STRUCTURE_H
#define __INCLUDE__ARGS_STRUCTURE_H

#include <cstdint>
#include <string>

namespace args {
    constexpr uint64_t KB = 1024;
    constexpr uint64_t MB = 1024 * KB;
    constexpr uint64_t GB = 1024 * MB;
    constexpr uint64_t TB = 1024 * GB;

    struct arguments { 
        bool verbose;

        uint64_t max_memory_size;
        uint64_t max_register_size;
        uint64_t insturction_per_seconds;
        std::string path_of_software;
    };
    
    const args::arguments parse_argument(int argc, char** argv);
}

#endif

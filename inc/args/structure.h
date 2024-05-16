#ifndef __INCLUDE__ARGS_STRUCTURE_H
#define __INCLUDE__ARGS_STRUCTURE_H

#include <cstdint>

namespace args {
    struct arguments { 
        uint64_t max_memory_size;
        uint64_t insturction_per_seconds;
    };
    
    const args::arguments parse_argument(int argc, char** argv);
}

#endif

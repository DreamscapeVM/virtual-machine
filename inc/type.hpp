#ifndef __INCLUDE_TPYE_CHACHA
#define __INCLUDE_TPYE_CHACHA
#include <vector>
#include <stack>

using com_data_t = std::vector<uint8_t>;
using com_register_t = std::stack<com_data_t>;

enum class data_type_t { 
    interger,
    fix_float,
    text,
};

#endif

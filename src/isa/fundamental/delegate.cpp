#include <isa/fundamental/delegate.h>
#include <isa/fundamental/set.h>

#include "ops.hpp.inl"

namespace fundamental_isa { 
#define MAKE_ADD(NAME) (std::make_pair(size_of_instruction<fundamental_isa::isa_##NAME>::size, fundamental_isa::ops_##NAME))
#define MAKE_ADD_TYPE(NAME, TYPE) (std::make_pair(size_of_instruction<fundamental_isa::isa_##NAME<TYPE>>::size, fundamental_isa::ops_##NAME<TYPE>))
#define MAKE_PUSH(X) (this->data.push_back(X))

fundamental_instruction_delegate::fundamental_instruction_delegate() {
    MAKE_PUSH(MAKE_ADD(exit));
    MAKE_PUSH(MAKE_ADD_TYPE(add, int));
    MAKE_PUSH(MAKE_ADD_TYPE(add, float));
}

uint8_t fundamental_instruction_delegate::get_total_instuction_size() const {
    return data.size();
}

uint8_t fundamental_instruction_delegate::get_instruction_size(uint8_t id) const {
    return data[id].first;
}

instruction_delegate::ops_func fundamental_instruction_delegate::get_ops(uint8_t id) { 
    return data[id].second;
}


}

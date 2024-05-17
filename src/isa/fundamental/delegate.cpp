#include <string>
#include <isa/fundamental/delegate.h>
#include <isa/fundamental/set.h>

namespace fundamental_isa { 

#define ADD(TYPE) (this->data.push_back(size_of_instruction<TYPE>::size))

fundamental_instruction_delegate::fundamental_instruction_delegate() {
    ADD(fundamental_isa::exit);
    ADD(fundamental_isa::add<int>);
    ADD(fundamental_isa::add<float>);
}

uint8_t fundamental_instruction_delegate::get_total_instuction_size() const {
    return data.size();
}

uint8_t fundamental_instruction_delegate::get_instruction_size(uint8_t id) const {
    return data[id];
}

}

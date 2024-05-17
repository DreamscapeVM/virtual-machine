#include <isa/fundamental/delegate.h>
#include <isa/fundamental/set.h>

#include "ops.hpp.inl"

namespace fundamental_isa { 
#if defined(GGEN) || defined(TGEN) || defined(BGEN)
#undef GGEN
#undef TGEN
#undef BGEN
#endif
#define MAKE_PUSH(X) (this->data.push_back(X))

#define MGGEN(ISA, NAME) (std::make_pair(size_of_instruction<fundamental_isa::isa_##NAME>::size, fundamental_isa::ops_##NAME))
#define MTGEN(ISA, NAME, TYPE) std::make_pair(size_of_instruction<fundamental_isa::isa_##NAME<TYPE##_t>>::size, fundamental_isa::ops_##NAME<TYPE##_t>)
#define MBGEN(ISA, NAME, BIT) std::make_pair(size_of_instruction<fundamental_isa::isa_##NAME<uint##BIT##_t>>::size, fundamental_isa::ops_##NAME<uint##BIT##_t>)

#define GGEN(ISA, NAME) (MAKE_PUSH(MGGEN(ISA, NAME)));
#define TGEN(ISA, NAME, TYPE) (MAKE_PUSH(MTGEN(ISA, NAME, TYPE)));
#define BGEN(ISA, NAME, BIT) (MAKE_PUSH(MBGEN(ISA, NAME, BIT)));

fundamental_instruction_delegate::fundamental_instruction_delegate(const uint8_t start_id) : instruction_delegate(start_id) {
#include <isa/fundamental/cpu_isa.h>
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

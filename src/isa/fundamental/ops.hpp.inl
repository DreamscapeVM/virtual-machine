#include <isa/instruction.h>
#include <isa/fundamental/set.h>

namespace fundamental_isa { 

OPS_NAME(exit) {
    std::exit(0);
}

template<typename T>
OPS_NAME(add) {
    auto self = (fundamental_isa::isa_add<T>*)inst;
    ((T*)reg)[self->output] = ((T*)reg)[self->lvalue] + ((T*)reg)[self->rvalue];
}

template<typename T>
OPS_NAME(load) {
    auto self = (fundamental_isa::isa_load<T>*)inst;
    for (uint64_t i = 0; i < fundamental_isa::isa_load<T>::size; i++) { 
        *((uint8_t*)(((T*)reg) + self->reg) + i) = mem[self->target + i];
    }
}

template<typename T>
OPS_NAME(store) {
    auto self = (fundamental_isa::isa_store<T>*)inst;
    for (uint64_t i = 0; i < fundamental_isa::isa_store<T>::size; i++) { 
        mem[self->target + i] = *((uint8_t*)(((T*)reg) + self->reg) + i);
    }
}

}
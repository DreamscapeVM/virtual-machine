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

}
#ifndef __INCLUDE_CPU_CHACHA
#define __INCLUDE_CPU_CHACHA

#include <array>
#include <isa/instruction.h>
#include <isa/fundamental/set.h>

class cpu { 
private:
    uint64_t pc;


public:
    std::array<uint32_t, 8> reg;

    void execute(const instruction* const data) {
        if (data->id == 0){
            exit(0);
        }else if (data->id == 1) { 
            auto p = (fundamental_isa::add<int>*)(data);
            reg[p->output] = reg[p->lvalue] + reg[p->rvalue];
        }
    }
};

#endif

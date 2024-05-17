#ifndef __INCLUDE_CPU_CHACHA
#define __INCLUDE_CPU_CHACHA

#include <array>
#include <isa/instruction.h>
#include <isa/fundamental/set.h>

class cpu { 
private:
    uint64_t pc;
public:
    std::array<uint8_t, 8> reg;

    void execute(instruction* data) {
        if (data->id == 0){
            auto p = static_cast<add<int>*>(data);
            reg[p->output] = reg[p->lvalue] + reg[p->rvalue];
        }
    }

};

#endif

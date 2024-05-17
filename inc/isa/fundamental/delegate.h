#ifndef __INCLUDE_ISA_FUNDAMENTAL_DELEGATE_H
#define __INCLUDE_ISA_FUNDAMENTAL_DELEGATE_H

#include <isa/instruction.h>

namespace fundamental_isa { 
class fundamental_instruction_delegate : public instruction_delegate {
    std::vector<uint8_t> data;

public:
    fundamental_instruction_delegate();

    virtual uint8_t get_total_instuction_size() const override;
    virtual uint8_t get_instruction_size(uint8_t id) const override;
};

}

#endif

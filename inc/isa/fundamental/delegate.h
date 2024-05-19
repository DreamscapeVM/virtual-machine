#ifndef __INCLUDE_ISA_FUNDAMENTAL_DELEGATE_H
#define __INCLUDE_ISA_FUNDAMENTAL_DELEGATE_H

#include <isa/instruction.h>

namespace fundamental_isa { 

class fundamental_instruction_delegate : public instruction_delegate {
    std::vector<std::pair<uint8_t, instruction_delegate::ops_func>> data;

public:
    fundamental_instruction_delegate(const uint8_t start_id);
    virtual uint8_t get_total_instuction_size() const override;
    virtual uint8_t get_instruction_size(uint8_t id) const override;
    virtual instruction_delegate::ops_func get_ops(uint8_t id) override;
};

}

#endif

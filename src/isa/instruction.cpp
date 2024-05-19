#include <isa/instruction.h>


void instruction_factory::init(std::vector<std::unique_ptr<instruction_delegate>> delegates) { 
    for (const auto& d : delegates) { 
        int size = d->get_total_instuction_size();
        for (int i = 0; i < size; i++) {
            instruct.push_back(std::make_pair(d->get_instruction_size(i), d->get_ops(i)));
        }
    }
}

const instruction* const instruction_factory::get_instruction(const uint64_t pc, const uint8_t* const mem) const { 
    uint8_t inst = mem[pc];
    return (const instruction* const)(&mem[pc]);
}
const uint8_t instruction_factory::get_instruction_size_in_instruction(const vm_cpu_isa id) const { 
    return instruct[(uint8_t)id].first;
}
const instruction_delegate::ops_func instruction_factory::get_ops(const vm_cpu_isa id) const { 
    return instruct[(uint8_t)id].second;
}

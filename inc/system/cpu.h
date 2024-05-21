#ifndef __INCLUDE_CPU_CHACHA
#define __INCLUDE_CPU_CHACHA

#include <array>
#include <isa/instruction.h>
#include <system/memory.h>

class cpu { 
private:
    memory mem;
    instruction_factory engine;
    const instruction* const get_instruction(const uint64_t pc, const uint8_t* const mem) const;
    uint64_t instruction_per_seconds;

public:
    using register_data = std::vector<uint64_t>;

    register_data reg;

    void init(const uint64_t memory_size, const std::vector<uint64_t> init_register, const uint64_t clock);
    inline void execute(const instruction* const data);
    
    // need to predefine into software program file
    // TODO: CHANGE IT!
    void entry(register_data reg);

    // for interpretor mode.
    // directly insert ops into like dram and register memory.
    const int add_instruct(const uint64_t pc, const std::shared_ptr<instruction> data);
    const int add_instruct(const uint64_t pc, const std::vector<std::shared_ptr<instruction>> data);

    instruction_factory* const get_isa_engine();

    void add_software(uint8_t* data, uint64_t size);
};

#endif

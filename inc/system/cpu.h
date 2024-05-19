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
    
public:
    using register_data = std::array<uint32_t, 8>;

    register_data reg;

    void init();
    inline void execute(const instruction* const data);
    void entry(register_data reg);
    const int add_instruct(const uint32_t pc, const std::shared_ptr<instruction> data);
    const int add_instruct(const uint32_t pc, const std::vector<std::shared_ptr<instruction>> data);
    instruction_factory* get_isa_engine() { 
        return &this->engine;
    }

    // const int add_software(const uint32_t pc, std::vector<instruction*> data);
};

#endif

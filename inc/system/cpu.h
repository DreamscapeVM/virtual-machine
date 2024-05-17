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
    std::array<uint32_t, 8> reg;

    void init();
    inline void execute(const instruction* const data);
    void entry(int pc);
    const int add_instruct(const uint32_t pc, instruction* data);
    // const int add_software(const uint32_t pc, std::vector<instruction*> data);
};

#endif

#ifndef __INCLUDE_CPU_CHACHA
#define __INCLUDE_CPU_CHACHA

#include <array>
#include <isa/instruction.h>
#include <isa/fundamental/set.h>
#include <isa/fundamental/delegate.h>

class cpu { 
private:
    memory mem;
    instruction_factory instf;

public:
    std::array<uint32_t, 8> reg;

    void init() {
        mem.init(1024*1024);

        auto dd = std::vector<std::unique_ptr<instruction_delegate>>();
        dd.push_back(std::make_unique<fundamental_isa::fundamental_instruction_delegate>());
        instf.init(std::move(dd));

    }

    void execute(const instruction* const data) {
        // data->execute(reg.data(), nullptr);
    }

    void entry(int pc) {
        reg[1] = 30;
        reg[2] = 40;

        while (true) { 
            auto inst = instf.get_instruction(pc, mem.get_memory());
            pc += instf.get_instruction_size_in_memory(pc, mem.get_memory());
            execute(inst);
            spdlog::info("pc : {}, reg : [{}, {}, {}, {}, {}, {}, {}, {}]", 
                    pc,
                    reg[0],
                    reg[1],
                    reg[2],
                    reg[3],
                    reg[4],
                    reg[5],
                    reg[6], 
                    reg[7]);
        }
    }

    const int add_instruct(const uint32_t pc, instruction* data) { 
        auto entry_point = pc;
        auto m = mem.get_memory();

        auto size = instf.get_instruction_size_in_instruction(data->id);
        for (int s = 0; s < size; s++) { 
            m[entry_point + s] = ((uint8_t*)&(*data))[s];
        }

        return pc + size;
    }

    const int add_software(const uint32_t pc, std::vector<instruction*> data) { 
        auto last = pc;
        for (int i = 0; i < data.size(); i++) {
            last += add_instruct(last, data[i]);
        }
        return last;
    }
};

#endif

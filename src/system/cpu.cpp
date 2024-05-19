#include <fstream>
#include <system/cpu.h>
#include <spdlog/spdlog.h>
#include <isa/fundamental/delegate.h>

const instruction* const cpu::get_instruction(const uint64_t pc, const uint8_t* const mem) const { 
    uint8_t inst = mem[pc];
    return (const instruction* const)(&mem[pc]);
}
    
void cpu::init() {
    mem.init(1024*1024);

    auto dd = std::vector<std::unique_ptr<instruction_delegate>>();
    dd.push_back(std::make_unique<fundamental_isa::fundamental_instruction_delegate>(0));
    // dd.push_back(std::make_unique<fundamental_isa::fundamental_instruction_delegate>(dd[dd.size() - 1]->get_total_instuction_size()));
    engine.init(std::move(dd));

}

void cpu::execute(const instruction* const data) {
    engine.get_ops(data->id)(data, reg.data(), mem.get_memory());
}

void cpu::entry(register_data reg) {
    for (int i = 0; i < reg.size(); i++) { 
        this->reg[i] = reg[i];
    }
    
    while (true) { 
        auto inst = get_instruction(this->reg[0], mem.get_memory());
        
        this->reg[0] += engine.get_instruction_size_in_instruction(inst->id);

        execute(inst);
    }
}

const int cpu::add_instruct(const uint32_t pc, const std::shared_ptr<instruction> data) { 
    auto entry_point = pc;
    auto m = mem.get_memory();

    auto size = engine.get_instruction_size_in_instruction(data->id);
    for (int s = 0; s < size; s++) { 
    
        m[entry_point + s] = ((uint8_t*)data.get())[s];
    }

    return size;
}

const int cpu::add_instruct(const uint32_t pc, std::vector<std::shared_ptr<instruction>> data) { 
    auto last = pc;
    for (int i = 0; i < data.size(); i++) {
        last += add_instruct(last, data[i]);
    }
    return last;
}


void cpu::save(std::string file, int pc) { 
    std::ofstream output(file, std::ios::binary | std::ios::out);
    uint64_t data = 0;
    data = 0; output.write(reinterpret_cast<const char*>(&data), sizeof(uint64_t)); 
    data = 13; output.write(reinterpret_cast<const char*>(&data), sizeof(uint64_t)); 
    data = 1; output.write(reinterpret_cast<const char*>(&data), sizeof(uint64_t)); 
    data = 1000; output.write(reinterpret_cast<const char*>(&data), sizeof(uint32_t)); 
    data = 1; output.write(reinterpret_cast<const char*>(&data), sizeof(uint32_t)); 
    data = 15; output.write(reinterpret_cast<const char*>(&data), sizeof(uint32_t));
    data = '\n'; output.write(reinterpret_cast<const char*>(&data), sizeof(uint8_t));
    
    for (int i = 0; i < pc; i++) { 
        output << mem.get_memory()[i];
    }
}

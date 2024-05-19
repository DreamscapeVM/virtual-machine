#include <args/parsing.h>
#include <system/cpu.h>
#include <isa/fundamental/delegate.h>
#include <load/software.h>
#include <secure/helper.hpp>

void create_software(std::string file, std::vector<std::shared_ptr<cipher>>& ciphers){ 
    cpu c;
    c.init();
    auto a = c.get_isa_engine();
    int pc = 0;
    pc += c.add_instruct(pc, CREATE_BIT(fundamental, load, 32, 1, 0));
    pc += c.add_instruct(pc, CREATE_BIT(fundamental, load, 32, 2, 4));
    pc += c.add_instruct(pc, CREATE_BIT(fundamental, load, 32, 3, 4));
    pc += c.add_instruct(pc, CREATE_BIT(fundamental, load, 32, 4, 8));

    int loop = pc + 13;
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, print_to_prompt_per_primitive, uint32, 0));
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, print_to_prompt_per_primitive, char, 12));
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, add, uint32, 1, 1, 1));
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, add, uint32, 2, 3, 2));
    pc += c.add_instruct(pc, CREATE_BIT(fundamental, store, 32, 1, 0));
    int loop_end = pc + size_of_instruction<fundamental_isa::isa_equal_condition<uint32_t>>::size + 13;
    pc += c.add_instruct(pc, CREATE_BIT(fundamental, equal_condition, 32, 2, 4, (uint32_t)loop_end, (uint32_t)loop));
    pc += c.add_instruct(pc, CREATE(fundamental, exit));
    c.save(file, pc);
}

void execute(std::string file, std::vector<std::shared_ptr<cipher>>& ciphers) { 
    auto ware = software::load(file);
    int pc = ware.get_entry_point();
    auto code = ware.get_binary();

    cpu c;
    c.init();
    c.add_software(code.data(), code.size());
    c.entry(cpu::register_data {
        (uint32_t)pc, 0,0,0,0,0,0,0
    });
}

int main(int argc, char** argv) {  
    auto cipher = init();
    create_software("code.vm", cipher);
    execute("code.vm", cipher);
    return 0;
}

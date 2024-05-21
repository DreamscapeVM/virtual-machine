#include <args/parsing.h>
#include <system/cpu.h>
#include <isa/fundamental/delegate.h>
#include <load/software.h>

/*
 Only code for really ensure work my code test.
*/
#define PUSH_INSTRUCT(PC, CPU, INSTRUCTION) pc += c.add_instruct(pc, CREATE_BIT(fundamental, load, 32, 1, 0))
void create_software(std::string file){ 
    cpu c;
    c.init();
    auto a = c.get_isa_engine();
    int data_size = 13;
    int pc = 0;
    PUSH_INSTRUCT(pc, c, CREATE_BIT(fundamental, load, 32, 1, 0));

    PUSH_INSTRUCT(pc, c, CREATE_BIT(fundamental, load, 32, 2, 4));
    PUSH_INSTRUCT(pc, c, CREATE_BIT(fundamental, load, 32, 3, 4));
    PUSH_INSTRUCT(pc, c, CREATE_BIT(fundamental, load, 32, 4, 8));

    int loop = pc + data_size;
    PUSH_INSTRUCT(pc, c, CREATE_TYPE(fundamental, print_to_prompt_per_primitive, uint32, 0));
    PUSH_INSTRUCT(pc, c, CREATE_TYPE(fundamental, print_to_prompt_per_primitive, char, 12));
    PUSH_INSTRUCT(pc, c, CREATE_TYPE(fundamental, add, uint32, 1, 1, 1));
    PUSH_INSTRUCT(pc, c, CREATE_TYPE(fundamental, add, uint32, 2, 3, 2));
    PUSH_INSTRUCT(pc, c, CREATE_BIT(fundamental, store, 32, 1, 0));
    int loop_end = pc + size_of_instruction<fundamental_isa::isa_equal_condition<uint32_t>>::size + data_size;
    PUSH_INSTRUCT(pc, c, CREATE_BIT(fundamental, equal_condition, 32, 2, 4, (uint32_t)loop_end, (uint32_t)loop));
    PUSH_INSTRUCT(pc, c, CREATE(fundamental, exit));

    c.save(file, pc);
}

void execute(std::string file) { 
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
    // create_software("./examples/binaries/code.vm");
    
    execute("./examples/binaries/code.vm");
    return 0;
}

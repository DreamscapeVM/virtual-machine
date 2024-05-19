
#include <gtest/gtest.h>
#include <system/cpu.h>
#include <isa/fundamental/delegate.h>
#include <load/software.h>

TEST(ASSEMBLY, ForLoopTest) { 
      cpu c;
    c.init();
    auto a = c.get_isa_engine();
    int pc = 0;
    // mem 1000 -> reg 1
    pc += c.add_instruct(pc, CREATE_BIT(fundamental, load, 32, 1, 0));
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, add, uint32, 1,1,1));
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, add, uint32, 1,1,1));
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, add, uint32, 1,1,1));
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, add, uint32, 1,1,1));
    pc += c.add_instruct(pc, CREATE_BIT(fundamental, store, 32, 1, 0));
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, print_to_prompt_per_primitive, uint32, 0));
    pc += c.add_instruct(pc, CREATE(fundamental, exit));
    c.save("hello.vm", pc);
    auto ware = software::load("hello.vm");
    
    pc = ware.get_entry_point();
    auto code = ware.get_binary();
    c.add_software(code.data(), code.size());
    c.entry(cpu::register_data {
        (uint32_t)pc, 0, 0,0, 0,0,0,0
    });

    // auto argument = args::parse_argument(argc, argv);
}
#include <args/parsing.h>
#include <system/cpu.h>
#include <isa/fundamental/delegate.h>
#include <load/software.h>

#define PUSH_INSTRUCT(CPU, PC, X) { PC += CPU..add_instruct(PC, X); }
int main(int argc, char** argv) {  
    cpu c;
    c.init();
    auto a = c.get_isa_engine();
    
    int pc = 0;
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, add, uint32, 1,1,1));
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, add, uint32, 1,1,1));
    pc += c.add_instruct(pc, CREATE_BIT(fundamental, store, 32, 1, 1000));
    pc += c.add_instruct(pc, CREATE_TYPE(fundamental, print_to_prompt_per_primitive, uint32, 1000));
    pc += c.add_instruct(pc, CREATE(fundamental, exit));
    
    c.entry(cpu::register_data {
        0, 1200, 0,0, 0,0,0,0
    }); 

    // auto argument = args::parse_argument(argc, argv);
    
    
    return 0;
}

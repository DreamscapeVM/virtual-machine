#include <spdlog/spdlog.h>

#include <args/parsing.h>
#include <system/cpu.h>
#include <load/software.h>


int execute(args::arguments args) { 
    auto ware = software::load(args.path_of_software);
    int pc = ware.get_entry_point();
    auto code = ware.get_binary();
    cpu c;

    if (ware.get_ops_in_software() != cpu_isa::allowable_list_ops) { 
        return ware.get_ops_in_software();
    }

    c.init(args.max_memory_size, ware.get_init_register_state(), args.insturction_per_seconds);
    c.add_software(code.data(), code.size());
    c.entry(cpu::register_data {
        (uint32_t)pc, 0,0,0,0,0,0,0
    });
    return 0;
}

int main(int argc, char** argv) {  
    auto arg = args::parse_argument(argc, argv);
    if (arg.verbose) { 
        spdlog::info("")
    }
    int result = execute(arg);
    if (result != 0) { 
        spdlog::error("between ops in software and ops cpu is different, CPU {}, in software {}", cpu_isa::allowable_list_ops, result);
    }
    return 0;
}

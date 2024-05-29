#include <spdlog/spdlog.h>

#include <args/parsing.h>
#include <system/cpu.h>
#include <load/software.h>

#define CAST(DATA, TYPE) (*(TYPE*)(&DATA))

bool execute(args::arguments args) { 
    auto ware = software::load(args.path_of_software);
    if (args.verbose) { 
        spdlog::info("Software Spec : \n");
        spdlog::info("  Used Ops in File : {}\n", ware.get_ops_in_software());
        spdlog::info("  EntryPoint in Memory based on File : {}\n", ware.get_entry_point());
        spdlog::info("  Static Data Size based on File : {}\n", ware.get_data_size());
        spdlog::info("  Code Size (Only Ops) based on File : {}\n", ware.get_binary_size());
        spdlog::info("  Metadata Size (but, now unused) based on File : {}\n", ware.get_metadata_size());
        auto reg = ware.get_init_register_state();
        spdlog::info("  Register Size based on File : {}\n", reg.size());
        for (const auto& p : reg) { 
            spdlog::info("      Reg1 (int64 : {}), (uint64 : {}) , (double : {})\n", CAST(p, int64_t), CAST(p, uint64_t), CAST(p, double));
        }

        spdlog::info("VirtualMachine Spec : \n");
        spdlog::info("  Compile Time\n");
        spdlog::info("      Allowed Ops List : {}\n", cpu_isa::allowable_list_ops);
    }   

    if (ware.get_ops_in_software() != cpu_isa::allowable_list_ops) { 
        if (args.verbose) { 
            spdlog::error("between ops in software and ops cpu is different, CPU {}, in software {}", cpu_isa::allowable_list_ops, ware.get_ops_in_software());
        }
        return false;
    }

    int pc = ware.get_entry_point();
    auto code = ware.get_binary();
    cpu c;

    if (ware.get_init_register_state().size() < args.max_register_size) { 
        if (args.verbose) { 
            spdlog::error("init register size < setuped cpu is not compacted for running this software (sw : {} < arg : {})", 
                            ware.get_init_register_state().size(), args.max_register_size);
        }
        return false;
    }
    
    // within pc in init register state
    c.init(args.max_memory_size, ware.get_init_register_state(), args.insturction_per_seconds);
    c.add_software(code.data(), code.size());
    c.entry();
    
    return 0;
}

int main(int argc, char** argv) {  
    auto arg = args::parse_argument(argc, argv);
    if (arg.verbose) { 
        spdlog::info("option of verbose is activate");
    }
    if (!execute(arg) && arg.verbose) { 
        spdlog::error("Doesn't Complete with passed program for running.");
    }
    return 0;
}

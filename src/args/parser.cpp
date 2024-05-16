#include <cxxopts.hpp>
#include <iostream>
#include <args/structure.h>

constexpr uint64_t KB = 1024;
constexpr uint64_t MB = 1024 * KB;
constexpr uint64_t GB = 1024 * MB;
constexpr uint64_t TB = 1024 * GB;

const args::arguments parse_argument(int argc, char** argv) { 
    cxxopts::Options options("MyProgram", "One line description of MyProgram");

    options.add_options()
        ("m,max_memory_size", "Int param", cxxopts::value<uint64_t>()->default_value(std::to_string(4 * MB)))
        ("i,insturction_per_seconds", "Int param", cxxopts::value<uint64_t>()->default_value(std::to_string(1 * KB)))
        ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print usage")
        ;

    auto result = options.parse(argc, argv);
    if (result.count("help"))
    {
      std::cout << options.help() << std::endl;
      exit(0);
    }
    auto mem = result["max_memory_size"].as<uint64_t>();
    auto ips = result["insturction_per_seconds"].as<uint64_t>();
    
    

    return args::arguments { 
        max_memory_size: mem,
        insturction_per_seconds: ips
    };

}
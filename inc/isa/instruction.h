#ifndef __INCLUDE_ISA_INSTUCTION_H
#define __INCLUDE_ISA_INSTUCTION_H

#include <cstdint>
#include <vector>
#include <memory>

template<typename T>
struct size_of_instruction { 
    static constexpr uint8_t size = sizeof(T);
};

struct instruction { 
    uint8_t id;
};

class instruction_factory_delegate {
public:
    virtual uint8_t get_total_instuction_size() const = 0;
    virtual std::string get_isa_name() const = 0;
    virtual std::string get_instruction_name(uint8_t id) const = 0;
    virtual instruction generate(const uint8_t id, const uint64_t pc, const uint8_t* const mem) const = 0;
};

class instruction_factory { 
private:
    // std::vector<std::unique_ptr<instruction_factory_delegate>> delegates;

public:
    void init() { 
    }

    const instruction* const get(const uint64_t pc, const uint8_t* const mem) const { 
        uint8_t inst = mem[pc];
        return (const instruction* const)(&mem[pc]);
    }
};




#endif

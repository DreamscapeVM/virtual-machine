#ifndef __INCLUDE_ISA_INSTUCTION_H
#define __INCLUDE_ISA_INSTUCTION_H

#include <cstdint>
#include <vector>
#include <memory>
#include <functional>

#define OPS_NAME(NAME) void ops_##NAME(instruction* inst, uint32_t* reg, uint8_t* mem)
#define ISA_NAME(NAME) struct isa_##NAME : public instruction

template<typename T>
struct size_of_instruction { 
    static constexpr uint8_t size = sizeof(T);
};

struct instruction { 
    uint8_t id;
    // virtual void execute(uint32_t* reg, uint8_t* mem) const = 0;
};

class instruction_delegate {
public:
    using ops_func = std::function<void(instruction*, uint32_t*, uint8_t*)>;

public:
    virtual uint8_t get_total_instuction_size() const = 0;
    virtual uint8_t get_instruction_size(uint8_t id) const = 0;
    virtual ops_func get_ops(uint8_t id) = 0;
    virtual ~instruction_delegate() = default;
    // virtual ~instruction_delegate() = 0;
    // virtual std::string get_isa_name() const = 0;
    // virtual std::string get_instruction_name(uint8_t id) const = 0;
};

class instruction_factory { 
private:
    std::vector<uint8_t> instruct;

public:
    void init(std::vector<std::unique_ptr<instruction_delegate>> delegates) { 
        for (const auto& d : delegates) { 
            int size = d->get_total_instuction_size();
            for (int i = 0; i < size; i++) {
                instruct.push_back(d->get_instruction_size(i));
            }
        }
    }

    const instruction* const get_instruction(const uint64_t pc, const uint8_t* const mem) const { 
        uint8_t inst = mem[pc];
        return (const instruction* const)(&mem[pc]);
    }
    const uint8_t get_instruction_size_in_memory(const uint64_t pc, const uint8_t* const mem) const { 
        return instruct[mem[pc]];
    }
    const uint8_t get_instruction_size_in_instruction(const uint8_t id) const { 
        return instruct[id];
    }
};




#endif

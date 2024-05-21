#ifndef __INCLUDE_ISA_INSTUCTION_H
#define __INCLUDE_ISA_INSTUCTION_H

#include <cstdint>
#include <vector>
#include <memory>
#include <functional>
#include <isa/cpu_isa.h>

#define OPS_NAME(NAME) void ops_##NAME(const instruction* const inst, uint32_t* reg, uint8_t* mem)
#define ISA_NAME(NAME) struct isa_##NAME : public instruction

template<typename T>
struct size_of_instruction { 
    static constexpr uint8_t size = sizeof(T);
};

struct instruction { 
    vm_cpu_isa id;
};

class instruction_delegate {
public:
    using ops_func = std::function<void(const instruction* const , uint32_t*, uint8_t*)>;
    uint8_t start_id;

public:
    instruction_delegate(const uint8_t start_id) : start_id(start_id) {}
    virtual ~instruction_delegate() = default;

    virtual uint8_t get_total_instuction_size() const = 0;
    virtual uint8_t get_instruction_size(uint8_t id) const = 0;
    virtual ops_func get_ops(uint8_t id) = 0;
};

#define CONVRT_TYPE(DATA) std::static_pointer_cast<instruction>(DATA)
#define CREATE(SET, OPS, ...) CONVRT_TYPE(std::make_shared<SET##_isa::isa_##OPS>(SET##_isa::isa_##OPS { vm_cpu_isa::SET##_##OPS, __VA_ARGS__ }))
#define CREATE_TYPE(SET, OPS, TYPE, ...) CONVRT_TYPE(std::make_shared<SET##_isa::isa_##OPS<TYPE##_t>>(SET##_isa::isa_##OPS<TYPE##_t> { vm_cpu_isa::SET##_##OPS##_##TYPE, __VA_ARGS__ }))
#define CREATE_BIT(SET, OPS, BIT, ...) CONVRT_TYPE(std::make_shared<SET##_isa::isa_##OPS<uint##BIT##_t>>(SET##_isa::isa_##OPS<uint##BIT##_t> { vm_cpu_isa::SET##_##OPS##_##BIT, __VA_ARGS__ }))

class instruction_factory { 
private:
    // for high speed converting
    std::vector<std::pair<uint8_t, instruction_delegate::ops_func>> instruct; 
    std::vector<std::unique_ptr<instruction_delegate>> delegate;

public:
    void init(std::vector<std::unique_ptr<instruction_delegate>> delegates);
    const instruction* const get_instruction(const uint64_t pc, const uint8_t* const mem) const;
    const uint8_t get_instruction_size_in_instruction(const vm_cpu_isa id) const;
    const instruction_delegate::ops_func get_ops(const vm_cpu_isa id) const;
};




#endif

#ifndef __INCLUDE_ISA_FUNDAMENTAL_DELEGATE_H
#define __INCLUDE_ISA_FUNDAMENTAL_DELEGATE_H

#include <isa/instruction.h>
#include <isa/fundamental/set.h>

#if defined(GGEN) || defined(TGEN) || defined(BGEN)
#undef GGEN
#undef TGEN
#undef BGEN
#endif
#define GGEN(ISA, NAME) ISA##_##NAME
#define TGEN(ISA, NAME, TYPE) ISA##_##NAME##_##TYPE
#define BGEN(ISA, NAME, BIT) ISA##_##NAME##_##BIT

// #define NGGEN(ISA, NAME) ISA##_##NAME
// #define NTGEN(ISA, NAME, TYPE) ISA##_##NAME##_##TYPE
// #define NBGEN(ISA, NAME, BIT) ISA##_##NAME##_##BIT

// #define GGEN(ISA, NAME) case vm_cpu_isa::NGGEN(ISA, NAME):                  \
//                             { *output = ISA##_isa::isa_##NAME { vm_cpu_isa::ISA##_##NAME }; return true; }   \
//                             break;

// #define TGEN(ISA, NAME, TYPE) case vm_cpu_isa::NTGEN(ISA, NAME, TYPE):              \
//                             { *output = ISA##_isa::isa_##NAME<TYPE##_t> { vm_cpu_isa::ISA##_##NAME##_##TYPE }; return true; } \
//                             break;

// #define BGEN(ISA, NAME, BIT) case vm_cpu_isa::NBGEN(ISA, NAME, BIT):                    \
//                             { *output =  ISA##_isa::isa_##NAME<uint##BIT##_t> { vm_cpu_isa::ISA##_##NAME##_##BIT }; return true; } \
//                             break;                            


namespace fundamental_isa { 

class fundamental_instruction_delegate : public instruction_delegate {
    std::vector<std::pair<uint8_t, instruction_delegate::ops_func>> data;

public:
    fundamental_instruction_delegate(const uint8_t start_id);
    virtual uint8_t get_total_instuction_size() const override;
    virtual uint8_t get_instruction_size(uint8_t id) const override;
    virtual instruction_delegate::ops_func get_ops(uint8_t id) override;
};

}

#endif

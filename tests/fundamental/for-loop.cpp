#include <gtest/gtest.h>
#include <args/parsing.h>
#include <system/cpu.h>
#include <isa/fundamental/delegate.h>
#include <load/software.h>

#define add_instruct(PC, INST, CPU) {PC += CPU.add_instruct(PC, &INST);}

TEST(ASSEMBLY, ForLoopTest) { 
  cpu c;
  c.init();

  int pc = 0;
  fundamental_isa::isa_add<int> p;
  p.id = vm_cpu_isa::fundamental_add_int32;
  p.lvalue = 1;
  p.rvalue = 2;
  p.output = 1;

  fundamental_isa::isa_exit e;
  e.id = vm_cpu_isa::fundamental_exit;

  fundamental_isa::isa_equal_condition<uint32_t> eq;
  eq.id = vm_cpu_isa::fundamental_equal_condition_32;
  eq.lreg = 1;
  eq.rreg = 3;
  eq.false_pc = 0;

  auto loop = pc;
  add_instruct(pc, p, c);
  eq.false_pc = loop;
  add_instruct(pc, eq, c);
  eq.true_pc = pc;
  add_instruct(pc, e, c);
  
  // execute code by exit.
  c.entry(cpu::register_data { 
    0, 0, 1, 15
  });

  EXPECT_EQ(c.reg[3], 15);
}
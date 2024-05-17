#include <spdlog/spdlog.h>
#include <system/system.h>
#include <system/cpu.h>
#include <isa/fundamental/set.h>
#include <isa/fundamental/delegate.h>
#include <isa/cpu_isa.h>

#define add_instruct(PC, INST, CPU) {PC += CPU.add_instruct(PC, &INST);}

int main() {  
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
  eq.true_pc = 22;

  add_instruct(pc, p, c);
  add_instruct(pc, eq, c);
  add_instruct(pc, e, c);

  // execute code by exit.
  c.entry(0);

  return 0;
}

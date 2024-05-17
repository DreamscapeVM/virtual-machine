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
  // eq.true_pc = 22;

  fundamental_isa::isa_scan_from_prompt_per_primitive<int32_t> input;
  input.id = vm_cpu_isa::fundamental_scan_from_prompt_per_primitive_int32;
  input.memory_address = 1000;

  fundamental_isa::isa_print_to_prompt_per_primitive<int32_t> output;
  output.id = vm_cpu_isa::fundamental_print_to_prompt_per_primitive_int32;
  output.memory_address = 1000;

  fundamental_isa::isa_load<int32_t> ll;
  ll.id = vm_cpu_isa::fundamental_load_32;
  ll.target = 1000;
  ll.reg = 1;

  fundamental_isa::isa_load<int32_t> str;
  str.id = vm_cpu_isa::fundamental_store_32;
  str.target = 1000;
  str.reg = 1;

  add_instruct(pc, input, c);
  auto loop = pc;
  add_instruct(pc, output, c);
  add_instruct(pc, ll, c);
  add_instruct(pc, p, c);
  add_instruct(pc, str, c);
  eq.false_pc = loop;
  add_instruct(pc, eq, c);
  eq.true_pc = pc;
  add_instruct(pc, e, c);

  // execute code by exit.
  c.entry(0);

  return 0;
}

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
  p.rvalue = 1;
  p.output = 1;

  fundamental_isa::isa_exit e;
  e.id = vm_cpu_isa::fundamental_exit;

  fundamental_isa::isa_store<uint32_t> s;
  s.id = vm_cpu_isa::fundamental_store_32;
  s.reg = 1;
  s.target = 0;

  fundamental_isa::isa_load<uint32_t> l;
  l.id = vm_cpu_isa::fundamental_load_32;
  l.reg = 2;
  l.target = 0;

  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, s, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, l, c);
  s.target = 4;
  add_instruct(pc, s, c);
  p.lvalue = 1;
  p.rvalue = 2;
  p.output = 3;
  add_instruct(pc, p, c);
  add_instruct(pc, e, c);

  // execute code by exit.
  c.entry(0);

  return 0;
}

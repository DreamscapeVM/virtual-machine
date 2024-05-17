#include <spdlog/spdlog.h>
#include <system/system.h>
#include <system/cpu.h>
#include <isa/fundamental/set.h>
#include <isa/fundamental/delegate.h>

#define add_instruct(PC, INST, CPU) {PC += CPU.add_instruct(PC, &INST);}

int main() {  
  cpu c;
  c.init();

  int pc = 0;
  fundamental_isa::isa_add<int> p;
  p.id = 1;
  p.lvalue = 1;
  p.rvalue = 1;
  p.output = 1;

  fundamental_isa::isa_exit e;
  e.id = 0;
  
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, p, c);
  add_instruct(pc, e, c);

  // execute code by exit.
  c.entry(0);
  

  return 0;
}

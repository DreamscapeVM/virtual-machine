#include <spdlog/spdlog.h>
#include <system/system.h>
#include <system/cpu.h>
#include <isa/fundamental/set.h>
#include <isa/fundamental/delegate.h>

int main() {  
  cpu c;
  c.init();

  fundamental_isa::isa_add<int> p;
  p.id = 1;
  p.lvalue = 1;
  p.rvalue = 1;
  p.output = 1;

  fundamental_isa::isa_exit e;
  e.id = 0;
  
  std::vector<instruction*> code;
  code.push_back(&p);
  code.push_back(&p);
  code.push_back(&e);

  c.add_software(0, code);

  // execute code by exit.
  c.entry(0);
  

  return 0;
}

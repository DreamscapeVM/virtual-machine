#include <spdlog/spdlog.h>
#include <system/system.h>
#include <system/cpu.h>
#include <isa/fundamental/set.h>
#include <isa/fundamental/delegate.h>

int main() {  
  cpu c;
  memory d;
  c.reg[1] = 30;
  c.reg[2] = 40;

  d.init(1024*1024);
  instruction_factory instf;
  auto dd = std::vector<std::unique_ptr<instruction_delegate>>();
  dd.push_back(std::make_unique<fundamental_isa::fundamental_instruction_delegate>());
  instf.init(std::move(dd));

  fundamental_isa::add<int> p;
  p.id = 1;
  p.lvalue = 1;
  p.rvalue = 1;
  p.output = 1;

  fundamental_isa::exit e;
  e.id = 0;

  // from program code like assembly to memory
  auto mem = d.get_memory();
  int pc = 0;
  for (int x = 0; x < 10; x++) { 
    auto size = instf.get_instruction_size_in_instruction(p.id);
    for (int i = 0; i < size; i++) { 
      mem[pc + i] = ((uint8_t*)&p)[i];
    }
    pc += size;
  }

  auto size = instf.get_instruction_size_in_instruction(e.id);
  for (int i = 0; i < size; i++) { 
    mem[pc + i] = ((uint8_t*)&e)[i];
  }

  // execute code by exit.
  pc = 0;
  for (int i = 0; i < 10; i++) { 
    auto inst = instf.get_instruction(pc, d.get_memory());
    pc += instf.get_instruction_size_in_memory(pc, d.get_memory());
    c.execute(inst);
    spdlog::info("pc : {}, reg : [{}, {}, {}, {}, {}, {}, {}, {}]", 
                      pc,
                      c.reg[0],
                      c.reg[1],
                      c.reg[2],
                      c.reg[3],
                      c.reg[4],
                      c.reg[5],
                      c.reg[6], 
                      c.reg[7]);

  }
  
  

  return 0;
}

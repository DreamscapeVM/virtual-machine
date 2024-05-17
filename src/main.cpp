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
  dd.push_back(std::make_unique<fundamental_instruction_delegate>());
  instf.init(std::move(dd));

  add<int> p;
  p.id = 0;
  p.lvalue = 1;
  p.rvalue = 2;
  p.output = 2;

  // from program code like assembly to memory
  auto mem = d.get_memory();
  for (int x = 0; x < 10; x++) { 
    int size = size_of_instruction<add<int>>::size;
    for (int i = 0; i < size; i++) { 
      mem[i + (size * x)] = ((uint8_t*)&p)[i];
    }
  }

  // execute 10 cycles
  int pc = 0;
  for (int i = 0; i < 10; i++) { 
    auto inst = instf.get_instruction(pc, d.get_memory());
    pc += instf.get_instruction_size(pc, d.get_memory());
    c.execute(inst);
  }
  
  spdlog::info("reg : [{}, {}, {}, {}, {}, {}, {}, {}]", 
                      c.reg[0],
                      c.reg[1],
                      c.reg[2],
                      c.reg[3],
                      c.reg[4],
                      c.reg[5],
                      c.reg[6], 
                      c.reg[7]);

  return 0;
}

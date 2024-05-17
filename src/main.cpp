#include <spdlog/spdlog.h>
#include <system/system.h>
#include <system/cpu.h>
#include <isa/fundamental/set.h>

int main() {  
  spdlog::info("Hello world!");
  cpu c;
  memory d;
  c.reg[1] = 30;
  c.reg[2] = 40;

  d.init(1024*1024);
  instruction_factory instf;
  add<int> p;
  p.id = 0;
  p.lvalue = 1;
  p.rvalue = 2;
  p.output = 3;

  auto mem = d.get_memory();
  for (int i = 0; i < size_of_instruction<add<int>>::size; i++) { 
     mem[i] = ((uint8_t*)&p)[i];
  }
  
  auto inst = instf.get(0, d.get_memory());
  c.execute(inst);

  spdlog::info("value : {}", c.reg[0]);
  spdlog::info("value : {}", c.reg[1]);
  spdlog::info("value : {}", c.reg[2]);
  spdlog::info("value : {}", c.reg[3]);
  spdlog::info("value : {}", c.reg[4]);
  spdlog::info("value : {}", c.reg[5]);
  // d.write<int>((uint64_t)0, 10234);
  // int a = *(int*)d.read(0);

  // spdlog::info("value {}", size_of_instruction<Add<int>>::size);

  return 0;
}

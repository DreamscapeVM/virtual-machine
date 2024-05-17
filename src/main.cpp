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
  add<int> i;
  i.id = 0;
  i.lvalue = 1;
  i.rvalue = 2;
  i.output = 3;

  c.execute(&i);
  
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

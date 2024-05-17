#include <spdlog/spdlog.h>
#include <system/system.h>
#include <isa/fundamental/set.h>
#
int main() {  
  spdlog::info("Hello world!");
  Add<int> a;
  spdlog::info("value {}, {}, {}", a.id, *(int*)(&a), sizeof(Add<int>));
  a.execute();

  // memory d;
  // d.init(1024*1024);
  // // int v = 1923;
  // d.write<int>((uint64_t)0, 10234);
  // int a = *(int*)d.read(0);

  // spdlog::info("value {}", size_of_instruction<Add<int>>::size);

  return 0;
}

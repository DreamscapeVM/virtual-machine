# VirutalComputer
it is validate for a code to algorithm.

[![All Unit Test](https://github.com/virtual-machine-created-by-myself/virtual-machine/actions/workflows/build_test.yaml/badge.svg?branch=main)](https://github.com/virtual-machine-created-by-myself/virtual-machine/actions/workflows/build_test.yaml)

## Assembly Instruction in this VM

ISA|Ops Id|Ops Name|Parameters|Ops Size
:---:|:---:|:---:|:---:|:---:|
fundamental|0|exit|X|1
fundamental|1|add|uint32, uint32|3
fundamental|2|add|int32, int32|3
fundamental|3|load_1byte|reg_id, mem_address|10
fundamental|4|load_1byte|reg_id, mem_address|10
fundamental|5|load_2byte|reg_id, mem_address|10
fundamental|6|load_4byte|reg_id, mem_address|10
fundamental|7|load_8byte|reg_id, mem_address|10
fundamental|8|store_1byte|reg_id, mem_address|10
fundamental|9|store_2byte|reg_id, mem_address|10
fundamental|10|store_4byte|reg_id, mem_address|10
fundamental|11|store_8byte|reg_id, mem_address|10
fundamental|12|equal_condition_1byte|reg1, reg2, true_pc, false_pc|19
fundamental|13|equal_condition_2byte|reg1, reg2, true_pc, false_pc|19
fundamental|14|equal_condition_4byte|reg1, reg2, true_pc, false_pc|19
fundamental|15|equal_condition_4byte|reg1, reg2, true_pc, false_pc|19

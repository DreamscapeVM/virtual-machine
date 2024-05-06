#ifndef __INCLUDE_COMPUTER_CHACHA
#define __INCLUDE_COMPUTER_CHACHA
#include <string>
#include "memory.hpp"

class ops { 
protected:
    ops* next_ops = nullptr;
    uint64_t line = 0;
public:
    virtual void execute() = 0;
    virtual const ops* get_next() = 0;
    virtual const uint64_t get_line() = 0;
    
};

// enum class operator_t {
//     LOAD,
//     STORE,
//     PUSH // IN 4 1 2 3 4
//     POP,
//     ADD, // ADD YPE
//     JMP, // JMP A B [0,1] [Line]
//     OUT // OUT [0i,1c,2s]
// };

class load : public ops { 
    memory* mem;
    com_register_t* reg;
    uint64_t index;
    uint64_t size;
public:
    void prepare(memory* mem, uint64_t index, uint64_t size, com_register_t* reg, ops* next = nullptr) {
        this->next_ops = next;
        this->mem = mem;
        this->reg = reg;
        this->index = index;
        this->size = size;
    }

    void execute() { 
        com_data_t data;
        auto r = this->mem->read(index, size);
        for (int i = 0; i < size; i++) { 
            data.push_back(((uint8_t*)(r))[i]);
        }

        this->reg->push(data);
    }
};
class store : public ops { 
    memory* mem;
    com_register_t* reg;
    uint64_t index;
public:
    void prepare(memory* mem, uint64_t index, com_register_t* reg, ops* next = nullptr) {
        this->next_ops = next;
        this->mem = mem;
        this->reg = reg;
        this->index = index;
    }

    void execute() { 
        com_data_t data = reg->top();
        this->mem->write(index, data.data(), data.size());
    }
};
class push : public ops { 
    com_register_t* reg;
    com_data_t data;
public:
    void prepare(com_register_t* reg, com_data_t data, ops* next = nullptr) {
        this->next_ops = next;
        this->reg = reg;
        this->data = data;
    }

    void execute() { 
        this->reg->push(data);    
    }
};
class pop : public ops { 
    com_register_t* reg;
public:
    void prepare(com_register_t* reg, ops* next = nullptr) {
        this->next_ops = next;
        this->reg = reg;
    }

    void execute() { 
        reg->pop();
    }
};
class add : public ops { 
    com_register_t* reg;
    data_type_t type;
public:
    void prepare(com_register_t* reg, data_type_t type, ops* next = nullptr) {
        this->next_ops = next;
        this->reg = reg;
        this->type = type;
    }

    void execute() { 
        auto rvalue = reg->top();
        reg->pop();
        auto lvalue = reg->top();
        reg->pop();

        uint8_t* result = nullptr;
        uint64_t length = 0;
        switch (this->type){
            case data_type_t::fix_float:
            float_t data = *((float_t*)rvalue.data()) + *((float_t*)lvalue.data());
            result = (uint8_t*)&data;
            length = 4;
            break;
            case data_type_t::interger:
            int32_t data = *((int32_t*)rvalue.data()) + *((int32_t*)lvalue.data());
            result = (uint8_t*)&data;
            length = 4;
            break;
        }
        
        com_data_t data;
        for (int i = 0 ; i < length; i++) { 
            data.push_back(result[i]);
        }
        reg->push(data);
    }
};

class jmp : public ops { 
    com_register_t* reg;
public:
    void prepare(com_register_t* reg, ops* next = nullptr) {
        this->reg = reg;
        this->next_ops = next;
    }

    void execute() { 
        
    }
};


#endif

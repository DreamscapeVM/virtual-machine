#ifndef __INCLUDE_ISA_LOAD_H
#define __INCLUDE_ISA_LOAD_H
#include <string>
#include <fstream>
#include <cassert>
#include <vector>
#include <stdint.h>

class software { 
private:
    uint64_t full_size;

    uint64_t metadata_section;
    uint64_t data_section;
    uint64_t use_ops;
    uint64_t register_size;
    std::vector<uint64_t> init_register_state;
    std::vector<uint8_t> binary;

    static int read(std::ifstream& file, char* buf, int read_size = 8) { 
        file.read(buf, read_size);
        int size = file.gcount();
        return size;
    }

public:
    std::vector<uint8_t> get_binary() const;
    std::vector<uint64_t> get_init_register_state() const;
    const uint64_t get_binary_size() const;
    const uint64_t get_entry_point() const;
    const uint64_t get_data_size() const;
    const uint64_t get_metadata_size() const;
    const uint64_t get_ops_in_software() const;

    static software load(std::string file_name) { 
        software result;

        std::ifstream data(file_name, std::ios::in | std::ios::binary | std::ios::ate);

        data.seekg(0, std::ios::end); // 파일 끝으로 이동
        // auto full_size = ; // 현재 위치 (파일 끝) 를 가져옴
        result.full_size = data.tellg();
        data.seekg(0, std::ios::beg); // 파일 끝으로 이동

        char buf[1025];
        read(data, buf, 8);
        result.metadata_section = *(uint64_t*)buf;
        read(data, buf, 8);
        result.data_section = *(uint64_t*)buf;
        read(data, buf, 8);
        result.use_ops = *(uint64_t*)buf;
        read(data, buf, 8);
        result.register_size = *(uint64_t*)buf;
        for (int i = 0; i < result.register_size; i++) { 
            read(data, buf, 8);
            uint64_t tmp = *(uint64_t*)buf;
            result.init_register_state.push_back(tmp);
        }
        
        uint64_t bin_size = result.full_size - (sizeof(uint64_t) * 3);
        result.binary.resize(static_cast<size_t>(bin_size));
        data.read(reinterpret_cast<char*> (result.binary.data()), bin_size);

        return result;
    }
};

#endif

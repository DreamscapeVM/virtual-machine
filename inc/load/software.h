#ifndef __INCLUDE_ISA_LOAD_H
#define __INCLUDE_ISA_LOAD_H
#include <string>
#include <fstream>
#include <cassert>

class software { 
private:
    uint64_t full_size;
    uint64_t metadata_section;
    uint64_t data_section;
    uint64_t code_section;
    uint64_t use_ops;
    std::vector<uint8_t> binary;

    static int read(std::fstream& file, char* buf, int read_size = 8) { 
        file.read(buf, read_size);
        int size = file.gcount();
        return size;
    }

public:
    static software load(std::string file_name) { 
        software result;

        std::ifstream data(file_name, std::ios::in | std::ios::binary);

        data.seekg(0, std::ios::end); // 파일 끝으로 이동
        result.full_size = data.tellg(); // 현재 위치 (파일 끝) 를 가져옴
        data.seekg(0, std::ios::beg); // 파일 끝으로 이동

        char buf[1025];
        result.metadata_section = *(uint64_t*)buf;
        result.data_section = *(uint64_t*)buf;
        result.code_section = *(uint64_t*)buf;
        result.use_ops = *(uint64_t*)buf;
        
        uint64_t bin_size = result.full_size - (sizeof(uint64_t) * 4);
        result.binary.resize(static_cast<size_t>(bin_size));
        while (data.eof()) { 
            data.read(reinterpret_cast<char*> (result.binary.data()), bin_size);
        }

        return result;
    }
};

#endif

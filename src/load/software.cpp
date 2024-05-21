#include <load/software.h>

std::vector<uint8_t> software::get_binary() const { 
    return binary;
}

const uint64_t software::get_binary_size() const { 
    return binary.size();
}
const uint64_t software::get_entry_point() const { 
    return sizeof(uint64_t) + metadata_section + 
            sizeof(uint64_t) + data_section + 
             sizeof(uint64_t) + (sizeof(uint64_t) * this->init_register_state.size());
}

const uint64_t software::get_data_size() const { 
    return data_section;
}
const uint64_t software::get_metadata_size() const { 
    return metadata_section;
}

const uint64_t software::get_ops_in_software() const { 
    return this->use_ops;
}

std::vector<uint64_t> software::get_init_register_state() const { 
    return this->init_register_state;
}
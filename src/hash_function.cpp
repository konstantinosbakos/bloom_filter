#include <iostream>

#include "bloom_filter.hpp"

unsigned long hash_i(std::string str, unsigned int i){ //Sample hash function.
    std::hash<std::string> hash_str;

    return hash_str(str) * i;
}
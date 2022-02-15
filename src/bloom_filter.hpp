#ifndef __BLOOM_FILTER__
#define __BLOOM_FILTER__

#include <cstdint>

#define K_HASH 10

class bloom_filter{
    private:
        long     bloom_size;
        uint8_t *bloom_bit_array;

        bool look_Array(unsigned long position);

        void update_Array(unsigned long position);
    public:
        bloom_filter(long size);
        ~bloom_filter();

        bool bloom_filter_search(std::string str);
        void bloom_filter_insert(std::string str);
};

unsigned long hash_i(std::string str, unsigned int i); //Hash function.

#endif
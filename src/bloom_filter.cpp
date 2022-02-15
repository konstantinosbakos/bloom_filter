#include <cmath>
#include <string>

#include "bloom_filter.hpp"

bloom_filter::bloom_filter(long size){
    this->bloom_size       = size;
    this->bloom_bit_array  = new uint8_t[this->bloom_size];

    for(int i=0;i<size;i++){
        this->bloom_bit_array[i] = 0;
    }
}

bloom_filter::~bloom_filter(){
    delete [] this->bloom_bit_array;
    this->bloom_bit_array = NULL;
}

//------Private------

bool bloom_filter::look_Array(unsigned long position){          //Used by bloom filter to locate the position of
    long byte_pos = long((position/8));                         //the bit that is being searched.
    long bit_pos  = long(position)-byte_pos*8;

    return ((((this->bloom_bit_array)[byte_pos] & (1u << bit_pos)))?  1  :  0  );
}

void bloom_filter::update_Array(unsigned long position){        //Update the bloom filter array by locating the bit and turning it to 1.
    long byte_pos = long((position/8));
    long bit_pos  = long(position)-byte_pos*8;

    (this->bloom_bit_array)[byte_pos] |= (1u << bit_pos);
}

//------Public-------

bool bloom_filter::bloom_filter_search(std::string str){
    for(int i=0; i<K_HASH; i++){
		unsigned long hash = hash_i(str,i)%(this->bloom_size*8); //Trim hash to fit the bloom size.

        if(!look_Array(hash)){
            return false;
        }
    }

    return true;
}

void bloom_filter::bloom_filter_insert(std::string str){
    for(int i=0; i<K_HASH; i++){
        unsigned long hash = hash_i(str,i)%((this->bloom_size)*8);

        update_Array(hash);
     }
}

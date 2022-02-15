#include <iostream>

#include "../src/bloom_filter.hpp"

int main(){
    int           flag = 1;
    bloom_filter *BF   = new bloom_filter(100);

    while(flag){
        int         choice = -1;
        std::string str    = "";

        std::cout << std::endl;
        std::cout << "Actions: " << std::endl;
        std::cout << "1: Insert" << std::endl;
        std::cout << "2: Search" << std::endl;
        std::cout << "3: Exit " << std::endl;
        std::cout << ">> ";

        std::cin >> choice;
        std::cout << std::endl;

        switch(choice){
            case 1:
                std::cin >> str;
                BF->bloom_filter_insert(str);
                break;
            case 2:
                std::cin >> str;

                std::cout << std::endl;

                if(BF->bloom_filter_search(str)){
                    std::cout << ">> True" << std::endl;
                }
                else{
                    std::cout << ">> False" << std::endl;
                }
                break;
            case 3:
                flag = 0;
                break;
            default:
                std::cout << "Wrong Input." << std::endl;
                break;
        }
    }

    delete BF;
    BF = NULL;

    return EXIT_SUCCESS;
}
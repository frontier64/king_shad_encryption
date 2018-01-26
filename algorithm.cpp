#include <stdlib.h>


uint32_t encrypt_block(uint32_t input, uint32_t key){
    return input ^ key;
}


uint32_t decrypt_block(uint32_t input, uint32_t key){
    return input ^ key;
}
/**
 * Title: algorithm.cpp
 * Author: Kixo
 * About: encryption and decryption algorithm for king_encrypt/decrypt
 * For: CSE 539. First Assignment
 * Date: 1/25/2017
 **/

#include <stdlib.h>


uint32_t encrypt_block(uint32_t input, uint32_t key){
    return input ^ key;
}


uint32_t decrypt_block(uint32_t input, uint32_t key){
    return input ^ key;
}
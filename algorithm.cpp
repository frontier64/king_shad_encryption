/**
 * Title: algorithm.cpp
 * Author: Kixo
 * About: encryption and decryption algorithm for king_encrypt/decrypt
 * For: CSE 539. First Assignment
 * Date: 1/25/2017
 **/

/**
 Idea:
  have 32 different transformations. I.e. invert all bits. left circ shift by 4. 
  add 4 then mod 2. permute all instances of 0110 to 1010.
  The key determines if these odd transformations should be done or not.
  if its 1001. you do the inversion then dont do the left circ then not add 4 mod 2 then permute all instances of 0110. 
  obviously if the key is 0000 then you fail. maybe 0 represents one transformation and 1 represents a different transformation. I like it
**/


#include <stdlib.h>

uint32_t encryption_round(uint32_t input, uint32_t key){
    uint32_t reversed_key = 0;
    uint32_t temp_key = key;
    int i;
    for (i = 0; i < 32; i++){
        reversed_key = reversed_key << 1;
        reversed_key += temp_key % 2;
        temp_key = temp_key >> 1;
    }
    uint32_t f_key = key ^ reversed_key;
//Reverse and xor key done.


    uint32_t rounded = f_key ^ input;
    


}

uint32_t encrypt_block(uint32_t input, uint32_t key){
    return input ^ key;
}


uint32_t decrypt_block(uint32_t input, uint32_t key){
    return input ^ key;
}


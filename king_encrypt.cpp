/**
 * Title: king_encrypt.cc
 * Author: Kixo
 * About: encrypt a file using a block cipher and a 32 bit key. 
 Given the plaintext and ciphertext the key itself should not be easily revealed.
  * For: CSE 539. First assignment
  * Date: January 22, 2017
  **/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <stdint.h>

using namespace std;

uint32_t encrypt_block(uint32_t input, uint32_t key);
uint32_t decrypt_block(uint32_t input, uint32_t key);

int main(int argc, char **argv){

    if (argc != 4){
        cout << "Incorrect # of arguments.";
        exit(1);
    }

    fstream plaintext;
    fstream ciphertext;


    plaintext.open(argv[2], fstream::in | fstream::binary);

    if (plaintext.is_open() == false){
        cout << "Input file does not exist.";
        exit(1);
    }

    ciphertext.open(argv[3], fstream::out | fstream::binary);

    uint32_t first_bits;

    int i;
    while ((i = plaintext.read((char *)&first_bits, sizeof(first_bits))) > 0){
        cout << i << ": ";
        cout << (char *) &first_bits << endl;
        ciphertext.write((char *)&first_bits, sizeof(first_bits));
        first_bits = 0;
    }
    cout << i << endl;
    ciphertext.write((char *)&first_bits, sizeof(first_bits));
    plaintext.close();
    ciphertext.close();
}



uint32_t encrypt_block(uint32_t input, uint32_t key){
    return input ^ key;
}

/*
uint32_t decrypt_block(uint32_t input, uint32_t key){
    return input ^ key;
}
*/

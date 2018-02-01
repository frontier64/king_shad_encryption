/**
 * Title: king_encrypt.cc
 * Author: Kixo
 * About: decrypt a file using a block cipher and a 32 bit key. 
 Given the plaintext and ciphertext the key itself should not be easily revealed.
 * For: CSE 539. First assignment
 * Date: January 25, 2017
 **/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <stdint.h>
#include "algorithm.cpp"

using namespace std;


uint32_t KEY;

int main(int argc, char **argv){

    if (argc != 4){
        cout << "Incorrect # of arguments.";
        exit(1);
    }

    fstream plaintext;
    fstream ciphertext;

    KEY = (uint32_t) *argv[1];

    ciphertext.open(argv[2], fstream::in | fstream::binary);

    if (ciphertext.is_open() == false){
        cout << "Input file does not exist.";
        exit(1);
    }
    cout << "Running on " << argv[2] << endl;

    plaintext.open(argv[3], fstream::out | fstream::binary);

    uint32_t first_bits;
    uint32_t cipher_bits;

    int i;
    while ((i = ciphertext.read((char *)&first_bits, sizeof(first_bits)))){

        //Output of the 4 characters treated. 

        cipher_bits = decrypt_block(first_bits, KEY);

        plaintext.write((char *)&cipher_bits, sizeof(cipher_bits));
        first_bits = 0;
        if (i == 0){
            break;
        }
    }

    ciphertext.close();
    plaintext.close();
    cout << "Wrote into " << argv[3] << endl;

}


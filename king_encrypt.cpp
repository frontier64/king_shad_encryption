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
#include <iomanip>
#include "algorithm.cpp"

using namespace std;

uint32_t KEY;



int test(int argc, char ** argv){
    uint32_t test = stol(argv[1], 0, 16);
    cout << encrypt_block(test, test) << endl;
    cout << "Encrypetd block: " << hex << encrypt_block(test, test) << endl;
    cout << "decrypted block: " << hex << decrypt_block(encrypt_block(test, test), test) << endl;
    return 0;
}

int main(int argc, char **argv){
    if (argc != 4){
        cout << "Incorrect # of arguments.";
        exit(1);
    }

    fstream plaintext;
    fstream ciphertext;

    KEY = (uint32_t) *argv[1];

    plaintext.open(argv[2], fstream::in | fstream::binary);

    if (plaintext.is_open() == false){
        cout << "Input file does not exist.";
        exit(1);
    }
    cout << "Running on " << argv[2] << endl;
    ciphertext.open(argv[3], fstream::out | fstream::binary);

    uint32_t first_bits;
    uint32_t cipher_bits;

    int i;
    while ((i = plaintext.read((char *)&first_bits, sizeof(first_bits)))){


        cipher_bits = encrypt_block(first_bits, KEY);

        ciphertext.write((char *)&cipher_bits, sizeof(cipher_bits));
        first_bits = 0;
        if (i == 0){
            break;
        }
    }
    cipher_bits = encrypt_block(first_bits, KEY);
    ciphertext.write((char *)&cipher_bits, sizeof(cipher_bits));

    plaintext.close();
    ciphertext.close();

    cout << "Wrote into " << argv[3] << endl;
}


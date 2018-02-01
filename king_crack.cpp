/**
 * Title: king_crack.cpp
 * Author: Kixo
 * About: Crack a file
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
#include <iomanip>

using namespace std;


uint32_t KEY;
bool test(int argc, char **argv);
int main(int argc, char** argv){
    KEY = 0;
    for (KEY = 0; KEY < 0xFFFFFFFF; KEY++){
        if (test(argc, argv)){
            cout << "Found key: " << hex << KEY << endl;
            break;
        } else {
            cout << "Disregarded key: " << hex << KEY << endl;
        }
    }
}
bool test(int argc, char** argv){
    if (argc != 3){
        cout << "Incorrect # of arguments.";
        exit(1);
    }

    fstream testtext;
    fstream ciphertext;

    ciphertext.open(argv[1], fstream::in | fstream::binary);
    testtext.open(argv[2], fstream::in | fstream::binary);
    if (ciphertext.is_open() == false || testtext.is_open() == false){
        cout << "Input file does not exist.";
        exit(1);
    }

    uint32_t first_bits;
    uint32_t cipher_bits;
    uint32_t test_bits;
    int i;
    int k = 0;
    bool go = true;
    while ((i = ciphertext.read((char *)&first_bits, sizeof(first_bits))) > 0 && testtext.read((char *)&test_bits, sizeof(test_bits)) > 0){

        cipher_bits = decrypt_block(first_bits, KEY);
        if (test_bits != cipher_bits){
            go = false;
            first_bits = 0;
            break;
        } 
        cout << "test bits:   " << test_bits << endl;
        cout << "cipher bits: " << cipher_bits << endl;
        first_bits = 0;

    }

    ciphertext.close();
    testtext.close();
    return go;


}


encrypt: king_encrypt.cpp algorithm.cpp
	c++ king_encrypt.cpp -o encrypt

decrypt: king_decrypt.cpp
	c++ king_decrypt.cpp -o decrypt
crack: king_crack.cpp
	c++ king_crack.cpp -o crack
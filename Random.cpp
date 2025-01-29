#include <iostream>
#include "Header.h"
#include <random>

/*
PLIK RANDOM.CPP
FUNKCJE DOTYCZĄCE GENEROWANIA LICZB LOSOWYCH
*/

using namespace std;

int losowaSeed(unsigned int seed, unsigned int przedzial1, unsigned int przedzial2) {
	mt19937 generator(seed);
	uniform_int_distribution<int> distribution(przedzial1, przedzial2);
	return distribution(generator);
}
unsigned int losowyUInt() {
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<unsigned int> distribution(0, 4294967295);
	return distribution(generator);
}
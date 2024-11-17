#include <iostream>
#include "Header.h"
#include <random>

using namespace std;

int losowaSeed(unsigned int seed) {
	mt19937 generator(seed);
	uniform_int_distribution<int> distribution(0, 90);
	return distribution(generator);
}
unsigned int losowyUInt() {
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<unsigned int> distribution(0, 4294967295);
	return distribution(generator);
}
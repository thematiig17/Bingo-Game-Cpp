#include <iostream>
#include "Header.h"
#include <cstdlib>
using namespace std;

void testLosowanie(unsigned int seed) {
	cout << "Start testu!" << endl;
	for (size_t i = 1; i <= 20; i++)
	{
		cout << "Losowanie " << i << ": " << losowaSeed(seed + i * 10) << endl;
	}
	system("pause");
	menuGlowne();
}
#include <iostream>
#include "Header.h"
#include <cstdlib>
using namespace std;

void testLosowanie(unsigned int seed) {
	cout << "Start testu!" << endl;
	
	system("pause");
	menuGlowne();
}

void ekranGry(int wygenerowanySeed) {
	wyczyscEkranANSI();
	for (size_t i = 0; i <= 8; i++)
	{
		for (size_t j = 1; j <= 10; j++)
		{
			cout << ((i*10)+j)<<".\t";
		}
		cout << "\n";
	}
	for (size_t i = 1; i <= 20; i++)
	{
		int losowaLiczba = losowaSeed(wygenerowanySeed + i * 10);
		ustawPozycjeKursora(80, 2);
		napiszDuzaLiczbe(losowaLiczba);
		cout << endl;
		cout << "Losowanie " << i << ": " << losowaLiczba << endl;
		system("pause");
	}

	system("pause");
	menuGlowne();
}


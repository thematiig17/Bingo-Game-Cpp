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
	int i = 0;
	int wylosowaneLiczby[90]{}; //tablica na wylosowane liczby
	while (i < 20) {
		wyczyscEkranANSI();
		int losowaLiczba = losowaSeed(wygenerowanySeed + i * 10);
		wylosowaneLiczby[losowaLiczba] = 1;
		for (size_t i = 0; i <= 8; i++)
		{
			for (size_t j = 1; j <= 10; j++)
			{
				if (wylosowaneLiczby[(i * 10) + j] == 1) {
					cout << "\033[32m" << ((i * 10) + j) << ".\t";
					cout << "\033[0m";
				}
				else {
					cout << ((i * 10) + j) << ".\t";
				}
			}
			cout << "\n";
		}
		ustawPozycjeKursora(80, 2);
		napiszDuzaLiczbe(losowaLiczba);
		cout << endl;
		cout << "Losowanie " << i << ": " << losowaLiczba << endl;
		system("pause");
		i++;
	}

	system("pause");
	menuGlowne();
}


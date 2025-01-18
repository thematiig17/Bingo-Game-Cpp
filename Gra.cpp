#include <iostream>
#include "Header.h"
#include <cstdlib>
using namespace std;

struct aktualnaKarta {
	int wylosowaneNumery[25]{};
	bool sprawdzWystepowanie(int wylosowanaLiczba) {
		for (size_t i = 0; i < 25; i++)
		{
			if (wylosowanaLiczba == wylosowaneNumery[i])
			{
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}
	void wygenerujNumery() {
		for (size_t i = 0; i < 25; i++)
		{
			int wylosowanaLiczba;
			do {
				wylosowanaLiczba = losowaSeed(losowyUInt());
			} while (sprawdzWystepowanie(wylosowanaLiczba) == true);
			wylosowaneNumery[i] = wylosowanaLiczba;
		}
	}
};



void testLosowanie(unsigned int seed) {
	cout << "Start testu!" << endl;
	
	system("pause");
	menuGlowne();
}

void ekranGry(int wygenerowanySeed) {
	int i = 0;
	int wylosowaneLiczby[90]{}; //tablica na wylosowane liczby
	aktualnaKarta karta;
	karta.wygenerujNumery();
	while (i < 20) { /*Petla ma za zadanie tak dlugo losowac liczbe, az nie wylosujemy liczby ktora sie nie powtorzy.*/
		wyczyscEkranANSI();
		int losowaLiczba;
		int zmianaLiczby = 0;
		while (true) {
			losowaLiczba = losowaSeed(wygenerowanySeed + i * 10 + zmianaLiczby);
			if (wylosowaneLiczby[losowaLiczba] == 1) {
				zmianaLiczby++;
				continue;
			}
			wylosowaneLiczby[losowaLiczba] = 1;
			break;
		}

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
		kartaBingoAmerykanskie(karta);
		system("pause");
		i++;
		
	}

	system("pause");
	menuGlowne();
}

void kartaBingoAmerykanskie(aktualnaKarta karta) {
	
	int wierszLiczb = 0;
	for (size_t i = 0; i < 11; i++)
	{
		if (i == 0)
		{
			cout << "╔══╦══╦══╦══╦══╗" << endl;
		}
		else if (i % 2 == 0 && i != 10) {
			cout << "╠══╬══╬══╬══╬══╣" << endl;
		}
		else if (i % 2 == 1) {
			cout << "║";
			for (size_t j = 0; j < 5; j++)
			{
				if (wierszLiczb == 2 && j == 2) {
					cout << " F║";
					karta.wylosowaneNumery[i] = 100;
				}
				else
				{
					if (karta.wylosowaneNumery[(wierszLiczb * 5) + j] < 10) {
						cout << " ";
					}
					//cout << "i:"<<i<<"j:" <<j<< "ro:" << (wierszLiczb * 5)  + j <<"\t"; //debug
					cout << karta.wylosowaneNumery[(wierszLiczb * 5) + j] << "║";
				}
			}
			cout << endl;
			wierszLiczb++;
		}
		else if (i == 10) {
			cout << "╚══╩══╩══╩══╩══╝" << endl;
		}
	}
}


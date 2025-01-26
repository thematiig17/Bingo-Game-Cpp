#include <iostream>
#include "Header.h"

using namespace std;

void pokazPrzeciwnikow(KartaBingo przeciwnicy[]) {
	wyczyscEkranANSI();
	
	for (size_t przeciwnik = 0; przeciwnik < 3; przeciwnik++)
	{
		ustawPozycjeKursora(przeciwnicy[przeciwnik].pozycjaNaEkranieX, przeciwnicy[przeciwnik].pozycjaNaEkranieY);
		int wierszLiczb = 0;
		for (size_t i = 0; i < 11; i++)
		{
			if (i == 0)
			{

				cout << "╔══╦══╦══╦══╦══╗\033[1B\033[16D";
			}
			else if (i % 2 == 0 && i != 10) {
				cout << "╠══╬══╬══╬══╬══╣\033[1B\033[16D";
			}
			else if (i % 2 == 1) {
				cout << "║";
				for (size_t j = 0; j < 5; j++)
				{
					if (wierszLiczb == 2 && j == 2) {
						cout << "\033[41m F" << "\033[0m" << "║";
						przeciwnicy[przeciwnik].wylosowaneNumery[(wierszLiczb * 5) + j] = 100;
					}
					else
					{
						if (przeciwnicy[przeciwnik].zaznaczoneNumery[(wierszLiczb * 5) + j] == 1)
						{
							cout << "\033[41m";
						}
						if (przeciwnicy[przeciwnik].wylosowaneNumery[(wierszLiczb * 5) + j] < 10) {
							cout << " ";
						}

						//cout << "i:"<<i<<"j:" <<j<< "ro:" << (wierszLiczb * 5)  + j <<"\t"; //debug

						cout << przeciwnicy[przeciwnik].wylosowaneNumery[(wierszLiczb * 5) + j] << "\033[0m" << "║";
					}
				}
				cout << "\033[1B\033[16D";
				wierszLiczb++;
			}
			else if (i == 10) {
				cout << "╚══╩══╩══╩══╩══╝\033[1B\033[16D";
			}

		}
	}
	system("pause");
	wyczyscEkranANSI();
}
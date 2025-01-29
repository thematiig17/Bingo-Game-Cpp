#include <iostream>
#include "Header.h"

using namespace std;

void pokazPrzeciwnikow(KartaBingo przeciwnicy[], int iloscPrzeciwnikow) {
	wyczyscEkranANSI();
	
	for (size_t przeciwnik = 0; przeciwnik < iloscPrzeciwnikow; przeciwnik++) //dla kazdego przeciwnika
	{
		ustawPozycjeKursora(przeciwnicy[przeciwnik].pozycjaNaEkranieX, przeciwnicy[przeciwnik].pozycjaNaEkranieY); //ustawia pozycje kursora na ekranie karty
		int wierszLiczb = 0;
		for (size_t i = 0; i < 11; i++)
		{
			if (i == 0)
			{
				cout << " Przeciwnik #" << przeciwnik + 1 << "\033[1B\033[14D";
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
						if (przeciwnicy[przeciwnik].zaznaczoneNumery[(wierszLiczb * 5) + j] == 1) //zaznacza na czerwono zaznaczone liczby
						{
							cout << "\033[41m";
						}
						if (przeciwnicy[przeciwnik].wylosowaneNumery[(wierszLiczb * 5) + j] < 10) {
							cout << " ";
						}
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
	ustawPozycjeKursora(5,20);
	for (size_t i = 0; i < iloscPrzeciwnikow; i++) //jezeli bingo to wypisuje komunikat ktory przeciwnik zglosil bingo
	{
		if (przeciwnicy[i].czyBingo)
		{
			cout << "\033[41mPrzeciwnik #" << i + 1 << " zglosil Bingo!\033[0m\n";
		}

	}
	system("pause");
	wyczyscEkranANSI();
}
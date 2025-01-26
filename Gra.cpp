#include <iostream>
#include "Header.h"
#include <cstdlib>
using namespace std;


void testLosowanie(unsigned int seed) {
	cout << "Start testu!" << endl;
	
	system("pause");
	menuGlowne();
}

void ekranGry(int wygenerowanySeed, int liczbaPrzeciwnikow) {
	int i = 0;
	
	KartaBingo karta;
	KartaBingo* wskaznikKarty = &karta;
	czyKontynuowacGre kontynuacjaGry;
	czyKontynuowacGre* wskaznikKontynuacji = &kontynuacjaGry;
	karta.wygenerujNumery();

	/*Generowanie przeciwnikow*/
	KartaBingo* przeciwnicy = new KartaBingo[liczbaPrzeciwnikow];
	for (size_t i = 0; i < liczbaPrzeciwnikow; i++)
	{
		przeciwnicy[i].wygenerujNumery();
		przeciwnicy[i].pozycjaNaEkranieX = 20*i;
		przeciwnicy[i].pozycjaNaEkranieY = 4;
	}


	wyczyscEkranANSI();
	while (i < 20) { //petla losuje 20 liczb
		//wyczyscEkranANSI();
		int losowaLiczba = 0;
		int zmianaLiczby = 0;
		while (true && !zmianaLiczby) { /*Petla ma za zadanie tak dlugo losowac liczbe, az nie wylosujemy liczby ktora sie nie powtorzy.*/
			losowaLiczba = losowaSeed(wygenerowanySeed + i * 10 + zmianaLiczby, 0, 90);
			if (kontynuacjaGry.wylosowaneLiczby[losowaLiczba] == 1) {
				zmianaLiczby++;
				continue;
			}
			kontynuacjaGry.wylosowaneLiczby[losowaLiczba] = 1;
			break;
		}
		kontynuacjaGry.kontynuujGre = false;

		for (size_t i = 0; i <= 8; i++)
		{
			for (size_t j = 1; j <= 10; j++)
			{
				ustawPozycjeKursora(i*5, j);
				if (kontynuacjaGry.wylosowaneLiczby[(i * 10) + j] == 1) {
					
					cout << "\033[32m" << ((i * 10) + j) << ".\033[0m";
				}
				else {
					cout << ((i * 10) + j) <<".";
				}
			}
			cout << "\n";
		}
		ustawPozycjeKursora(50, 2);
		napiszDuzaLiczbe(losowaLiczba);
		zaznaczNumerPrzeciwnikom(przeciwnicy, losowaLiczba, liczbaPrzeciwnikow);
		cout << endl << endl << endl;
		cout << "Losowanie " << i+1 << ": " << losowaLiczba << endl;
		kartaBingoAmerykanskie(wskaznikKarty, kontynuacjaGry.wylosowaneLiczby, wskaznikKontynuacji, przeciwnicy, liczbaPrzeciwnikow);
		//system("pause");
		if (kontynuacjaGry.kontynuujGre)
		{
			
			i++;
		}
		
	}

	system("pause");
	delete[] przeciwnicy;
	menuGlowne();
}

void kartaBingoAmerykanskie(KartaBingo* karta, int wylosowaneLiczby[], czyKontynuowacGre* kontynuacjaGry, KartaBingo przeciwnicy[], int liczbaPrzeciwnikow) {
	
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
					if ((wierszLiczb * 5) + j == 5 * karta->pozY + karta->pozX)
					{
						cout << "\033[32m";
					}
					if (karta->zaznaczoneNumery[(wierszLiczb * 5) + j] == 1)
					{
						cout << "\033[41m";
					}
					cout << " F" << "\033[0m" <<"║";
					karta->wylosowaneNumery[(wierszLiczb * 5) + j] = 100;
				}
				else
				{
					ustawPozycjeKursora((j * 3) + 2, i + 13);
					
					if ((wierszLiczb * 5) + j == 5 * karta->pozY + karta->pozX)
					{
						cout << "\033[32m";
					}
					if (karta->zaznaczoneNumery[(wierszLiczb * 5) + j] == 1)
					{
						cout << "\033[41m";
					}
					if (karta->wylosowaneNumery[(wierszLiczb * 5) + j] < 10) {
						cout << " ";
					}
					
					//cout << "i:"<<i<<"j:" <<j<< "ro:" << (wierszLiczb * 5)  + j <<"\t"; //debug
					
					cout << karta->wylosowaneNumery[(wierszLiczb * 5) + j] << "\033[0m" << "║";
				}
			}
			cout << endl;
			wierszLiczb++;
		}
		else if (i == 10) {
			cout << "╚══╩══╩══╩══╩══╝" << endl;
		}
		
	}
	cout << "\nAby przejsc do nastepnego losowania nacisnij klawisz C...\n";
	czyKliknietoKlawisz(karta, kontynuacjaGry, przeciwnicy, liczbaPrzeciwnikow);
}

void zaznaczNumerPrzeciwnikom(KartaBingo przeciwnicy[], int wylosowanaLiczba, int iloscPrzeciwnikow) {
	for (size_t i = 0; i < iloscPrzeciwnikow; i++)
	{
		for (size_t j = 0; j < 25; j++)
		{
			if (przeciwnicy[i].wylosowaneNumery[j] == wylosowanaLiczba)
			{
				przeciwnicy[i].zaznaczoneNumery[j] = 1;
			}
		}
	}
}
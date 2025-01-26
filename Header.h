#pragma once
#include <string>
/*Struktuy*/

/*Menu.cpp*/
void menuGlowne();
void instrukcja();
void ustawienia(unsigned int);
void ustawienia();
void top10wynikow();

/*Funkcje.cpp*/
void wyczyscEkranWindows();
void wyczyscEkranANSI();
void napiszDuzaLiczbe(int);
void enableVirtualTerminalProcessing();
void ustawPozycjeKursora(int x, int y);


/*Random.cpp*/
int losowaSeed(unsigned int, unsigned int, unsigned int);
unsigned int losowyUInt();

/*Gra.cpp*/
void testLosowanie(unsigned int);
void ekranGry(int);


/*ObslugaPlikow.cpp*/
void zapiszDoPliku(std::string, std::string, bool);
std::string* wczytajZPliku(std::string, std::string);

struct KartaBingo {
	int wylosowaneNumery[25]{};
	int pozX = 0;
	int pozY = 0;
	int pozycjaNaEkranieX = 0;
	int pozycjaNaEkranieY = 0;
	int zaznaczoneNumery[25]{};
	bool czyBingo = false;
	void zaznaczNumer(int numeryDoZaznaczenia[]) {
		if (numeryDoZaznaczenia[wylosowaneNumery[(pozY * 5) + pozX]] || wylosowaneNumery[(pozY * 5) + pozX] == 100) //100 to znacznik "Free", na srodku planszy Amerykanskiego Binga
		{
			zaznaczoneNumery[(pozY * 5) + pozX] = 1;
		}
	}
	bool sprawdzWystepowanie(int wylosowanaLiczba) {
		for (size_t i = 0; i < 25; i++)
		{
			if (wylosowanaLiczba == wylosowaneNumery[i])
			{
				return true;
			}
		}
		return false;
	}
	void wygenerujNumery() {
		for (size_t i = 0; i < 25; i++)
		{
			int wylosowanaLiczba = 0;
			int kolumna = i % 5;
			switch (kolumna)
			{
			case 0:
				do {
					wylosowanaLiczba = losowaSeed(losowyUInt(), 0, 15);
				} while (sprawdzWystepowanie(wylosowanaLiczba) == true);
				wylosowaneNumery[i] = wylosowanaLiczba;
				break;
			case 1:
				do {
					wylosowanaLiczba = losowaSeed(losowyUInt(), 16, 30);
				} while (sprawdzWystepowanie(wylosowanaLiczba) == true);
				wylosowaneNumery[i] = wylosowanaLiczba;
				break;
			case 2:
				do {
					wylosowanaLiczba = losowaSeed(losowyUInt(), 31, 45);
				} while (sprawdzWystepowanie(wylosowanaLiczba) == true);
				wylosowaneNumery[i] = wylosowanaLiczba;
				break;
			case 3:
				do {
					wylosowanaLiczba = losowaSeed(losowyUInt(), 46, 60);
				} while (sprawdzWystepowanie(wylosowanaLiczba) == true);
				wylosowaneNumery[i] = wylosowanaLiczba;
				break;
			case 4:
				do {
					wylosowanaLiczba = losowaSeed(losowyUInt(), 61, 75);
				} while (sprawdzWystepowanie(wylosowanaLiczba) == true);
				wylosowaneNumery[i] = wylosowanaLiczba;
				break;
			default:
				wylosowaneNumery[i] = 0;
				break;
			}
		}
	}
};

struct czyKontynuowacGre {
	bool kontynuujGre = false;
	int wylosowaneLiczby[90]{};
};

void kartaBingoAmerykanskie(KartaBingo*, int*, czyKontynuowacGre*, KartaBingo[]);
void czyKliknietoKlawisz(KartaBingo*, czyKontynuowacGre*, KartaBingo[]);
void pokazPrzeciwnikow(KartaBingo[]);
void zaznaczNumerPrzeciwnikom(KartaBingo[], int);




#pragma once
#include <string>

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
void wlaczFunkcjeVirtualTerminal();
void ustawPozycjeKursora(int x, int y);
void piszDuzeBingo(bool);


/*Random.cpp*/
int losowaSeed(unsigned int, unsigned int, unsigned int);
unsigned int losowyUInt();

/*Gra.cpp*/
void ekranGry(unsigned int, int);


/*ObslugaPlikow.cpp*/
void zapiszDoPliku(std::string, std::string, bool);
std::string* wczytajZPliku(std::string, std::string);

/*Glowna struktura karty do Bingo*/
struct KartaBingo {
	int wylosowaneNumery[25]{}; //tablica 25 liczb na karcie
	int pozX = 0; //pozycja kursora w osi X
	int pozY = 0; //pozycja kursora w osi Y
	int pozycjaNaEkranieX = 0; //pozycja okienka z gra na ekranie w osi X
	int pozycjaNaEkranieY = 0; //pozycja okienka z gra na ekranie w osi Y
	int zaznaczoneNumery[25]{}; //tablica liczb ktore zostaly zaznaczone przez gracza/bota
	bool czyBingo = false; //czy gracz/bot zglosil Bingo

	void zaznaczNumer(int numeryDoZaznaczenia[]) { //funkcja zaznacza numer na karcie ktory zostal juz wylosowany
		if (numeryDoZaznaczenia[wylosowaneNumery[(pozY * 5) + pozX]] || wylosowaneNumery[(pozY * 5) + pozX] == 100) //100 to znacznik "Free", na srodku planszy Amerykanskiego Binga
		{
			zaznaczoneNumery[(pozY * 5) + pozX] = 1;
		}
	}

	bool sprawdzWystepowanie(int wylosowanaLiczba) { //sprawdza czy wylosowana liczba juz wystapila na karcie (uzywane zeby uniknac powtorzen)
		for (size_t i = 0; i < 25; i++)
		{
			if (wylosowanaLiczba == wylosowaneNumery[i])
			{
				return true;
			}
		}
		return false;
	}

	void wygenerujNumery() { //generuje 25 unikalnych liczb na karcie
		for (size_t i = 0; i < 25; i++)
		{
			int wylosowanaLiczba = 0;
			int kolumna = i % 5;
			switch (kolumna)
			{
			case 0:
				do {
					wylosowanaLiczba = losowaSeed(losowyUInt(), 1, 18);
				} while (sprawdzWystepowanie(wylosowanaLiczba) == true);
				wylosowaneNumery[i] = wylosowanaLiczba;
				break;
			case 1:
				do {
					wylosowanaLiczba = losowaSeed(losowyUInt(), 19, 36);
				} while (sprawdzWystepowanie(wylosowanaLiczba) == true);
				wylosowaneNumery[i] = wylosowanaLiczba;
				break;
			case 2:
				do {
					wylosowanaLiczba = losowaSeed(losowyUInt(), 37, 54);
				} while (sprawdzWystepowanie(wylosowanaLiczba) == true);
				wylosowaneNumery[i] = wylosowanaLiczba;
				break;
			case 3:
				do {
					wylosowanaLiczba = losowaSeed(losowyUInt(), 55, 72);
				} while (sprawdzWystepowanie(wylosowanaLiczba) == true);
				wylosowaneNumery[i] = wylosowanaLiczba;
				break;
			case 4:
				do {
					wylosowanaLiczba = losowaSeed(losowyUInt(), 73, 90);
				} while (sprawdzWystepowanie(wylosowanaLiczba) == true);
				wylosowaneNumery[i] = wylosowanaLiczba;
				break;
			default:
				wylosowaneNumery[i] = 0;
				break;
			}
		}
	}

	void zrobBingo() { //cheat do celow testowych, tylko do prezentacji bez koniecznosci wygrania. (w wersji realese bylby usuniety)
		for (size_t i = 0; i < 5; i++)
		{
			zaznaczoneNumery[i] = 1;
		}
	}

	bool sprawdzCzyBingo() { //sprawdza czy na karcie wystapilo Bingo
		for (size_t i = 0; i < 5; i++) //poziome bingo
		{
			if (zaznaczoneNumery[i * 5] == 1 && zaznaczoneNumery[i * 5 + 1] == 1 && zaznaczoneNumery[i * 5 + 2] == 1 && zaznaczoneNumery[i * 5 + 3] == 1 && zaznaczoneNumery[i * 5 + 4] == 1)
			{
				czyBingo = true;
				return true;
			}
		}
		for (size_t i = 0; i < 5; i++) //pionowe bingo
		{
			if (zaznaczoneNumery[i] == 1 && zaznaczoneNumery[i + 5] == 1 && zaznaczoneNumery[i + 10] == 1 && zaznaczoneNumery[i + 15] == 1 && zaznaczoneNumery[i + 20] == 1)
			{
				czyBingo = true;
				return true;
			}
		}
		if (zaznaczoneNumery[0] == 1 && zaznaczoneNumery[6] == 1 && zaznaczoneNumery[12] == 1 && zaznaczoneNumery[18] == 1 && zaznaczoneNumery[24] == 1) //przekatne bingo
		{
			czyBingo = true;
			return true;
		}
		if (zaznaczoneNumery[4] == 1 && zaznaczoneNumery[8] == 1 && zaznaczoneNumery[12] == 1 && zaznaczoneNumery[16] == 1 && zaznaczoneNumery[20] == 1) //przekatne bingo
		{
			czyBingo = true;
			return true;
		}
		czyBingo = false;
		return false;
	}
};

/*Struktura przechowujaca wartosc czy kontynuowac gre i liczby ktore zostaly wylosowane*/
struct czyKontynuowacGre {
	bool kontynuujGre = false;
	int wylosowaneLiczby[91]{}; //tablica z wylosowanymi liczbami, 0 - nie wylosowano, 1 - wylosowano
};

/*Funkcje wykorzystujace struktury*/
/*Dla gracza:*/
void kartaBingoAmerykanskie(KartaBingo*, int*, czyKontynuowacGre*, KartaBingo[], int);
void czyKliknietoKlawisz(KartaBingo*, czyKontynuowacGre*, KartaBingo[], int);
/*Dla botow:*/
void pokazPrzeciwnikow(KartaBingo[], int);
void zaznaczNumerPrzeciwnikom(KartaBingo[], int, int);




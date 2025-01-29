#include <iostream>
#include "Header.h"
#include <cstdlib>
using namespace std;

/*
GRA.CPP
FUNKCJE DOTYCZACE SAMEJ GRY
NAJWAZNIEJSZY PLIK, MECHANIKA GRY
*/

void ekranGry(unsigned int wygenerowanySeed, int liczbaPrzeciwnikow) {

	int i = 0; //numer losowania

	/*Inicjalizacja struktur potrzebnych do gry i ich wskaznikow*/
	KartaBingo karta; 
	KartaBingo* wskaznikKarty = &karta;
	czyKontynuowacGre kontynuacjaGry;
	czyKontynuowacGre* wskaznikKontynuacji = &kontynuacjaGry;

	/*Generowanie numerow w karcie gracza*/
	karta.wygenerujNumery();

	/*Generowanie przeciwnikow*/
	KartaBingo* przeciwnicy = new KartaBingo[liczbaPrzeciwnikow]; //dynamiczna alokacja tablicy przeciwnikow w zaleznosci od ich ilosci
	for (size_t i = 0; i < liczbaPrzeciwnikow; i++)
	{
		przeciwnicy[i].wygenerujNumery();
		przeciwnicy[i].pozycjaNaEkranieX = 20*i;
		przeciwnicy[i].pozycjaNaEkranieY = 4;
		przeciwnicy[i].wylosowaneNumery[12] = 100; //ustawienie "Free" na srodku planszy
	}

	int losowaLiczba = 0; //wylosowana liczba, przed pierwszym losowaniem 0
	kontynuacjaGry.kontynuujGre = true; //zmienna kontrolujaca czy kontynuowac gre
	wyczyscEkranANSI();

	while (i < 90) { //petla losuje 90 liczb, tyle ile jest w Bingo

		if (karta.czyBingo) { //sprawdzenie czy gracz zglosil Bingo
			
			cout << "\033[2A\033[17CBINGO! Wygrales w "<<i+1<<" losowaniach!\033[1B\033[31D";
			system("pause");
			cout << "\033[0m";
			
			wyczyscEkranANSI();
			cout << "WYGRANA W "<<i+1<<" LOSOWANIACH!"<<endl;
			cout << "Czy zapisac wynik? (T/N) ";
			char zapiszWynik = ' ';
			try { //sprawdzamy czy uda sie zapisac wynik do pliku
				cin >> zapiszWynik;
				cout << endl;
				if (zapiszWynik == 'T' || zapiszWynik == 't') {
					string nick = "";
					cout << "Podaj nick: ";
					cin >> nick;
					zapiszDoPliku("wyniki.txt", nick, i + 1);
					cout << "Wynik zapisany!" << endl;
				}
			}
			catch (int e) { //nawet w wypadku bledu bezpiecznie usuwamy tablice przeciwnikow i wracamy do menu
				cout << "Blad zapisywania pliku. Aktualnie nie mozna zapisac pliku. Blad: " << e << endl;
				system("pause");
				delete[] przeciwnicy;
				return;
			}
			
			system("pause");
			delete[] przeciwnicy;
			return;
		}
		for (size_t i = 0; i < liczbaPrzeciwnikow; i++) //sprawdzenie czy ktorys z botow zglosil bingo
		{
			if (przeciwnicy[i].sprawdzCzyBingo()) {
				piszDuzeBingo(true);
				system("pause");
				cout << "\033[0m";
				pokazPrzeciwnikow(przeciwnicy, liczbaPrzeciwnikow);
				wyczyscEkranANSI();
				cout << "Niestety przegrales! Powodzenia nastepnym razem!\nPorada: Mniejsza ilosc przeciwnikow sprawia, ze mniej prawdopodobne ze ktorys wygra.";
				system("pause");
				delete[] przeciwnicy;
				return;
			}
		}

		int zmianaLiczby = 0; //zmienna sluzaca zmianie wylosowanej liczby w przypadku powtorzenia
		while (kontynuacjaGry.kontynuujGre == true) { /*Petla ma za zadanie tak dlugo losowac liczbe, az nie wylosujemy liczby ktora sie nie powtorzy.*/
			losowaLiczba = losowaSeed(wygenerowanySeed + (i * -7) + (zmianaLiczby * -7), 1, 90); //algorytm losowania liczby (warunek seedu wiekszego od 10000 zapewnia, ze nie wyjdziemy poza zakres)
			if (kontynuacjaGry.wylosowaneLiczby[losowaLiczba] == 1) {
				zmianaLiczby++;
				continue;
			}
			kontynuacjaGry.wylosowaneLiczby[losowaLiczba] = 1;
			break;
		}

		kontynuacjaGry.kontynuujGre = false; //ustawienie zmiennej na false, aby nie kontynuowac gry dopoki nie klikniemy klawisza C

		/*WYPISANIE TABLICY LICZB ZAZNACZONYCH*/
		for (size_t i = 0; i <= 8; i++)
		{
			for (size_t j = 1; j <= 10; j++)
			{
				ustawPozycjeKursora(i*5, j);
				if (kontynuacjaGry.wylosowaneLiczby[(i * 10) + j] == 1) {
					
					cout << "\033[32m" << ((i * 10) + j) << ".\033[0m"; //jak liczba jest zaznaczona to jest ona kolorowana na zielono.
				}
				else {
					cout << ((i * 10) + j) <<".";
				}
			}
			cout << "\n";
		}

		zaznaczNumerPrzeciwnikom(przeciwnicy, losowaLiczba, liczbaPrzeciwnikow); //zaznaczenie wylosowanego numeru na kartach przeciwnikow

		ustawPozycjeKursora(50, 2);
		napiszDuzaLiczbe(losowaLiczba); //piszemy liczbe duza czcionka po prawej stronie ekranu

		cout << endl << endl << endl;
		cout << "Losowanie " << i+1 << ": " << losowaLiczba << "  " << endl; //wypisanie numeru losowania i wylosowanej liczby

		kartaBingoAmerykanskie(wskaznikKarty, kontynuacjaGry.wylosowaneLiczby, wskaznikKontynuacji, przeciwnicy, liczbaPrzeciwnikow); //wyswietlenie karty gracza

		if (kontynuacjaGry.kontynuujGre) //jezeli uzytkownik chce kontynuowac gre to zmienia sie numer losowania
		{
			i++;
		}
	}

	cout << "Nikomu nie udalo sie zglosic Bingo!"<<endl;
	system("pause"); /*Gdy skonczy sie ilosc losowan to program bezpiecznie sie zakonczy usuwajac dynamicznie zarezerwowana pamiec*/
	delete[] przeciwnicy;
	return;
}

void kartaBingoAmerykanskie(KartaBingo* karta, int wylosowaneLiczby[], czyKontynuowacGre* kontynuacjaGry, KartaBingo przeciwnicy[], int liczbaPrzeciwnikow) {
	
	int wierszLiczb = 0;
	for (size_t i = 0; i < 11; i++) //wypisanie karty gracza
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
				if (wierszLiczb == 2 && j == 2) { //zaznaczenie pola F na srodku karty
					if ((wierszLiczb * 5) + j == 5 * karta->pozY + karta->pozX) //jezeli uzytkownik najedzie na pole to zmieni kolor na zielony
					{
						cout << "\033[32m";
					}
					if (karta->zaznaczoneNumery[(wierszLiczb * 5) + j] == 1) //jezeli numer jest zaznaczony to tlo staje sie czerwone
					{
						cout << "\033[41m";
					}
					cout << " F" << "\033[0m" <<"║";
					karta->wylosowaneNumery[(wierszLiczb * 5) + j] = 100; //numer 100 oznacza "Free" na srodku karty
				}
				else
				{
					ustawPozycjeKursora((j * 3) + 2, i + 13);
					
					if ((wierszLiczb * 5) + j == 5 * karta->pozY + karta->pozX) //jezeli uzytkownik najedzie na pole to zmieni kolor na zielony
					{
						cout << "\033[32m";
					}
					if (karta->zaznaczoneNumery[(wierszLiczb * 5) + j] == 1) //jezeli numer jest zaznaczony to tlo staje sie czerwone
					{
						cout << "\033[41m";
					}
					if (karta->wylosowaneNumery[(wierszLiczb * 5) + j] < 10) { //jezeli numer jest mniejszy niz 10 to dodajemy spacje przed nim
						cout << " ";
					}
					cout << karta->wylosowaneNumery[(wierszLiczb * 5) + j] << "\033[0m" << "║"; //wypisujemy liczbe
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
	for (size_t i = 0; i < iloscPrzeciwnikow; i++) //zaznacza kazdemu przeciwnikowi wylosowana liczbe
	{
		for (size_t j = 0; j < 25; j++)
		{
			if (przeciwnicy[i].wylosowaneNumery[j] == wylosowanaLiczba || przeciwnicy[i].wylosowaneNumery[j] == 100)
			{
				przeciwnicy[i].zaznaczoneNumery[j] = 1;
			}
		}
	}
}
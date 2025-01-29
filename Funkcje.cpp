#include <iostream>
#include <windows.h>
#include "Header.h"
#include <conio.h>

using namespace std;


void wyczyscEkranWindows() { //funkcja czysci ekran za pomoca komendy systemowej
	system("cls");
}
void wyczyscEkranANSI() { //funkcja czysci ekran za pomoca kodow ANSI
	cout << "\033[2J\033[1;1H";
}
void napiszDuzaLiczbe(int liczba) { //funkcja wypisuje liczbe dwucyfrowa w konsoli duzymi znakami
	if (liczba > 90 || liczba < 0)
	{
		cout << "napiszDuzaLiczbe(): Liczba spoza zakresu.";
	}
	else {
		int liczbaDziesiatek = liczba / 10;
		int liczbaJednosci = liczba % 10;
		//cout << "\033[47m" - białe tło;
		//cout << "\033[30m" - czarny tekst;
		switch (liczbaDziesiatek) {
		case 0:
			cout << " ## " << "\033[1B\033[4D"; //kody ANSI do przesuniecia kursora w konsoli o jeden w dol, i cztery w lewo
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
		break;
		case 1:
			cout << "  # " << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			cout << "# # " << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			break;
		case 2:
			cout << " ## " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			cout << " #  " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "### " << "\033[1B\033[4D";
			break;
		case 3:
			cout << " ## " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			break;
		case 4:
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			break;
		case 5:
			cout << "### " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "##  " << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			break;
		case 6:
			cout << " ## " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "##  " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			break;
		case 7:
			cout << "### " << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			cout << " #  " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			break;
		case 8:
			cout << " ## " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			break;
		case 9:
			cout << " ## " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ###" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			break;
		}


		cout << "\033[7A\033[5C"; //przesuniecie kursora o 7 w gore i 5 w prawo

		switch (liczbaJednosci) {
		case 0:
			cout << " ## " << "\033[1B\033[4D"; //kody ANSI do przesuniecia kursora w konsoli o jeden w dol, i cztery w lewo
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			break;
		case 1:
			cout << "  # " << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			cout << "# # " << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			break;
		case 2:
			cout << " ## " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			cout << " #  " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "### " << "\033[1B\033[4D";
			break;
		case 3:
			cout << " ## " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			break;
		case 4:
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			break;
		case 5:
			cout << "### " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "##  " << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			break;
		case 6:
			cout << " ## " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "##  " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			break;
		case 7:
			cout << "### " << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "  # " << "\033[1B\033[4D";
			cout << " #  " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			cout << "#   " << "\033[1B\033[4D";
			break;
		case 8:
			cout << " ## " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			break;
		case 9:
			cout << " ## " << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ###" << "\033[1B\033[4D";
			cout << "   #" << "\033[1B\033[4D";
			cout << "#  #" << "\033[1B\033[4D";
			cout << " ## " << "\033[1B\033[4D";
			break;
		}
		cout << "\033[0m";
	}

}
void wlaczFunkcjeVirtualTerminal() { //umozliwia wykorzystanie kodów ANSI w konsoli Windows, uruchamiana tylko na poczatku w main()
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hConsole, &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hConsole, mode);
}
void ustawPozycjeKursora(int x, int y) { //ustawienie kursora na pozadanych koordynatach w konsoli
	// Sekwencja ANSI: "\033[y;xH"
	cout << "\033[" << y << ";" << x << "H";
}
void czyKliknietoKlawisz(KartaBingo* karta, czyKontynuowacGre* kontynuowanieGry, KartaBingo przeciwnicy[], int iloscPrzeciwnikow) { //funkcja obslugi przyciskow z klawiatury w grze
	bool oczekiwanieNaPrzycisk = true;
	while (oczekiwanieNaPrzycisk) {
		if (_kbhit()) {
			int ch = _getch(); //pobieramy kod klawisza
			if (ch == 224) { //strzalki na klawiaturze sa poprzedzone kodem 224
				switch (_getch()) {
				case 72: //strzalka w gore
					if (karta->pozY > 0)
					{
						karta->pozY--;
						oczekiwanieNaPrzycisk = false;
					}
					break;
				case 80: //strzalka w dol
					if (karta->pozY < 4)
					{
						karta->pozY++;
						oczekiwanieNaPrzycisk = false;
					}
					break;
				case 75: //strzalka w lewo
					if (karta->pozX > 0)
					{
						karta->pozX--;
						oczekiwanieNaPrzycisk = false;
					}
					break;
				case 77: //strzalka w prawo
					if (karta->pozX < 4)
					{
						karta->pozX++;
						oczekiwanieNaPrzycisk = false;
					}
					break;
				}

			}
			else if (ch == 27) { //escape
				oczekiwanieNaPrzycisk = false;
			}
			else if (ch == 13) { //enter - zaznacz numer
				karta->zaznaczNumer(kontynuowanieGry->wylosowaneLiczby);
				oczekiwanieNaPrzycisk = false;
			}
			else if (ch == 99) { //C - kontynuuj gre
				kontynuowanieGry->kontynuujGre = true;
				oczekiwanieNaPrzycisk = false;
			}
			else if (ch == 112) { //P - pokaz ekran przeciwnikow
				pokazPrzeciwnikow(przeciwnicy, iloscPrzeciwnikow);
				oczekiwanieNaPrzycisk = false;
			}
			else if (ch == 98) { //B - zglos Bingo
				if (karta->sprawdzCzyBingo()) {
					piszDuzeBingo(false);
					//cout << "BINGO!"; //zrobic duzy napis bingo na caly ekran
					karta->czyBingo = true;
					system("pause");
				}
				oczekiwanieNaPrzycisk = false;
			}
			else if (ch == 115) { //S - Cheat do celow pokazowych, zrob sobie Bingo
				karta->zrobBingo();
				oczekiwanieNaPrzycisk = false;
			}
		}
	}
}

void piszDuzeBingo(bool czyPrzeciwnik) { //funkcja wypisuje napis BINGO na calym ekranie
	ustawPozycjeKursora(3, 6);
	for (size_t i = 0; i < 8; i++) //czysci pole przed napisaneim BINGO
	{
		cout << "                                                        \033[1B\033[56D";
	}
	ustawPozycjeKursora(6, 6);
	if (czyPrzeciwnik) {
		cout << "\033[41m\033[30m";
	}
	else {
		cout << "\033[42m\033[30m";
	}
	cout << "                                                        \033[1B\033[56D";
	cout << "   /$$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$   /$$$$$$  /$$  \033[1B\033[56D";
	cout << "  | $$__  $$|_  $$_/| $$$ | $$ /$$__  $$ /$$__  $$| $$  \033[1B\033[56D";
	cout << "  | $$  \\ $$  | $$  | $$$$| $$| $$  \\__/| $$  \\ $$| $$  \033[1B\033[56D";
	cout << "  | $$$$$$$   | $$  | $$ $$ $$| $$ /$$$$| $$  | $$| $$  \033[1B\033[56D";
	cout << "  | $$__  $$  | $$  | $$  $$$$| $$|_  $$| $$  | $$|__/  \033[1B\033[56D";
	cout << "  | $$  \\ $$  | $$  | $$\\  $$$| $$  \\ $$| $$  | $$      \033[1B\033[56D";
	cout << "  | $$$$$$$/ /$$$$$$| $$ \\  $$|  $$$$$$/|  $$$$$$/ /$$  \033[1B\033[56D";
	cout << "  |_______/ |______/|__/  \\__/ \\______/  \\______/ |__/  \033[1B\033[56D";
	cout << "                                                        \033[1B\033[56D";

	if (czyPrzeciwnik)
	{
		cout << "          Przegrana! Przeciwnik zgłosił Bingo!          \033[1B\033[56D";
	}
	else {
		cout << "                    Zgłosiłeś Bingo!                    \033[1B\033[56D";
	}
	cout << "                                                        \033[1B\033[56D";
	cout << "                                                        \033[43D\033[1A";
}
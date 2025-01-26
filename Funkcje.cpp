#include <iostream>
#include <windows.h>
#include "Header.h"
#include <conio.h>

using namespace std;


void wyczyscEkranWindows() {
	system("cls");
}
void wyczyscEkranANSI() {
	cout << "\033[2J\033[1;1H";
}
void napiszDuzaLiczbe(int liczba) {
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
void enableVirtualTerminalProcessing() { //umozliwia wykorzystanie kodów ANSI w konsoli Windows, uruchamiana tylko na poczatku w main()
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
void czyKliknietoKlawisz(KartaBingo* karta, czyKontynuowacGre* kontynuowanieGry, KartaBingo przeciwnicy[]) {
	bool running = true;
	while (running) {
		if (_kbhit()) {
			int ch = _getch();
			if (ch == 224) { // Arrow keys are preceded by 224
				switch (_getch()) {
				case 72: // Up arrow key
					if (karta->pozY > 0)
					{
						karta->pozY--;
						running = false;
					}
					break;
				case 80: // Down arrow key
					if (karta->pozY < 4)
					{
						karta->pozY++;
						running = false;
					}
					break;
				case 75: // Left arrow key
					if (karta->pozX > 0)
					{
						karta->pozX--;
						running = false;
					}
					break;
				case 77: // Right arrow key
					if (karta->pozX < 4)
					{
						karta->pozX++;
						running = false;
					}
					break;
				}

			}
			else if (ch == 27) { // Escape key to exit
				running = false;
			}
			else if (ch == 13) { // Enter key
				karta->zaznaczNumer(kontynuowanieGry->wylosowaneLiczby);
				running = false;
			}
			else if (ch == 99) { // C key
				kontynuowanieGry->kontynuujGre = true;
				running = false;
			}
			else if (ch == 112) { // P key
				pokazPrzeciwnikow(przeciwnicy);
				running = false;
			}
		}
	}
}
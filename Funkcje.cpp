#include <iostream>
#include <windows.h>
#include "Header.h"

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
		//cout << "\033[47m";
		//cout << "\033[30m";
		switch (liczbaDziesiatek) {
		case 0:
			cout << " ## " << "\033[1B\033[4D";
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
			//cout << "\033[1B";
			cout << "### " << "\033[1B\033[4D"; //kody ANSI do przesuniecia kursora w konsoli o jeden w dol, i cztery w lewo
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
			cout << " ## " << "\033[1B\033[4D";
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
			//cout << "\033[1B";
			cout << "### " << "\033[1B\033[4D"; //kody ANSI do przesuniecia kursora w konsoli o jeden w dol, i cztery w lewo
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
void enableVirtualTerminalProcessing() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hConsole, &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hConsole, mode);
}
void ustawPozycjeKursora(int x, int y) {
	// Sekwencja ANSI: "\033[y;xH"
	cout << "\033[" << y << ";" << x << "H";
}

/*void ustawRozmiarKonsoli(int width, int height) {
	// Uzyskaj uchwyt do aktywnej konsoli
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) {
		std::cout << "Błąd: Nie można uzyskać uchwytu konsoli.\n";
		return;
	}

	// Ustaw rozmiar okna konsoli
	SMALL_RECT windowSize = { 0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1) };
	if (!SetConsoleWindowInfo(hConsole, TRUE, &windowSize)) {
		std::cout << "Błąd: Nie można ustawić rozmiaru okna konsoli.\n";
		return;
	}

	// Ustaw rozmiar bufora ekranu
	COORD bufferSize = { static_cast<SHORT>(width), static_cast<SHORT>(height) };
	if (!SetConsoleScreenBufferSize(hConsole, bufferSize)) {
		std::cout << "Błąd: Nie można ustawić rozmiaru bufora ekranu.\n";
		return;
	}
}*/
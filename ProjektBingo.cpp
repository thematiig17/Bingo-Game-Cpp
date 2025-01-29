#include <iostream>
#include <windows.h>
#include "Header.h"

/*
PLIK PROJEKTBINGO.CPP
FUNKCJA MAIN, WEJSCIE DO PROGRAMU
*/

using namespace std;

int main()
{
    /*
    START PROGRAMU, USTAWIENIE KONSOLI
    */
    setlocale(LC_ALL, "en_US.UTF-8");
    SetConsoleOutputCP(CP_UTF8);
    wlaczFunkcjeVirtualTerminal();

    /*
    WYWOŁANIE GŁÓWNEJ FUNKCJI
    */

	while (true) {
		menuGlowne();
	}

    cout << "Zakonczono gre." << endl;
    system("pause");
}

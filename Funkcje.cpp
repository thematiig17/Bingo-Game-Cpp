#include <iostream>
#include "Header.h"

using namespace std;

void wyczyscEkranWindows() {
	system("cls");
}
void wyczyscEkranANSI() {
	cout << "\033[2J\033[1;1H";
}
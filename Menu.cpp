#include <iostream>
#include "Header.h"
#include <cstdlib>
using namespace std;

void menuGlowne() {
	//Ekran Glowny:
	wyczyscEkranANSI();
	cout << "###   #  #  #  ####  ####" << endl;
	cout << "#  #     ## #  #     #  #" << endl;
	cout << "###   #  # ##  # ##  #  #" << endl;
	cout << "#  #  #  #  #  #  #  #  #" << endl;
	cout << "###   #  #  #  ####  ####" << endl;
	cout << endl;
	cout << "1. Graj!" << endl;
	cout << "2. Instrukcja" << endl;
	cout << "3. Wyjdz" << endl;
	cout << endl;
	cout << "Twoj wybor: ";
	int wybor = 0; //wybor opcji w menu
	while (true) {
		cin >> wybor;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wybierz poprawna opcje!" << endl;
		}
		else {
			break;
		}
	}
	switch (wybor) {
	case 1: 
		/*graj*/ cout << "Graj placeholder" << endl;
		system("pause");
		menuGlowne();
		break;
	case 2: /*instrukcja*/ instrukcja(); break;
	case 3: exit(0); break;
	}
}

void instrukcja() {
	wyczyscEkranANSI();
	cout << "Tutaj bedzie instrukcja." << endl;
	system("pause");
	menuGlowne();
}
﻿#include <iostream>
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
	cout << "3. Wyjdz (4 - test losowania)" << endl;
	cout << endl;
	cout << "Twoj wybor: ";
	int wybor = 0; //wybor opcji w menu
	while (true) {
		cin >> wybor;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wybierz poprawna opcje!" << endl;
			system("pause");
			menuGlowne();
		}
		else {
			break;
		}
	}
	switch (wybor) {
	case 1: 
		/*graj*/ 
		ustawienia();
		//system("pause");
		//menuGlowne();
		break;
	case 2: /*instrukcja*/ instrukcja(); break;
	case 3: exit(0); break;
	case 4: testLosowanie(12345678); break;
	default: 
		cout << "Wybierz poprawna opcje!" << endl; 
		system("pause"); 
		menuGlowne(); 
		break;
	}
}

void instrukcja() {
	wyczyscEkranANSI();
	cout << "Tutaj bedzie instrukcja." << endl;
	system("pause");
	menuGlowne();
}

void ustawienia() {
	wyczyscEkranANSI();
	unsigned int wygenerowanySeed = losowyUInt();
	cout << "Seed Gry: " << wygenerowanySeed << endl;
	cout << "Jezeli chcesz zagrac razem z kims\nto podaj ten sam seed w obu klientach:\n(wpisz 0 jezeli chcesz uzyc wygenerowanego seeda)" << endl;
	cout << "Custom Seed: ";
	unsigned int wprowadzonySeed = 0;
	while (true) {
		cin >> wprowadzonySeed;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wprowadzono nieprawidlowy seed! Sprobuj jeszcze raz." << endl;
			system("pause");
			ustawienia();
		}
		else if(wprowadzonySeed != 0){
			ustawienia(wprowadzonySeed);
		}
		else {
			break;
		}
	}
	cout << endl;
	cout << "Wszystko gotowe! Nacisnij dowolny przycisk aby rozpoczac gre!" << endl;
	testLosowanie(wygenerowanySeed);
}
void ustawienia(unsigned int seed) {
	wyczyscEkranANSI();
	cout << "Seed Gry: " << seed << endl;
	cout << "Jezeli chcesz zagrac razem z kims\nto podaj ten sam seed w obu klientach:\n(wpisz 0 jezeli chcesz uzyc powyzszego seeda)" << endl;
	cout << "Custom Seed: ";
	unsigned int wprowadzonySeed;
	while (true) {
		cin >> wprowadzonySeed;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wprowadzono nieprawidlowy seed! Sprobuj jeszcze raz." << endl;
			system("pause");
			ustawienia();
		}
		else if (wprowadzonySeed != 0) {
			ustawienia(wprowadzonySeed);
		}
		else {
			break;
		}
	}
	cout << endl;
	cout << "Wszystko gotowe! Nacisnij dowolny przycisk aby rozpoczac gre!" << endl;
	testLosowanie(seed);
}

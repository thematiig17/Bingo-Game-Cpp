#include <iostream>
#include "Header.h"
#include <cstdlib>
using namespace std;

/*
MENU.CPP
EKRANY I FUNKCJE MENU PRZED STARTEM GRY
*/


void menuGlowne() { //Menu glowne gry, wybor opcji

	wyczyscEkranANSI();
	cout << "###   #  #  #  ####  ####" << endl;
	cout << "#  #     ## #  #     #  #" << endl;
	cout << "###   #  # ##  # ##  #  #" << endl;
	cout << "#  #  #  #  #  #  #  #  #" << endl;
	cout << "###   #  #  #  ####  ####" << endl;
	cout << endl;
	cout << "1. Graj!" << endl;
	cout << "2. Instrukcja" << endl;
	cout << "3. Top 10 wynikow" << endl;
	cout << "4. Wyjdz" << endl;
	cout << endl;
	cout << "Twoj wybor: ";

	int wybor = 0; //wybor uzytkownika opcji w menu
	while (true) {
		cin >> wybor;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wybierz poprawna opcje!" << endl;
			system("pause");
			return;
		}
		else {
			break;
		}
	}

	switch (wybor) { //wywolanie odpowiedniej funkcji w zaleznosci od wyboru
	case 1: /*rozpoczecie gry, ustawienia*/ ustawienia(); break;
	case 2: /*instrukcja*/ instrukcja(); break;
	case 3: /*highscore*/ top10wynikow(); break;
	case 4: /*wyjscie */exit(0); break;
	default: 
		cout << "Wybierz poprawna opcje!" << endl; 
		system("pause"); 
		return;
		break;
	}
}


void instrukcja() { //instrukcja gry
	wyczyscEkranANSI();
	cout << "Tutaj bedzie instrukcja." << endl;
	system("pause");
	return;
}

int wybierzIloscPrzeciwnikow() { //wybor ilosci przeciwnikow, wykorzystywane w ustawieniach
	while (true) {
		cout << "Wybierz ilosc przeciwnikow (1-5): ";
		int iloscPrzeciwnikow = 0;
		cin >> iloscPrzeciwnikow;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wprowadzono nieprawidlowa liczbe! Sprobuj jeszcze raz." << endl;
		}
		else if (iloscPrzeciwnikow < 1 || iloscPrzeciwnikow > 5) {
			cout << "Wprowadzono liczbe spoza zakresu! Sprobuj jeszcze raz." << endl;
		}
		else {
			return iloscPrzeciwnikow;
		}
	}
}

void ustawienia() { //ustawienia gry, wybor seeda (losowany)
	wyczyscEkranANSI();
	unsigned int wygenerowanySeed = losowyUInt();
	cout << "Seed Gry: " << wygenerowanySeed << endl;
	cout << "Jezeli chcesz zagrac razem z kims\nto podaj ten sam seed w obu klientach:\n(seed musi byc wiekszy niz 10000)\n(wpisz 0 jezeli chcesz uzyc wygenerowanego seeda)" << endl;
	cout << "Custom Seed: ";
	unsigned int wprowadzonySeed = 0;
	while (true) {
		cin >> wprowadzonySeed;
		if (cin.fail() || (wprowadzonySeed < 10000 && wprowadzonySeed != 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //czysci bufor wejsciowy calkowicie ze wszystkich znakow do znaku nowej linii
			cout << "Wprowadzono nieprawidlowy seed! Sprobuj jeszcze raz." << endl;
			system("pause");
			return;
		}
		else if(wprowadzonySeed != 0){
			ustawienia(wprowadzonySeed);
			return;
		}
		else {
			break;
		}
	}
	cout << endl;
	ekranGry(wygenerowanySeed, wybierzIloscPrzeciwnikow()); //wywolanie funkcji gry
	return;
}
void ustawienia(unsigned int seed) { //ustawienia gry, wybor seeda (wybranego przez uzytkownika)
	wyczyscEkranANSI();
	cout << "Seed Gry: " << seed << endl;
	cout << "Jezeli chcesz zagrac razem z kims\nto podaj ten sam seed w obu klientach:\n(seed musi byc wiekszy niz 10000)\n(wpisz 0 jezeli chcesz uzyc powyzszego seeda)" << endl;
	cout << "Custom Seed: ";
	unsigned int wprowadzonySeed;
	while (true) {
		cin >> wprowadzonySeed;
		if (cin.fail() || (wprowadzonySeed < 10000 && wprowadzonySeed != 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wprowadzono nieprawidlowy seed! Sprobuj jeszcze raz." << endl;
			system("pause");
			return;
		}
		else if (wprowadzonySeed != 0) {
			ustawienia(wprowadzonySeed);
			return;
		}
		else {
			break;
		}
	}
	cout << endl;
	ekranGry(seed, wybierzIloscPrzeciwnikow());
	return;
}

void top10wynikow() { //wyswietlenie top 10 wynikow
	wyczyscEkranANSI();
	cout << "Top 10 wynikow:" << endl;
	string* wyniki = wczytajZPliku("wyniki.txt", "wyniki");
	for (size_t i = 0; i < 10; i++)
	{
		cout << i+1 << ".\t" << wyniki[i] << endl;
	}
	system("pause");
	return;

}
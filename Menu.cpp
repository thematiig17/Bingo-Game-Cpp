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
	cout << "3. Top 10 wynikow" << endl;
	cout << "4. Wyjdz (5 - test losowania)" << endl;
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
			return;
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
	case 3: /*highscore*/ top10wynikow();
	case 4: exit(0); break;
	case 5: testLosowanie(12345678); break;
	default: 
		cout << "Wybierz poprawna opcje!" << endl; 
		system("pause"); 
		return;
		break;
	}
}

void instrukcja() {
	wyczyscEkranANSI();
	cout << "Tutaj bedzie instrukcja." << endl;
	system("pause");
	return;
}

int wybierzIloscPrzeciwnikow() {
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

void ustawienia() {
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
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	//cout << "Wszystko gotowe! Nacisnij dowolny przycisk aby rozpoczac gre!" << endl;
	ekranGry(wygenerowanySeed, wybierzIloscPrzeciwnikow());
	return;
}
void ustawienia(unsigned int seed) {
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
	//cout << "Wszystko gotowe! Nacisnij dowolny przycisk aby rozpoczac gre!" << endl;
	ekranGry(seed, wybierzIloscPrzeciwnikow());
	return;
}

void top10wynikow() {
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
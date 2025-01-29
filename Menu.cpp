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
	cout << endl;
	cout << "1. Graj!" << endl;
	cout << "2. Instrukcja" << endl;
	cout << "3. Top 10 wyników" << endl;
	cout << "4. Wyjdź" << endl;
	cout << endl;
	cout << "Twój wybór: ";

	int wybor = 0; //wybor uzytkownika opcji w menu
	while (true) {
		cin >> wybor;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wybierz poprawną opcje!" << endl;
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
		cout << "Wybierz poprawną opcje!" << endl; 
		system("pause"); 
		return;
		break;
	}
}


void instrukcja() { //instrukcja gry
	wyczyscEkranANSI();
	cout << "# INSTRUKCJA #" << endl;
	cout << "# Cel gry: " << endl;
	cout << " - Celem gry jest zakreślenie określonego wzoru na swojej karcie \n Bingo poprzez zaznaczanie losowo wywoływanych numerów. " << endl;
	cout << " - Wzory: Linia pozioma, linia pionowa, linia ukośna (w każdej \n linii musi znajdować się 5 zakreślonych numerów żeby zgłosić Bingo." << endl;
	cout << "# Przebieg gry: " << endl;
	cout << " - Program losuje numer który zostaje ogłoszony graczom." << endl;
	cout << " - Gracz sprawdza swoją kartę. Jeśli dany numer znajduje \n się na karcie, zaznacza się go." << endl;
	cout << " - Pierwszy gracz, który zaznaczy wymagany wzór, woła \"Bingo!\"." << endl;
	cout << "# Warunki wygranej: " << endl;
	cout << " - Gracz jako pierwszy musi zaznaczyć wymagany wzór i ogłosić Bingo." << endl;
	cout << "# Warunki przegranej: " << endl;
	cout << " - Jeżeli przeciwnik jako pierwszy ogłasi Bingo, wtedy następuje koniec gry." << endl;
	cout << "# Sterowanie: " << endl;
	cout << " - Strzałki: Przesuwanie kursorem po karcie." << endl;
	cout << " - Enter: Zaznaczenie numeru (da się go tylko zaznaczyć jeżeli został wylosowany)." << endl;
	cout << " - Klawisz C: Przejście do następnego losowania." << endl;
	cout << " - Klawisz B: Ogłoś Bingo! (tylko jak faktycznie ma się Bingo)." << endl;
	cout << " - Klawisz P: Pokaż karty przeciwników." << endl;
	cout << "# Ustawienia" << endl;
	cout << " - Przed grą pojawia się ekran ustawień. W nim można dostosować dwie opcje." << endl;
	cout << " - Seed: Liczba która definiuje kolejność losowania liczb. \n Wykorzystywana w grze Multiplayer, wystarczy na dwóch klientach wpisać ten sam Seed, \n aby dwie osoby mogły rywalizować między sobą" << endl;
	cout << " - Ilość przeciwników: Dobierz ilość botów przeciwko którym chcesz się zmierzyć!\n Im więcej przeciwników, tym trudniejsza gra!" <<endl;


	cout << "# Powodzenia w grze! Pamiętaj że po wygranej możesz zapisać swój\n wynik na ścianę chwały! (Opcja 3 w Menu)" << endl;
	system("pause");
	return;
}

int wybierzIloscPrzeciwnikow() { //wybor ilosci przeciwnikow, wykorzystywane w ustawieniach
	while (true) {
		cout << "Wybierz ilość przeciwników (0-5): ";
		int iloscPrzeciwnikow = 0;
		cin >> iloscPrzeciwnikow;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wprowadzono nieprawidłową liczbe! Spróbuj jeszcze raz." << endl;
		}
		else if (iloscPrzeciwnikow < 0 || iloscPrzeciwnikow > 5) {
			cout << "Wprowadzono liczbe spoza zakresu! Spróbuj jeszcze raz." << endl;
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
	cout << "Jeżeli chcesz zagrać razem z kimś\nto podaj ten sam seed w obu klientach:\n(seed musi być większy niż 10000)\n(wpisz 0 jeżeli chcesz użyć wygenerowanego seeda)" << endl;
	cout << "Custom Seed: ";
	unsigned int wprowadzonySeed = 0;
	while (true) {
		cin >> wprowadzonySeed;
		if (cin.fail() || (wprowadzonySeed < 10000 && wprowadzonySeed != 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //czysci bufor wejsciowy calkowicie ze wszystkich znakow do znaku nowej linii
			cout << "Wprowadzono nieprawidłowy seed! Spróbuj jeszcze raz." << endl;
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
	cout << "Jeżeli chcesz zagrać razem z kimś\nto podaj ten sam seed w obu klientach:\n(seed musi być większy niż 10000)\n(wpisz 0 jezeli chcesz użyć powyzszego seeda)" << endl;
	cout << "Custom Seed: ";
	unsigned int wprowadzonySeed;
	while (true) {
		cin >> wprowadzonySeed;
		if (cin.fail() || (wprowadzonySeed < 10000 && wprowadzonySeed != 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wprowadzono nieprawidłowy seed! Spróbuj jeszcze raz." << endl;
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
	cout << "Najwyższe wyniki:" << endl << endl;
	wypiszDaneZPliku(wczytajZPliku("wyniki.txt"));
	system("pause");
	return;

}
#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
/*
OBSLUGAPLIKOW.CPP
FUNKCJE DOTYCZACE ZAPISU/ODCZYTU Z PLIKOW
*/

using namespace std;

bool porownanie(pobraneDaneZPliku a, pobraneDaneZPliku b) { //Porowananie do segregacji wedlug wynikow rosnaco
	return a.wynik < b.wynik;
}

void wypiszDaneZPliku(vector<pobraneDaneZPliku> dane) { //Wypisuje 10 lub mniej danych z pliku
	if (dane.size() > 10) {
		for (size_t i = 0; i < 10; i++)
		{
			cout << i + 1 << ". " << dane[i].nick << " " << dane[i].wynik << " losowań" << endl;
		}
	}
	else {
		for (size_t i = 0; i < dane.size(); i++)
		{
			cout << i + 1 << ". " << dane[i].nick << " " << dane[i].wynik << " losowań" << endl;
		}
	}
}


void zapiszDoPliku(string nazwaPliku, string tekst, int wynik) { //Zapisuje do pliku nowy wynik
	fstream plik;
	vector<pobraneDaneZPliku> daneZPliku = wczytajZPliku(nazwaPliku);
	plik.open(nazwaPliku, ios::out);
	if (!plik.good()) {
		cout << "Blad zapisu do pliku!" << endl;
		plik.close();
		return;
	}
	if (daneZPliku.size() == 0) {
		string linia = tekst + " " + to_string(wynik);
		plik << linia;
		plik.close();
		return;
	}
	daneZPliku.push_back({ tekst, wynik });
	sort(daneZPliku.begin(), daneZPliku.end(), porownanie);
	for (size_t i = 0; i < daneZPliku.size(); i++)
	{
		plik << daneZPliku[i].nick << " " << daneZPliku[i].wynik << endl;
	}
	plik.close();
}
vector<pobraneDaneZPliku> wczytajZPliku(string nazwaPliku) { //Wczytuje z pliku dane do vectora
	fstream plik;
	plik.open(nazwaPliku, ios::in);
	if (plik.good()){
		vector<pobraneDaneZPliku> wyniki;
		int i = 0;
		plik.seekg(0, ios::end);
		if (plik.tellg() == 0)
		{
			plik.close();
			return wyniki;
		}
		plik.seekg(0, ios::beg);
		while (!plik.eof() && i <= 10) {
			try {
				pobraneDaneZPliku aktualnaLinia;
				plik >> aktualnaLinia.nick;
				if (aktualnaLinia.nick == "") //Jezeli jest pusty to zwracamy po prostu pusty vector
				{
					plik.close();
					return wyniki;
				}
				string wynikTekst = "";
				plik >> wynikTekst;
				aktualnaLinia.wynik = stoi(wynikTekst); //Konwersja aby wylapac blad
				wyniki.push_back(aktualnaLinia);
				i++;
			}
			catch (...) { //Gdy cos jest nie tak z formatem pliku, nastepuje wyswietlenie komunikatu o uszkodzeniu pliku
				cout << "Plik jest uszkodzony. Czy zresetowac zawartosc pliku? (T/N)"<< endl; 
				char reset;
				cin >> reset;
				if (reset == 'T' || reset == 't') { //Wybor czy zresetowac zawartosc pliku.
					plik.close();
					plik.open(nazwaPliku, ios::out); /*Stworzenie pustego pliku*/
					plik << "";
					plik.close();
					cout << "Plik zostal wyczyszcony.";
					return wczytajZPliku(nazwaPliku);
				}
				else {
					cout << "Plik NIE zostal wyczyszcony." << endl;
					vector<pobraneDaneZPliku> pusty;
					plik.close();
					return pusty;
				}
				break;
			}
		}
		plik.close();
		return wyniki;
	}
	else {
		cout << "Nie udalo sie otworzyc pliku!" << endl;
	}
	vector<pobraneDaneZPliku> pusty;
	plik.close();
	return pusty;
}
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

vector<string> podzielString(string& str, char znak) {
	vector<string> podzielone;
	stringstream ss(str);
	string slowo;
	while (getline(ss, slowo, znak)) {
		podzielone.push_back(slowo);
	}
	return podzielone;
}

bool porownanie(pobraneDaneZPliku a, pobraneDaneZPliku b) {
	return a.wynik < b.wynik;
}

void wypiszDaneZPliku(vector<pobraneDaneZPliku> dane) {
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


void zapiszDoPliku(string nazwaPliku, string tekst, int wynik) {
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
vector<pobraneDaneZPliku> wczytajZPliku(string nazwaPliku) {
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
				plik >> aktualnaLinia.wynik;
				wyniki.push_back(aktualnaLinia);
				i++;
			}
			catch (int e) {
				cout << "Plik jest uszkodzony. Czy zresetowac zawartosc pliku? (T/N)"<< endl; /*Stworzenie pustego pliku*/
				char reset;
				cin >> reset;
				if (reset == 'T' || reset == 't') {
					plik.close();
					plik.open(nazwaPliku, ios::out);
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
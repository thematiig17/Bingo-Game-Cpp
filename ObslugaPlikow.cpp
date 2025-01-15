#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>

using namespace std;

void zapiszDoPliku(string nazwaPliku, string tekst, bool nadpisz) {
	fstream plik;
	if (nadpisz)
	{
		plik.open(nazwaPliku, ios::out);
	}
	else {
		plik.open(nazwaPliku, ios::out | ios::app);
		if (plik.good()) {
			plik << endl;
		}
	}
	if (plik.good()) {
		plik << tekst;
	}
	plik.close();
}
string* wczytajZPliku(string nazwaPliku, string tekst) {
	fstream plik;
	plik.open(nazwaPliku, ios::in);
	if (plik.good()){
		string* tablica = new string[100];
		int i = 0;
		while (!plik.eof()) {
			getline(plik, tablica[i]);
			i++;
		}
		return tablica;
		delete tablica;
	}
	else {
		cout << "Nie udalo sie otworzyc pliku!" << endl;
	}


}
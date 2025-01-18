#pragma once
#include <string>

/*Menu.cpp*/
void menuGlowne();
void instrukcja();
void ustawienia(unsigned int);
void ustawienia();
void top10wynikow();

/*Funkcje.cpp*/
void wyczyscEkranWindows();
void wyczyscEkranANSI();
void napiszDuzaLiczbe(int);
void enableVirtualTerminalProcessing();
void ustawPozycjeKursora(int x, int y);

/*Random.cpp*/
int losowaSeed(unsigned int);
unsigned int losowyUInt();

/*Gra.cpp*/
struct aktualnaKarta;
void testLosowanie(unsigned int);
void ekranGry(int);
void kartaBingoAmerykanskie(aktualnaKarta);

/*ObslugaPlikow.cpp*/
void zapiszDoPliku(std::string, std::string, bool);
std::string* wczytajZPliku(std::string, std::string);









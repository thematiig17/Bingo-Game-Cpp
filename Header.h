#pragma once
#include <string>

void menuGlowne();
void instrukcja();
void wyczyscEkranWindows();
void wyczyscEkranANSI();
int losowaSeed(unsigned int);
void testLosowanie(unsigned int);
unsigned int losowyUInt();
int sprawdzWejscie();
void ustawienia(unsigned int);
void ustawienia();
void zapiszDoPliku(std::string, std::string, bool);
std::string* wczytajZPliku(std::string, std::string);
void top10wynikow();
void ekranGry(int);
void napiszDuzaLiczbe(int);
void ustawPozycjeKursora(int x, int y);
void ustawRozmiarKonsoli(int, int);
void enableVirtualTerminalProcessing();
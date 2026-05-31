#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H
#include "santraukos.h"

string failo_pasirinkimas();
void zodziu_skaiciavimas(const string pavadinimas, map <wstring, int> &kiekis);
wstring zodzio_sutvarkymas(const wstring &zodis);
void saraso_isvedimas(map <wstring, int> &kiekis, string pav);
void cross_reference(const string pavadinimas);
void lenteles_isvedimas(map <wstring, int> &kiekis, map<wstring, set<int>> eilutes,string pav);

#endif
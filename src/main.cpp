#include "funkcijos.h"
#include "santraukos.h"

int main()
{
    std::locale::global(std::locale("lt_LT.UTF-8"));
    std::wcout.imbue(std::locale());
    std::wcin.imbue(std::locale());

    string failas = failo_pasirinkimas();
    map <wstring, int> kiekis;
    zodziu_skaiciavimas(failas, kiekis);
    saraso_isvedimas(kiekis, "zodziu_pasikartojimai.txt");
    cross_reference(failas);
    string url_failas = failo_pasirinkimas();
    url_aptikimas(url_failas);
}   
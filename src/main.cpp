#include "funkcijos.h"
#include "santraukos.h"

int main()
{
    std::locale::global(std::locale("lt_LT.UTF-8"));
    std::wcout.imbue(std::locale());
    std::wcin.imbue(std::locale());

    string failas = failo_pasirinkimas();
    zodziu_skaiciavimas(failas);
}   
#include "funkcijos.h"
#include "santraukos.h"

//  patikrinti ^

string failo_pasirinkimas()
{
    string pavadinimas;
    std:: ifstream fd;
    while (true)
    {
        #ifdef _WIN32
            system("dir *.txt /B"); 
        #else
            system("ls *.txt"); 
        #endif

            cout << "Ivesk failo pavadinima: ";
            cin >> pavadinimas;

        try
        {
            fd.open(pavadinimas);
            if (!fd)
            {
                    throw std::runtime_error("Klaida: nepavyko atidaryti failo!");
            }
            break;
        }
        catch (const std::runtime_error &e)
	    {
		    std::cerr << e.what() << endl;
            fd.clear();
	    }
    }
    return pavadinimas;
}

void zodziu_skaiciavimas(const string pavadinimas, map <wstring, int> &kiekis)
{
    wifstream failas (pavadinimas);
    if (!failas)
    {
        throw std::ios_base::failure("Klaida: nepavyko atidaryti failo!");
        return;
    }

    failas.imbue(std::locale("lt_LT.UTF-8"));

    wstringstream buferis;
	buferis << failas.rdbuf();
	failas.close();

    wstring zodis;
    while  (buferis >> zodis)
    {
        wstring sutvarkytas_zod = zodzio_sutvarkymas(zodis);
        if (!sutvarkytas_zod.empty())
        {
            kiekis[sutvarkytas_zod]++;
        }
    }
}

wstring zodzio_sutvarkymas(const wstring &zodis)
{
    wstring naujas;
    for (wchar_t c : zodis)
    {
        if (iswalpha(c))
        {
            naujas += towlower(c);
        }
    }

    return naujas;
}

void saraso_isvedimas(map <wstring, int> &kiekis)
{
    wofstream rezultatai("zodziu_pasikartojimai.txt");
    rezultatai.imbue(std::locale("lt_LT.UTF-8"));

    for (const auto &x : kiekis)
    {
        if (x.second > 1)
		{
			rezultatai << x.first << ": " << x.second << endl;
		}
    }

    rezultatai.close();
}
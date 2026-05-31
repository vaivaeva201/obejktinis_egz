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

void failo_nuskaitymas(const string pavadinimas)
{
    wifstream failas (pavadinimas);
    if (!failas)
    {
        throw std::ios_base::failure("Klaida: nepavyko atidaryti failo!");
        return;
    }

    wstringstream buferis;
	buferis << failas.rdbuf();
	failas.close();

    map <wstring, int> kiekis;
    wstring zodis;
    

}
#ifndef JEDNOREKIBANDYTA_H
#define JEDNOREKIBANDYTA_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Gracz.h"

using namespace std;

class JednorekiBandyta : public Gracz
{
public:
    JednorekiBandyta()
    {
        liczba1 = 0;
        liczba2 = 0;
        liczba3 = 0;
    }
    void WylosujLiczby()
    {
        srand(time(NULL));
        liczba1 = rand()%10;
        liczba2 = rand()%10;
        liczba3 = rand()%10;
    }
    int PokazLiczbe1()
    {
        return liczba1;
    }
    int PokazLiczbe2()
    {
        return liczba2;
    }
    int PokazLiczbe3()
    {
        return liczba3;
    }
    bool CzyWygrales(double &pieniadze, double &zaklad, double &wygrana)
    {
        if(liczba1 == liczba2 && liczba2 == liczba3)
        {
            cout << "\nGratulacje!" << endl;
            PomnozWygrana(pieniadze, zaklad, wygrana);
            cout << "\nTwoja wygrana: " << zaklad << endl;
            return 1;
        }
        cout << "\nPrzegrana! Moze nastepnym razem..." << endl;
        return 0;
    }
private:
    int liczba1;
    int liczba2;
    int liczba3;
};
#endif

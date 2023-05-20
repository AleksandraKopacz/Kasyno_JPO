#ifndef RULETKA_H
#define RULETKA_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Gracz.h"

using namespace std;

class Ruletka : public Gracz
{
public:
    Ruletka()
    {
        ruletka = 0;
        postawionyNumer = 0;
    }
    bool losuj(double &pieniadze, double &zaklad, double &wygrana)
    {
        srand(time(NULL));
        ruletka = rand()%37;
        cout << "\nWybierz numer: ";
        do
        {
            cin.clear();
            cin.ignore();
            cin >> postawionyNumer;
            cin.clear();
            cin.ignore();
        }
        while (cin.fail() || postawionyNumer > 36 || postawionyNumer < 0);
        cout << "\nWylosowany numer: " << ruletka << endl;
        if(ruletka == postawionyNumer)
        {
            cout << "\nGratulacje!" << endl;
            PomnozWygrana(pieniadze, zaklad, wygrana);
            return 1;
        }
        else
        {
            cout << "\nPrzegrana! Moze nastepnym razem..." << endl;
            return 0;
        }
    }
private:
    int postawionyNumer;
    int ruletka;
};
#endif

#ifndef GRACZ_H
#define GRACZ_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Gracz
{
public:
    double WylosujPieniadze(double pieniadze)
    {
        srand(time(NULL));
        pieniadze = (rand()%1990)+10;
        return pieniadze;
    }
    double PostawPieniadze(double &pieniadze, double &zaklad, double &wygrana)
    {
        do
        {
            cout << "\nPostaw pieniadze: ";
            cin >> zaklad;
            cin.clear();
            cin.ignore();
        }
        while(cin.fail() || zaklad > pieniadze || zaklad <= 0);
        pieniadze -= zaklad;
        return zaklad;
    }
    void PozostalePieniadze(double pieniadze)
    {
        cout << "\nPozostale pieniadze: " << pieniadze << endl;
    }
    void TwojaWygrana(double wygrana)
    {
        cout << "\nTwoja wygrana: " << wygrana << endl;
    }
    double PomnozWygrana(double &pieniadze, double &zaklad, double &wygrana)
    {
        zaklad *= 1.10;
        wygrana += zaklad;
        pieniadze += zaklad;
        PozostalePieniadze(pieniadze);
        return pieniadze;
    }
    double ZwrocPieniadze(double &pieniadze, double &zaklad)
    {
        pieniadze += zaklad;
        return pieniadze;
    }
};
#endif

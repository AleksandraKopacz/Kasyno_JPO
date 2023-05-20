#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Gracz.h"

using namespace std;

class Blackjack : public Gracz
{
public:
    Blackjack()
    {
        karta1Gracz = 0;
        karta2Gracz = 0;
        karta1Komputer = 0;
        karta2Komputer = 0;
        dodatkowaKarta = 0;
        decyzja = 0;
    }
    bool WylosujKarty(double &pieniadze, double &zaklad, double &wygrana)
    {
        srand(time(NULL));
        karta1Komputer = (rand()%10)+2;
        karta2Komputer = (rand()%10)+2;
        karta1Gracz = (rand()%10)+2;
        karta2Gracz = (rand()%10)+2;
        sumaGracz = karta1Gracz + karta2Gracz;
        sumaKomputer = karta1Komputer + karta2Komputer;
        cout << "Karta krupiera: " << karta1Komputer << endl;
        cout << "Twoje karty: " << karta1Gracz << ", " << karta2Gracz << "\nSuma twoich kart: " << sumaGracz << endl;
        if (sumaGracz > 21)
        {
            cout << "\nSuma kart krupiera: " << sumaKomputer << "\nSuma twoich kart: " << sumaGracz << endl;
            cout << "\nPrzegrana! Moze nastepnym razem..." << endl;
            return 0;
        }
        else if (sumaGracz == 21)
        {
            KolejKrupiera();
            Porownaj(pieniadze, zaklad, wygrana);
        }
        else
        {
            do
            {
                cout << "\nCo chcesz zrobic?\n1. Wyciagnij kolejna karte\n2. Odkryj karty" << endl;
                cin >> decyzja;
                cin.clear();
                cin.ignore();
            }
            while(cin.fail() || (decyzja != 1 && decyzja != 2));
            if(decyzja == 1)
            {
                WylosujDodatkowaKarte();
                cout << "\nTwoja dodatkowa karta: " << dodatkowaKarta << endl;
                sumaGracz += dodatkowaKarta;
                if (sumaGracz > 21)
                {
                    cout << "\nSuma kart krupiera: " << sumaKomputer << "\nSuma twoich kart: " << sumaGracz << endl;
                    cout << "Przegrana! Moze nastepnym razem..." << endl;
                    return 0;
                }
            }
            KolejKrupiera();
            Porownaj(pieniadze, zaklad, wygrana);
        }
        return 1;
    }
private:
    void KolejKrupiera()
    {
        cout << "\nKarty krupiera: " << karta1Komputer << ", " << karta2Komputer << endl;
        if(sumaKomputer <= 16)
        {
            WylosujDodatkowaKarte();
            cout << "Dodatkowa karta dla krupiera: " << dodatkowaKarta << endl;
            sumaKomputer += dodatkowaKarta;
        }
    }
    int WylosujDodatkowaKarte()
    {
        dodatkowaKarta = (rand()%10)+2;
        return dodatkowaKarta;
    }
    bool Porownaj(double &pieniadze, double &zaklad, double &wygrana)
    {
        if(sumaKomputer > 21)
        {
            cout << "\nSuma kart krupiera: " << sumaKomputer << "\nSuma twoich kart: " << sumaGracz << endl;
            cout << "\nGratulacje!" << endl;
            PomnozWygrana(pieniadze, zaklad, wygrana);
            return 1;
        }
        else if(sumaKomputer == sumaGracz)
        {
            cout << "\nSuma kart krupiera: " << sumaKomputer << "\nSuma twoich kart: " << sumaGracz << endl;
            cout << "\nRemis! Twoja pieniadze zostana zwrocone" << endl;
            ZwrocPieniadze(pieniadze, zaklad);
            return 0;
        }
        else if(sumaKomputer > sumaGracz)
        {
            cout << "\nSuma kart krupiera: " << sumaKomputer << "\nSuma twoich kart: " << sumaGracz << endl;
            cout << "\nPrzegrana! Moze nastepnym razem..." << endl;
            return 0;
        }
        else
        {
            cout << "\nSuma kart krupiera: " << sumaKomputer << "\nSuma twoich kart: " << sumaGracz << endl;
            cout << "\nGratulacje!" << endl;
            PomnozWygrana(pieniadze, zaklad, wygrana);
            return 1;
        }
    }
    int karta1Gracz;
    int karta2Gracz;
    int karta1Komputer;
    int karta2Komputer;
    int dodatkowaKarta;
    int sumaGracz;
    int sumaKomputer;
    int decyzja;
};
#endif

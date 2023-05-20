#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

#include "Gracz.h"
#include "JednorekiBandyta.h"
#include "Blackjack.h"
#include "Ruletka.h"

using namespace std;

void TopGracze(string imie, double wygrana)
{
    string imiona[100];
    double wygrane[100];
    ifstream ranking;
    ofstream zapisz;
    string linia;
    int indeks;

    ranking.open("top100.txt");
    bool rankingPusty = ranking.peek() == EOF;
    if(rankingPusty)
        indeks = 0;
    else
    {
        do
        {
            getline(ranking, linia, ' ');
            if(!(linia.find_first_not_of(' ') != std::string::npos))
                break;
            indeks = stoi(linia);
            getline(ranking, linia, ' ');
            imiona[indeks-1] = linia;
            getline(ranking, linia, ' ');
            wygrane[indeks-1] = stod(linia);
        }
        while(ranking.good());
    }
    ranking.close();

    if(wygrana > 0)
    {
        for(int i = indeks; i < 100; i++)
        {
            imiona[i] = "";
            wygrane[i] = 0;
        }

        if(indeks == 100)
            indeks = 99;

        for(int i = 0; i <= indeks; i++)
        {
            //jeœli miejsce jest puste - wpisz do rankingu
            if(wygrane[i] == 0)
            {
                imiona[i] = imie;
                wygrane[i] = wygrana;
                break;
            }

            //jeœli masz wynik lepszy od poprzedniego gracza - przesuñ wszystkich graczy o 1 miejsce i zapisz do rankingu
            else if(wygrana > wygrane[i])
            {
                for(int j = 99; j > i; j--)
                {
                    imiona[j] = imiona[j-1];
                    wygrane[j] = wygrane[j-1];
                }
                imiona[i] = imie;
                wygrane[i] = wygrana;
                break;
            }
        }

        //zapisz ranking do pliku
        zapisz.open("top100.txt");
        for(int i = 0; i <= indeks; i++)
            zapisz << i+1 << " " << imiona[i] << " " << wygrane[i] << " ";
        zapisz.close();
        indeks++;
    }

    cout << "TOP 100" << endl;
    for (int i = 0; i < indeks; i++)
    {
        cout << i+1 << ". " << imiona[i] << " " << wygrane[i] << " zl" << endl;
    }
}

int main()
{
    Gracz g;
    JednorekiBandyta jb;
    Blackjack b;
    Ruletka r;
    double pieniadze = g.WylosujPieniadze(pieniadze);
    double zaklad, wygrana = 0;
    int wybierz;
    string imie;
    cout << "Podaj swoje imie: ";
    getline(cin, imie);
    do
    {
        do
        {
            cout << "\nWitamy w kasynie! Wybierz gre:\n1. Jednoreki Bandyta\n2. Blackjack\n3. Ruletka\n4. Wyjdz" << endl;
            cin >> wybierz;
            cin.clear();
            cin.ignore();
        }
        while (cin.fail() || (wybierz != 1 && wybierz != 2 && wybierz != 3 && wybierz != 4));
        cout << "\nTwoje pieniadze: " << pieniadze << endl;
        switch(wybierz)
        {
        case 1:
            cout << "\nJEDNOREKI BANDYTA" << endl;
            zaklad = jb.PostawPieniadze(pieniadze, zaklad, wygrana);
            jb.WylosujLiczby();
            cout << "\n" << jb.PokazLiczbe1() << "-" << jb.PokazLiczbe2() << "-" << jb.PokazLiczbe3() << endl;
            jb.CzyWygrales(pieniadze, zaklad, wygrana);
            break;
        case 2:
            cout << "\nBLACKJACK" << endl;
            zaklad = b.PostawPieniadze(pieniadze, zaklad, wygrana);
            b.WylosujKarty(pieniadze, zaklad, wygrana);
            break;
        case 3:
            cout << "\nRULETKA" << endl;
            zaklad = r.PostawPieniadze(pieniadze, zaklad, wygrana);
            r.losuj(pieniadze, zaklad, wygrana);
            break;
        }
        g.TwojaWygrana(wygrana);
    }
    while (pieniadze != 0 && wybierz != 4);
    TopGracze(imie, wygrana);
    return 0;
}

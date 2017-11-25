#ifndef STATY_H
#define STATY_H

#include "Wyniki.h"

class Staty
{
    private:
        Wyniki statystyki[10];
        //tabela wyników
        char *nazwa_pliku = "Wyniki.txt";
        //nazwa pliku z wynikami

        void sortowanie_starych();
        //sortuje dane, które s¹ zapisane
        void sortowanie_nowych(string nazwa_gracza , int punkty);
        //sortuje dane, które s¹ nowe
        //string nazwa_gracza->nazwa gracza do zapisu
        //int punkty->punkty gracza do zapisu
        bool zapis_wynikow();
        //zapis do pliku
        //false-> b³¹d odczytu z pliku
        //true-> prawid³owe wykonanie
        bool odczyt_wynikow();
        //odczyt z pliku
        //false-> b³¹d odczytu z pliku
        //true-> prawid³owe wykonanie
    public:
        void get_wyniki();
        //tylko konsola wyswietla wyniki
        Staty();
        //konstruktor czyca yniki z pliku
        void dodaj_wynik(string nazwa_gracza , int punkty);
        //dodaje nowy wynik
        //string nazwa_gracza->nazwa gracza do zapisu
        //int punkty->punkty gracza do zapisu
        ~Staty();
        //destruktoy zapisuje wynik w pliku
        string get_nazwa(int i);
        //zwraca nazwe
        //i->liczba iterujaca
        int get_pozycja(int i);
        //zwraca pozycje
        //i->liczba iterujaca
        int get_punkty(int i);
        //zwraca punkty
        //i->liczba iterujaca
};

#endif // STATY_H

#ifndef STATY_H
#define STATY_H

#include "Wyniki.h"

class Staty
{
    private:
        Wyniki statystyki[10];
        //tabela wynik�w
        char *nazwa_pliku = "Wyniki.txt";
        //nazwa pliku z wynikami

        void sortowanie_starych();
        //sortuje dane, kt�re s� zapisane
        void sortowanie_nowych(string nazwa_gracza , int punkty);
        //sortuje dane, kt�re s� nowe
        //string nazwa_gracza->nazwa gracza do zapisu
        //int punkty->punkty gracza do zapisu
        bool zapis_wynikow();
        //zapis do pliku
        //false-> b��d odczytu z pliku
        //true-> prawid�owe wykonanie
        bool odczyt_wynikow();
        //odczyt z pliku
        //false-> b��d odczytu z pliku
        //true-> prawid�owe wykonanie
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

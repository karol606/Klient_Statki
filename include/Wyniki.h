#ifndef WYNIKI_H
#define WYNIKI_H
using namespace std;
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

class Wyniki{
    public:
        void set_wynik(Wyniki pom);
        //kopiuje wynik z pom do nowego obiektu
        //Wyniki pom->pojedynczy wynik
        void set_wynik(int pozycja, int punkty, string nazwa);
        //ustawie wynik
        //int pozycja->pozycja gracza
        //int punkty->punkty gracza
        //string nazwa->nazwa gracza
        void set_pozycja(int pozycja);
        //zapisuje pozycje
        void set_punkty(int punkty);
        //zapisuje punkty
        void set_nazwa(string nazwa);
        //zapisuje nazwa
        int get_punkty();
        //zapisuje punkty
        //int punkty->punkty gracza
        int get_pozycja();
        //zapisuje pozycje
        //int pozycja->pozycja gracza
        string get_nazwa();
        //zapisuje nazwa
        //string nazwa->nazwa gracza
    private:
        string nazwa;
        int punkty;
        int pozycja;

};

#endif // WYNIKI_H

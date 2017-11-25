#ifndef GRA_H
#define GRA_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Gra{//gra z PC
    private:
        int planszaS [10][10];
            //plansza ze zmianami dokonanymi przez gracz lub PC
        int plansza [10][10];
            //plansza ze statkami i zmianami dokonanymi przez gracz lub PC
        bool sprawdzenie_pola(int x, int y, int o, int statek);
            //sprawdza czy pole jest zajête
            //sprawdza czy nie jest poza plansz¹
            //false->pole zajete lub poza plansz¹
            //true->pole wolne i w panszy
        int losuj_kord(int liczba);
            //losuje kord pola PC
            //int liczba->podzielnik modulo
            //kord->wylosowana liczba
        void ustawienie_pola(int x,int y,int o,int statek);
            //ustawia jedno pole
            //int x->na osi OX
            //int y->na osi OY
            //int o->orjêtacja piom, poziom
            //int statek->wielkoœæ statku
    public:
        Gra();
            //konstruktor czyszcz¹cy plansze
        int get_plansza();
            //zwraca tablice 10x10 plansze ustawionych statków gracza
        int get_planszaS();
            //zwraca tablice 10x10 plansze strzałów gracza
        void wyswietl_plansze(Gra graPC);
            //tylko konsola wyswietla plansze
            //Gra graPC->plansza trafieñ gracza
        int ustawienie(int x, int y, int o, int statek);
            //ustawienie statku gracz
            //zwraca wielkosc statku lub sielkosc statku powiekszon¹ o 1
            //int x->na osi OX
            //int y->na osi OY
            //int o->orjêtacja piom, poziom
            //int statek->wielkoœæ statku
        void losowanie();
            //ustawienie statku PC
        int zmiana(int x, int y);
            //zmiena stan planszy
            //ustawia  2 trafiony
            //3 trafione puste pole
            //liczba zwracana dodawana jest do ilosc punktow
            //-1 powraca do strza³u
            //int x->na osi OX
            //int y->na osi OY
            //zwraca -1->gdy trafimy to samo pole
            //zwraca 1->gdy trafimy pole ze statkiem
            //zwraca 0->gdy trafimy pole puste
        int los_strzal();
            //strzelanie PC
            //zwraca 1->gdy trafimy pole ze statkiem
            //zwraca 0->gdy trafimy pole puste
};

#endif // GRA_H

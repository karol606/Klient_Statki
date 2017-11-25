#include "Wyniki.h"
    void Wyniki::set_wynik(Wyniki pom){
        //kopiuje wynik z pom do nowego obiektu
        //Wyniki pom->pojedynczy wynik
        punkty = pom.punkty;
        nazwa = pom.nazwa;
        pozycja =  pom.pozycja;
    }
    void Wyniki::set_wynik(int pozycja, int punkty, string nazwa){
        //ustawie wynik
        //int pozycja->pozycja gracza
        //int punkty->punkty gracza
        //string nazwa->nazwa gracza
        this->punkty = punkty;
        this->nazwa = nazwa;
        this->pozycja =  pozycja;
    }
    string Wyniki::get_nazwa(){
        //zwraca nazwe
        return nazwa;
    }
    int Wyniki::get_punkty(){
        //zwraca punkty
        return punkty;
    }
    int Wyniki::get_pozycja(){
        //zwraca pozycje
        return pozycja;
    }
    void Wyniki::set_pozycja(int pozycja){
        //zapisuje pozycje
        //int pozycja->pozycja gracza
        this->pozycja = pozycja;
    }
    void Wyniki::set_punkty(int punkty){
        //zapisuje punkty
        //int punkty->punkty gracza
        this->punkty = punkty;
    }
    void Wyniki::set_nazwa(string nazwa){
        //zapisuje nazwa
        //string nazwa->nazwa gracza
        this->nazwa = nazwa;
    }

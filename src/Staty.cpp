#include "Staty.h"

    Staty::Staty(){
        //konstruktor czyca yniki z pliku
        if(odczyt_wynikow() == false){
            //tu komunikat o b³êdzie
        }
    }

    Staty::~Staty(){
        //destruktoy zapisuje wynik w pliku
        if(zapis_wynikow() == false){
            //tu komunikat o b³edzie
        }
    }

    void Staty::get_wyniki(){
        //tylko konsola wyswietla wyniki
        for(int i = 0; i < 10; i++)
            cout<< statystyki[i].get_pozycja() << "\t"<< statystyki[i].get_nazwa() << "\t" << statystyki[i].get_punkty()<<endl;
    }

    void Staty::dodaj_wynik(string nazwa_gracza , int punkty){
        //dodaje nowy wynik
        //string nazwa_gracza->nazwa gracza do zapisu
        //int punkty->punkty gracza do zapisu
        sortowanie_nowych(nazwa_gracza, punkty);
    }


    bool Staty::zapis_wynikow(){
        //zapis do pliku
        //false-> b³¹d odczytu z pliku
        //true-> prawid³owe wykonanie
        fstream plik;
        plik.open( nazwa_pliku, ios::in | ios::out );
        if( plik.good() == true ){
            for(int i = 0; i < 10; i++){
                plik<< statystyki[i].get_pozycja() << " "<< statystyki[i].get_nazwa() << " " << statystyki[i].get_punkty()<<endl;
            }
            plik.close();
            return true;
        }else
            return false;
    }

    bool Staty::odczyt_wynikow(){
        //odczyt z pliku
        //false-> b³¹d odczytu z pliku
        //true-> prawid³owe wykonanie
        fstream plik;
        plik.open( nazwa_pliku, ios::in | ios::out );
        if( plik.good() == true ){
            string nazwa;
            int punkty,pozycja;
            for(int i = 0; i < 10; i++){
                plik >> pozycja >> nazwa >> punkty;
                statystyki[i].set_wynik(pozycja, punkty, nazwa);
            }
            plik.close();
            sortowanie_starych();
            return true;
        }else
            return false;
    }

    void Staty::sortowanie_starych(){
        //sortuje dane, które s¹ zapisane
        for(int j = 0; j < 10; j++){
            for(int i = 0; i < 10 - 1; i++){
                if(statystyki[i].get_punkty() < statystyki[i + 1].get_punkty()){
                    Wyniki pom;
                    pom.set_wynik(statystyki[i]);
                    statystyki[i].set_wynik(statystyki[i + 1]);
                    statystyki[i + 1].set_wynik(pom);
                }
            }
            statystyki[j].set_pozycja(j + 1);
        }
    }

    void Staty::sortowanie_nowych(string nazwa_gracza , int punkty){
        //sortuje dane, które s¹ nowe
        //string nazwa_gracza->nazwa gracza do zapisu
        //int punkty->punkty gracza do zapisu
        int pozycja, mini = 10;
        for(int i = 0; i < 10; i++){
            if(statystyki[i].get_punkty() < punkty){
                mini-=1;
            }
            for(int i = mini; i < 10; i++){
                if(statystyki[i].get_punkty() <= punkty){
                    Wyniki pom;
                    pozycja = statystyki[i].get_pozycja();
                    pom.set_wynik(statystyki[i]);
                    statystyki[i].set_wynik(pozycja,punkty,nazwa_gracza);
                    punkty = pom.get_punkty();
                    nazwa_gracza = pom.get_nazwa();
                    pozycja = pom.get_pozycja();
                }
            }
        }
    }

    string Staty::get_nazwa(int i){
        //zwraca nazwe
        //i->liczba iterujaca
        return statystyki[i].get_nazwa();
    }
    int Staty::get_pozycja(int i){
        //zwraca pozycje
        //i->liczba iterujaca
        return statystyki[i].get_pozycja();
    }
    int Staty::get_punkty(int i){
        //zwraca punkty
        //i->liczba iterujaca
        return statystyki[i].get_punkty();
    }

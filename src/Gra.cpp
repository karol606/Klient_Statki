#include "Gra.h"

    bool Gra::sprawdzenie_pola(int x, int y, int o, int statek){
        //sprawdza czy pole jest zajête
        //sprawdza czy nie jest poza plansz¹
        //false->pole zajete lub poza plansz¹
        //true->pole wolne i w panszy
        if(o == 1){
            for(int i = 0; i <= statek; i++){
                if((y+i) == 10){
                    return false;
                }
                if(plansza[y+i][x] == 1){
                    return false;
                }
            }
        }else if(o == 2){
            for(int i = 0; i <= statek; i++){
                if((x+i) == 10){
                    return false;
                }
                if(plansza[y][x+i] == 1){
                    return false;
                }
               }
        }
        return true;
    }
    int Gra::losuj_kord(int liczba){
        //losuje kord pola PC
        //int liczba->podzielnik modulo
        //kord->wylosowana liczba
        int kord = rand() % liczba + 1;
        if(kord < 0)
            kord*=(-1);
        return kord;
    }
    void Gra::ustawienie_pola(int x,int y,int o,int statek){
        //ustawia jedno pole
        //int x->na osi OX
        //int y->na osi OY
        //int o->orjêtacja piom, poziom
        //int statek->wielkoœæ statku
        if(o == 1){
            for(int i = 0; i < statek; i++){
                plansza[y+i][x] = 1;
            }
        }else if(o == 2){
            for(int i = 0; i < statek; i++){
                plansza[y][x+i] = 1;
            }
        }
    }

    Gra::Gra(){
        //konstruktor czyszcz¹cy plansze
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                plansza[i][j] = 0;
                planszaS[i][j] = 0;
            }
        }
    }

    void Gra::wyswietl_plansze(Gra graPC){
        //tylko konsola wyswietla plansze
        //Gra graPC->plansza trafieñ gracza
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cout<<plansza[i][j]<<" ";
            }
            cout <<"\t";
            for(int j = 0; j < 10; j++){
                cout<<graPC.planszaS[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int Gra::get_plansza(){
        //zwraca tablice 10x10 plansze ustawionych statków gracza
        return plansza[10][10];
    }
    int Gra::get_planszaS(){
        //zwraca tablice 10x10 plansze strzałów gracza
        return planszaS[10][10];
    }
    int Gra::ustawienie(int x, int y, int o, int statek){
        //ustawienie statku gracz
        //zwraca wielkosc statku lub sielkosc statku powiekszon¹ o 1
        //int x->na osi OX
        //int y->na osi OY
        //int o->orjêtacja piom, poziom
        //int statek->wielkoœæ statku
        if(sprawdzenie_pola(x, y, o, statek)){
            ustawienie_pola(x,y,o,statek);
            return ++statek;
        }else{
            return statek;
        }

    }

    void Gra::losowanie(){
        //ustawienie statku PC
        srand(time(NULL));
        int y,x,o;
        do{
            x = losuj_kord(9);
            y = losuj_kord(9);
            o = losuj_kord(2);
        }while(!sprawdzenie_pola( x,  y, o, 3));
        ustawienie_pola(x , y, o, 3);
        for(int statek = 2; statek < 6; statek++){
            do{
                x = losuj_kord(9);
                y = losuj_kord(9);
                o = losuj_kord(2);
            }while(!sprawdzenie_pola( x,  y, o, statek));
            ustawienie_pola(x,y,o,statek);
        }
    }

    int Gra::zmiana(int x, int y){
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
        if(plansza[y-1][x-1] != 1 || plansza[y-1][x-1] != 0){
            if(plansza[y-1][x-1] == 1){
                plansza[y-1][x-1] = 2;
                planszaS[y-1][x-1] = 2;
                return 1;
            }else if(plansza[y-1][x-1] == 0){
                plansza[y-1][x-1] = 3;
                planszaS[y-1][x-1] = 3;

                return 0;
            }
        }else{
            return -1;
        }

    }

    int Gra::los_strzal(){
        //strzelanie PC
        //zwraca 1->gdy trafimy pole ze statkiem
        //zwraca 0->gdy trafimy pole puste
        bool kon = true;
        while(kon){
            int x = losuj_kord(9);
            int y = losuj_kord(9);
            int i = zmiana(x,y);
            if(i == 1){
                kon = false;
                return 1;
            }else if(i == 0){
                kon = false;
                return 0;
            }
        }
    }


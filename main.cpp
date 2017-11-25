#include <iostream>
#include <string>
#include <conio.h>
#include <winsock2.h>
#include "Staty.h"
#include "Gra.h"

using namespace std;

class Komunikacja{//Komuniakcja z serverem

};


int graZpc = 1, STATYSTYKI = 3, gra_multi = 2, koniec = 0;
int main(){
    int klient = -1;

    while(klient != 0){
        do{
            cout << "Wejscie klienta" << endl;
            cout << "1.Gra" << endl;
            cout << "2.Gra multi" << endl;
            cout << "3.Statystyki" << endl;
            cout << "0.KONIEC" << endl;
            cin >> klient;
         }while(klient != 1 && klient != 2 && klient != 3 && klient != 0);
        if(klient == graZpc){//gra z PC -> zrobić statystyki
                int x = -1,y = -1,o = -1,statek = 2;
                Gra g , gPC;
                string nazwa_gracza;
                cout << "Gra" << endl;
                cout << "Nazwa gracza: ";
                cin >> nazwa_gracza;
                while(x != 11 && statek != 6){
                    x = -1,y = -1,o = -1;
                    g.wyswietl_plansze(gPC);
                    while(o < 1 || o > 2){
                        cout <<"1.Pion: "<<endl;
                        cout <<"2.Poziom: "<<endl;
                        cout <<"Orjentacja: ";
                        cin >> o;
                    }
                    while(x < 1 || x > 10){
                        cout <<"Podaj x: ";
                        cin >> x;
                    }
                    while(y < 1 || y > 10){
                        cout <<"Podaj y: ";
                        cin >> y;
                    }
                    statek = g.ustawienie(x-1,y-1,o,statek);
                    system("cls");
                }
                gPC.losowanie();
                int punkty = 0,punktyPC = 0;
                while(punkty != 1 && punktyPC != 17){
                    x = -1,y = -1,o = -1;
                    g.wyswietl_plansze(gPC);
                    cout<<endl;
                    while(x < 1 || x > 10){
                        cout <<"Podaj x: ";
                        cin >> x;
                    }
                    while(y < 1 || y > 10){
                        cout <<"Podaj y: ";
                        cin >> y;
                    }

                    int i = gPC.zmiana(x,y);
                    if(i == 1){
                        ++punkty;
                        punktyPC += g.los_strzal();
                    }else if(i == 0){
                        punktyPC += g.los_strzal();
                    }
                    system("cls");
                }
                if(punktyPC < punkty){
                    Staty s;
                    s.dodaj_wynik(nazwa_gracza,punkty);
                    cout << "WYGRANA!!" << endl;
                }else{
                    cout << "PRZEGRANA!!" << endl;
                }
                system("cls");
        }
        else if(klient == gra_multi){
            cout << "Gra multi" << endl;
            int x = -1,y = -1,o = -1,statek = 2;
                Gra g;
                string nazwa_gracza;
                cout << "Gra" << endl;
                cout << "Nazwa gracza: ";
                cin >> nazwa_gracza;
                //połączenie
                //pobranie tarczy ostrzału
                while(x != 11 && statek != 6){
                    x = -1,y = -1,o = -1;
                    //g.wyswietl_plansze(gPC);
                    while(o < 1 || o > 2){
                        cout <<"1.Pion: "<<endl;
                        cout <<"2.Poziom: "<<endl;
                        cout <<"Orjentacja: ";
                        cin >> o;
                    }
                    while(x < 1 || x > 10){
                        cout <<"Podaj x: ";
                        cin >> x;
                    }
                    while(y < 1 || y > 10){
                        cout <<"Podaj y: ";
                        cin >> y;
                    }
                    statek = g.ustawienie(x-1,y-1,o,statek);
                    system("cls");
                }
               // g.wyswietl_plansze();
                //wysyłanie na server i odbieranie z servera
                //wysłanie planszy
                //odebranie kolejność
                    //odebranie kordów
                    //wysłanie kordów
        }
        else if(klient == STATYSTYKI){
            int kon;
            do{
                cout << "Statystyki" << endl;
                cout << "1.Lokalne" << endl;
                cout << "2.Globalne" << endl;
                cout << "0.WYJSCIE" << endl;
                cin >> kon;
                system("cls");
            }while(kon != 1 && kon != 2 && kon != 0);
            if(kon == 1){
                cout << "Lokalne" << endl;
                cout << "Pozycja\t" << "Nazwa\t" << "Punkty" << endl;
                Staty s;
                for(int i = 0; i < 10; i++)
                    cout<< s.get_pozycja(i) << "\t"<< s.get_nazwa(i) << "\t" << s.get_punkty(i)<<endl;
                getch();
                system("cls");
            }
            else if(kon == 2){
                cout << "Globalne" << endl;
                cout << "Pozycja\t" << "Nazwa\t" << "Punkty" << endl;

                getch();
                system("cls");
            }else;
        }
        else if(klient == koniec){
            cout<< endl <<"KONIEC"<< endl;
            klient = 0;
        }else {
            cout << "Jakis blad";
        }
    }
    return 0;
}

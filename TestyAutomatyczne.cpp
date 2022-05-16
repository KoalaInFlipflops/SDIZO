#include <iostream>
#include <fstream>
#include "TestyAutomatyczne.h"
#include "Czas.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Drzewo.h"

using namespace std;

void TestyAutomatyczne::testTablicy() {
    srand(time(NULL));
    Czas czas;
    Tablica tablica;
    int wybor = 99;
    int wartosc;
    int pozycja;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    while (wybor != 0) {
        cout << "Wybierz funkcje tablicy:" << endl;
        cout << "    1. Dodaj na poczatek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usun pierwszy" << endl;
        cout << "    5. Usun ostatni" << endl;
        cout << "    6. Usun ktorykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj tablice" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> wybor;

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawierający dane wejsciowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open(R"(E:\CLionProjects\SDiZO-Projekt1-master\SDiZO-Projekt1-master\Input/)" + daneWejsciowe);
        plikWyjsciowy.open(R"(E:\CLionProjects\SDiZO-Projekt1-master\SDiZO-Projekt1-master\Output\Tablica/)" + daneWyjsciowe, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        } else {
            cout << "Nie udało sie otworzyc pliku wejsciowego!" << endl;
            return;
        }

        if (plikWyjsciowy.is_open()) {
            cout << "Otworzono plik " << daneWyjsciowe << endl;
        } else {
            cout << "Nie udalo sie otworzyc pliku wyjsciowego!" << endl;
            return;
        }

        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                return;

            case 1:
                cout << "Rozpoczynam test automatyczny...";

                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    tablica.dodajNaPoczatek(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:
                cout << "Rozpoczynam test automatyczny...";

                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    tablica.dodajNaKoniec(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 3:
                cout << "Rozpoczynam test automatyczny...";

                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    tablica.dodajGdziekolwiek(wartosc, rand() % tablica.rozmiarTablicy);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 4:
                cout << "Rozpoczynam test automatyczny...";

                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.dodajNaPoczatek(wartosc);
                }
                while (tablica.rozmiarTablicy != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    tablica.usunPierwszy();
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 5:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.dodajNaPoczatek(wartosc);
                }
                while (tablica.rozmiarTablicy != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    tablica.usunOstatni();
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 6:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.dodajNaPoczatek(wartosc);
                }
                while (tablica.rozmiarTablicy != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    tablica.usunKtorys(rand() % tablica.rozmiarTablicy);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 7:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.dodajNaPoczatek(wartosc);
                }

                for (int i = 0; i < tablica.rozmiarTablicy; i++) {
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    tablica.sprawdzCzyIstnieje(rand() % 2000000 - 1000000);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 8:
                czas.czasStart();
                tablica.wydrukujTablice();
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;
        }

    }
}

void TestyAutomatyczne::testListy() {
    srand(time(NULL));
    Czas czas;
    Lista lista;
    int wybor = 99;
    int wartosc;
    int pozycja;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;


    while (wybor != 0) {
        cout << "Wybierz funkcję listy:" << endl;
        cout << "    1. Dodaj na poczatek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usun pierwszy" << endl;
        cout << "    5. Usun ostatni" << endl;
        cout << "    6. Usun którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj liste" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> wybor;

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawierajacy dane wejsciowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open(R"(E:\CLionProjects\SDiZO-Projekt1-master\SDiZO-Projekt1-master\Input/)" + daneWejsciowe);
        plikWyjsciowy.open(R"(E:\CLionProjects\SDiZO-Projekt1-master\SDiZO-Projekt1-master\Output\Lista/)" + daneWyjsciowe, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) {
            cout << "Otworzono plik " << daneWejsciowe << endl;
        } else {
            cout << "Nie udało sie otworzyc pliku wejsciowego!" << endl;
            return;
        }

        if (plikWyjsciowy.is_open()) {
            cout << "Otworzono plik " << daneWyjsciowe << endl;
        } else {
            cout << "Nie udalo sie otworzyc pliku wyjsciowego!" << endl;
            return;
        }

        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    lista.dodajNaPoczatek(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:
                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    lista.dodajNaKoniec(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 3:
                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;

                    if (lista.rozmiar == 0) {
                        czas.czasStart();
                        lista.dodajGdziekolwiek(wartosc, 0);
                        czas.czasStop();
                    } else {
                        czas.czasStart();
                        lista.dodajGdziekolwiek(wartosc, 1);
                        czas.czasStop();
                    }
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 4:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.dodajNaPoczatek(wartosc);
                }
                while (lista.rozmiar != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    lista.usunPierwszy();
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 5:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.dodajNaPoczatek(wartosc);
                }
                while (lista.rozmiar != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    lista.usunOstatni();
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 6:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.dodajNaPoczatek(wartosc);
                }
                while (lista.rozmiar != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    lista.usunKtorys(rand() % lista.rozmiar);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 7:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.dodajNaPoczatek(wartosc);
                }

                for (int i = 0; i < lista.rozmiar; i++) {
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    lista.sprawdzCzyIstnieje(rand() % 2000000 - 1000000);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 8:
                czas.czasStart();
                lista.wydrukujListe();
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

        }

    }
}

void TestyAutomatyczne::testKopca() {
    srand(time(NULL));
    Czas czas;
    Kopiec kopiec;
    int wybor = 99;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    while (wybor != 0) {
        cout << "Wybierz funkcję Kopca:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usun" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj kopiec" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> wybor;

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawierający dane wejsciowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open(R"(E:\CLionProjects\SDiZO-Projekt1-master\SDiZO-Projekt1-master\Input/)" + daneWejsciowe);
        plikWyjsciowy.open(R"(E:\CLionProjects\SDiZO-Projekt1-master\SDiZO-Projekt1-master\Output\Kopiec/)" + daneWyjsciowe, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) {
            cout << "Otworzono plik " << daneWejsciowe << endl;
        } else {
            cout << "Nie udalo sie otworzyć pliku wejsciowego!" << endl;
            return;
        }

        if (plikWyjsciowy.is_open()) {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        } else {
            cout << "Nie udalo sie otworzyć pliku wyjsciowego!" << endl;
            return;
        }

        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    kopiec.dodaj(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:


                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    kopiec.usun();
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 3:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    kopiec.dodaj(wartosc);
                }

                for (int i = 0; i < kopiec.rozmiar; i++) {
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    kopiec.sprawdzCzyIstnieje(rand() % 2000000 - 1000000);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 4:
                czas.czasStart();
                kopiec.wydrukujKopiec();
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;
        }

    }
}

void TestyAutomatyczne::testDrzewa() {
    srand(time(NULL));
    Czas czas;
    Drzewo drzewo;
    int wybor = 99;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    while (wybor != 0) {
        cout << "Wybierz funkcję Drzewa:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usun" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj drzewo" << endl;
        cout << "    0. Wyjscie" << endl << endl;
        cout << "Wybor: ";
        cin >> wybor;

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawierajacy dane wejsciowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open(R"(E:\CLionProjects\SDiZO-Projekt1-master\SDiZO-Projekt1-master\Input/)" + daneWejsciowe);
        plikWyjsciowy.open(R"(E:\CLionProjects\SDiZO-Projekt1-master\SDiZO-Projekt1-master\Output/Drzewo/)" + daneWyjsciowe, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) {
            cout << "Otworzono plik " << daneWejsciowe << endl;
        } else {
            cout << "Nie udalo sie otworzyc pliku wejsciowego!" << endl;
            return;
        }

        if (plikWyjsciowy.is_open()) {
            cout << "Otworzono plik " << daneWyjsciowe << endl;
        } else {
            cout << "Nie udalo sie otworzyc pliku wyjsciowego!" << endl;
            return;
        }

        switch (wybor) {
            default:
                cout << "Bledny wybor!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    drzewo.dodaj(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    drzewo.dodaj(wartosc);
                }


                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    drzewo.usun(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 3:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    drzewo.dodaj(wartosc);
                }

                for (int i = 0; i < drzewo.rozmiar; i++) {
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    drzewo.sprawdzCzyIstnieje(rand() % 2000000 - 1000000);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;


            case 4:
                czas.czasStart();
                cout << "NIE DZIALA" << endl;
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

        }

    }
}
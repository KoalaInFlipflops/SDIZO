#include <iostream>
#include "Lista.h"

using namespace std;

Lista::Lista() {

    Lista::pierwszyElement = nullptr;
    Lista::aktualnyElement = nullptr;
    Lista::ostatniElement = nullptr;
    Lista::rozmiar = 0;

}

Lista::~Lista() {


    for (int i = 0; i < Lista::rozmiar; i++) {

        //Przypisz kolejny element jako aktualny
        aktualnyElement = pierwszyElement->nastepny;
        //Usuń pierwszy element
        delete pierwszyElement;

        pierwszyElement = aktualnyElement;
    }

}

void Lista::dodajNaPoczatek(int wartosc) {

    //Sprawdź, czy istnieje element początkowy
    if (pierwszyElement == nullptr) {
        //Utwórz nowy element i ustaw go jako element początkowy i końcowy
        pierwszyElement = new ElementListy(wartosc, nullptr, nullptr);
        ostatniElement = pierwszyElement;

    } else {
        //Ustaw element ktory był pierwszym jako aktualny
        aktualnyElement = pierwszyElement;
        //Zastąp pierwszy element nowym
        //Ustaw jego wartość oraz element kolejny na element aktualny (były pierwszy)
        pierwszyElement = new ElementListy(wartosc, aktualnyElement, nullptr);
        aktualnyElement->poprzedni = pierwszyElement;

    }

    //Zwiększ rozmiar listy
    rozmiar = rozmiar + 1;

}

void Lista::dodajNaKoniec(int wartosc) {
    //Sprawdź, czy istnieje element początkowy
    if (pierwszyElement == nullptr) {
        //Utwórz nowy element i ustaw go jako element początkowy i końcowy
        ostatniElement = new ElementListy(wartosc, nullptr, nullptr);
        pierwszyElement = ostatniElement;

    } else {
        //Ustaw element który był ostatnim jako aktualny
        aktualnyElement = ostatniElement;
        //Zastąp ostatni element nowym
        //Ustaw jego wartość oraz element poprzedni na element aktualny (były ostatni)
        ostatniElement = new ElementListy(wartosc, nullptr, aktualnyElement);
        aktualnyElement->nastepny = ostatniElement;
    }
    //Zwiększ rozmiar listy o 1
    rozmiar++;
}


void Lista::dodajGdziekolwiek(int wartosc, int pozycja) {

    //Sprawdź czy w liście istnieje pozycja podana przez użytkownika
    if (pozycja < 0 || pozycja > rozmiar) {
        cout << "W liscie nie istnieje pozycja [" << pozycja << "]" << endl;
        return;
    }
    //Sprawdź czy wybrana pozycja jest pierwszą
    if (pozycja == 0) {
        Lista::dodajNaPoczatek(wartosc);
        return;
    }

    //Sprawdź czy wybrana pozycja jest ostatnią
    if (pozycja == rozmiar - 1) {
        dodajNaKoniec(wartosc);
        return;
    }
    aktualnyElement = pierwszyElement;

    while(aktualnyElement->nastepny != nullptr && --pozycja)
    {
        aktualnyElement = aktualnyElement -> nastepny;
    }
    aktualnyElement -> nastepny = new ElementListy(wartosc, aktualnyElement->nastepny,aktualnyElement);
    rozmiar++;
}

void Lista::usunPierwszy() {

    //przypisz drugi element jako aktualny
    aktualnyElement = pierwszyElement->nastepny;

    //Usuń pierwszy element
    delete pierwszyElement;

    //Sprawdź, czy w liście są jeszcze jakieś elementy
    //Jeżeli tak, ustaw aktualny element jako pierwszy
    //Jeżeli nie, wyzeruj elementy listy
    if (rozmiar > 1) {
        aktualnyElement->poprzedni = nullptr;
        pierwszyElement = aktualnyElement;
    } else {
        aktualnyElement = nullptr;
        pierwszyElement = nullptr;
        ostatniElement = nullptr;
    }

    //Zmniejsz rozmiar listy
    rozmiar--;
}

void Lista::usunOstatni() {

    //Przypisz przedostani element jako aktualny
    aktualnyElement = ostatniElement->poprzedni;
    //Usuń ostatni element
    delete ostatniElement;

    //Sprawdź, czy w liście są jeszcze jakieś elementy
    //Jeżeli tak, ustaw aktualny element jako ostatni
    //Jeżeli nie, wyzeruj elementy listy
    if (rozmiar > 1) {
        aktualnyElement->nastepny = nullptr;
        ostatniElement = aktualnyElement;
    } else {
        aktualnyElement = nullptr;
        pierwszyElement = nullptr;
        ostatniElement = nullptr;
    }

    //Zmniejsz rozmiar listy
    rozmiar--;

}

void Lista::usunKtorys(int pozycja) {

//Sprawdź czy w liście istnieje pozycja podana przez użytkownika
    if (pozycja < 0 || pozycja > rozmiar) {
        cout << "W liscie nie istnieje pozycja [" << pozycja << "]" << endl;
        return;
    }
    //Sprawdź czy wybrana pozycja jest pierwszą
    if (pozycja == 0) {
        usunPierwszy();
        return;
    }

    //Sprawdź czy wybrana pozycja jest ostatnią
    if (pozycja == rozmiar - 1) {
        usunOstatni();
        return;
    }

    //Sprawdź w której połowie listy znajduje się wybrany element
    if (pozycja < rozmiar / 2) {

        //Przypisz za aktualny element pierwszy
        aktualnyElement = pierwszyElement;

        //Przesuń wszyskie elementy o jeden dalej
        for (int i = 1; i < pozycja - 1; ++i) {
            aktualnyElement = aktualnyElement->nastepny;
        }

    } else {

        //Przypisz za aktualny element ostatni
        aktualnyElement = ostatniElement;

        //Przesuń wszystkie elementy o jedną pozycję wstecz
        for (int i = 0; i < rozmiar - pozycja - 1; ++i) {
            aktualnyElement = aktualnyElement->poprzedni;
        }

    }

    //Stwórz nowy element listy z podanymi parametrami
    ElementListy *nowyElementListy = aktualnyElement->nastepny;

    //przypisz nowy element w odpowiednim miejscu tablicy
    aktualnyElement->nastepny = nowyElementListy->nastepny;
    aktualnyElement->nastepny->poprzedni = nowyElementListy;

    delete[]nowyElementListy;

    //Zmniejsz rozmiar listy
    rozmiar--;

}

bool Lista::sprawdzCzyIstnieje(int wartosc) {

    //Jeżeli lista jest pusta, zwróć false z automatu
    if (rozmiar == 0) {
        return false;

    }

    //Przypisa pierwszy element jako aktualny
    aktualnyElement = pierwszyElement;

    //Przeszukaj listę pod kątem wartości
    for (int i = 0; i < rozmiar; i++) {
        if (aktualnyElement->wartosc == wartosc) {
            cout << "Szukana wartosc   zajmuje w liscie pozycje [" << i << "]" << endl;
            return true;
        }

        aktualnyElement = aktualnyElement->nastepny;
    }

    //Jeżeli wartość nie wystąpiła w żadnej iteracji listy zwróć false
    cout << "Szukana wartosc nie występuje w liscie" << endl;
    return false;
}

void Lista::wydrukujListe() {

    //Ustaw jako akutualny element pierwszy element listy
    aktualnyElement = pierwszyElement;

    for (int i = 0; i < rozmiar; i++) {

        cout << "[" << i << "] " << aktualnyElement->wartosc << endl;

        //Przypisz kolejny element listy jako aktualny
        aktualnyElement = aktualnyElement->nastepny;

    }

}
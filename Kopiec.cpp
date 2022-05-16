#include <iostream>
#include "Kopiec.h"
#include<cmath>

using namespace std;

Kopiec::Kopiec() {
    Kopiec::tablica = NULL;
    Kopiec::rozmiar = 0;
}

Kopiec::~Kopiec() {

    if (Kopiec::rozmiar > 0) {
        delete[]tablica;
    }

}

void Kopiec::kopcowanie(int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left<rozmiar && tablica[left]>tablica[largest])
        largest = left;

    if (right<rozmiar && tablica[right]>tablica[largest])
        largest = right;

    if (largest != i) {
        swap(tablica[i], tablica[largest]);
        kopcowanie(largest);
    }
}

void Kopiec::mkopcowanie()
{
                for (int i = rozmiar / 2 - 1; i >= 0; i--)
                {
                    kopcowanie(i);
                }
}

void Kopiec::dodaj(int wartosc) {

    //Wartości w kopcu nie mogą się powtarzać
    //Kontynuuj tylko, jeżeli wartość nie istnieje jeszcze w kopcu


        //Stwórz nową tablicę większą o jeden element
        int *nowaTablica = new int[rozmiar + 1];

        //Przepisanie danych ze starej tablicy do nowej
        for (int i = 0; i < rozmiar; i++) {
            nowaTablica[i] = tablica[i];
        }

        //Dodanie wybranej wartości do kopca
        nowaTablica[rozmiar] = wartosc;

        //Usuń starą tablicę
        delete[]tablica;

        //Zastąp starą tablicę nową
        tablica = nowaTablica;

        //Popraw kolejność elementów w kopcu
        Kopiec::poprawStrukture();

        //Zwiększ rozmiar kopca
        rozmiar++;




}

/*void Kopiec::usun(int wartosc) {

    //Iteracja po całej tablicy kopca w elu znalezienia wartości
    for (int i = 0; i < rozmiar; i++) {

        if (tablica[i] == wartosc) {

            //Stwórz nową tablicę, pomniejszoną o jeden element
            int *nowaTablica = new int[rozmiar - 1];

            //Przepisz elementy z tablicy do pozycji na której znajduje się usuwany element
            for (int k = 0; k < i; k++) {
                nowaTablica[k] = tablica[k];
            }

            //Przepisz pozostałe elementy przesunięte o jedną pozycję
            for (int k = i + 1; k < rozmiar; k++) {
                nowaTablica[k - 1] = tablica[k];
            }

            //usuń starą tablicę i przypisz na jej miejsce nową
            delete[]tablica;
            tablica = nowaTablica;

            //Zmniejsz rozmiar tablicy
            rozmiar--;

            //Popraw kolejność elementów w tablicy kopca
            Kopiec::poprawStrukture();
            return;

        }

    }

}*/

void Kopiec::usun()
{
        for (int i=0; i < rozmiar; i++)
        {
            tablica[i] = tablica[i+1];
        }
        tablica = (int *) realloc(tablica, (rozmiar - 1) * sizeof(int));
        rozmiar--;

        mkopcowanie();
}

bool Kopiec::sprawdzCzyIstnieje(int wartosc) {

    //Przeszukaj tablicę pod kątem wartości
    for (int i = 0; i < rozmiar; i++) {
        //Jeżeli wartość wystąpi w iteracji zwróc true
        if (tablica[i] == wartosc) {
            cout << "Szukana wartosc zajmuje w tablicy kopca pozycje [" << i << "]" << endl;
            return true;
        }
    }
    //Jeżeli wartość nie wystąpiła w żadnej iteracji tabeli zwróć false
    cout << "Szukana wartosc nie wystepuje w kopcu" << endl;
    return false;

}



void Kopiec::wydrukujKopiec() {
int separator=0, power=0;
    cout << "Aktualny stan kopca:" << endl;
    //Jeżeli tablica nie ma elementów, wyświetl komunikat
    //W przeciwnym wypadku wydrukuj wszystkie elementy tablicy
    if (tablica != NULL) {
        for (int i = 0; i < rozmiar; i++) {
            cout << "    [" << i << "] " << tablica[i];
            if(!i || separator == pow(2,power))
            {
                cout<<endl;
                separator = 0;
                power++;
                separator++;
                continue;
            }
            separator++;
            if (!(i%2))
                cout <<" . ";
        }
    } else {
        cout << "    Tablica nie ma zadnych elementow" << endl;
    }

}

void Kopiec::poprawStrukture() {

    //Zmienna pomocnicza do pętli sortującej
    int tymczasowa = 0;

    //Pętla sortująca, układająca elementy kopca w odpowiedniej kolejności
    //
    for (int i = rozmiar; 0 < i; i--) {
        if (tablica[i - 1] < tablica[i]) {
            tymczasowa = tablica[i - 1];
            tablica[i - 1] = tablica[i];
            tablica[i] = tymczasowa;
        }


    }

}
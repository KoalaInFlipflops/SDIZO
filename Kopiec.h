#ifndef SDIZO_PROJEKT_KOPIEC_H
#define SDIZO_PROJEKT_KOPIEC_H


class Kopiec {
public:
    int *tablica;
    unsigned int rozmiar;

    Kopiec();

    ~Kopiec();

    void dodaj(int);

    void usun();

    bool sprawdzCzyIstnieje(int);

    void wydrukujKopiec();

    void poprawStrukture();

    void kopcowanie(int i);

    void mkopcowanie();

    int iloscPoziomow();
};


#endif //SDIZO_PROJEKT_KOPIEC_H

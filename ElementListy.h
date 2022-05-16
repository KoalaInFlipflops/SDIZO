
#ifndef SDIZO_PROJEKT_ELEMENTLISTY_H
#define SDIZO_PROJEKT_ELEMENTLISTY_H


class ElementListy {

public:
    ElementListy *nastepny;
    ElementListy *poprzedni;
    int wartosc;

    ElementListy(int, ElementListy *, ElementListy *);
};


#endif //SDIZO_PROJEKT_ELEMENTLISTY_H

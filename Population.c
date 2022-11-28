#include "Population.h"
#include <stdlib.h>
#include <stdio.h>

Population ajoutt_pop(Population l, Individu i) {

    Individus *temp;
    temp = (Individus*)malloc(sizeof(Individus));
    temp->val = i;
    temp->next=l;

    return temp;
}

Population initPop(int taillePop) {
    if(taillePop == 0) {
        return NULL;
    } else {
        return ajoutt_pop(initPop(taillePop-1),initIndiv_recursif(8));
    }
}

Population triQualiteDec(Population p) {

}

Population meilleursIndiv(Population p, int tSelect)
{
    p = triQualiteDec(p);
    Population i = p;
    while(!vide(i) && tSelect > 0)
    {
        i = i->next;
        tSelect--;
    }
    while(!vide(i))
    {
        i->val = p->val;
        i = i->next;
        p = p->next;
    }
}

Population croiserPop(Population p) {

}
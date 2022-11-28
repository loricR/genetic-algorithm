#include "Population.h"
#include <stdlib.h>
#include <stdio.h>

Population initPop(int taillePop) {

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
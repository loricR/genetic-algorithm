#include "Population.h"
#include <stdlib.h>
#include <stdio.h>

int vide_pop(Population p)
{
    return p == NULL;
}

void afficherPop(Population p) {
    while(p != NULL) {
        afficherInd(p->val);
        p = p->next;
    }
}

Population ajoutt_pop(Population l, Individu i) {

    Individus *temp;
    temp = (Individus *) malloc(sizeof(Individus));
    temp->val = i;
    temp->next = l;

    return temp;
}

Population initPop(int taillePop)
{
    if (taillePop == 0)
    {
        return NULL;
    }
    else
    {
        return ajoutt_pop(initPop(taillePop - 1), initIndiv_recursif(8));
    }
}

Population triQualiteDec(Population p)
{
    Population premier = p;
    Population dernier = p;
    while(!vide_pop(dernier->next))
    {
        dernier = dernier->next;
    }

    if(premier < dernier)
}

Population partition(Population p)
{
    Population dernier = p;
    while(!vide_pop(dernier->next))
    {
        dernier = dernier->next;
    }
    Population pivot = dernier; // pivot
    Population i = p; // Index of smaller element and indicates
    // the right position of pivot found so far

    Population j = p;
    while(!vide_pop(j)) {
        // If current element is smaller than the pivot
        if (qualiteIndiv(j->val) < qualiteIndiv(pivot->val)) {
            i = i->next; // increment index of smaller element
            echangeIndiv(i, j);
        }
        j = j->next;
    }
    echangeIndiv(i->next, dernier);
    return i->next;
}

void echangeIndiv(Population a, Population b)
{
    Individu temp;
    temp = a->val;
    a->val = b->val;
    b->val = temp;
}

Population meilleursIndiv(Population p, int tSelect)
{
    p = triQualiteDec(p);
    Population i = p;
    while (!vide(i) && tSelect > 0)
    {
        i = i->next;
        tSelect--;
    }
    while (!vide(i))
    {
        i->val = p->val;
        i = i->next;
        p = p->next;
    }
}

Population croiserPop(Population p)
{
    Population p2 = NULL;
    Individu i, j;
    i = NULL;
    j = NULL;

    while (taillePop(p2) != taillePop(p))
    {
        do
        {
            i = randIndiv(p);
            j = randIndiv(p);
        } while (i == j);
        p2 = ajoutt_pop(p2, croiserList(0.5, i, j));
    }
    return p2;
}

int taillePop(Population p)
{
    if (p != NULL)
    {
        return taillePop(p->next) + 1;
    } else return 0;
}

Individu randIndiv(Population p)
{
    int a = rand() % taillePop(p);
    while (a > 0)
    {
        a--;
        p = p->next;
    }
    return p->val;
}
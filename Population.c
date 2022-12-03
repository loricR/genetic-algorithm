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
        printf("%f\n", qualiteIndiv(p->val));
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

void triQualiteDec(Population premier, Population dernier)
{
    if(premier != dernier)
    {
        Population pivot = partition(premier, dernier);

        if(pivot != NULL && pivot->next != NULL)
        {
            triQualiteDec(pivot->next, dernier);
        }
        if(pivot != NULL && premier != pivot)
        {
            triQualiteDec(premier, pivot);
        }
    }
}

Population partition(Population premier, Population dernier)
{
    Population pivot = premier;
    Population actuel = premier;
    Individu temp;

    while(actuel != NULL && actuel != dernier)
    {
        if(qualiteIndiv(actuel->val) > qualiteIndiv(dernier->val))
        {
            pivot = premier;

            //échange individus
            temp = premier->val;
            premier->val = actuel->val;
            actuel->val = temp;

            premier = premier->next;
        }
        actuel = actuel->next;
    }
    //échange la dernière valeur avec la valeur actuelle
    temp = premier->val;
    premier->val = dernier->val;
    dernier->val = temp;

    return pivot;
}

Population dernierIndiv(Population p)
{
    Population dernier = p;
    while(!vide_pop(dernier->next))
    {
        dernier = dernier->next;
    }
    return dernier;
}

Population meilleursIndiv(Population p, int tSelect)
{
    triQualiteDec(p, dernierIndiv(p));
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
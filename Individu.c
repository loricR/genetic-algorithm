#include "Individu.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

Individu initIndiv(int longIndiv){

}

Individu initIndiv_recursif(int longIndiv){

}

int decodeList(Individu l)
{
    if(vide(l))
    {
        return 0;
    }
    else
    {
        return (int) (l + 2 * decodeList(l->next));
    }
}

Individu croiserList(float pCroise, Individu l1, Individu l2)
{
    srand(NULL);
    if(!vide(l1) && !vide(l2))
    {
        if((rand()%2) <= pCroise)
        {
            return ajoutt(croiserList(pCroise, l1->next, l2->next), l1);
        }
        else
        {
            return ajoutt(croiserList(pCroise, l1->next, l2->next), l2);
        }
    }
    else
    {
        return NULL;
    }
}

float qualite(Individu i) {
   // int valInd = decodeList(i.listBits);

    return ((decodeList(i.listBits) / (2^(i.longIndiv))) * 2 + 1)^2
}


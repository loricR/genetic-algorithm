#include "Individu.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int vide(Individu l) {
    return l == NULL;
}

Individu ajoutq(Individu l, int v) {

    Bits *i=l;
    Bits *temp;

    temp = (Bits*)malloc(sizeof(Bits));

    while(i->next != NULL) {
        i = i->next;
    }
    temp->next = NULL;
    i->next = temp;
    temp->val = v;
    return l;
}

Individu ajoutt(Individu l, int v) {

    Bits *temp;
    temp = (Bits*)malloc(sizeof(Bits));
    temp->val = v;
    temp->next=l;

    return temp;
}

Individu initIndiv(int longIndiv){
    srand(NULL);
    Individu l = NULL;
    while(longIndiv > 0) {
        l = ajoutq(l,rand()%2);
        longIndiv--;
    }
}

Individu initIndiv_recursif(int longIndiv){
    srand(NULL);
    if(longIndiv == 0) {
        return NULL;
    } else {
        return ajoutt(initIndiv_recursif(longIndiv-1),rand()%2);
    }
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

    return ((decodeList(i.listBits) / (2^(longIndiv(i)))) * 2 + 1)^2
}

int longIndiv(Individu l)
{
    int compteur = 0;
    while(!vide(l))
    {
        l = l->next;
        compteur++;
    }
}

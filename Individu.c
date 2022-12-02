#include "Individu.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int vide(Individu l)
{
    return l == NULL;
}

Individu ajoutq(Individu l, Bit v)
{

    Bits *i = l;
    Bits *temp;

    temp = (Bits *) malloc(sizeof(Bits));
    temp->next = NULL;
    temp->val = v;

    if (!vide(i))
    {
        while (i->next != NULL)
        {
            i = i->next;
        }

        i->next = temp;
    } else
    {
        l = temp;
    }
    return l;
}

Individu ajoutt(Individu l, Bit v)
{

    Bits *temp;
    temp = (Bits *) malloc(sizeof(Bits));
    temp->val = v;
    temp->next = l;

    return temp;
}

Individu initIndiv(int longIndiv)
{
    Individu l = NULL;
    while (longIndiv > 0)
    {
        l = ajoutq(l, rand() % 2);
        longIndiv--;
    }
    return l;
}

Individu initIndiv_recursif(int longIndiv)
{
    if (longIndiv == 0)
    {
        return NULL;
    } else
    {
        return ajoutt(initIndiv_recursif(longIndiv - 1), rand() % 2);
    }
}

int decodeList(Individu l)
{
    if (vide(l))
    {
        return 0;
    } else
    {
        return (l->val + 2 * decodeList(l->next));
    }
}

Individu croiserList(float pCroise, Individu l1, Individu l2)
{
    if (!vide(l1) && !vide(l2))
    {
        if ((rand() % 20) <= pCroise * 10)   //TODO: voir si la proba est bonne
        {
            return ajoutt(croiserList(pCroise, l1->next, l2->next), l1->val);
        } else
        {
            return ajoutt(croiserList(pCroise, l1->next, l2->next), l2->val);
        }
    } else
    {
        return NULL;
    }
}

float qualiteIndiv(Individu i)
{
    return powf(((decodeList(i) / pow(2, longIndiv(i))) * 2 + 1), 2);
}

int longIndiv(Individu l)
{
    int compteur = 0;
    while (!vide(l))
    {
        l = l->next;
        compteur++;
    }
    return compteur;
}
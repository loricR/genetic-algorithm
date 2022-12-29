#include "Individu.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int vide(Individu l)
{
    return l == NULL;
}

void afficherInd(Individu l)
{
    if (!vide(l))
    {
        // Tant qu'on n'est pas arrivés au bout de l'Individu
        while (l != NULL)
        {
            // On affiche le bit et on passe au suivant
            printf("%d ", l->val);
            l = l->next;
        }
    }
    printf("\n");
}

Individu ajoutq(Individu l, Bit v)
{
    Bits *i = l;
    Bits *temp;

    temp = (Bits *) malloc(sizeof(Bits));
    temp->next = NULL;
    temp->val = v;

    // Si la liste de bits n'est pas vide
    if (!vide(i))
    {
        // On parcourt la liste de bits jusqu'à arriver au dernier élément
        while (i->next != NULL)
        {
            i = i->next;
        }
        // Le dernier élément pointe vers la valeur attribuée à temp
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
    // Le bit v pointe vers le premier élément de la liste de bits
    temp->next = l;

    return temp;
}

Individu initIndiv(int longIndiv)
{
    Individu l = NULL;
    // Tant que la taille voulue de la liste de bits n'est pas atteinte
    while (longIndiv > 0)
    {
        // On ajoute en queue de la liste de bits soit la valeur 0, soit 1
        l = ajoutq(l, rand() % 2);
        longIndiv--;
    }
    return l;
}

Individu initIndiv_recursif(int longIndiv)
{
    // Cas d'arrêt : si on a atteint la taille voulue de la liste de bits
    if (longIndiv == 0)
    {
        return NULL;
    }
        // Cas général : on ajoute en tête de la liste renvoyée par l'appel récursif de la
        // fonction de taille voulue -1 soit la valeur 0, soit la valeur 1
    else
    {
        return ajoutt(initIndiv_recursif(longIndiv - 1), rand() % 2);
    }
}

int decodeList(Individu l)
{
    // Cas d'arrêt : Si la liste de bits est vide
    if (vide(l))
    {
        return 0;
    }
        // Cas général : On ajoute une puissance de 2 par bit parcouru
    else
    {
        return (l->val + 2 * decodeList(l->next));
    }
}

Individu croiserList(float pCroise, Individu l1, Individu l2)
{
    // Cas général
    if (!vide(l1) && !vide(l2))
    {
        // Probabilité pCroise d'ajouter en tête de la liste résultat soit la valeur de l1, soit celle de l2
        if ((rand() % 100) < pCroise * 100)
        {
            return ajoutt(croiserList(pCroise, l1->next, l2->next), l1->val);
        } else
        {
            return ajoutt(croiserList(pCroise, l1->next, l2->next), l2->val);
        }
    }
        // Cas d'arrêt : quand une des deux listes est vide
    else
    {
        return NULL;
    }
}

float qualiteIndiv(Individu i)
{
    // return powf(((decodeList(i) / pow(2, longIndiv(i))) * 2 + 1), 2);
    // Pour la manipulation :
    return -log10f(((decodeList(i) / pow(2, longIndiv(i))) * 4.9 + 0.1));
}

int longIndiv(Individu l)
{
    if (l != NULL)
    {
        return longIndiv(l->next) + 1;
    } else return 0;
}
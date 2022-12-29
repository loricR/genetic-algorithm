#include "Population.h"
#include <stdlib.h>
#include <stdio.h>

int vide_pop(Population p)
{
    return p == NULL;
}

void afficherPop(Population p) {

    // Tant que l'intégralité des Individus de la Population n'ont pas été parcourus
    while(p != NULL) {

        // On affiche l'individu et on passe au suivant
        afficherInd(p->val);
        printf("%f\n", qualiteIndiv(p->val));
        p = p->next;
    }
}

Population ajoutt_pop(Population l, Individu i) {

    // Même principe que ajoutt dans Individu.c
    Individus *temp;
    temp = (Individus *) malloc(sizeof(Individus));
    temp->val = i;
    temp->next = l;

    return temp;
}


Population ajoutq_pop(Population p, Individu i)
{
    // Même principe que ajoutq dans Individu.c
    Individus *j=p;
    Individus *temp;

    temp = (Individus*)malloc(sizeof(Individus));
    temp->next = NULL;
    temp->val = i;

    if(j != NULL)
    {
        while (j->next != NULL) {
            j = j->next;
        }
        j->next = temp;
    }
    else
    {
        p = temp;
    }
    return p;
}


Population initPop(int taillePop)
{
    // Cas d'arrêt : lorsque la taille de la population voulue est atteinte
    if (taillePop == 0)
    {
        return NULL;
    }
    // Cas général : On ajoute un individu de taille 8 à la population de taille voulue - 1
    else
    {
        return ajoutt_pop(initPop(taillePop - 1), initIndiv_recursif(LONG_INDIV));
    }
}

void triQualiteDec(Population premier, Population dernier)
{
    // Si l'intégralité de la population n'a pas déjà été testée
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

    // Tant que le dernier Individu de la population n'est pas atteint
    while(!vide_pop(dernier->next))
    {
        dernier = dernier->next;
    }
    return dernier;
}

Population meilleursIndiv(Population p, int tSelect)
{
   Population p2 = NULL;
   Population p_mem, p_ret;
   Population temp = p;

   // On enregistre les tSelect premiers éléments de p dans p2
   while(tSelect > 0) {
       p2 = ajoutq_pop(p2, temp->val);
       temp = temp->next;
       tSelect--;
   }

   //On garde en mémoire la liste p2
   p_mem = p2;
   //On garde en mémoire le début de la liste p (pour renvoyer en fin de fonction)
   p_ret = p;


   //Tant qu'on est pas arrivés au bout de p
   while(p != NULL) {

       // On remplace les éléments de p par ceux de p2
       while(p != NULL && p2 != NULL) {
           p->val = p2->val;
           p = p->next;
           p2 = p2->next;
       }
       // Et lorsque p2 est vide, on recommence avec le p2 de départ gardé en mémoire
       p2 = p_mem;
   }
   return p_ret;
}

Population croiserPop(Population p)
{
    Population p2 = NULL;
    Individu i, j;
    i = NULL;
    j = NULL;

    // Tant que la Population fille n'est pas de même taille que la Population mère
    while (taillePop(p2) != taillePop(p))
    {
        // Prendre deux individus dans la population mère et recommencer
        // si on tombe deux fois sur le même individu
        do
        {
            i = randIndiv(p);
            j = randIndiv(p);
        } while (i == j);

        // On ajoute à la Population fille le croisement des deux individus
        p2 = ajoutt_pop(p2, croiserList(0.5, i, j));
    }
    return p2;
}

int taillePop(Population p)
{
    // Si la Population n'est pas vide (cas général)
    if (p != NULL)
    {
        return taillePop(p->next) + 1;
    } else return 0;
}


Individu randIndiv(Population p) {
    // On prend un nombre compris dans la taille de la Population
    int a = rand()%taillePop(p);

    // On parcourt la Population jusqu'à trouver le a-ième individu
    while(a > 0) {
        a--;
        p = p->next;
    }
    // On retourne uniquement le a-ième individu
    return p->val;
}
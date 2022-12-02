#include "Population.h"
#include <stdlib.h>
#include <stdio.h>

void afficherPop(Population p) {
    while(p != NULL) {
        afficherInd(p->val);
        p = p->next;
    }
}

Population ajoutt_pop(Population l, Individu i) {

    Individus *temp;
    temp = (Individus*)malloc(sizeof(Individus));
    temp->val = i;
    temp->next=l;

    return temp;
}

Population ajoutq_pop(Population p, Individu i)
{

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
   /* p = triQualiteDec(p);
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
   */
   Population p2 = NULL;
   Population p_mem, p_ret;
   p = triQualiteDec(p);

   // On enregistre les tSelect premiers éléments de p dans p2
   while(tSelect > 0) {
       p2 = ajoutq_pop(p2, p->val);
       p = p->next;
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

Population croiserPop(Population p) {
    Population p2 = NULL;
    Individu i,j;
    i = NULL;
    j = NULL;

    while (taillePop(p2) != taillePop(p)) {
        do {
            i = randIndiv(p);
            j = randIndiv(p);
        } while (i == j);
        p2 = ajoutt_pop(p2, croiserList(0.5,i,j));
    }
    return p2;
}

int taillePop(Population p) {
    if (p != NULL) {
        return taillePop(p->next) + 1;
    } else return 0;
}

Individu randIndiv(Population p) {
    int a = rand()%taillePop(p);
    printf("%d ",a);
    while(a > 0) {
        a--;
        p = p->next;
    }
    return p->val;
}
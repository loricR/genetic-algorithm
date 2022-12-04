#include "Individu.h"
#include "Population.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
//    //-------------------TEST INDIVIDU---------------------------------------------
//    Individu i, j;
//    srand(time(NULL));
//
//
//    i = initIndiv(8);
//    j = initIndiv_recursif(8);
//
//    Individu x=i;
//    Individu y=j;
//
//    afficherInd(x);
//    afficherInd(y);
//
//    printf("i : %d\nj : %d\n", decodeList(i), decodeList(j));
//
//    Individu croisement = croiserList(0.5, i, j);
//    Individu crois = croisement;
//    while (crois != NULL)
//    {
//        printf("%d ", crois->val);
//        crois = crois->next;
//    }
//    printf("\n");
//
//    printf("qualite : %f\n", qualiteIndiv(croisement));
//
//    //-----------------------------------------------------------------------------
//
//    //-------------------TEST POPULATION-------------------------------------------
//
//    Population p, p2;
//    p = initPop(5);
//    p2 = initPop(5);
//    afficherPop(p);
//    printf("\n p fille :\n");
//    p2 = croiserPop(p);
//    afficherPop(p2);
//
//
//    //------------------------------------------------------------------------------
//    printf("----------------\n");
//    afficherPop(meilleursIndiv(p2, 3));

    srand(time(NULL));
    int taillePop = (rand() % (200 - 20 + 1)) + 1;
    int nGen = (rand() % (200 - 20 + 1)) + 1;
    int tSelect = 5;
    Population p = initPop(taillePop);

    for(int i=0; i<nGen; i++)
    {
        p = croiserPop(p);
        triQualiteDec(p, dernierIndiv(p));
        p = meilleursIndiv(p, tSelect);
    }
    printf("\n-------------------------------\n");
    afficherPop(p);
    printf("\n---------\n");
    afficherInd(p->val);    //affichage de l'individu avec la meilleure qualité
    printf("qualite : %f\n", qualiteIndiv(p->val));
    printf("nGen : %d / taillePop : %d",nGen,taillePop);

    return 0;
}
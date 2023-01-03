#include "Individu.h"
#include "Population.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int taillePop = (rand() % 181) + 20;
    int nGen = (rand() % 181) + 20;
    int tS = (rand() % 81) + 10;
    int tSelect = (float)(tS)/100 *  taillePop;
    float pCroise = 0.5f;

    Population p = initPop(taillePop);

    for(int i=0; i<nGen; i++)
    {
        p = croiserPop(p, pCroise);
        triQualiteDec(p, dernierIndiv(p));
        p = meilleursIndiv(p, tSelect);
    }
    afficherInd(p->val);    //affichage de l'individu avec la meilleure qualité
    printf("qualite : %f\n", qualiteIndiv(p->val));
    printf("nGen : %d / taillePop : %d / tSelect : %d",nGen,taillePop, tSelect);

    return 0;
}
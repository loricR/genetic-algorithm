#include "Individu.h"
#include "Population.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //-------------------TEST INDIVIDU---------------------------------------------
    Individu i, j;
    srand(time(NULL));


    i = initIndiv(8);
    j = initIndiv_recursif(8);
    Individu x=i;
    Individu y=j;
    while (x != NULL) {
        printf("%d ", x->val);
        x = x->next;
    }
    printf("\n");
    while (y != NULL) {
        printf("%d ", y->val);
        y = y->next;
    }
    printf("\n");

    printf("i : %d\nj : %d\n", decodeList(i), decodeList(j));

    Individu croisement = croiserList(0.5, i, j);
    Individu crois = croisement;
    while (crois != NULL) {
        printf("%d ", crois->val);
        crois = crois->next;
    }
    printf("\n");

    printf("qualite : %f", qualiteIndiv(croisement));

    //-----------------------------------------------------------------------------

    return 0;
}
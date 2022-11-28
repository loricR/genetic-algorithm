#include "Individu.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int vide(List l) {
    return l == NULL;
}

List ajoutq(List l, int v) {

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

List ajoutt(List l, int v) {

    Bits *temp;
    temp = (Bits*)malloc(sizeof(Bits));
    temp->val = v;
    temp->next=l;

    return temp;
}

Individu initIndiv(int longIndiv){
    List l = NULL;
    while(longIndiv > 0) {
        l = ajoutq(l,rand()%2);
        longIndiv--;
    }
}

Individu initIndiv_recursif(int longIndiv){
    if(longIndiv == 0) {
        return NULL;
    } else {
        return ajoutt(initIndiv_recursif(longIndiv-1),rand()%2);
    }
}

int decodeList(List l){

}

Individu croiserList(float pCroise, List l1, List l2) {

}

float qualite(Individu i) {
    int valInd = decodeList(i.listBits);
}


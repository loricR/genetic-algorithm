#ifndef INDIVIDU_H
#define INDIVIDU_H

// Bit valeur 0 ou 1
typedef unsigned char Bit;

// Structure pour liste chaînée de bits
typedef struct Bits
{
    Bit val;
    struct Bits *next;
} Bits;

// Liste chaînée de Bits
typedef Bit *List;

// Individu
typedef struct
{
    int longIndiv;
    List listBits;
} Individu ;

// Opérations sur l'individu
Individu initIndiv();
Individu initIndiv_recursif();
int decodeList(List l);
void croiserList(float pCroise, List l1, List l2);
float qualiteIndiv(Individu i);

#endif
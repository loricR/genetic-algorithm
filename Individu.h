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
typedef Bits *List;

// Individu
typedef struct
{
    int longIndiv;
    List listBits;
} Individu ;

int vide(Individu l);

/**
 * @brief Initialise de manière aléatoire la suite de bits caractérisant un individu
 *
 * @param longIndiv la longueur souhaitée de la liste de bits représentant l'individu
 * @return Individu
 */
Individu initIndiv(int longIndiv);

/**
 * @brief Initialise récursivement de manière aléatoire la suite de bits caractérisant un individu
 *
 * @param longIndiv la longueur souhaitée de la liste de bits représentant l'individu
 * @return Individu
 */
Individu initIndiv_recursif(int longIndiv);

/**
 * @brief calcule la valeur associée à la liste de bits d'un individu
 *
 * @param l la liste de bits d'un individu
 * @return int
 */
int decodeList(Individu l);

/**
 * @brief intervertit les valeurs de deux listes de bits en fonction d'une probabilité
 * pour renvoyer une nouvelle liste de bits
 *
 * @param pCroise la probabilité d'intervertissement, l1 et l2 les deux listes de bits à intervertir
 * @return Individu
 */
Individu croiserList(float pCroise, Individu l1, Individu l2);

/**
 * @brief calcule la qualité d'un individu en fonction de sa liste de bits
 *
 * @param i l'individu à tester
 * @return float
 */
float qualiteIndiv(Individu i);

#endif
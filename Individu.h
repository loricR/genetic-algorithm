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

// Liste chaînée de Bits Individu
typedef Bits *Individu;





/**
 * @brief Détermine si une liste est vide
 *
 * @param l la liste à tester
 * @return int 0 ou 1
 */
int vide(Individu l);

/**
 * @brief Afficher la liste de bits composant un Individu
 *
 * @param l l'Individu à afficher'
 * @return
 */
void afficherInd(Individu l);

/**
 * @brief Ajoute un élément en tête de liste
 *
 * @param l la liste à laquelle ajouter un Bit
 * @param v la valeur à ajouter
 * @return List
 */
Individu ajoutq(Individu l, Bit v) ;

/**
 * @brief Ajoute un élément en queue de liste
 *
 * @param l la liste à laquelle ajouter un Bit
 * @param v la valeur à ajouter
 * @return List
 */
Individu ajoutt(Individu l, Bit v);

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
 * @param pCroise la probabilité d'intervertissement
 * @param l1,l2 les deux listes de bits à intervertir
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

/**
 * @brief renvoie la taille de la liste de Bits composant un Individu
 *
 * @param i l'individu à tester
 * @return int
 */
int longIndiv(Individu l);

#endif
#ifndef POPULATION_H
#define POPULATION_H
#include "Individu.h"

// Déclaration du type Population comme une liste chaînée d'individus
typedef struct Individus
{
    Individu val;
    struct Individus *next;
} Individus;

typedef Individus *Population;

int vide_pop(Population p);


/**
 * @brief afficher l'ensemble des individus présents dans une Population
 *
 * @param p la Population à afficher
 * @return
 */
void afficherPop(Population p);

/**
 * @brief ajoute un Individu en tête d'une Population
 *
 * @param i l'Individu à afficher
 * @param p la Population à laquelle on veut ajouter un Individu
 * @return Population
 */
Population ajoutt_pop(Population l, Individu i);

/**
 * @brief initialise une population composée d'individus aléatoires
 *
 * @param taillePop la taille souhaitée de la population en terme d'individus la composant
 * @return Population
 */
Population initPop(int taillePop);

/**
 * @brief trie en méthode Quicksort une Population par qualité de l'individu décroissante
 *
 * @param p la population à trier
 * @return Population
 */
Population triQualiteDec(Population p);

Population partition(Population p);

void echangeIndiv(Population a, Population b);

/**
 * @brief Sélectionne les meilleurs individus d'une population et les répertorie dans une population réduite
 *
 * @param p la population initiale
 * @param tSelect le taux de sélection voulu
 * @return Population
 */
Population meilleursIndiv(Population p, int tSelect);

/**
 * @brief croise des individus deux à deux d'une population, et répertorie le résultat de ces croisements dans
 * une sous-population que la fonction renverra
 *
 * @param p la population initiale
 * @return Population
 */
Population croiserPop(Population p);


/**
 * @brief retourne la taille d'une population
 *
 * @param p la population initiale
 * @return int
 */
int taillePop(Population p);


/**
 * @brief retourne un individu aléatoire dans une population
 *
 * @param p la population initiale
 * @return Individu
 */
Individu randIndiv(Population p);


#endif
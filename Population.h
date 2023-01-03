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


/**
 * @brief retourne 1 si la Population en paramètre est vide et 0 si elle ne l'est pas
 *
 * @param p la Population à tester
 * @return int
 */
int vide_pop(Population p);

/**
 * @brief affiche l'ensemble des individus présents dans une Population
 *
 * @param p la Population à afficher
 * @return void
 */
void afficherPop(Population p);

/**
 * @brief ajoute un Individu en tête d'une Population
 *
 * @param i l'Individu que l'on souhaite ajouter
 * @param p la Population à laquelle on veut ajouter un Individu
 * @return Population
 */
Population ajoutt_pop(Population p, Individu i);

/**
 * @brief ajoute un Individu en queue d'une Population
 *
 * @param i l'Individu que l'on souhaite ajouter
 * @param p la Population à laquelle on veut ajouter un Individu
 * @return Population
 */
Population ajoutq_pop(Population p, Individu i);

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

/**
 * @brief renvoie un pointeur sur le dernier Individu d'une Population
 *
 * @param p la Population à traiter
 * @return Population
 */
Population dernierIndiv(Population p);

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
 * @param premier le pointeur sur le premier individu d'une population
 * @param dernier le pointeur sur le dernier individu d'une population
 */
void triQualiteDec(Population premier, Population dernier);

/**
 * @brief échange les place d'individus dans une Population sous certaines conditions
 *
 * @param premier le pointeur sur le premier individu d'une population
 * @param dernier le pointeur sur le dernier individu d'une population
 * @return Population
 */
Population partition(Population premier, Population dernier);

/**
 * @brief sélectionne les meilleurs individus d'une population et les répertorie dans une population réduite
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
 * @param pCroise la probabilité de croisement
 * @return Population
 */
Population croiserPop(Population p, float pCroise);

#endif
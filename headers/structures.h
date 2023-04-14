/**
 * @file structures.h
 * @author Théo Taillefumier
 * @brief structures de données
 * @date 2023-03-31
 * 
 * @necessities
 * 
 * 
 */
#ifndef STRUCTURES_H
#define STRCUTURES_H

#include "cartes.h"

//structures concernant les cartes
struct liste_cartes {
    int nb_cartes;
    carte *cartes;
};
typedef struct liste_cartes* liste_cartes;

/**
 * @brief ajoute une carte à la liste
 * 
 * @param liste un pointeur vers la liste de cartes
 * @param carte la carte à ajouter
*/
void ajout_carte(liste_cartes liste, carte carte);


/**
 * @brief supprime une carte à la liste
 * 
 * @param liste un pointeur vers la liste des cartes
 * @param carte la carte à supprimer
*/
void suppr_cartes(liste_cartes liste, carte carte);

/**
 * @brief lecture de la carte d'indice index
 * 
 * @param liste un pointeur vers la liste des cartes
 * @param index l'indice dont on veut la carte
 * 
 * @return carte* un pointeur vers la carte d'indice index
*/
carte lecture_cartes(liste_cartes liste, int index);






//structures concernant les probas
struct matrice_probas {
    float** proba;
    int taille;
};
typedef struct matrice_probas* matrice_probas;

/**
 * @brief lecture de la probabilité d'indice i,j
 * 
 * @param matrice un pointeur vers la matrice de probas
 * @param i 
 * @param j 
 * 
 * @return float la valeur de la proba d'indice i,j
*/
float lecture_probas(matrice_probas matrice, int i, int j);


/**
 * @brief création d'une matrice de probas de taille taille
 * 
 * @param taille la taille de la matrice
*/
matrice_probas creer_matrice(int taille);

/**
 * @brief écriture de la probabilité d'indice i,j
 * 
 * @param matrice un pointeur vers la matrice de probas
 * @param i 
 * @param j 
 * @param proba la valeur de la proba à écrire
*/
void modifier_proba(matrice_probas matrice, int i, int j, float proba);


/**
 * @brief suppression d'une matrice de probas
 * 
 * @param matrice un pointeur vers la matrice de probas
*/
void suppression_matrice(matrice_probas matrice);

/**
 * @brief produit de deux matrices de probas
 * 
 * @param matrice1 un pointeur vers la première matrice
 * @param matrice2 un pointeur vers la deuxième matrice
 * 
 * @return matrice_probas un pointeur vers la matrice résultat
*/
matrice_probas produit_matrice(matrice_probas matrice1, matrice_probas matrice2);

#endif

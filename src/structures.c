/**
 * @file structures.c
 * @author Théo Taillefumier
 * @brief structures de données
 * @date 2023-03-31
 * 
 * @necessities
 * 
 * 
 */


#include "../headers/structures.h"

/* Getter et Setters */
/**
 * @brief renvoie un entier correspondant au nombre de cartes présentes dans la liste
 * 
 * @param lc 
 * @return int correspondant au nombre de cartes 
 */
int getNbCartes(liste_cartes lc){
    return lc->nb_cartes;
}

/**
 * @brief met à jour le nombre de cartes de la main
 * 
 * @param n 
 */
void setNbCartes(liste_cartes lc, int n){
    lc->nb_cartes = n;
}

/**
 * @brief renvoie la liste de cartes de la liste de cartes passés en arguments
 * 
 * @param lc 
 * @return carte* tableau de cartes
 */
carte* getCartes(liste_cartes lc){
    return lc->cartes;
}

/**
 * @brief renvoie la taille de la matrice
 * 
 * @param matrice un pointeur vers la matrice de probas
 * 
 * @return int la taille de la matrice
*/
int getTailleMatrice(matrice_probas matrice){
    return matrice->taille_matrice;
}

/**
 * @brief met à jour la taille de la matrice
 * 
 * @param taille la nouvelle taille de la matrice
*/
void setTailleMatrice(matrice_probas matrice, int taille){
    matrice->taille_matrice = taille;
}




void ajout_carte(liste_cartes liste, carte carte){
    setNbCartes(lsite,getNbCartes(liste)+1);
    getCartes(liste) = realloc(getCartes(liste), getNbCartes(liste) * sizeof(carte));
    getCartes(liste)[getNbCartes(liste) - 1] = carte;
}

carte lecture_cartes(liste_cartes liste, int index){
    if (index < getNbCartes(liste)){
        return getCartes(liste)[index];
    }
    return NULL;
}

void suppr_cartes(liste_cartes liste, carte carte){
    int index = 0;
    while (index < getNbCartes(liste) && getCartes(liste)[index] != carte){
        index++;
    }
    if (index < getNbCartes(liste)){
        setNbCartes(lsite,getNbCartes(liste)-1);
        for (int i = index; i < getNbCartes(liste); i++){
            getCartes(liste)[i] = getCartes(liste)[i + 1];
        }
        getCartes(liste) = realloc(getCartes(liste), getNbCartes(liste) * sizeof(carte));
    }
}

matrice_probas creer_matrice(int taille){
    matrice_probas matrice = malloc(sizeof(matrice_probas));
    matrice->taille_matrice = taille;
    matrice->proba = malloc(taille * sizeof(float*));
    for (int i = 0; i < taille; i++){
        matrice->proba[i] = malloc(taille * sizeof(float));
    }
    return matrice;
}

float lecture_probas(matrice_probas matrice, int i, int j){
    return matrice->proba[i][j];
}

void modifier_proba(matrice_probas matrice, int i, int j, float proba){
    matrice->proba[i][j] = proba;
}

void suppression_matrice(matrice_probas matrice){
    for (int i = 0; i < matrice->taille_matrice; i++){
        free(matrice->proba[i]);
    }
    free(matrice->proba);
    free(matrice);
}

matrice_probas produit_matrice(matrice_probas matrice1, matrice_probas matrice2){
    if (matrice1->taille_matrice != matrice2->taille_matrice){
        return NULL;
    }
    matrice_probas matrice = creer_matrice(matrice1->taille_matrice);
    for (int i = 0; i < matrice->taille_matrice; i++){
        for (int j = 0; j < matrice->taille_matrice; j++){
            float somme = 0;
            for (int k = 0; k < matrice->taille_matrice; k++){
                somme += matrice1->proba[i][k] * matrice2->proba[k][j];
            }
            matrice->proba[i][j] = somme;
        }
    }
    return matrice;
}

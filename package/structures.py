from cartes.py import Carte

class MatriceProbas:
    def __init__(self, matrice, taille_matrice):
        self.matrice = matrice
        self.taille_matrice = taille_matrice

    def __init__(self, taille_matrice):
        prob = 1/taille_matrice
        self.matrice = [[prob] * taille_matrice for _ in range(taille_matrice)]

    def lecture_probas(self, i, j):
        return self.matrice[i][j]
    
    def modifier_proba(self, i, j, proba):
        self.matrice[i][j] = proba

    def produit_matrice(matrice1, matrice2):
        if matrice1.taille_matrice != matrice2.taille_matrice:
            return None
        
        taille_matrice = matrice1.taille_matrice
        matrice = MatriceProbas(taille_matrice) #on crée une nouvelle matrice de probabilités
        
        for i in range(taille_matrice):
            for j in range(taille_matrice):
                somme = 0
                for k in range(taille_matrice):
                    somme += matrice1.proba[i][k] * matrice2.proba[k][j]
                matrice.proba[i][j] = somme
        
        return matrice

    def getTailleMatrice(self):
        return self.taille_matrice
    
    def setTailleMatrice(self, taille):
        self.taille_matrice = taille


class ListeCartes:
    def __init__(self):
        self.nb_cartes = 0 #nombre de cartes
        self.cartes = [] #liste de cartes

    def getNbCartes(self):
        return self.nb_cartes

    def setNbCartes(self, n):
        self.nb_cartes = n

    def getCartes(self):
        return self.cartes
    
    def ajout_carte(self, carte):
        self.setNbCartes(self.getNbCartes() + 1)
        self.cartes.append(carte)

    def lecture_cartes(self, index):
        if index < self.getNbCartes():
            return self.getCartes()[index]
        else:
            print("index out of range")
            return None

    def suppr_cartes(self, carte):
        index = 0
        while index < self.getNbCartes() and self.getCartes()[index] != carte:
            index += 1
        if index < self.getNbCartes():
            self.setNbCartes(self.getNbCartes() - 1)
            del self.cartes[index]

    def libere_liste_cartes(self):
        for carte in self.cartes:
            del carte
        del self.cartes
        del self   
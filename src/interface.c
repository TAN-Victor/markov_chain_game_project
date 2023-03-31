/**
 * @file interface.c
 * @author Victor TAN
 * @brief Implémentation des fonctions de "interface.h"
 *        Contiendra:
 * - \b afficher_toute_info(joueuse,joueuse,zones) qui permet d'afficher dans la console toutes les informations du jeu: les zones du jeu, les personnages qui sont dessus, la joueuse dont c'est le tour, le capital des joueuses, ...
 * - \b demander_capital(joueuse) pour demander à une joueuse combien de capital elle veut utiliser (elle peut répondre ne pas vouloir en utiliser)
 * - \b demander_carte(joueuse) pour demander à une joueuse si elle veut jouer une carte et si oui, laquelle
 * - \b demander_zones(zones) pour demander à une joueuse sur quel zone il faudrait augmenter la probabilité et sur laquelle il faudrait la baisser à partir de la zone où elle effectue cette action
 * - \b message_fin_du_jeu(joueuse,joueuse) qui permet d'afficher dans la console un message quand le jeu est fini
 * - \b messsage_generique(int,joueuse,int) pour afficher des messages génériques (par exemple si un membre a été mangé)
 * 
 * 
 * @necessities interface.h
*/

/**
 * \brief Affiche dans la console toutes les informations du jeu: les zones du jeu, les personnages qui sont dessus, la joueuse dont c'est le tour, le capital des joueuses, ...
 * \param joueuse,joueuse sont les 2 joueuses afin de récupérer les informations leurs concernants (les membres de chaque joueuse compris)
 * \param zones afin de récupérer les informations sur toute les zones du jeu
 * \return rien
*/
void afficher_toute_info(joueuse,joueuse,zones);

/**
 * \brief Demande à une joueuse combien de capital elle souhaite utiliser (elle peut répondre ne pas vouloir en utiliser)
 * \param joueuse afin de savoir à quelle joueuse demander
 * \return le nombre de capital que la joueuse souhaite dépenser, 0 sinon
*/
int demander_capital(joueuse);

/**
 * \brief Demande à une joueuse si elle veut jouer une carte qu'elle possède et si oui, laquelle
 * \param joueuse afin de savoir à quelle joueuse demander (les cartes associées sont déjà dans les fonctions de joueuses.h)
 * \return la carte correspondante, NULL sinon
*/
carte demander_carte(joueuse);

/**
 * \brief Demande à une joueuse où elle veut augmenter la probabilité et une autre où elle doit diminuer, elle peut répondre NULL si elle veut rien modifier
 * \param zones afin de savoir sur quelle zone intéragir (un paramamètre joueuse n'est pas utile car dans le main on sait déjà sur quelle joueuse demander)
 * \return un tableau contenant 3 int représentant le numéro de la zone de départ et 2 zones où la probabilité est à modifier(le premier sera celle à augmenter et le deuxième celle à diminuer), NULL sinon
*/
int* demander_zones(zones);

/**
 * \brief Affiche dans la console un message quand le jeu est fini
 * \param joueuse,joueuse afin d'avoir les informations si tout les membres de l'école d'une joueuse ont été mangés
 * \return rien
*/
void message_fin_du_jeu(joueuse,joueuse);

/**
* \brief Affiche des messages génériques
* \param int Numéro du message à afficher
* \param joueuse Joueuse concernéé par le message
* \param int Index du personnage de la joueuse ou index du numéro de carte utilisé, ... m=0 lorsqu'il n'est pas utile
*/
void message_generique(int,joueuse,int);


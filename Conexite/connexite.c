#include "connexite.h"

void attributionCouleursConnexes(pSommet* graphe, int ordre){
    //Création d'un temporaire qui prendra
    // la valeur des couleurs de chaque composante connexes
    char temp[CONST_TAILLE_MAX_COMPO_CONNEXES] = {0};
    //Entier qui contient la tailleLogique du tableau de temporaire
    int tailleLogique = 0;


    //On initialise pour chaque sommet sa couleur connexe à '-1' équivalent de NULL
    for (int i = 0; i < ordre; i++) {
        graphe[i]->connexite = -1;
    }

    //Boucle parcourant tous les sommets
    for (int i = 0; i < ordre; i++) {
        //Si le sommet n'appartient pas encore à une composante connexe : sa couleur est à 'NULL'
        if (graphe[i]->connexite == -1) {
            //On effectue un parcours BFS sur ce sommet
            InitialParcourLargeur(graphe, ordre, i, 1);
            //La case 'tailleLogique' du tableau temporaire prend donc la valeur du sommet
            // depuis lequel a été lancé le parcours BFS (cf. InitialParcoursLargeur();)
            temp[tailleLogique] = (char) i;
            //Une couleur a été ajoutée donc on augmente de 1 la tailleLogique
            tailleLogique++;
        }
    }


    //Boucle d'affichage
    //Pour le nombre de couleurs dans le tableau de temporaire
    //équivalent donc aux nombres de composantes connexes
    for (int i = 0; i < tailleLogique; i++) {
        //On affiche le numéro de la composante
        printf("\nComposante connexe %d : ", i+1);
        for (int j = 0; j < ordre; j++) {
            //Si le sommet 'j' a la même couleur que la case 'i' du tableau
            //Alors il fait partie de la même composante connexe
            if(graphe[j]->connexite == temp[i]){
                //On affiche les sommets de la composante
                printf(" %d", j);
            }
        }
    }
}

#include "Graphe/Graphe.h"
#include "BFS/bfs.h"
#include "DFS/dfs.h"



int main() {
    Graphe* g = lire_graphe("../binaries/graphe1_TP2.txt");
    int sommetInitial = 0, choixParcours = 0;

    //appel de la methode pour afficher le graphe selon quel parcours
    printf("Choix du parcours ? Tapez 1 (BFS), 2 (DFS) : \n");
    scanf(" %d", &choixParcours);

    //saisie du numero du sommet initial pour lancer un parcours
    printf("numero du sommet initial : \n");
    scanf(" %d", &sommetInitial);


    //afficher le graphe
    graphe_afficher(g);

    switch (choixParcours) {
        case 1:{
            InitialParcourLargeur(g->pSommet, g->ordre, sommetInitial);
            fonctionPredecesseurs(g->pSommet, g->ordre, sommetInitial);
            break;
        }

        case 2:{
            InitialParcourLongueurPileLIFO(g->pSommet, g->ordre, sommetInitial);
            fonctionPredecesseurs(g->pSommet, g->ordre, sommetInitial);
            break;
        }

        default:{
            printf("Erreur choix...\n");
        }

    }

    return 0;
}
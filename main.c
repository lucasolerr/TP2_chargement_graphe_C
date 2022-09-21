#include "Graphe/Graphe.h"
#include "BFS/bfs.h"
#include "DFS/dfs.h"
#include "Conexite/connexite.h"

/*
 * Nous avons utilisé pour la résolution de ce TP
 * les algorithmes BFS et DFS implémentés en C par Jerome Morissard
 * nous les avons modifiés et améliorés pour répondre aux exigences
 * de ce TP.
 * Dans le sujet, il y avait une ambiguïté sur le choix d'implémentation de l'algorithme DFS
 * (récursif ou avec une pile LIFO) nous avons choisi de l'implémenté avec une pile LIFO
 *
 * L'algorithme de recherche de composantes connexes a été entièrement imaginé
 * par nos soins.
 */



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

    //Switch permettant de faire un choix de parcours (BFS/DFS)
    switch (choixParcours) {
        case 1:{
            //Lancement du parcours BFS
            InitialParcourLargeur(g->pSommet, g->ordre, sommetInitial, 0);
            fonctionPredecesseurs(g->pSommet, g->ordre, sommetInitial);
            break;
        }

        case 2:{
            //Lancement du parcours DFS
            InitialParcourLongueurPileLIFO(g->pSommet, g->ordre, sommetInitial);
            fonctionPredecesseurs(g->pSommet, g->ordre, sommetInitial);
            break;
        }

        default:{
            printf("Erreur choix...\n");
        }

    }

    printf("\nVoulez vous afficher les composantes connexes de ce graphe ? (1: Oui)\n");
    scanf(" %d", &choixParcours);

    if(choixParcours){
        attributionCouleursConnexes(g->pSommet, g->ordre);
    } else {
        printf("Fin du programme.\n");
    }

    return 0;
}
#include "connexite.h"

void attributionCouleursConnexes(pSommet* graphe, int ordre){

    for (int i = 0; i < ordre; i++) {
        graphe[i]->connexite = 'A';
    }

    for (int i = 0; i < ordre; i++) {
        if (graphe[i]->connexite == 'A') {
            InitialParcourLargeur(graphe, ordre, i, (char) i);
        }
    }




}

void afficherComposantesConnexes(pSommet* graphe, int ordre){
    int compteur = 0;
    char temp[5] = {-1, -1, -1, -1, -1};

    for (int i = 0; i < ordre; i++) {
        if(graphe[i]->connexite != 'A'){
            for (int j = 0; j < compteur + 1; j++) {
                if (graphe[i]->connexite != temp[j]) {
                    temp[compteur] = graphe[i]->connexite;
                    compteur++;
                } else {
                }
            }
        }
    }

    for (int i = 0; i < compteur; i++) {
        printf("\nComposante connexe %d : ", i+1);
        for (int j = 0; j < ordre; j++) {
            if(graphe[j]->connexite == temp[i]){
                printf(" %d", j);
            }
        }
    }
}
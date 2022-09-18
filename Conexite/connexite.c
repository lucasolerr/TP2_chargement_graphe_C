#include "connexite.h"

//reste à commenter cette partie de code

void attributionCouleursConnexes(pSommet* graphe, int ordre){
    char temp[5] = {0};
    int compteur = 0;

    for (int i = 0; i < ordre; i++) {
        graphe[i]->connexite = -1;
    }

    for (int i = 0; i < ordre; i++) {
        if (graphe[i]->connexite == -1) {
            InitialParcourLargeur(graphe, ordre, i, 0);
            temp[compteur] = (char) i;
            compteur++;
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

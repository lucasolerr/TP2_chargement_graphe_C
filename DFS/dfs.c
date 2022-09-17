#include "dfs.h"

void InitialParcourLongueur(pSommet *graphe, int ordre) {
    /*Initialisation de la couleur des sommets*/
    /*N=Noir, deja vu.  B=Blanc a voir*/
    printf("\n***PARCOURS EN LONGUEUR***\n");
    int i;
    for (i = 0; i < ordre; i++) {
        graphe[i]->couleur = 'B';
    }
    for (i = 0; i < ordre; i++) {
        if (graphe[i]->couleur == 'B') {
            printf("%d,", graphe[i]->valeur);
            graphe[i]->couleur = 'N';
            pArc Temparc = graphe[i]->arc;
            while (Temparc != NULL) {
                ParcourLongueur(graphe, Temparc->sommet, ordre);
                Temparc = Temparc->arc_suivant;
            }
        }
    }
}

/****************************************************/
void ParcourLongueur(pSommet *graphe, int s, int ordre) {
    if (graphe[s]->couleur == 'B') {
        printf("%d,", graphe[s]->valeur);
        graphe[s]->couleur = 'N';
        pArc Temparc = graphe[s]->arc;
        while (Temparc != NULL) {
            ParcourLongueur(graphe, Temparc->sommet, ordre);
            Temparc = Temparc->arc_suivant;
        }
    }
}

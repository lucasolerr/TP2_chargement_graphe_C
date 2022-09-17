#include "dfs.h"
#include "../BFS/bfs.h"

typage defilementLIFO(File F) {
    Cellule cellule;
    Cellule temp;
    typage element;
    //La file n'existe pas
    if (F == NULL || longueur(F) == 0) printf("File existe pas - defilement");

    //On assigne une cellule temporaire à la cellule de queue de file (LIFO)
    cellule = F->queue;
    //On assigne une cellule temporaire à la cellule de tête de file
    //pour pouvoir parcourir la file jusqu'à l'avant-dernier élément
    temp = F->tete;
    //On assigne au temporaire element le sommet de la cellule en tête de file
    element = cellule->element;

    //Si la file est de longueur 1
    if (longueur(F) == 1) {
        //On vide la file car l'objectif de cette fonction est d'enlever un élément de la liste
        //soit dans ce if de la mettre à 0
        F->tete = F->queue = NULL;
    } else {
        //Sinon on parcours la liste jusqu'à l'avant-dernière cellule
        while (temp->suivant != cellule){
            temp = temp->suivant;
        }
        //La nouvelle queue de liste est l'avant-dernière cellule
        F->queue = temp;
        //Cette cellule n'a donc plus de successeur car on le défile
        F->queue->suivant = NULL;
    }
    //On libère l'ex-queue de liste
    free(cellule);
    //On réduit la longueur de la file
    --(F->longueur);
    //On retourne le sommet qui a été enlevé de la file
    return (element);
}

void InitialParcourLongueurPileLIFO(pSommet *graphe, int ordre, int sommetInitial) {
    /*Initialisation de la couleur des sommets*/
    /*N=Noir, deja vu.  B=Blanc a voir*/
    /* !!! A noter : Ce parcours DFS est visité selon l'ordre inverse de ses numéros !!! */
    printf("\n***PARCOURS EN LARGEUR***\n");
    int i = 0;
    //Création d'une file vide
    File file = fileVide();
    for (i = 0; i < ordre; i++) {
        //On assigne à chaque sommet la couleur 'Blanche'
        graphe[i]->couleur = 'B';
        //On initialise ses prédécesseurs à une valeur arbitraire '-1' équivalente à NULL
        graphe[i]->predecesseur = -1;
    }
    //On met dans la file le 1er sommet depuis lequel on souhaite faire le parcours DFS
    enfiler(file, sommetInitial);

    //Tant que la file est pleine
    while (longueur(file)) {
        //On enlève en queue une cellule
        i = defilementLIFO(file);
        //i contient le numéro de sommet qui a été défilé
        if (graphe[i]->couleur == 'B') {
            //Si i était non découvert
            //On créé le temportaire pour l'arc
            pArc Temparc = graphe[i]->arc;
            //Si le sommet à un pointeur sur structure Arc (à des successeurs)
            if (Temparc != NULL) {
                //On ajoute en fin de file le 1er sommet adjacent à i
                enfiler(file, Temparc->sommet);
                if (graphe[Temparc->sommet]->predecesseur == -1 && Temparc->sommet != sommetInitial) {
                    graphe[Temparc->sommet]->predecesseur = i;
                }
                //Tant que il a encore des sommets adjacents
                while (Temparc->arc_suivant != NULL) {
                    //On les attribue au temp
                    Temparc = Temparc->arc_suivant;
                    //On les met en fin de file
                    if (graphe[Temparc->sommet]->couleur == 'B') {
                        enfiler(file, Temparc->sommet);
                    }
                    if (graphe[Temparc->sommet]->predecesseur == -1 && Temparc->sommet != sommetInitial) {
                        graphe[Temparc->sommet]->predecesseur = i;
                    }
                }
            }
            /*printf("%d ", graphe[i]->valeur);*/
            //le sommet i est de couleur noire
            graphe[i]->couleur = 'N';
        }
    }
    printf("\n");
}

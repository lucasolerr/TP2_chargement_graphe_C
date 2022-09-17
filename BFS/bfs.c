#include "bfs.h"

File fileVide() {
    File F;
    //On alloue dynamiquement la liste
    F = (File) malloc(sizeof(struct file));
    if (F == NULL) printf("erreur allocation fileVide");
    //La liste est vide donc de longueur 0
    F->longueur = 0;
    //La liste est vide donc ne contient aucune cellule
    F->tete = F->queue = NULL;
    return (F);
}

int longueur(File F) {
    if (F == NULL)printf("file existe pas - longueur");
    return (F->longueur);
}

void enfiler(File F, typage element) {
    Cellule cellule;
    if (F == NULL) printf("file existe pas - enfiler");

    //On alloue l'élément de la liste dynamiquement
    cellule = (Cellule) malloc(sizeof(struct cellule));
    //On vérifie l'allocation
    if (cellule == NULL) printf("erreur allocation memoire - enfiler");

    //On assigne à l'élément de la liste le numéro de sommet passé en paramètre
    cellule->element = element;
    //FIFO donc on va défiler par la tête donc on enfile en queue de liste soit le suivant = NULL
    cellule->suivant = NULL;
    //Si la liste est vide : Cellule = tête de liste et aussi queue de liste car 1 élement dans la liste
    if (longueur(F) == 0) {
        F->tete = F->queue = cellule;
    } else {
        //Sinon on part de la queue de la liste et on ajoute notre cellule
        F->queue->suivant = cellule;
        //On fait pointer la queue de la liste vers notre cellule
        F->queue = cellule;
    }
    //On augmente donc la taille de la liste de 1
    ++(F->longueur);
}

typage defilement(File F) {
    Cellule cellule;
    typage element;
    //La file n'existe pas
    if (F == NULL || longueur(F) == 0) printf("File existe pas - defilement");

    //On assigne une cellule temporaire à la cellule de tête de file
    cellule = F->tete;
    //On assigne au temporaire element le sommet de la cellule en tête de file
    element = cellule->element;

    //Si la file est de longueur 1
    if (longueur(F) == 1) {
        //On vide la file car l'objectif de cette fonction est d'enlever un élément de la liste
        //soit dans ce if de la mettre à 0
        F->tete = F->queue = NULL;
    } else {
        //Sinon on met l'élément de la file numéro 2 en tête de liste
        F->tete = F->tete->suivant;
    }
    //On libère l'ex-tête de liste
    free(cellule);
    //On réduit la longueur de la file
    --(F->longueur);
    //On retourne le sommet qui a été enlevé de la file
    return (element);
}




void InitialParcourLargeur(pSommet *graphe, int ordre, int sommetInitial, char couleurConnexe) {
    /*Initialisation de la couleur des sommets*/
    /*N=Noir, deja vu.  B=Blanc a voir*/
    printf("\n***PARCOURS EN LARGEUR***\n");
    int i = 0;
    //Création d'une file vide
    File file = fileVide();
    for (i = 0; i < ordre; i++) {
        //On assigne à chaque sommet la couleur 'Blanche'
        graphe[i]->couleur = 'B';
        graphe[i]->predecesseur = -1;
    }
    //On met dans la file le 1er sommet depuis lequel on souhaite faire le parcours BFS
    enfiler(file, sommetInitial);

    //Tant que la file est pleine
    while (longueur(file)) {
        //On enlève en tête une cellule
        i = defilement(file);
        //i contient le numéro de sommet qui a été défilé
        if (graphe[i]->couleur == 'B') {
            //Si i était non découvert
            //On créé le temportaire pour l'arc
            pArc Temparc = graphe[i]->arc;
            //Si le sommet à un pointeur sur structure Arc
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
                    enfiler(file, Temparc->sommet);
                    if (graphe[Temparc->sommet]->predecesseur == -1 && Temparc->sommet != sommetInitial) {
                        graphe[Temparc->sommet]->predecesseur = i;
                    }

                }
            }
            /*printf("%d ", graphe[i]->valeur);*/

            //le sommet i est de couleur noire
            graphe[i]->couleur = 'N';

            graphe[i]->connexite = sommetInitial;
        }
    }
    printf("\n");
}

void fonctionPredecesseurs(pSommet* pSommet, int ordre, int sommetInitial){
    //boucle for pour parcourir tous les sommets
    for (int i = 0; i < ordre; ++i) {
        //Si le sommet en question n'a pas déjà de prédécesseur alors
        if (pSommet[i]->predecesseur != -1) {
            //on met un temporaire à la valeur de ce sommet
            int tempPred = i;

            //on l'affiche
            printf("\n%d", i);

            //Fonction récursive qui permet de parcourir les prédécesseurs de ce sommet
            //Tant que le prédécesseur est != du sommet initial
            while (tempPred != sommetInitial) {
                //le temporaire prend la valeur du prédécesseur du n-1 sommet
                tempPred = pSommet[tempPred]->predecesseur;
                //on affiche ce prédécesseur
                printf(" <-- %d", tempPred);
            }
                        //on saute un ligne entre chaque branche de l'arborescence
            printf("\n");
        }
    }
}
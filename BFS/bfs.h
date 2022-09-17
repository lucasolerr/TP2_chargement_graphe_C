#ifndef TP2_CHARGEMENT_GRAPHE_C_BFS_H
#define TP2_CHARGEMENT_GRAPHE_C_BFS_H

#include "../Graphe.h"

void InitialParcourLargeur(pSommet* graphe, int ordre, int sommetInitial);

// fifo.h

typedef int typage;

struct cellule {
    typage element;
    struct cellule *suivant;
};

typedef struct cellule* Cellule;

struct file {
    int longueur;
    Cellule tete;
    Cellule queue;
};

typedef struct file* File;

#define fileEstVide(F) ((F)->longueur == 0)

File fileVide();
int longueur(File F);
void enfiler(File F, typage element);
typage tete(File F);
void defiler(File F);
typage defilement(File F);
void ecrireFile(File F);
void fonctionId(pSommet* pSommet, int ordre, int sommetInitial);



#endif

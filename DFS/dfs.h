#ifndef TP2_CHARGEMENT_GRAPHE_C_DFS_H
#define TP2_CHARGEMENT_GRAPHE_C_DFS_H

#include "../Graphe/Graphe.h"

void InitialParcourLongueur(pSommet* graphe, int ordre, int sommetInitial);

void ParcourLongueur(pSommet* graphe,int s, int ordre, int sommetInitial);

void InitialParcourLongueurPileLIFO(pSommet *graphe, int ordre, int sommetInitial);


#endif

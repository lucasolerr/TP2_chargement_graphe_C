#ifndef TP2_CHARGEMENT_GRAPHE_C_CONNEXITE_H
#define TP2_CHARGEMENT_GRAPHE_C_CONNEXITE_H

#include "../Graphe/Graphe.h"
#include "../BFS/bfs.h"

void attributionCouleursConnexes(pSommet* graphe, int ordre);

void afficherComposantesConnexes(pSommet* graphe, int ordre);

#endif

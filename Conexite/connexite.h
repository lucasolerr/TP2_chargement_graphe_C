#ifndef TP2_CHARGEMENT_GRAPHE_C_CONNEXITE_H
#define TP2_CHARGEMENT_GRAPHE_C_CONNEXITE_H

#include "../Graphe/Graphe.h"
#include "../BFS/bfs.h"

//Macro qui permet de définir un nombre maximal de composante connexes d'un graphe attribuables
#define CONST_TAILLE_MAX_COMPO_CONNEXES 10

void attributionCouleursConnexes(pSommet* graphe, int ordre);

#endif

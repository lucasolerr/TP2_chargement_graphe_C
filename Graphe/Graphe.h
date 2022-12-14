#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


/* Structure d'un arc*/
struct Arc
{
    int sommet; // numero de sommet d'un arc adjacent au sommet initial
    int valeur;
    struct Arc* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc* pArc;

/* Structure d'un sommet*/
struct Sommet
{
    struct Arc* arc;
    int valeur;
    char couleur;
    //On a choisi d'ajouter un paramètre dans la structure Sommet
    //pour connaître le prédécesseur d'un sommet directement dans sa structure propre
    int predecesseur;
    //Ajout d'un paramètre pour savoir si la connexité a été effectuée sur ce sommet
    char connexite;

};

/* Alias de pointeur sur un Sommet */
typedef struct Sommet* pSommet;

/* Alias d'un Graphe */
typedef struct Graphe
{
    int taille;
    int orientation;
    int ordre;
    pSommet* pSommet;
} Graphe;

// creer le graphe
Graphe* CreerGraphe(int ordre);

/* La construction du reseau peut se faire a partir d'un fichier dont le nom est passe en parametre
Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs */
Graphe * lire_graphe(char * nomFichier);

// Ajouter l'arete entre les sommets s1 et s2 du graphe
pSommet* CreerArete(pSommet* sommet,int s1,int s2);

/* affichage des successeurs du sommet num*/
void afficher_successeurs(pSommet * sommet, int num);

/*affichage du graphe avec les successeurs de chaque sommet */
void graphe_afficher(Graphe* graphe);

#endif // GRAPHE_H_INCLUDED

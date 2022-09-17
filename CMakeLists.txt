cmake_minimum_required(VERSION 3.20)
project(TP2_chargement_graphe_C C)

set(CMAKE_C_STANDARD 99)

add_executable(TP2_chargement_graphe_C main.c BFS/bfs.c BFS/bfs.h DFS/dfs.c DFS/dfs.h Graphe/Graphe.c Conexite/connexite.c Conexite/connexite.h)

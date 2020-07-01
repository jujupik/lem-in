# Lem-in

Projet algorithmique de parcours de graphe augmentant afin d'obtenir les flux maximum.

### Projet répondant à la problématique suivante :

Faire parcourir un graphe, préalablement recupéré, par un maximum de flux le plus rapidement possible.

### Principes utilisés :

Pour répondre à la problématique de ce sujet j'ai utilisé **l'algorithme de Suurballe**. 
Cet algorithme consiste à trouver, dans un graphe orienté, la liste des chemins disjoints (mais partageants les mêmes points de départ et d'arrivée)
permettant à un flux donné de parcourir le graphe le plus rapidement possible. 

Ce programme prend donc en paramètre un fichier, qu’il va lire afin de récupérer le nombre d'élements qui vont parcourir le graphe, les nodes, la nodes de départ (start), la node d’arrivée (end) et enfin la liste des connections entre les nodes.

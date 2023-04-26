# Objectif

Dans ce projet, il s'agit de concevoir et développer une application permettant de jouer au jeu de société
Schotten-Totten, créé par Reiner Knizia.

## 1 Fonctionnalités attendues

L'application devra permettre de jouer des parties dans une édition/variante choisie. Il sera possible de
jouer au moins à Schotten-Totten dans la variante de base et la variante tactique.



## 2 Éléments d'interface

L'application doit permettre de paramétrer une partie :

 choisir l'édition/variante du jeu dans laquelle on souhaite jouer ;
 paramètres des joueurs (nom, joueur humain/IA, type d'IA si plusieurs, rôle selon édition) ;

L'application doit disposer d'au moins 1 type d'IA. Pour cela, vous pourrez développer une IA très
simple qui prend ses décisions au hasard en fonction des possibilités.

L'application doit permettre de jouer la partie, de vérier les revendications des joueurs, et de déterminer
le gagnant.

Vous êtes libre d'organiser votre interface du moment qu'elle permet de piloter facilement l'application.
Les visuels doivent seulement être susants pour comprendre l'état du jeu. Ainsi, pour les cartes, bornes
ou murailles, il n'est pas spécialement demandé d'utiliser des graphismes. Soyez créatifs dans la façon
de gérer les tours pour faire en sorte qu'un joueur ne puisse pas voir la main de l'autre.



## 3 Évolution de l'application

L'architecture de votre application devra permettre d'intégrer de nouvelles éditions/variantes du jeu
sans remettre en cause le code existant (ou a minima). Les choix de conception devront donc permettre
de rendre l'application évolutive et notamment de garantir la facilité d'ajout des composants suivants
(sans impacter le reste du programme) :
 nouvelles IA joueurs,
 ajout de nouvelles éditions/variantes du jeu,
 éventuellement l'ajout d'éléments d'IHM de paramétrage liés aux nouveaux ajouts.

Vous démontrerez la pertinence de votre architecture dans votre rapport en expliquant comment ajouter
ces éléments.
En choisissant une édition/variante du jeu que vous n'avez pas implémentée (et que vous n'avez pas
à implémenter), à titre d'illustration, vous expliquerez dans votre rapport nal comment faire (sans le
coder) pour implémenter cette autre version (classes à créer, intégration dans l'architecture, éventuelles
modications de codes à prévoir, ...).
4 Consignes
 Le projet est à eectuer en groupe de 4 ou 5 étudiants (du même groupe de TD).
 Vous êtes libres de réutiliser et modier les classes déjà élaborées en TD pour les adapter votre
architecture.
 En plus des instructions standards du C++/C++11/C++14, vous pouvez utiliser l'ensemble des
bibliothèques standards du C++/C++11/C++14.
 L'interface graphique est à réaliser en utilisant le framework Qt.

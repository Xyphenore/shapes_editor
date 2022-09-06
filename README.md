# Shape Editor

Ce projet doit créer un éditeur de forme en C++

Pour pouvoir le compiler et l'exécuter, il vous faudra **CMAKE** en version ***3.1*** minimum, les bibliothèques
graphiques **X11** et **Xext** si vous êtes sous Linux, ou bien **GDI32** et **MSIMG32** sous Windows.
Il vous faudra aussi **Make** sous Linux, ou bien **Mingw32-make** sous Windows ou bien NMake. De même, il est
nécessaire d'avoir un compilateur C++, soit **gcc** ou **g++**, ou un de ces **forks**.

## Ce projet nécessite un Compilateur C++17 au minimum, par exemple gcc 8

- 1 - **Cloner** le depot du projet
- 2 - **Créer** à la racine du projet un **dossier build**, qui contiendra les constructions
- 3 - Vous avez deux choix :
    - soit vous utilisez l'**interface graphique** de CMAKE et vous remplissez les adresses nécessaires, soit l'adresses
      du dossier build et celle du dossier source
      Et vous vous laissez guider par le logiciel
    - soit vous utilisez un **terminal de commande**, et vous vous déplacez dans le dossier de build, *cf commande cd*.
      Et vous entrez la commande suivante : **cmake path_to_src** sous Linux et **cmake -G"MinGW Makefiles"
      path_to_src** sous Windows avec MingW32 d'installé ( en supposant que cmake est bien configuré dans la variable
      path, à vous de la paramétrer si ce n'est pas le cas )

- Cela va vous créer tout les MakeFiles nécessaires dans le dossier build, pour la construction de l'application
- 4 - Maintenant plus qu'à **exécuter make**, dans le terminal, dans le même dossier build avec la commande : **make**
  sous Linux et **mingw32-make** sous Windows si MingW32 est installé
- Un executable du nom de "**ShapeEditor**" est créé, il ne vous reste plus qu'à l'**exécuter**

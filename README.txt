# Projet OpenMP - Calcul parallèle de la somme de deux grands entiers avec utilisation d’algorithmes de type Carry Look Ahead

## Introduction
Ce projet vise à développer un programme parallèle en utilisant OpenMP pour calculer efficacement la somme de deux grands entiers en utilisant des algorithmes de type Carry Look Ahead (CLA). Le fichier README fournit des informations détaillées sur les options de compilation, les choix d'algorithmes et de conception, ainsi qu'une description des tâches effectuées dans le cadre de ce projet.

## Options de Compilation
Le programme peut être compilé à l'aide d'un compilateur prenant en charge OpenMP, tel que GCC. Voici la commande de compilation typique :

### Pour l'approche initiale du l'algorithme Carry Look Ahead sans parallélisme :
g++ sum.cpp -o sum -lstdc++
..Ensuite, exécutez la commande suivante pour fournir les inputs :
cat input.txt | ./sum  

### Pour l'approche utilisant l'algorithme Carry Look Ahead avec OpenMP :
g++ -fopenmp sumomp.cpp -o sumomp -lstdc++
..Ensuite, exécutez la commande suivante pour fournir les inputs :
cat input.txt | ./sumomp

Assurez-vous que votre compilateur prend en charge OpenMP et que l'option `-fopenmp` est activée.

## Choix d'Algorithmes et de Conception
### Algorithme Carry Look Ahead (CLA)
L'algorithme Carry Look Ahead a été choisi pour optimiser le calcul de la somme de deux grands entiers. Cet algorithme permet de générer et de propager les retenues de manière anticipée, réduisant ainsi les dépendances de données et permettant des calculs en parallèle, ce qui peut conduire à des performances améliorées.

### Parallélisation avec OpenMP
OpenMP a été choisi comme framework de parallélisation en raison de sa simplicité d'utilisation et de sa compatibilité avec les architectures multi-cœurs. Les directives OpenMP ont été utilisées pour créer des régions parallèles et paralléliser les boucles et les sections critiques du programme.

## Tâches Effectuées
Le programme comprend plusieurs fonctions et tâches, chacune remplissant un rôle spécifique dans le calcul de la somme de deux grands entiers.
1. `decimalToBinary(const string &decimal)` : Convertit un nombre décimal en une chaîne binaire.
2. `binaryToDecimal(const string &binary)` : Convertit une chaîne binaire en nombre décimal.
3. `generatePropagate(const string &bin1, const string &bin2, vector<int> &G, vector<int> &P)` : Génère les signaux G et P utilisés dans l'algorithme Carry Look Ahead.
4. `carryLookahead(const vector<int> &P, vector<int> &C)` : Effectue la propagation de la retenue à partir des signaux P générés précédemment.
5. `addStrings(string num1, string num2)` : Effectue l'addition binaire des deux grands entiers en utilisant l'algorithme Carry Look Ahead.

## Tests Proposés 
Des tests peuvent être effectués par vous même cher professeur pour vérifier la précision et l'efficacité du programme :
- Des tests unitaires pour chaque fonction pour s'assurer qu'elle produit les résultats attendus.
- Des tests de performance pour évaluer les performances du programme par rapport à des implémentations non parallèles et à d'autres méthodes d'addition de grands entiers.


## Conclusion
Ce projet démontre l'efficacité de l'utilisation de l'algorithme Carry Look Ahead avec OpenMP pour paralléliser le calcul de la somme de deux grands entiers. 
Le dossier contient également le rapport complet `Projet OpenMP` et le fichier `input.txt` utilisé pour les tests.
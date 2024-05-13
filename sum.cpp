#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

// Fonction pour convertir un nombre décimal en une chaîne binaire
string decimalToBinary(const string &decimal)
{
    string binary;
    // Conversion de chaque chiffre décimal en binaire
    for (char digit : decimal)
    {
        int num = digit - '0'; // Conversion du caractère en entier
        string binaryDigit;
        while (num > 0)
        {
            binaryDigit += to_string(num % 2); // Ajout du reste de la division par 2
            num /= 2;                          // Division par 2
        }
        reverse(binaryDigit.begin(), binaryDigit.end()); // Inversion de la chaîne binaire
        // Assurer que chaque chiffre binaire a une longueur fixe de 4 chiffres
        while (binaryDigit.size() < 4)
            binaryDigit = "0" + binaryDigit; // Ajout de zéros à gauche si nécessaire
        binary += binaryDigit;               // Concaténation des chiffres binaires
    }
    return binary; // Retourner la représentation binaire
}

// Fonction pour convertir une chaîne binaire en nombre décimal
string binaryToDecimal(const string &binary)
{
    string decimal;
    // Conversion de chaque groupe de 4 chiffres binaires en décimal
    for (size_t i = 0; i < binary.size(); i += 4)
    {
        string binaryDigit = binary.substr(i, 4);
        int num = stoi(binaryDigit, nullptr, 2);
        decimal += to_string(num);
    }
    return decimal;
}

// Fonction pour générer les signaux G et P
void generatePropagate(const string &bin1, const string &bin2, vector<int> &G, vector<int> &P)
{
    int size = max(bin1.size(), bin2.size());
    for (int i = 0; i < size; i++)
    {
        int a = (i < bin1.size()) ? bin1[i] - '0' : 0;
        int b = (i < bin2.size()) ? bin2[i] - '0' : 0;
        G[i] = a & b; // Générer le signal G
        P[i] = a | b; // Générer le signal P
    }
}

// Fonction pour effectuer la propagation de la retenue
void carryLookahead(const vector<int> &P, vector<int> &C)
{
    int size = P.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (P[j])
            {
                C[i] = 1; // Si le signal P est vrai, définir le signal C à 1
                break;
            }
        }
    }
}

// Fonction pour effectuer l'addition binaire avec l'algorithme Carry Look Ahead (CLA)
string addStrings(string num1, string num2)
{
    // Convertir les chaînes d'entrée décimales en binaire
    string bin1 = decimalToBinary(num1);
    string bin2 = decimalToBinary(num2);

    // Inverser les chaînes binaires pour faciliter le traitement
    reverse(bin1.begin(), bin1.end());
    reverse(bin2.begin(), bin2.end());

    int size = max(bin1.size(), bin2.size()) + 1; // Taille du résultat, en tenant compte d'une éventuelle retenue

    // Initialiser les vecteurs pour stocker les signaux
    vector<int> G(size, 0);
    vector<int> P(size, 0);
    vector<int> C(size, 0);

    // Générer les signaux G et P
    generatePropagate(bin1, bin2, G, P);

    // Générer les signaux de retenue
    carryLookahead(P, C);

    // Effectuer l'addition en utilisant les signaux de retenue
    string result;
    int carry = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int a = (i < bin1.size()) ? bin1[i] - '0' : 0;
        int b = (i < bin2.size()) ? bin2[i] - '0' : 0;
        int sum = a ^ b ^ carry;                   // Calcul de la somme
        result += sum + '0';                       // Ajout de la somme au résultat
        carry = (G[i] || (P[i] && carry)) ? 1 : 0; // Calcul de la nouvelle retenue
    }
    if (carry)
        result += '1'; // S'il y a une retenue à la fin

    // Inverser la chaîne résultante avant de la retourner
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    // Lecture des deux nombres en entrée
    string num1, num2;
    cin >> num1;
    cin >> num2;

    auto start = high_resolution_clock::now(); // Début du calcul du temps

    string sum = addStrings(num1, num2); // Addition des nombres

    auto stop = high_resolution_clock::now(); // Fin du calcul du temps

    auto duration = duration_cast<nanoseconds>(stop - start);        // Durée en nanosecondes
    auto duration_micro = duration_cast<microseconds>(stop - start); // Durée en microsecondes
    auto duration_milli = duration_cast<milliseconds>(stop - start); // Durée en millisecondes

    // Affichage du résultat
    cout << "La somme binaire est : " << sum << endl;
    cout << "Le resultat decimal est : " << binaryToDecimal(sum) << endl;

    cout << "Temps de calcul : " << duration.count() << " nanosecondes" << endl;
    cout << "Temps de calcul : " << duration_micro.count() << " microsecondes" << endl;
    cout << "Temps de calcul : " << duration_milli.count() << " millisecondes" << endl;
    return 0;
}

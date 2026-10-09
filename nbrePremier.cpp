/*
  ------------------------------------------------------------------------------
  Fichier     : nbre_1er.cpp
  Auteur(s)   : Maël Naudet
  Date        : 07.10.2026

  But         : identifier tous les nombres premiers compris
                et une valeur choisie par l'utilisateur

  Remarque(s) : les erreurs de saisie ne sont pas vérifiées

  Compilateur : gcc
  ------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main() {

    const int n_col = 5;
    const int min_limit = 2;
    const int max_limit = 1000;
    int user_value;
    char user_restart;

    cout << "Ce programme ..." << endl << endl;

    // Loop to restart the program
    do {

        // User input until it matches the limits
        do {
            cout << "entrer une valeur [" << min_limit << "-" << max_limit << "] : ";
            cin >> user_value;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }while (/*!cin || */(user_value < min_limit || user_value > max_limit));

        cout << endl << "Voici la liste des nombres premiers" << endl;

        int current_col = 0;

        // Iterate through all possible prime numbers until user value
        for (int i = min_limit; i <= user_value; i++) {
            bool isPrime = true;

            // Max value to check if prime
            const int maxValue = i >= 4 ? static_cast<int>(sqrt(i)) + 1 : 2;

            // Check if prime
            // for (int j = 2; j < i; j++) {
            for (int j = 2; j < maxValue ; j++) {
                // Dividable by something else than 1 or itself
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            // Print if prime
            if (isPrime) {
                cout << setw(10) << i;
                current_col++;
                if (current_col == n_col) {
                    current_col = 0;
                    cout << endl;
                }
            }
        }

        cout << endl << endl;

        // Loop : should the program restart ?
        do {
            cout << "Voulez-vous recommencer [O/N] : ";
            cin >> user_restart;
        } while (user_restart != 'O' && user_restart != 'N');

    } while (user_restart == 'O');

    cout << "Fin de programme" << endl;

    return EXIT_SUCCESS;
}


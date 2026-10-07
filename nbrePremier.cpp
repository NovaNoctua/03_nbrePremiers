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
#include <iostream>
#include <limits>

using namespace std;

int main() {

    const int min_limit = 2;
    const int max_limit = 1000;
    int user_value;
    char user_restart;

    cout << "Ce programme ..." << endl;

    // Loop to restart the program
    do {

        // User input until it matches the limits
        do {
            cout << "entrer une valeur [" << min_limit << "-" << max_limit << "] : ";
            cin >> user_value;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }while (/*!cin || */(user_value < min_limit || user_value > max_limit));

        cout << "Voici la liste des nombres premiers" << endl;

        // Iterate through all possible prime numbers until user value
        for (int i = min_limit; i <= user_value; i++) {
            bool isPrime = true;
            // Check if prime
            // for (int j = 2; j < i; j++) {
            for (int j = 2;(j >= 4) ? j < i / 2 : j < i ; j++) {
                // Dividable by something else than 1 or itself
                if (i % j == 0) {
                    isPrime = false;
                    // cout << i << " is not prime." << endl;
                    break;
                }
            }
            // Print if prime
            if (isPrime) {
                cout << i << ", ";
            }
        }

        cout << endl;

        // Loop should the program restart ?
        do {
            cout << "Voulez-vous recommencer [O/N] : ";
            cin >> user_restart;
        }while (user_restart != 'O' && user_restart != 'N');

    }while (user_restart == 'O');

    cout << "Fin de programme" << endl;


    return EXIT_SUCCESS;
}


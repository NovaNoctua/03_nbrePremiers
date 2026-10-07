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

using namespace std;

int main() {

    const int min_value = 2;
    const int max_value = 1000;
    int user_value;

    do {
        cout << "entrer une valeur [" << min_value << "-" << max_value << "] : ";
        cin >> user_value;
    }while (/*!cin || */(user_value < min_value || user_value > max_value));

    cout << user_value << endl;

    return EXIT_SUCCESS;
}


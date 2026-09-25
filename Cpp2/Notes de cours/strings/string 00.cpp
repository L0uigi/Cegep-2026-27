#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*

LE TYPE STRING

    - une variable de type string est un contenant pour conserver une chaine de caractères quelconques

    - il est possible de connaitre la taille de la chaine de caractères

*/

int main()
{
    // A) définition d'une variable de type string

    string a;                   // a initialisée avec la chaine vide "" par défaut
    string b = "";              // b initialisée avec la chaine vide ""
    string c = "bonjour";       // c initialisée avec la chaine "bonjour"


    // B) affectation d'une nouvelle valeur

    a = "test";         // la valeur de a est "test"              
    b = 'A';            // la valeur de b est "A"
    c = "123";	        // la valeur de c est "123"  att: différent de l'entier 123
    a = "";		        // la valeur de a est ""


    // C) affichage

    string message = "bienvenue en programmation !";

    cout << message << endl;


    // D) taille (en caractères) de la string

    int taille = message.size();    // size() retourne la taille de message     att: message.length() marche aussi

    cout << "la taille du message: " << taille << " caracteres" << endl;     


    // E) taille maximum

    cout << "la taille maximum: " << message.max_size() << endl;


	_getch();
}
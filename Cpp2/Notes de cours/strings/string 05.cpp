#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*

AUTRES UTILITAIRES PRATIQUES AVEC STRING

    empty()                 vérifier si une string est vide
    clear()                 vider une string
    +=                      ajouter à la fin d'une string
    insert()                insérer des caractères dans une string
    push_back()             ajouter un caractère à la fin
    pop_back()              retirer le dernier caractère
    front() / back()        accéder au premier ou au dernier caractère
    find(..., position)     rechercher à partir d'une position donnée
    getline()               lire une ligne complète, incluant les espaces
    to_string()             convertir un nombre en string

    REMARQUE:
        getline() n'est pas une fonction membre de la classe string, mais elle est
        particulièrement utile lorsqu'on veut saisir une phrase dans une string.

        to_string() n'est pas non plus une fonction membre de string. Elle retourne
        une string représentant la valeur numérique reçue.

*/

int main()
{
    // EXEMPLE #1 -- Vérifier si une string est vide et la vider
    {
        string s = "bonjour";

        cout << s.empty() << endl;  // affiche 0

        s.clear();

        cout << s.empty() << endl;  // affiche 1
    }


    // EXEMPLE #2 -- Ajouter du contenu à la fin
    {
        string s = "bon";

        s += "jour";
        s += '!';

        cout << s << endl;          // affiche "bonjour!"
    }


    // EXEMPLE #3 -- Ajouter et retirer un caractère à la fin
    {
        string s = "abc";

        s.push_back('d');
        cout << s << endl;          // affiche "abcd"

        s.pop_back();
        cout << s << endl;          // affiche "abc"
    }


    // EXEMPLE #4 -- Premier et dernier caractère
    {
        string s = "bonjour";

        if (!s.empty())
        {
            cout << s.front() << endl;   // affiche 'b'
            cout << s.back() << endl;    // affiche 'r'
        }
    }


    // EXEMPLE #5 -- Insérer dans une string
    {
        string s = "bonsoir";

        s.insert(3, "jour et ");

        cout << s << endl;          // affiche "bonjour et soir"
    }


    // EXEMPLE #6 -- Rechercher à partir d'une position donnée
    {
        string s = "un deux un trois un";
        size_t pos = 0;

        pos = s.find("un", pos);        // trouve le premier "un"
        cout << pos << endl;            // affiche 0

        pos = s.find("un", pos + 1);    // poursuit la recherche après cette position
        cout << pos << endl;            // affiche 8
    }


    // EXEMPLE #7 -- Lire une ligne complète
    {
        string phrase;

        cout << "Entrez une phrase: ";
        getline(cin, phrase);

        cout << "Vous avez entre: " << phrase << endl;
    }


    // EXEMPLE #8 -- Convertir des nombres en string avec to_string()
    {
        int age = 21;
        float temperature = 18.5f;
        double moyenne = 92.75;

        string s = "Age: ";
        s += to_string(age);

        cout << s << endl;                  // affiche "Age: 21"
        cout << to_string(temperature) << endl; // affiche généralement "18.500000"
        cout << to_string(moyenne) << endl;     // affiche généralement "92.750000"
    }


    // EXEMPLE #9 -- Concaténer du texte et des nombres
    {
        string nom = "Alice";
        int score = 125;
        double temps = 8.4;

        string resultat = nom + " : " + to_string(score) + " points";

        string messageTemps = "Temps: ";
        messageTemps += to_string(temps);
        messageTemps += " secondes";

        cout << resultat << endl;
        cout << messageTemps << endl;
    }


    _getch();
}

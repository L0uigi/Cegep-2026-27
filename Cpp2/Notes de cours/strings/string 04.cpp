#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*

LE TYPE STRING ET SES UTILITAIRES

    rechercher, effacer, remplacer, extraire, c-string

    RAPPEL: la position du premier caractère d'une string est à l'indice 0

*/

int main()
{
    // EXEMPLE #1 -- Rechercher une sous string dans une string, à partir du début avec find() ou de la fin avec rfind()
    {
        size_t f, r, n;             // pour les positions
        string s = "12ab3333ab21";

        f = s.find("ab");	// f = 2    --> trouvé à l'indice 2
        r = s.rfind("ab");	// r = 8    --> trouvé à l'indice 8

        n = s.find("z");	// n = string::npos   --> n'a pas été trouvée --> vaut SIZE_MAX
    

        cout << f << ", " << r << ", " << n << endl; // affiche: "2, 8, SIZE_MAX"

        if (s.find("z") == string::npos)
            cout << "inexistante" << endl << endl;
    }


    // EXEMPLE #2 -- Effacer des caractères dans une string
    {
        string s = "123reste456";

        s.erase(0, 3);              // effacer 3 caractères à partir de l'indice 0  --> efface "123" --> s == "reste456"

        s.erase(5, 3);              // effacer 3 caractères à partir de l'indice 5  --> efface "456" --> s == "reste"

        cout << s << endl << endl;  // affiche: "reste"
    }


    // EXEMPLE #3 -- Remplacer des caractères par d'autres
    {
        string s = "mot1 mot2 mot3 mot4";

        s.replace(5, 9, "motx");    // remplacer les 9 caractères à partir de l'indice 5 avec "motx"  --> s == "mot1 motx mot4"

        cout << s << endl << endl;	// affiche: "mot1 motx mot4"
    }


    // EXEMPLE #4 -- Extraire une sous-chaine
    {
        string s = "123sous456chaine", sub1, sub2;

        sub1 = s.substr(3, 4);      // extraire 4  caractères à partir de l'indice 3  --> sub1 == "sous"
        sub2 = s.substr(10);        // extraire les caractères de l'indice 10 jusqu'à la fin --> sub2 == "chaine"

        cout << s << ", " << sub1 << ", " << sub2 << endl << endl;  // affiche: "123sous456chaine, sous, chaine"
    }

	_getch();
}
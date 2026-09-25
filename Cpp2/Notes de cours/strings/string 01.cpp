#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*

LE TYPE STRING ET LES OPÉRATEURS DE COMPARAISON

    - c'est la valeur de l'entier ascii qui sert de comparaison

    - à valeur égale, c'est la taille de la chaine qui est considérée

*/

int main()
{
    // EXEMPLES -- Les opérateurs de comparaison ( "==" , "!=" , "<" , "<=" , ">" , ">=" )
    
    string s1 = "bobo", s2 = "toto", s3 = "Toto", s4 = "tototo", s5 = "T";

    cout << (s1 < s3) << endl;	// affiche --> "0"	(vrai)

    cout << (s2 == s3) << endl;	// affiche --> "0"  (faux)

    cout << (s2 < s3) << endl;	// affiche --> "0"	(faux) -- les majuscules avant les minuscules dans la table ascii
    
    cout << (s2 < s4) << endl;	// affiche --> "1"	(vrai) -- car s2.size() < s4.size()

    cout << (s2 < s5) << endl;	// affiche --> "0"	(faux)

    cout << endl;

	_getch();
}
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*

LA CONCATÉNATION DE STRING

    - L'opérateur '+' permet de concaténer (on dit aussi juxtaposer) une string à une autre. L'opérande de gauche
      doit absolument être de type string.

    - Attention:
        - "une chaine" n'est pas une string en C++
        - Comme nous le verrons plus tard, il s'agit d'un tableau de char (ou quelque fois appelé c-string)

*/

int main()
{
    // EXEMPLE #1 -- opérateur +
    string s;

    s = "La";
    s = s + " " + "concat\x82nation";
    s = s + ' ' + "!!!";

    cout << s << endl;	// affiche --> "La concaténation !!!"


    // EXEMPLE #2 -- 
    char c;

    cout << "input:  ";

    s = "";
    for (int i = 1; i <= 4; ++i)
    {
        c = _getch();
        cout << c;
        s = s + c;
    }
    cout << endl << "output: " << s << endl;


    // EXEMPLE #3 -- Attention
    s = "";
    s = s + "ying" + "yang";	// ok
	
	// s = "ying" + "yang"  	// erreur ne fonctionne pas car l'opérande de gauche de '+' ==> "ying" n'est pas une string 

	_getch();
}
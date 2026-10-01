#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

#include <sstream> // pour le type stringstream et ses outils

using namespace std;

/*

LE TYPE STRINGSTREAM ET SES OUTILS

	stringstream est un type de contenant qui permet de gérer un flux (stream) de caractères (i.e. une liste de caractères) dans une mémoire tampon

		a) le flux peut servir pour extraire des caractères	(à la manière d'un cin)

		b) le flux peut servir pour accumuler des caractères	(à la manière d'un cout)

		c) le flux peut servir pour faire (a) et (b) en même temps

	Att: le flux de caractères n'est pas lié au clavier (comme le cin) ou à la fenêtre de la console (comme le cout)

*/


int main()
{
	// EXEMPLE #1 -- définition et initialisation d'un stringstream
	{		
		string texte = "ceci est mon texte";
		
		stringstream ss(texte);												// défini ss et initialise son tampon de caractères avec la string texte

		ss.str("");															// réinitialise le tampon de ss avec la chaine vide

		ss << "voici " << 2 << " nombres: " << 10 << " et " << 1.5;			// ajoute successivement les expressions à la fin du tampon de ss

		ss.str(texte);														// réinitialise ss avec texte
	}

	// EXEMPLE #2 -- le stringstream pour faire de l'extraction
	{
		int i;
		double d;

		stringstream ss;

		ss << "  125   10.85  ";

		ss >> i >> d ;

		if (ss.fail())				// vérifier si l'extraction n'a pas fonctionnée
		{
			ss.clear();				// remettre le stream ss en état de marche
			ss.str("");				// réinitialise le tampon de ss avec la chaine vide
		}
		else
		{
			cout << "i = " << i << endl << "d = " << d << endl << endl;
		}
	}

	// EXEMPLE #3 -- construction d'un texte (string) avec des valeurs numériques insérées dans celui-ci
	{	
		const double TPS = 0.05, TVQ = 0.09975;
		double montant = 0, total;

		string texte;
		stringstream ss;

		cout << "Montant ($) avant taxe ? : ";
		cin >> montant;

		total = montant * (1 + TPS + TVQ);

		ss << fixed << setprecision(2);
		ss << "Un montant de " << montant << " $ " << "donne " << total << " $" << " avec les taxes !" << endl;
		
		texte = ss.str();		// obtenir le contenu du stream ss sous forme de string et l'affecter à texte;

		cout << endl << texte;
	}

	_getch();
}
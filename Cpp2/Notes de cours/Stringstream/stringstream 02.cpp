#include <iostream>
#include <string>
#include <conio.h>

#include <sstream> // pour le type stringstream et ses outils

using namespace std;

/*

LE TYPE STRINGSTREAM ET SES OUTILS

	Nettoyer une variable string avec les stringstream

		--> enlever les blancs inutiles au début et à la fin du texte

		--> mettre un blanc maximun entre chaque mot

		--> eliminer les '\t' et les '\n'
*/

void wipe(string& s)					// pour nettoyer s
{
	string mot;
	stringstream ss(s);					// initialise le stream ss avec le texte s
	
	s = "";
	ss >> s;							// extraire le premier mot
	while (ss >> mot) s += " " + mot;	// tant que l'extraction marche: extraire les autres mots en y ajoutant un blanc avant
}

int main()
{
	// nettoyer le texte

	string text = "\t\t mon  texte	\t\t avec   des blancs  \n   inutiles    !   ";

	cout << endl << text << endl;
	wipe(text);
	cout << endl << text << endl;

	_getch();
}
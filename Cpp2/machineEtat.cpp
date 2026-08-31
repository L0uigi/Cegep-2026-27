#include <iostream>
#include <conio.h>

#include "X:\\cvm_25.h"

using namespace std;

enum Etat {ETEINTE, PAUSE, LENT, MOYEN, RAPIDE, INVALIDE};

const string ETAT_AFFICHAGE[6]{ "ETEINTE", "PAUSE", "LENT", "MOYEN", "RAPIDE", "INVALIDE" };

void afficherEtat(Etat etat);
Etat saisirEtatSuivant();
Etat changerEtat(Etat actuel, Etat suivant);
bool demandeQuitter(Etat actuel, Etat suivant);
void actualiserAffichage(Etat actuel, int x, int y);
void executerMachine();

int	main(void)
{
	cout << "Les options de la machine : " << endl
		<< "e = ETEINTE" << endl
		<< "p = PAUSE" << endl
		<< "l = LENT" << endl
		<< "m = MOYEN" << endl
		<< "r = RAPIDE" << endl;

	cout << "Eteindre deux fois pour quitter le programme" << endl;

	executerMachine();
	cout << "Au revoir";
	return 0;
}

void afficherEtat(Etat etat)
{
	cout << ETAT_AFFICHAGE[etat] << endl;
}
Etat saisirEtatSuivant()
{
	char reponse;
	reponse = _getch();

	switch (reponse)
	{
	case 'e': return Etat::ETEINTE;
	case 'p': return Etat::PAUSE;
	case 'l': return Etat::LENT;
	case 'm': return Etat::MOYEN;
	case 'r': return Etat::RAPIDE;
	default: return Etat::INVALIDE;
	}
}
// deplacement de 1.
Etat changerEtat(Etat actuel, Etat suivant)
{
	if (abs(actuel - suivant) > 1 || suivant == INVALIDE)
		return suivant;
	else
		return actuel;
}
bool demandeQuitter(Etat actuel, Etat suivant)
{
	if (actuel == Etat::ETEINTE && suivant == Etat::ETEINTE)
		return true;
	return false;
}
void	actualiserAffichage(Etat actuel, int x, int y)
{
	gotoxy(x, y);
	clreol();
	afficherEtat(actuel);
}
void executerMachine()
{
	Etat actuel = ETEINTE;
		int x = wherex();
		int y = wherey();
	
		bool continuer = true;
	
		while (continuer)
		{
			Etat suivant = saisirEtatSuivant();

			if (demandeQuitter(actuel, suivant))
				continuer = false;
			else
			{
				actuel = changerEtat(actuel, suivant);
				actualiserAffichage(actuel, x, y);
			}
		}
}

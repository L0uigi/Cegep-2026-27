#include <iostream>
#include "X:\cvm_25.h"
#include <conio.h>
#include <windows.h>

using namespace std;

enum class EtatFeu { ROUGE, JAUNE, VERT };

const Color COULEUR_FEU[3]{ Color::red, Color::yel, Color::grn }; // changer la couleur dans la console.
const string STR_COULEUR[3]{ "ROUGE", "JAUNE", "VERT" };
const int DUREES_FEU[3]{ 5000, 2000, 5000 };

void afficherEtat(EtatFeu etat, int x, int y);
EtatFeu changerEtat(EtatFeu etat);
char lireTouche();
int	obtenirDureeMs(EtatFeu etat);
void simulation();

int	main(void)
{
	simulation();

	setcolor(Color::wht);

	cout << "\nAu revoir!";
	return 0;
}

void afficherEtat(EtatFeu etat, int x, int y)
{
	gotoxy(x, y);
	clreol();
	switch (etat)
	{
	case EtatFeu::ROUGE: setcolor(Color::red); cout << STR_COULEUR[0]; break;// int idx = (int)etat; pour utiliser l'indice de COULEUR_FEU et STR_COULEUR; ( a cause de class apres enum)
	case EtatFeu::JAUNE: setcolor(Color::yel); cout << STR_COULEUR[1]; break;
	case EtatFeu::VERT: setcolor(Color::grn); cout << STR_COULEUR[2]; break;
	default: setcolor(Color::red); cout << STR_COULEUR[0];
	}

}
EtatFeu changerEtat(EtatFeu etat)
{
	switch (etat)
	{
		case EtatFeu::ROUGE: return EtatFeu::VERT;
		case EtatFeu::JAUNE: return EtatFeu::ROUGE;
		case EtatFeu::VERT: return EtatFeu::JAUNE;
	}
}
char lireTouche()
{
	if (!_kbhit())
	{
		return 0;
	}
	char touche = _getch();

	while (_kbhit())
	{
		_getch();
	}
	return touche;
}
int	obtenirDureeMs(EtatFeu etat)
{
	switch (etat)
	{
		case EtatFeu::ROUGE: return 5000;
		case EtatFeu::JAUNE: return 2000;
		case EtatFeu::VERT: return 5000;
		default: return 5000;
	}
}
//flipper a jaune si on appui espace
void simulation()
{
	bool continuer = true;

	EtatFeu etatCourant = EtatFeu::VERT;

	int dureeMs = obtenirDureeMs(etatCourant);

	cout << "Le feu est : ";

	int x = wherex(); // permet de retourner a un endroit particulier dans la console.
	int y = wherey();

	afficherEtat(etatCourant, x, y);

	char touche = 0;
	while (continuer)// roule le timer et change l'etat.
	{
		if (dureeMs < 0)
		{
			etatCourant = changerEtat(etatCourant);
			dureeMs = obtenirDureeMs(etatCourant);
			afficherEtat(etatCourant, x, y);
		}
		else
		{
			Sleep(100); // passe le temps;
			dureeMs = dureeMs - 100;
		}
		touche = lireTouche();

		if (touche == 'q' || touche == 'Q')
		{
			continuer = false;
		}
		if (touche == ' ' && etatCourant == EtatFeu::VERT)
		{
			etatCourant = EtatFeu::JAUNE;
			dureeMs = obtenirDureeMs(etatCourant);
			afficherEtat(etatCourant, x, y);
		}
	}
}

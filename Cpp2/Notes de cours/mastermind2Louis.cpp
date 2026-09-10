#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "C:\Users\1957480\source\repos\MastermindV2\cvm_25.h"

using namespace std;

const int TAILLE_MAX = 12;
//const int TAILLE = 5;
const char LETTRE_VALIDE[8]{ 'q', 'w', 'e', 'r', 't', 'y','u', 'i' };
//const char NBRE_LETTRE_DISPO = 8;
//const int NB_ESSAIS = 12;

enum class Deplacement
{
	LEFT = 75,
	RIGHT = 77,
	BACK = 8
};

using Dp = Deplacement;

//char enigme[TAILLE]{};
//char reponseJoueur[TAILLE]{};
//char copieEnigme[TAILLE]{};

// pour verifier solution, changer la copie de la solution pour mettre des 0 pour les lettre devinee ou touchee. Refaire une copie avec lettre originaux.
void	genererEnigme(char enigme[], char copieEnigme[], int taille, int NbreLettreDispo)
{

	for (size_t i = 0; i < taille; i++)
		enigme[i] = LETTRE_VALIDE[rand() % NbreLettreDispo]; // [i] pour tester !!!!!;
}
void	genererCopieEnigme(char tab[], char copieEnigme[], int taille)
{
	for (int i = 0; i < taille; i++)
	{
		copieEnigme[i] = tab[i];
	}
}
bool lettreEstValide(char c, int NbreLettreDispo)
{
	for (size_t i = 0; i < NbreLettreDispo; ++i)
	{
		if (c == LETTRE_VALIDE[i])
			return true;
	}
	return false;
}
char saisirEtAfficherLettre(int NbreLettreDispo)
{
	char lettre;

	do
	{
		lettre = _getch();
		lettre = tolower(lettre);
	} while (!lettreEstValide(lettre, NbreLettreDispo));
	cout << lettre;
	return lettre;
}
// verifier si 1 bonne lettre mais mauvaise place.
bool	verifierPoint(char c, char copieEnigme[], int taille)
{
	for (int i = 0; i < taille; i++)
	{
		if (copieEnigme[i] == c)
		{
			copieEnigme[i] = '0';
			return true;
		}
	}
	return false;
}
// retourne 1 si reponse complete trouve. Imprime X et . selon les characters trouves.
bool	verifierSolution(char tab[],char copieEnigme[], int taille)
{
	bool vraiReponse = false;
	int count = 0;

	for (int i = 0; i < taille; i++)
	{
		if (copieEnigme[i] == tab[i])
		{
			copieEnigme[i] = '0';
			cout << 'X';
			count++;
		}
		if (count == taille)
			vraiReponse = true;
	}
	for (int i = 0; i < taille; i++)
	{
		if (verifierPoint(tab[i], copieEnigme, taille) == true)
		{
			cout << '.';
		}
	}
	return vraiReponse;
}

int	saisirNombre(int max, int min, string message)
{
	int result;
	do
	{
		clreol();
		cout << message;
		cin >> result;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(64, '\n');
		}
	} while (cin.fail() || result < min || result > max);
	return result;
}
int	main(void)
{
	
	unsigned int i = 0;
	bool vraiReponse;
	char reponseRejouer;
	char enigme[TAILLE_MAX]{};
	char reponseJoueur[TAILLE_MAX]{};
	char copieEnigme[TAILLE_MAX]{};
	unsigned int nbreEssais;
	int	taille;
	int NbreLettreDispo;
	do
	{
		clrscr();
		//cout << "Combien d'essais voulez-vous ? (entre 6 et 18) : " << endl;
		nbreEssais = saisirNombre(18, 6, "Combien d'essais voulez-vous ? (entre 6 et 18) : ");
		//cout << "Nombre de charactere a deviner ? (entre 3 et 12) : " << endl;
		taille = saisirNombre(12, 3, "Nombre de charactere a deviner ? (entre 3 et 12) : ");
		//cout << "Choissez la difficulte(Nombre de lettre differente entre 2 et 8) : ";
		NbreLettreDispo = saisirNombre(8, 2, "Choissez la difficulte(Nombre de lettre differente entre 2 et 8) : ");

		//cout << nbreEssais << endl << taille << endl << NbreLettreDispo << endl;   // test 
		_getch();
		srand(time(0));
		genererEnigme(enigme, copieEnigme, taille, NbreLettreDispo);
		system("cls"); // clear console
		for (int k = 0; k < taille; k++)
		{
			cout << enigme[k];
		}

	//	cout << "\t\t\t\t   Les lettres disponibles sont : q w e r t y u i : " << endl; // a modifier
		cout << "\t\t\t\t   Les lettres disponibles sont : ";
		for (int l = 0; l < NbreLettreDispo; l++)
		{
			cout << LETTRE_VALIDE[l] << ' ';
		}
		cout << endl;
		// saisir lettres, compare avec copie enigme, imprime X, imprime .  
		while (i <= nbreEssais)
		{
			cout << "\nTour " << i << " : ";
			for (int y = 0; y < taille; y++)
			{
				reponseJoueur[y] = saisirEtAfficherLettre(NbreLettreDispo);
			}
			cout << " -> ";
			genererCopieEnigme(enigme, copieEnigme, taille); // stocke dans enigmeCopie.
			vraiReponse = verifierSolution(reponseJoueur,copieEnigme, taille);
			if (vraiReponse == true)
				break;
			i++;
		}

		cout << "\n\n\nLe code est : ";
		for (int k = 0; k < taille; k++)
		{
			cout << enigme[k];
		}
		cout << endl;
		if (vraiReponse == true)
			cout << "Felications ! vous avez reussi" << endl;
		else
			cout << "Meilleur chance la prochaine fois !" << endl;
		cout << "Voulez-vous rejouer (O / N) ? ";
		reponseRejouer = _getch();
		reponseRejouer = toupper(reponseRejouer);
	} while (reponseRejouer == 'O');
	return 0;
}
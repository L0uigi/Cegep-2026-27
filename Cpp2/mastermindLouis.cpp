#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

const int TAILLE = 5;
const char LETTRE_VALIDE[8]{ 'q', 'w', 'e', 'r', 't', 'y','u', 'i'};
const char NBRE_LETTRE_DISPO = 8;
const int NB_ESSAIS = 12;
char enigme[TAILLE]{};
char reponseJoueur[TAILLE]{};
char copieEnigme[TAILLE]{};

// pour verifier solution, changer la copie de la solution pour mettre des 0 pour les lettre devinee ou touchee. Refaire une copie avec lettre originaux.
void	genererEnigme(void)
{

	for (size_t i = 0; i < TAILLE; i++)
		enigme[i] = LETTRE_VALIDE[rand() % NBRE_LETTRE_DISPO]; // [i] pour tester !!!!!;
}
void	genererCopieEnigme(char tab[])
{
	for (int i = 0; i < TAILLE; i++)
	{
		copieEnigme[i] = tab[i];
	}
}
bool lettreEstValide(char c)
{
	for (size_t i = 0; i < NBRE_LETTRE_DISPO; ++i)
	{
		if (c == LETTRE_VALIDE[i])
			return true;
	}
	return false;
}
char saisirEtAfficherLettre()
{
	char lettre;

	do
	{
		lettre = _getch();
		lettre = tolower(lettre);
	} while (!lettreEstValide(lettre));
	cout << lettre;
	return lettre;
}
// verifier si 1 bonne lettre mais mauvaise place.
bool	verifierPoint(char c)
{
	for (int i = 0; i < TAILLE; i++)
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
bool	verifierSolution(char tab[])
{
	bool vraiReponse = false;
	int count = 0;

	for (int i = 0; i < TAILLE; i++)
	{
		if (copieEnigme[i] == tab[i])
		{
			copieEnigme[i] = '0';
			cout << 'X';
			count++;
		}
		if (count == TAILLE)
			vraiReponse = true;
	}
	for (int i = 0; i < TAILLE; i++)
	{
		if (verifierPoint(tab[i]) == true)
		{
			cout << '.';
		}
	}
	return vraiReponse;
}
int	main(void)
{
	unsigned int i;
	bool vraiReponse;
	char reponseRejouer;
	
	do
	{
		srand(time(0));
		genererEnigme();
		system("cls"); // clear console

		i = 0;
		cout << "\t\t\t\t   Les lettres disponibles sont : q w e r t y u i" << endl;
		cout << enigme << endl; //test 
		// saisir lettres, compare avec copie enigme, imprime X, imprime .  
		while (i <= NB_ESSAIS)
		{
			cout << "\nTour " << i << " : ";
			for (int y = 0; y < TAILLE; y++)
			{
				reponseJoueur[y] = saisirEtAfficherLettre();
			}
			cout << " -> ";
			genererCopieEnigme(enigme); // stocke dans enigmeCopie.
			vraiReponse = verifierSolution(reponseJoueur);
			if (vraiReponse == true)
				break;
			i++;
		}

		cout << "\n\n\nLe code est : " << enigme << endl;
		if (vraiReponse == true)
			cout << "Felications ! vous avez reussi" << endl;
		else
			cout << "Meilleur chance la prochaine fois !" << endl;
		cout << "Voulez-vous rejouer (O / N) ? ";
		reponseRejouer = _getche();
		reponseRejouer = toupper(reponseRejouer);
	} while (reponseRejouer == 'O');
	return 0;
}
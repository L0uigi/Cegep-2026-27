#include <iostream>
#include <conio.h>
using namespace std;

const int TAILLE = 5;
const char LETTRE_VALIDE[8]{ 'q', 'w', 'e', 'r', 't', 'y','u', 'i'};
const char NBRE_LETTRE_DISPO = 5;
const int NB_ESSAIS = 12;
char enigme[TAILLE]{};
char reponseJoueur[TAILLE]{};
char copieEnigme[TAILLE]{};

// pour verifier solution, changer la copie de la solution pour mettre des 0 pour les lettre devinee ou touchee. Refaire une copie avec lettre originaux.
void	genererEnigme(void)
{

	for (size_t i = 0; i < TAILLE; i++)
		enigme[i] = LETTRE_VALIDE[rand() % TAILLE]; // [i] pour tester !!!!!;
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

int	main(void)
{
	unsigned int i = 1;
	srand(time(0));
	genererEnigme();
	

	cout << "Les lettres disponibles sont : q w e r t y u i"<< endl;
	// saisir lettres, compare avec copie enigme, imprime X, imprime .  
	while (i <= NB_ESSAIS)
	{
		cout << "\nTour " << i << " : ";
		for (int y = 0; y < TAILLE; y++)
		{
			saisirEtAfficherLettre();
		}
		cout << "->"
		i++;
	}
	
	cout << endl << "La solution etait : " << enigme << endl;

	return 0;
}
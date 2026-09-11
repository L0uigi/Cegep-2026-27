#include <iostream>
#include "cvm_25.h" 

using namespace std;

const size_t LARGEUR_CASE = 3;
const size_t HAUTEUR_CASE = 3;
const size_t COIN_X = 4;
const size_t COIN_Y = 6;
const size_t GAP_X = 1;
const size_t GAP_Y = 1;

void dessinerCase(size_t ligStart, size_t colStart, char contour, char interieur);
void dessinerDamier(size_t nbCasesHor, size_t nbCasesVer);

int	main(void)
{
	gotoxy(COIN_X, COIN_Y);
	dessinerDamier(5, 5);
}

void dessinerCase(size_t ligStart, size_t colStart, char contour, char interieur)
{
	gotoxy(colStart, ligStart);

	for (int i = 0; i < HAUTEUR_CASE; ++i)
	{
		for (int j = 0; j < LARGEUR_CASE; ++j)
		{
			if (i == 0 || i == HAUTEUR_CASE - 1)
			{
				cout << contour;
			}
			else if (j == 0 || j == LARGEUR_CASE - 1)
			{
				cout << contour;
			}
			else
			{
				cout << interieur;
			}
		}
		gotoxy(colStart, ligStart + i + 1); // car i commence a 0
	}
}

void dessinerDamier(size_t nbCasesHor, size_t nbCasesVer)
{
	for (int i = 0; i < nbCasesVer; ++i)
	{
		for (int j = 0; j < nbCasesHor; ++j)
		{
			if ((i + j) % 2 == 0)
			{
				dessinerCase(COIN_X + (HAUTEUR_CASE + GAP_X) * i, COIN_Y + (LARGEUR_CASE + GAP_Y) * j, 'X', 'O');
			}
			else
				dessinerCase(COIN_X + (HAUTEUR_CASE + GAP_X) * i , COIN_Y + (LARGEUR_CASE + GAP_Y) * j, 'O', 'X');
			
		}
	}
}
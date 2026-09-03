#include <iostream>

using namespace std;

void	cppSwap(int& a, int& b)
{
	int temp = a;

	a = b;
	b = temp;
}


void selectionSort(int tab[], int taille) // faire un swap 1 fois. On utilise l'indice du tableau.
{
	size_t IdxMin;
	for (size_t i = 0; i < taille; ++i)
	{
		for (size_t j = i ; j < taille; ++j)
		{
			IdxMin = i;
			if (tab[j] < tab[i])
			{
				IdxMin = j;
			}
		}
		cppSwap(tab[i], tab[IdxMin]);
	}
}

void	afficherTab(int tab[], int taille)
{
	for (int i = 0; i < taille; ++i)
	{
		cout << tab[i];
	}
}

int main(void)
{
	int tab[]{ 5,8,3,9,1 };

	afficherTab(tab, 5);
	cout << endl;
	selectionSort(tab, 5);
	afficherTab(tab, 5);
}
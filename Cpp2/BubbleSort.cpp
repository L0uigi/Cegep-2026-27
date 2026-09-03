#include <iostream>
using namespace std;

void	cppSwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void	bubbleSort(int tab[], int taille) // tab[] dans parametre modifie l'adresse egalement. comme &
{
	int temp;
	bool swapped = true;
	for (int y = 0; y < taille - 1 && swapped; y++)
	{
		swapped = false;
		for (int i = 0; i < taille - 1 - y; i++) // -y car a chaque iteration, le plus grand se place a droite deja.
		{
			if (tab[i] > tab[i + 1])
			{
				cppSwap(tab[i], tab[i + 1]);
				swapped = true;
				
			}
		}
		//if (!swapped)
			//return
	}
}
void	afficherTab(int tab[], int taille)
{
	for (int i = 0; i < taille; ++i)
	{
		cout << tab[i];
	}
}
int	main(void)
{
	int	a, b, c, d;
	a = 5;
	b = 2;
	cppSwap(a, b); // ex 1 swap des item.
	cout << 'a' << &a << endl
		<< 'b' << &b << endl;


	int tab1[5]{ 1,2,5,4,3}; // ex 2 trier un tableau en ordre croissant.
	bubbleSort(tab1, 5);
	afficherTab(tab1, 5);
		return 0;
}
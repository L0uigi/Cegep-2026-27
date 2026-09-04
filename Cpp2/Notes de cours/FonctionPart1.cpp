#include <iostream>
//exercices sur fonction partie 1 du cours.
using namespace std;

int	addition(int a, int b)
{
	return a + b;
}

float CelsiusToFaharenheit(float celsius)
{
	float far;

	far = celsius * (9.00f / 5.00f) + 32;
	return far;
}
float FarhenheitToCelsius(float far)
{
	float cel;

	cel = (far - 32) * (5.00f / 9.00f);
	return cel;
}
bool	isPrime(int nbr)
{
	int i;
	i = 2;
	while (i < nbr)
	{
		if (nbr % i == 0)
			return false;
		i++;
	}
	return true;
}

void	showPrime(int x)
{
	int i = 1;
	int count = 0;
	while  (count <= x)
	{
		if (isPrime(i) == true)
		{
			cout << i << ' ';
			count++;
		}
		i++;
	}

}
int sommeTableau(int tab[], int taille)
{
	int somme = 0;
	for (int i = 0; i < taille; i++)
	{
		somme = somme + tab[i];
	}
	return somme;
}
float moyenneTableau(int tab[], int taille)
{
	int somme = sommeTableau(tab, taille);
	float moyenne = 0;
	
	moyenne = (float)somme / taille;
	
	return moyenne;
}


int	main(void)
{
	//cout << addition(2, 3) << '\n';
	//cout << CelsiusToFaharenheit(40) << '\n';
	//cout << FarhenheitToCelsius(104) << '\n';
	//cout << isPrime(13) << '\n';
	//showPrime(13);	!!error
	int tableau1[5]{ 2,3,4,7,9 };
	//cout << sommeTableau(tableau1, 5);
	cout << moyenneTableau(tableau1, 5);

	//char tableau2[5]{a,}
	return 0;
}
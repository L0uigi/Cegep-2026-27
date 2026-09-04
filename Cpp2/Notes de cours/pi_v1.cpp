#include <iostream>
#include <cmath>
#include "cvm_25.h"
#include <conio.h>

using namespace std;

struct Point
{
	double	x = 0; // mettre une valeur par default. Modifiable.
	double y = 0;
};

double	randomDouble(void);
double distanceOrigine(Point p);
int	demanderNombre(int min, int max);
void simulation(size_t nombrePoints);

int	main(void)
{
	int nombre = demanderNombre(0, 1000000);
	
	simulation(nombre);

	return 0;

}

double	randomDouble(void)
{
	double resultat = rand() % RAND_MAX / (double)RAND_MAX;
	return resultat;
}
double distanceOrigine(Point p)
{
	double distance = sqrt(p.x * p.x + p.y * p.y);
	return distance;
}
int	demanderNombre(int min, int max)
{
	int resultat;
	cout << "Entrer un nombre entre " << min << " et " << max << " inclus : ";
	int x = wherex();
	int y = wherey();

	do
	{
		gotoxy(x, y);
		clreol();
		cin >> resultat;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(64, '\n');
		}

	} while (cin.fail() || resultat < min || resultat > max);

	cout << resultat << endl;
	return resultat;
}

void simulation(size_t nombrePoints)
{
	double nombrePointsDansRayon = 0;
	Point p;

	for (size_t i = 0; i < nombrePoints; ++i)
	{
		p.x = randomDouble();
		p.y = randomDouble();
		if (distanceOrigine(p) < 1)
		{
			nombrePointsDansRayon++;
		}
	}
	cout << 4 * (nombrePointsDansRayon / nombrePoints) << endl;
}

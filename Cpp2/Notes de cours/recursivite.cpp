#include <iostream>

using namespace std;

void foo(int valeur)
{
	cout << valeur << endl;
	if (valeur <= 0)
	{
		return;
	}
	foo(valeur - 1); // progression : se raproche de la condition du IF
	cout << valeur << endl; // LES DERNIERS APPELS REVIENNENT EN DERNIER;
}

int  main(void)
{
	foo(3);
	/*
	output :

	3
	2
	1
	0
	1
	2
	3

	*/
	return 0;
}
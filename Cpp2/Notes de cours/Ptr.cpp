#include <iostream>

using namespace std;



int main(void)
{
	int a = 3;
	int* ptr1 = &a;

	cout << ptr1;

	*ptr1 = 14;

	const int* ptr2 = &a; // *** peut changer l'adresse mais pas la donnees. 

	// *ptr2 = 13;  IMPOSSIBLE a cause du const

	int b = 16;
	ptr2 = &b; // changer l'adresse !

	int* const ptr3 = &b; // *** peut changer la valeur mais pas l'adresse 

	*ptr3 = 19; // changer la donnee
	//ptr3 = &a; // peut pas changer adresse;

	const int* const ptr4 = &a; // peut pas changer l'adresse ni la valeur.


	return 0;
}
#include <iostream>

using namespace std;


int	fiboRecursif(int num);
int fiboIteratif(int num);

int main(void)
{
	cout << fiboIteratif(45);
}


int	fiboRecursif(int num)
{
	static int callNumber = 0; // espace memoire en dehors de la fct.
	callNumber++;

	cout << "Call Number : " << callNumber << " num : " << num << endl;

	if (num == 0)
		return 0;

	if (num == 1)
		return 1;

	else
	{
		return (fiboRecursif(num - 2) + fiboRecursif(num - 1));
	}
}

int fiboIteratif(int num)
{
	int precedent = 0;
	int actuel = 1;
	int temp = 1;

	for (int i = 1; i < num; ++i)
	{
		temp = actuel;
		actuel = precedent + actuel;
		precedent = temp;
		cout << 1 << endl;
	}
	return (actuel);
}

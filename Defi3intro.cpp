#include <iostream>
using namespace std;

int	main(void)
{
	int temp, nbre, revNbre;

	nbre = 123456;
	temp = nbre;
	revNbre = 0;

	while(nbre)
	{
		revNbre = (revNbre * 10) + nbre % 10;
		nbre = nbre / 10;
	}
	cout << revNbre;

	if (temp == revNbre)
		cout << ' ' << "(palindrome)";
	else
		cout << ' ' << "(non palindrome)";

	return 0;
}
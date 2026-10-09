#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int	main(void)
{
	fstream f;
	string filename1 = "inventaire.txt";
	stringstream ss;

	f.open(filename1, ios::in);

	if (f.is_open())
	{
		string nomArticle;
		int quantiteArticle;
		int sommeArticles = 0;

		while (f >> nomArticle >> quantiteArticle)
		{
			if (quantiteArticle < 5)
			{
				ss << "ALERTE : " << nomArticle << ' ' << quantiteArticle << endl;
			}
			sommeArticles += quantiteArticle;
		}
		ss << "Somme des quantites : " << sommeArticles << endl;
		cout << ss.str();
	}
	f.close();

	string rapport = "rapport.txt";

	f.open(rapport, ios::app);
	if (f.is_open())
	{
		f << ss.str();
	}

	f.close();

	return 0;
}
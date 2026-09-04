#include <iostream>
#include <conio.h>

#include "./cvm_25.h"

using namespace std;

/*

	Ce programme est un exemple pour lire les touches fléchées (arrow keys) du clavier

	Elles peuvent provenir de deux endroits sur le clavier:

		1) 8 touches fléchées disponibles avec le clavier numérique (numpad), si celui-ci est déverrouillé (touche du coin supérieur gauche du numpad)

		2) 4 touches fléchées disponibles avec la section fléchée (arrowpad) du clavier régulier

*/


enum class Arrowkeys		// énumération des touches fléchées du clavier et leur code ascii respectif (numéros en décimals)
{
	UP_LEFT		= 71,
	UP			= 72,
	UP_RIGHT	= 73,
	LEFT		= 75,
	RIGHT		= 77,
	DOWN_LEFT	= 79,
	DOWN		= 80,
	DOWN_RIGHT	= 81
};

using Ak = Arrowkeys;		// un alias plus concis


/*

NOTES:

	A) À chaque fois que l'on appuie sur une touche fléchée, DEUX codes ascii sont ajoutés dans le tampon d'input

		1) le premier code ascii ajouté sera toujours un code réservé ayant soit le numéro décimal 0 (s'il provient du numpad) ou soit 224 (s'il provient du arrowpad)
		
		2) le deuxième code ascci sera celui de la flèche (ex: numéro ascii 71 pour "up_left")

	B) Il faudra toujours vérifier la présence de ce code ascii spécial (0 ou 224) :
	
		s'il est présent	--> lire le code suivant pour déduire la touche fléchée appuyée

		sinon				--> il s'agira du code d'un caractère régulier
	
	C) Remarquer que "UP_LEFT" porte le code ascii 71 qui est le même que celui du 'G' majuscule, mais "UP_LEFT" aura envoyé un code réservé avant,
	   ce qui permettra de le distinguer du 'G'

	   exemple:

			TOUCHE CLAVIER APPUYÉ				TAMPON D'INPUT
				'g'						==>			71					touche régulière du clavier
				UP_LEFT (numpad)		==>			0 (suivi de) 71		touche spéciale du clavier

*/

int main ()
{
	string out;
	const uint8_t ESCAPE = 27;			// "uint8_t" est un alias standard --> using uint8_t = unsigned char;

	uint8_t c;
	size_t x, y;

	gotoxy(3,5); cout << "Appuyez sur une touche fl\202ch\202e : "; 
	x = wherex(); 
	y = wherey();

	do
	{
		c = _getch();					// lire le premier code retourné par _getch()
		gotoxy(x, y); clreol();

		if (c == 0 || c == 224)			// vérifier s'il s'agit du code réservé. Si oui, il faut lire le code suivant
		{
			if (_kbhit())				// _kbhit() est ajouté ici “par prudence” pour éviter un blocage si, pour une raison quelconque, le 2e octet n’est pas encore disponible.
			{
				c = _getch();			// lire le code ascii suivant
				out = "";
				switch ((Ak)c)			// Ak(c) ==> convertir c en Ak
				{
					case Ak::UP_LEFT:		out = "UP_LEFT";	break;
					case Ak::UP:			out = "UP";			break;
					case Ak::UP_RIGHT:		out = "UP_RIGHT";	break;
					case Ak::LEFT:			out = "LEFT";		break;
					case Ak::RIGHT:			out = "RIGHT";		break;
					case Ak::DOWN_LEFT:		out = "DOWN_LEFT";	break;
					case Ak::DOWN:			out = "DOWN";		break;
					case Ak::DOWN_RIGHT:	out = "DOWN_RIGHT";	break;
				}
				cout << out;
			}
		}
		else
		{
			// ici pour traiter éventuellement un caractère régulier
		}
	}
	while (c != ESCAPE); // escape termine le programme
}

// _kbhit() retourne un int qui indique s’il y a au moins un caractère en attente dans le tampon clavier
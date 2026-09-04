#include <iostream>
#include <conio.h>

#include "cvm_25.h"

using namespace std;

enum class Arrowkeys		// énumération des touches fléchées du clavier et leur code ascii respectif (numéros en décimals)
{
	UP_LEFT = 71,
	UP = 72,
	UP_RIGHT = 73,
	LEFT = 75,
	RIGHT = 77,
	DOWN_LEFT = 79,
	DOWN = 80,
	DOWN_RIGHT = 81
};
using Ak = Arrowkeys;

struct Point
{
	int x = 0;
	int y = 0;
};

void deplacerCurseur();

int	main(void)
{
	deplacerCurseur();
	return 0;
}

void deplacerCurseur()
{
	uint8_t c;
	Point destination;
	Point source;

	do
	{
		destination = source;
		c = _getch();
		if (c == 0 || c == 224)
		{
			c = _getch();

			switch ((Ak)c) // axe y est inverse !!!!!!!
			{
				case Ak::UP_LEFT:    --destination.x, --destination.y; break; // doit appeller Ak car enum class.
				case Ak::UP:			              --destination.y; break;
				case Ak::UP_RIGHT:   ++destination.x, --destination.y; break;
				case Ak::LEFT:	     --destination.x;                  break;
				case Ak::RIGHT:	     ++destination.x;				   break;
				case Ak::DOWN_LEFT:  --destination.x, ++destination.y; break;
				case Ak::DOWN:	                      ++destination.y; break;
				case Ak::DOWN_RIGHT: ++destination.x, ++destination.y; break;
			}
			if (destination.x < 0 || destination.y < 0)
			{
				destination = source;
			}
			else
			{
				source = destination;
			}
		}
		gotoxy(destination.x, destination.y);

	} while(c != 27);
}
#include <iostream>

using namespace std;

int   main(void)
{
    int Devinette;

    Devinette = 1;

    switch(Devinette)
    {
        case 1: cout << "CHAUD\n";
                break;
        case 2: cout << "TIEDE\n";
                break;
        case 3: cout << "FROID\n";
                break;
        default: cout << "valeur inconnue\n";
    }
}
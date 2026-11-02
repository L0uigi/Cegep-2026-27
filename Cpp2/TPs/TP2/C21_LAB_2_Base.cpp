#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <windows.h>

#include "cvm_25.h"

using namespace std;


/* ----------------------------------- */
/* LES VARIABLES GLOBALES DU PROGRAMME */
/* ----------------------------------- */

// ATTENTION: aucune autre variable globale n'est permise dans ce TP

const size_t CLIENTS_MAX = 70;						// nombre maximal de clients
const size_t COMPTES_MAX = 3;						// nombre de comptes par client

const double MARGE_CREDIT_MAX = 10000;				// marge de crédit maximun d'un compte du client
const double SOLDE_COMPTE_MAX = 1000000;			// maximun à ne pas dépasser dans un compte d'un client


/* ----------------------------------- */
/* ALIAS ET DÉFINITIONS DES TYPES      */
/* ----------------------------------- */

enum class Commandes { AJOUTER, AFFICHER, DEPOSER, RETIRER, VIRER, LISTER, SUPPRIMER, QUITTER, INCONNUE };// À COMPLÉTER AVEC LES AUTRES COMMANDES ...

using Cmd = Commandes;

struct Nom											// nom d'un client
{
	string prenom;
	string nom;
};

struct Adresse										// adresse d'un client
{
	string noCivique;
	string rue;
	string ville;
	string codePostal;
};

struct Personne										// informations personnelles d'un client
{
	Nom		nom;
	Adresse	adresse;
	string	telephone;
	string	nas;
};

struct Compte										// un compte d'un client
{
	double solde;
	double margeCredit;
};

struct Client										// informations relatives à un client
{
	Personne	info;
	Compte		comptes[COMPTES_MAX];
	time_t		date;								// date d'ajout du client
};

struct Banque										// La banque de clients
{
	size_t cpt = 0;									// cpt: compteur de client [0..CLIENTS_MAX]
	Client clients[CLIENTS_MAX];
};


/* ------------------------------------------ */
/* LES DÉCLARATIONS (PROTOTYPES) DE FONCTIONS */
/* ------------------------------------------ */

void ioBip();
void ioClean();
double ioRound(double v, size_t p = 2);			// par defaut la précision est à deux décimales (p = 2)
int recupererInt(int min, int max, string message);
float recupererFloat(float min, float max, string message);
string recupererString(string message);
bool OuiNon(string message);

// Affichage 
void afficherMenu();

// Lecture
Commandes lireChoixMenu();

// Initialiser
Client creerClient();
void cmdAjouter(Banque &b);

//modifier

/*
	Suggestion de fonctions:

		size_t lireNoClientValide(size_t noMax);
		size_t lireNoCompteValide();
		double lireMontantValide(double montantMax);
		void afficherComptesClient(Client& client);
*/

// écrire ici toutes les déclarations de fonctions ici...
// ...


/* ------------------------------------------------------------ */
/* LES FONCTIONS OBLIGATOIRES POUR CHAQUE COMMANDE DU PROGRAMME */
/* CRÉER LES DÉCLARATIONS AU BON ENDROIT ET DÉPLACER LES		*/
/* DÉFINITIONS APRÈS LE MAIN ENSUITE						    */
/* ------------------------------------------------------------ */

void afficherMenu()
{
	clrscr();
	cout << "\t\tBANQUE CVM - Succ C21\n\n\n\n"
		<< "\t\t1. Ajouter un client\n\n"
		<< "\t\t2. Afficher les informations d'un client\n\n"
		<< "\t\t3. Dépôt\n\n"
		<< "\t\t4. Retrait\n\n"
		<< "\t\t5. Virement\n\n"
		<< "\t\t6. Lister les clients et leur crédit actuel\n\n"
		<< "\t\t7. Supprimer un client\n\n"
		<< "\t\tQ.Quitter\n\n\n\n\n\n\n"
		<< "\t\tEntrez votre choix : ";
}

Commandes lireChoixMenu()
{ 
	Commandes cmd = Cmd::INCONNUE;					// commande par défaut
	char reponse;
	do
	{
		reponse = _getch();
		if (reponse == 'q')
			reponse = toupper(reponse);

		switch (reponse)
		{
		case '1': cmd = Cmd::AJOUTER; break;
		case '2': cmd = Cmd::AFFICHER; break;
		case '3': cmd = Cmd::DEPOSER; break;
		case '4': cmd = Cmd::RETIRER; break;
		case '5': cmd = Cmd::VIRER; break;
		case '6': cmd = Cmd::LISTER; break;
		case '7': cmd = Cmd::SUPPRIMER; break;
		case 'Q': cmd = Cmd::QUITTER; break;
		}

	} while (cmd == Cmd::INCONNUE);

	return cmd;
}

void cmdAjouter(Banque& b) // mettre les ajouts dans fonction creerClient
{
	bool valide;
	Client c {};
	
	clrscr();
	cout << "CMD - ajouter un client"
		<< "\n\nCréation du client #" << b.cpt << endl << endl;
	c = creerClient();

	cout << endl;

	valide = OuiNon("Enregistrer le nouveau client ? (O/N) : ");
		
	if (valide == 'O')
	{
		b.clients[b.cpt] = c;
		++b.cpt;
	}
}

void cmdAfficher( /* Paramètres ? */ )
{
	cout << "Dans Afficher";
	
	
	
	_getch();
}

void cmdDeposer( /* Paramètres ? */ )
{
	cout << "Dans Deposer";
	_getch();
}

void cmdRetirer( /* Paramètres ? */ )
{
	cout << "Dans Retirer";
	_getch();
}

void cmdVirer( /* Paramètres ? */ )
{
	cout << "Dans Virer";
	_getch();
}

void cmdLister( /* Paramètres ? */ )
{
	cout << "Dans Lister";
	_getch();
}

void cmdSupprimer( /* Paramètres ? */ )
{
	cout << "Dans Supprimer";
	_getch();
}

void cmdQuitter( /* Paramètres ? */)
{
	cout << "Dans Quitter";
	_getch();
}

/* ---------------------- */
/* LA FONCTION PRINCIPALE */
/* ---------------------- */

int main()
{
	setcp(65001);						// permet de faire un 'cout' avec les accents directement
	cout << fixed << setprecision(2);	// tous les montants sont affichés avec une précision à 2

	Cmd cmd = Cmd::INCONNUE;

	Banque b{};

	do
	{
		afficherMenu();
		cmd = lireChoixMenu();
		
		switch (cmd)
		{
			case Cmd::AJOUTER: cmdAjouter(b); break;
			case Cmd::AFFICHER: cmdAfficher(b); break;
			case Cmd::DEPOSER: cmdDeposer( /* cette fonction doit avoir accès à la variable b de main */ ); break;
			case Cmd::RETIRER: cmdRetirer( /* cette fonction doit avoir accès à la variable b de main */ ); break;
			case Cmd::VIRER: cmdVirer( /* cette fonction doit avoir accès à la variable b de main */ ); break;
			case Cmd::LISTER: cmdLister( /* cette fonction doit avoir accès à la variable b de main */ ); break;
			case Cmd::SUPPRIMER: cmdSupprimer( /* cette fonction doit avoir accès à la variable b de main */ ); break;
			case Cmd::QUITTER: cmdQuitter( /* cette fonction doit avoir accès à la variable b de main */); break;
			default: break;
		}

	} while(cmd != Cmd::QUITTER);

}

int recupererInt(int min, int max, string message)
{
	int reponse;
	int x, y;

	cout << message;
	x = wherex();
	y = wherey();
	do
	{
		if (cin.fail())
			ioClean();

		gotoxy(x, y);
		clreol();
		cin >> reponse;
		
	} while (cin.fail() || reponse < min || reponse > max);
	return reponse;
}
float recupererFloat(float min, float max, string message)
{
	float reponse;

	cout << message;
	int x = wherex();
	int y = wherey();
	do
	{
		if (cin.fail())
			ioClean();
		gotoxy(x,y);
		clreol();
		cin >> reponse;
		
	} while (cin.fail() || reponse < min || reponse > max);
	return reponse;
}
string recupererString(string message)
{
	string reponse;

	cout << message;
	int x = wherex();
	int y = wherey();
	
	do
	{
		if (cin.fail())
			ioClean();

		gotoxy(x, y);
		clreol();
		cin >> reponse;

	} while (cin.fail());
	return reponse;
}

bool OuiNon(string message)
{
	char reponse;
	setcolor(Color::yel);
	cout << message;
	setcolor(Color::wht);
	int x = wherex();
	int y = wherey();

	do
	{
		reponse = _getch();
		reponse = toupper(reponse);

		if (reponse == 'O')
			return 1;

		if (reponse == 'N')
			return 0;
			
	} while (1);
	 
	return 0; 
}

Client creerClient() // initialise client
{
	Client c{};
	
	c.info.nom.prenom = recupererString("Prénom\t\t\t: ");
	c.info.nom.nom = recupererString("Nom\t\t\t: ");

	c.info.adresse.noCivique = recupererString("\nNuméro civique\t\t: ");
	c.info.adresse.rue = recupererString("Rue\t\t\t: ");
	c.info.adresse.ville = recupererString("Ville\t\t\t: ");
	c.info.adresse.codePostal = recupererString("Code Postal\t\t: ");
	c.info.telephone = recupererInt(0000000001, 9999999999, "Téléphone\t\t: ");

	c.info.nas = recupererString("\nNo assurance sociale\t\t\t: ");

	c.comptes[0].margeCredit = recupererFloat(0, 10000.00, "Marge de crédit du compte #1 (Max de 10000.00 $)\t\t: ");
	c.comptes[1].margeCredit = recupererFloat(0, 10000.00, "Marge de crédit du compte #2 (Max de 10000.00 $)\t\t: ");
	c.comptes[2].margeCredit = recupererFloat(0, 10000.00, "Marge de crédit du compte #3 (Max de 10000.00 $)\t\t: ");

	c.date = time(NULL); // à modifier

	return c;
}

void ioBip() { Beep(200, 300); }

void ioClean()										// pour vider les 2 tampons d'input
{
	cin.clear();									// s'assure que le cin est remis en marche
	cin.ignore(cin.rdbuf()->in_avail());			// vide le tampon du cin
	while (_kbhit()) (void)_getch();				// vide le tampon de la console
}

double ioRound(double v, size_t p)					// tous les montants lus devront être arrondis à 2 décimales avec cette fonction (v:valeur et p:précision)
{													// ex: montant = io_round(montant,2);
	double e = pow(10, p);
	return round(v * e) / e;
}
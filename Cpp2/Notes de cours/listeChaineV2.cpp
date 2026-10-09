#include <iostream>

/*
* 3 INVARIANTS À MAINTENIR SYSTÉMATIQUEMENT
*
* taille == 0 alors tete == nullptr && queue == nullptr
* taille == 1 alors tete == queue
* taille > 0 alors queue->suivant == nullptr
*/


using namespace std;

struct Data
{
	int valeur;
};

struct Node
{
	Data data;
	Node* suivant;
};

struct ListeChainee
{
	Node* tete = nullptr;
	Node* queue = nullptr;
	size_t taille = 0;
};

void insererEnTete(ListeChainee& l, const Data& d);
void supprimerEnTete(ListeChainee& l);

void insererEnQueue(ListeChainee& l, const Data& d);
void supprimerEnQueue(ListeChainee& l);
void insererAposition(ListeChainee& l, const Data& d, size_t position);

void viderListe(ListeChainee& l);
Data* obtenirAPosition(const ListeChainee& l, size_t position);
void supprimerAPosition(ListeChainee& l, size_t position);

bool listeEstVide(const ListeChainee& l);

void afficherData(const Data& d);
void afficherListe(const ListeChainee& l);

int main()
{
	ListeChainee liste;

	insererEnTete(liste, { 10 });
	insererEnTete(liste, { 20 });
	insererEnTete(liste, { 30 });

	cout << "Liste :" << endl;
	afficherListe(liste);

	cout << endl << "Taille : " << liste.taille << endl;

	supprimerEnTete(liste);

	cout << endl << "Apres suppression en tete :" << endl;
	afficherListe(liste);

	cout << endl << "Taille : " << liste.taille << endl;

	viderListe(liste);

	cout << endl << "Liste vide : " << listeEstVide(liste) << endl;
	cout << "Taille : " << liste.taille << endl;

	return 0;
}

void insererEnTete(ListeChainee& l, const Data& d)
{
	Node* nouveau = new Node{ d, l.tete };

	if (l.taille == 0)
	{
		l.queue = nouveau;
	}

	l.tete = nouveau;
	l.taille++;
}


void supprimerEnTete(ListeChainee& l)
{
	if (l.tete == nullptr)
	{
		return;
	}

	Node* aSupprimer = l.tete;

	l.tete = l.tete->suivant;

	if (l.taille == 1)
	{
		l.queue = nullptr;
	}

	delete aSupprimer;

	l.taille--;
}


void viderListe(ListeChainee& l)
{
	while (l.tete != nullptr)
	{
		Node* aSupprimer = l.tete;
		l.tete = l.tete->suivant;

		delete aSupprimer;
	}

	l.queue = nullptr;
	l.taille = 0;
}

Data* obtenirAPosition(const ListeChainee& l, size_t position)
{
	if (l.taille == 0 || position > l.taille - 1)
		return nullptr;
	Node* courant = l.tete;

	for (int i = 0; i < position; ++i)
	{
		courant = courant->suivant;
	}
	return &courant->data;
}

void supprimerAPosition(ListeChainee& l, size_t position)
{
	if (l.taille == 0)
	{
		supprimerEnQueue;
	}
		if (position >= l.taille)
		return;
	if (position = l.taille - 1)
	{
		supprimerEnQueue(l);
		return;
	}
	Node* courant = l.tete;
	for (size_t i = 0; i < position - 1; ++i)
	{
		courant = courant->suivant;
	}
	Node* temp = courant->suivant;

	courant->suivant = courant->suivant->suivant;
	delete temp; 
	--l.taille;
}

bool listeEstVide(const ListeChainee& l)
{
	return l.tete == nullptr;
}

void afficherData(const Data& d)
{
	cout << d.valeur;
}


void afficherListe(const ListeChainee& l)
{
	const Node* courant = l.tete;

	while (courant != nullptr)
	{
		afficherData(courant->data);
		cout << endl;

		courant = courant->suivant;
	}
}

void insererEnQueue(ListeChainee& l, const Data& d)
{
	if (l.taille == 0)
	{
		insererEnTete(l, d);
		return;
	}

	Node* nouveau = new Node{ d, nullptr };

	l.queue->suivant = nouveau;
	l.queue = nouveau;

	++l.taille;
}

void supprimerEnQueue(ListeChainee& l)
{
	if (l.taille == 0)
	{
		return;
	}

	if (l.taille == 1)
	{
		delete l.tete;
		l.tete = nullptr;
		l.queue = nullptr;
		l.taille = 0;

		return;
	}

	Node* avantDernier = l.tete;

	while (avantDernier->suivant != l.queue)
	{
		avantDernier = avantDernier->suivant;
	}
	delete l.queue;

	l.queue = avantDernier;
	l.queue->suivant = nullptr;


	--l.taille;
}

void insererAposition(ListeChainee& l, const Data& d, size_t position)
{
	if (position > l.taille)
		return;

	if (position == 0)
	{
		insererEnTete(l, d);
		return;
	}
	Node* courant = l.tete;

	for (size_t i = 0; i < position; ++i)
	{
		courant = courant->suivant;
	}
	Node* nouveau = new Node;
	nouveau->data = { courant->data };
	courant->data = d;
	nouveau->suivant = courant->suivant;
	courant->suivant = nouveau;
	++l.taille;
}


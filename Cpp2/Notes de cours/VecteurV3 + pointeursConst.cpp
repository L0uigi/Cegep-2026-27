#include <iostream>

using namespace std;

using TypeVecteur = int;

struct Vecteur
{
    size_t taille = 0;
    size_t capacite = 0;
    TypeVecteur* valeurs = nullptr;
};


// Initialisation / destruction
Vecteur initialiserVecteur(size_t capacite = 5);
void detruireVecteur(Vecteur& v);

// Consultation
bool vecteurEstVide(const Vecteur& v);

TypeVecteur* obtenirAPosition(Vecteur& v, size_t position);
const TypeVecteur* obtenirAPosition(const Vecteur& v, size_t position);

// Modification
void ajouter(Vecteur& v, const TypeVecteur& data);
void retirerDernier(Vecteur& v);
void viderVecteur(Vecteur& v);
void insererAPosition(Vecteur& v, const TypeVecteur& data, size_t position);
void supprimerAPosition(Vecteur& v, size_t position);
void remplacerAposition(Vecteur& v, size_t position, const TypeVecteur& data);

// Gestion mémoire
void reserver(Vecteur& v, size_t nouvelleCapacite);

// Copie
Vecteur copierVecteur(const Vecteur& source);

// Affichage
void afficherVecteur(const Vecteur& v);
void afficherElement(const TypeVecteur& e);

int main()
{
    Vecteur v = initialiserVecteur();
   // TypeVecteur* t = obtenirAPosition(v, 99);

    ajouter(v, 1);
    ajouter(v, 2);
    ajouter(v, 3);
    ajouter(v, 4);

    //TypeVecteur* t = obtenirAPosition(v, 3);
    //*t = 99; // attention, si une de nos fct fait un nouveau vecteur, l'adresse pointee sera obsolete.
    //afficherVecteur(v);
    
    ajouter(v, 5);
    ajouter(v, 6);

    remplacerAposition(v, 3, 9999);
    afficherVecteur(v);
    //insererAPosition(v, 10, 2);
    afficherVecteur(v);
    detruireVecteur(v);

    return 0;
}


Vecteur initialiserVecteur(size_t capacite)
{
    Vecteur v;

    if (capacite > 0)
    {
        v.capacite = capacite;
        v.valeurs = new TypeVecteur[capacite]{};
    }

    return v;
}


void detruireVecteur(Vecteur& v)
{
    delete[] v.valeurs;

    v.valeurs = nullptr;
    v.taille = 0;
    v.capacite = 0;
}


bool vecteurEstVide(const Vecteur& v)
{
    return v.taille == 0;
}

TypeVecteur* obtenirAPosition(Vecteur& v, size_t position)
{
    if (position >= v.taille)
        return nullptr;

    return &v.valeurs[position];
}

const TypeVecteur* obtenirAPosition(const Vecteur& v, size_t position)
{
    if (position >= v.taille)
        return nullptr;

    return &v.valeurs[position];
}

void afficherElement(const TypeVecteur& e)
{
    cout << e;
}

void ajouter(Vecteur& v, const TypeVecteur& data)
{
    // Si le vecteur est plein, on en crée un nouveau de capacite x2 
    // la fonction reserver fait un appel à copier
    if (v.taille == v.capacite)
    {
        size_t nouvelleCapacite = (v.capacite == 0) ? 1 : v.capacite * 2;
        reserver(v, nouvelleCapacite);
    }

    v.valeurs[v.taille] = data;
    ++v.taille;
}


void retirerDernier(Vecteur& v)
{
    // Si le vecteur n'est pas vide, diminuer sa taille de 1.
    // La capacité et le tableau dynamique ne changent pas.
}


void viderVecteur(Vecteur& v)
{
    // Mettre la taille à 0.
    // Conserver la capacité et le tableau dynamique.
}

void insererAPosition(Vecteur& v, const TypeVecteur& data, size_t position)
{
    if (position > v.taille || position < 0)
        return;
    if (v.taille >= v.capacite)
    {
        reserver(v, v.capacite * 2);
    }
    v.taille++;
    for (int i = v.taille + 1; i > position; --i)
    {
        v.valeurs[i] = v.valeurs[i - 1];
    }
    v.valeurs[position] = data; // a la position de l'element qui change
}

void supprimerAPosition(Vecteur& v, size_t position)
{
    if (position >= v.taille)
    {
        return;

    }
    for (int i = position; i < v.taille; ++i)
    {
        v.valeurs[i] = v.valeurs[i + 1];
    }
    v.taille--;
}

void remplacerAposition(Vecteur& v, size_t position, const TypeVecteur& data)
{
    if (position >= v.taille)
        return;

    TypeVecteur* p = obtenirAPosition(v, position);
    
    if (p == nullptr)
        return;

    *p = data;
}

void reserver(Vecteur& v, size_t nouvelleCapacite)
{
    if (nouvelleCapacite <= v.capacite)
    {
        return;
    }

    TypeVecteur* copie = new TypeVecteur[nouvelleCapacite]{};

    for (size_t i = 0; i < v.taille; ++i)
    {
        copie[i] = v.valeurs[i];
    }

    delete[] v.valeurs;

    v.valeurs = copie;
    v.capacite = nouvelleCapacite;
}


Vecteur copierVecteur(const Vecteur& source)
{
    // Créer un nouveau vecteur ayant sa propre allocation.
    // Copier la taille, la capacité et chacun des éléments.

    Vecteur copie = initialiserVecteur(source.capacite);

    copie.taille = source.taille;

    for (size_t i = 0; i < source.taille; ++i)
    {
        copie.valeurs[i] = source.valeurs[i];
    }

    return copie;
}

// Cette fonction affiche un vecteur, mais ne fonctionnerait pas bien si notre 
// TypeVecteur était autre chose qu'un primitif (char, short, int, long, float, double)
// Il faudrait se créer une fonction afficherData qui saurait comment afficherData
// le TypeVecteur.
void afficherVecteur(const Vecteur& v)
{
    cout << "Vecteur de taille : " << v.taille << " [";

    for (size_t i = 0; i < v.taille; ++i)
    {
        if (i > 0)
        {
            cout << ", ";
        }

        //cout << v.valeurs[i]; remplacee par afficherElement

        const TypeVecteur* e = obtenirAPosition(v, i);
        afficherElement(*e);
    }
   

    cout << "]" << endl;
}
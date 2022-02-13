#pragma once
// Structures mémoires pour une collection de films.


#include <string>
#include <iostream>
using namespace std;

struct Film; struct Acteur; // Permet d'utiliser les types alors qu'ils seront défini après.

class ListeFilms
{
public:

	void Double_capacite(int capacite);
	void Ajout_Film(Film* ptrFilm);
	void Supp_PtrFilm(Film* ptrfilm);
	Acteur* Trouver_Acteur(string nomActeur) const;
	Acteur* lireActeur(istream& fichier);
	Film* lireFilm(istream& fichier);
	ListeFilms creerListe(string nomFichier);
	void Detruire_Film(Film* filmDetruit);
	void Detruire_Liste();
	void afficherActeur(Acteur& acteur)const;
	void afficherFilm(Film& film)const;
	void afficherListeFilms();
	void afficherFilmographieActeur(string& nomActeur) const;

private:
	int capacite, nElements_;
	Film elements;
};

struct ListeActeurs {
	int capacite, nElements;
	Acteur** elements; // Pointeur vers un tableau de Acteur*, chaque Acteur* pointant vers un Acteur.
};

struct Film
{
	std::string titre, realisateur; // Titre et nom du réalisateur (on suppose qu'il n'y a qu'un réalisateur).
	int anneeSortie, recette; // Année de sortie et recette globale du film en millions de dollars
	ListeActeurs acteurs;
};

struct Acteur
{
	std::string nom; int anneeNaissance; char sexe;
	ListeFilms joueDans;
};

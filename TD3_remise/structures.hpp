#pragma once
// Structures mémoires pour une collection de films.


#include <string>
#include <iostream>
#include <memory>
using namespace std;

struct Film; struct Acteur; // Permet d'utiliser les types alors qu'ils seront défini après.

class ListeFilms
{
public:
	ListeFilms() {
		elements_ = nullptr;
		capacite_ = 0;
		nElements_ = 0;
	}
	void doubleCapacite(int capacite);
	void ajoutFilm(Film* ptrFilm);
	void supprimePtrFilm(Film* ptrfilm);
	Acteur* trouverActeur(string nomActeur) const;
	void detruireFilm(Film* filmDetruit);
	void detruireListe();
	void afficherActeur(Acteur& acteur)const;
	void afficherFilm(Film* film)const;
	void afficherListeFilms()const;
	void afficherFilmographieActeur(string& nomActeur)const;
	Film* SelectionneFilm(int indexFilm)const;

private:
	int capacite_, nElements_; 
	Film** elements_;
};

class ListeActeurs {
public:
	ListeActeurs(){
		elements_ = nullptr;
		capacite_ = 0;
		nElements_ = 0;
	}

private:
	int capacite_, nElements_;
	unique_ptr<Acteur*[]> elements_;
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

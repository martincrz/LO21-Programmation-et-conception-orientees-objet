#ifndef _SET_H
#define _SET_H

#include <iostream>
#include <string>
#include <initializer_list>
#include <array>
#include <cstdlib>
using namespace std;

namespace Set {
	// classe pour gérer les exceptions dans le set
	class SetException {
	public:
		SetException(const string& i) :info(i) {}
		string getInfo() const { return info; }
	private:
		string info;
	};

	// caractéristiques
	enum class Couleur { rouge, mauve, vert };
	enum class Nombre { un=1, deux=2, trois=3 };
	enum class Forme { ovale, vague, losange };
	enum class Remplissage { plein, vide, hachure };

	// conversion d'une caractéristique en string
	string toString(Couleur c);
	string toString(Nombre v);
	string toString(Forme f);
	string toString(Remplissage v);

	// écriture d'une caractéristique sur un flux ostream
	ostream& operator<<(ostream& f, Couleur c);
	ostream& operator<<(ostream& f, Nombre v);
	ostream& operator<<(ostream& f, Forme x);
	ostream& operator<<(ostream& f, Remplissage r);

	// listes contenant les valeurs possibles pour chacune des caractéristiques
	extern std::initializer_list<Couleur> Couleurs;
	extern std::initializer_list<Nombre> Nombres;
	extern std::initializer_list<Forme> Formes;
	extern std::initializer_list<Remplissage> Remplissages;

	// affichage des valeurs possibles pour chaque caractéristiques
	void printCouleurs(std::ostream& f = cout);
	void printNombres(std::ostream& f = cout);
	void printFormes(std::ostream& f = cout);
	void printRemplissages(std::ostream& f = cout);

	class Carte {
	public:
		Carte(Couleur c, Nombre n, Forme f, Remplissage r) :
			couleur(c), nombre(n), forme(f), remplissage(r) {}
		Couleur getCouleur() const { return couleur; }
		Nombre getNombre() const { return nombre; }
		Forme getForme() const { return forme; }
		Remplissage getRemplissage() const { return remplissage; }
		~Carte() = default;
		Carte(const Carte& c) = default;
		Carte& operator=(const Carte& c) = default;
	private:
		Couleur couleur;
		Nombre nombre;
		Forme forme;
		Remplissage remplissage;
	};

	std::ostream& operator<<(std::ostream& f, const Carte& c);

	class Jeu {
	public:
		Jeu();
		size_t getNbCartes() const { return 81; }
		const Carte& getCarte(size_t i) const;
		~Jeu();
		// désactivation du costructeur de recopie et de l'affectation
		Jeu(const Jeu& j) = delete;
		Jeu& operator=(const Jeu& j) = delete;
	private:
		const Carte* cartes[81]; // tableau de pointeurs const automatique
	};

	class Pioche {
	public:
		explicit Pioche(const Jeu& j);
		const Carte& piocher();
		~Pioche();
		Pioche(const Pioche&) = delete;
		Pioche& operator=(const Pioche&) = delete;
		size_t getNbCartes() const { return nb; }
		bool estVide() const { return nb == 0; }
	private:
		const Carte** cartes=nullptr; // tableau de poiteurs const alloué dynamiquement
		size_t nb = 0;
	};

	class Plateau {
	public:
		Plateau();
		void ajouterCarte(const Carte& c);
		void retirerCarte(const Carte& c);
		~Plateau();
		Plateau(const Plateau& p);
		Plateau& operator=(const Plateau& p);
	private:
		void agrandirTableau(size_t t);
		const Carte** cartes = nullptr; // tableau de poiteurs const alloué dynamiquement
		size_t nb = 0; // nb de cartes dans le tableau
		size_t nbMax; // taille du tableau
	};

}


#endif

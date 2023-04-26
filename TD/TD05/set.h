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
		
		Couleur getCouleur() const { return couleur; }
		Nombre getNombre() const { return nombre; }
		Forme getForme() const { return forme; }
		Remplissage getRemplissage() const { return remplissage; }
		~Carte() = default;
		
	private:
		friend class Jeu;
		// usage du constructeur exclusif à Jeu
		Carte(Couleur c, Nombre n, Forme f, Remplissage r) :
			couleur(c), nombre(n), forme(f), remplissage(r) {}
		Carte(const Carte& c) = delete;
		Carte& operator=(const Carte& c) = delete;
		Couleur couleur;
		Nombre nombre;
		Forme forme;
		Remplissage remplissage;
	};

	std::ostream& operator<<(std::ostream& f, const Carte& c);

	class Jeu {
	public:
		class Iterator {
		public:
			bool isDone() const {
				return indice >= Jeu::getInstance().getNbCartes();
			}
			void next() { indice++; }
			const Carte& currentItem() const { 
				return Jeu::getInstance().getCarte(indice); 
			}
			Iterator() = default;
		private:
			// information pour en oeuvre l'itérateur
			size_t indice = 0;
		};
		Iterator getIterator() const { return Iterator(); }

		class FormeIterator {
		public:
			bool isDone() const {
				return indice >= Jeu::getInstance().getNbCartes();
			}
			void next() { 
				indice++; 
				while (indice < Jeu::getInstance().getNbCartes() &&
					forme != Jeu::getInstance().getCarte(indice).getForme())
					indice++;
			}
			const Carte& currentItem() const {
				return Jeu::getInstance().getCarte(indice);
			}
			FormeIterator(Forme f) : forme(f) {
				while (indice < Jeu::getInstance().getNbCartes() &&
					forme != Jeu::getInstance().getCarte(indice).getForme()) 
					indice++;
			}
		private:
			Forme forme;
			// information pour en oeuvre l'itérateur
			size_t indice = 0;
		};
		FormeIterator getIterator(Forme f) const { return FormeIterator(f); }


		size_t getNbCartes() const { return 81; }
		// désactivation du costructeur de recopie et de l'affectation
		Jeu(const Jeu& j) = delete;
		Jeu& operator=(const Jeu& j) = delete;
		static const Jeu& getInstance();
		static void libereInstance();
		
	private:
		const Carte& getCarte(size_t i) const;

		// version 2
		//static Jeu* instance;

		//version 3
		struct Handler {
			Jeu* instance = nullptr;
			~Handler() { delete instance; }
		};
		static Handler handler;


		// interdiction de la construction/destruction aux
		// utilisateurs
		Jeu();
		~Jeu();
		const Carte* cartes[81]; // tableau de pointeurs const automatique
	};

	class Pioche {
	public:
		explicit Pioche();
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
		class const_iterator {
		public:
			const_iterator& operator++() { courant++; return *this; }
			const Carte& operator*() const { return **courant; }
			bool operator!=(const_iterator it) const {
				return courant != it.courant;
			}
		private:
			const Carte** courant; // adresse de la cellule courante dans
								   // le tableau de pointeurs de cartes
			const_iterator(const Carte** c):courant(c){}
			friend class Plateau;
		};
		const_iterator begin() const { return const_iterator(cartes); }
		const_iterator end() const { return const_iterator(cartes+nb); }

		Plateau();
		void ajouterCarte(const Carte& c);
		void retirerCarte(const Carte& c);
		~Plateau();
		Plateau(const Plateau& p);
		Plateau& operator=(const Plateau& p);
		size_t getNbCartes() const { return nb; }
		void print(ostream& f) const;
	private:
		void agrandirTableau(size_t t);
		const Carte** cartes = nullptr; // tableau de poiteurs const alloué dynamiquement
		size_t nb = 0; // nb de cartes dans le tableau
		size_t nbMax; // taille du tableau
	};

	ostream& operator<<(ostream& f, const Plateau& p);



	class Combinaison {
	public:
		Combinaison(const Carte& C1, const Carte& C2,
			const Carte& C3) : c1(&C1), c2(&C2), c3(&C3) {}
		const Carte& getCarte1() const { return *c1; }
		const Carte& getCarte2() const { return *c2; }
		const Carte& getCarte3() const { return *c3; }
		bool estUnSet() const;
		~Combinaison() = default;
		Combinaison(const Combinaison&) = default;
		Combinaison& operator=(const Combinaison&) = default;
	private:
		const Carte* c1;
		const Carte* c2;
		const Carte* c3;
	};

	ostream& operator<<(ostream& f, const Combinaison& c);

	class Controleur {
	public:
		Controleur():pioche(new Pioche) {}
		Plateau& getPlateau() { return plateau; }
		const Plateau& getPlateau() const { return plateau; }
		void distribuer();
		~Controleur() { delete pioche; }
		Controleur(const Controleur&) = delete;
		Controleur& operator=(const Controleur&) = delete;
	private:
		//Jeu jeu;
		Plateau plateau;
		Pioche* pioche=nullptr;
	};

}


#endif

#include "set.h"
#include<cstdlib>

namespace Set {
	
	std::initializer_list<Couleur> Couleurs = { Couleur::rouge, Couleur::mauve, Couleur::vert };
	std::initializer_list<Nombre> Nombres = { Nombre::un, Nombre::deux, Nombre::trois };
	std::initializer_list<Forme> Formes = { Forme::ovale, Forme::vague, Forme::losange };
	std::initializer_list<Remplissage> Remplissages = { Remplissage::plein, Remplissage::vide, Remplissage::hachure };

	string toString(Couleur c) {
		switch (c) { 
		case Couleur::rouge: return "R";
		case Couleur::mauve: return "M";
		case Couleur::vert: return "V";
		default: throw SetException("Couleur inconnue");
		}
	}

	string toString(Nombre v) {
		switch (v) {
		case Nombre::un: return "1";
		case Nombre::deux: return "2";
		case Nombre::trois: return "3";
		default: throw SetException("Nombre inconnue");
		}
	}

	string toString(Forme f) {
		switch (f) {
		case Forme::ovale: return "O";
		case Forme::vague: return "~";
		case Forme::losange: return "\004";
		default: throw SetException("Forme inconnue");
		}
	}

	string toString(Remplissage r) {
		switch (r) {
		case Remplissage::plein: return "P";
		case Remplissage::vide: return "_";
		case Remplissage::hachure: return "H";
		default: throw SetException("Remplissage inconnu");
		}
	}

	std::ostream& operator<<(std::ostream& f, Couleur c) { f << toString(c); return f; }
	std::ostream& operator<<(std::ostream& f, Nombre v) {	f << toString(v); return f; }
	std::ostream& operator<<(std::ostream& f, Forme x) { f << toString(x);  return f; }
	std::ostream& operator<<(std::ostream& f, Remplissage r) { f << toString(r); return f; }

	void printCouleurs(std::ostream& f) {
		for (auto c : Couleurs) f << c << " ";
		f << "\n";
	}

	void printNombres(std::ostream& f) {
		for (auto v : Nombres) f << v << " ";
		f << "\n";
	}

	void printFormes(std::ostream& f) {
		for (auto x : Formes) f << x << " ";
		f << "\n";
	}

	void printRemplissages(std::ostream& f) {
		for (auto r : Remplissages) f << r << " ";
		f << "\n";
	}

	std::ostream& operator<<(std::ostream& f, const Carte& c) {
		f << "(" << c.getCouleur() << "," << c.getNombre() << ","
			<< c.getForme() << "," << c.getRemplissage() << ")";
		return f;
	}

	Jeu::Jeu(){
		size_t i = 0;
		for (auto c : Couleurs)
			for (auto v : Nombres)
				for (auto x : Formes)
					for (auto r : Remplissages)
						cartes[i++] = new Carte(c, v, x, r);
	}

	
	
	const Carte& Jeu::getCarte(size_t i) const{
		if (i >= getNbCartes()) throw SetException("carte inexistante");
		return *cartes[i];
	}
	
	Jeu::~Jeu(){
		for (size_t i = 0; i < getNbCartes(); i++) delete cartes[i];
	}

	Pioche::Pioche():
		cartes(new const Carte*[Jeu::getInstance().getNbCartes()]),
		nb(Jeu::getInstance().getNbCartes()){
		//for (size_t i = 0; i < nb; i++) 
			//cartes[i] = &Jeu::getInstance().getCarte(i);
		size_t i = 0;
		for(auto it=Jeu::getInstance().getIterator();
			!it.isDone();it.next())
			cartes[i++] = &it.currentItem();

	}

	const Carte& Pioche::piocher(){
		if (estVide()) throw SetException("piocher dans une pioche vide");
		size_t x = rand() % nb;
		const Carte& c = *cartes[x]; // création d'une ref sur la carte piochée
		cartes[x] = cartes[--nb]; // déplacement de la dernière carte 
							// à l'emplacement de l acrte piochée		
		return c;
	}
	
	Pioche::~Pioche(){
		delete[] cartes; // désallocation du tableau de pointeurs
	}

	Plateau::Plateau():cartes(new const Carte*[12]), 
						nbMax(12), nb(0) {
	}

	void Plateau::agrandirTableau(size_t t) {
		if (t <= nbMax) return;
		// allocation nouveau tableau
		auto nouveau_tab = new const Carte * [t];
		// recopie des données du tableau initial
		for (size_t i = 0; i < nb; i++) 
			nouveau_tab[i] = cartes[i];
		auto old = cartes;
		// mise à jour des attributs
		cartes = nouveau_tab;
		nbMax = t;
		// destruction ancien tableau
		delete[] old;
	}

	void Plateau::ajouterCarte(const Carte& c) {
		if (nb == nbMax) agrandirTableau((nb + 1)*2);
		cartes[nb++] = &c;
	}

	void Plateau::retirerCarte(const Carte& c) {
		size_t i = 0;
		while (i < nb && cartes[i] != &c) i++;
		if (i == nb) throw SetException("carte inexistante du plateau");
		cartes[i] = cartes[--nb];
	}

	Plateau::~Plateau() {
		delete[] cartes;
	}

	Plateau::Plateau(const Plateau& p): 
		cartes(new const Carte* [p.nb]),
		nbMax(p.nb),nb(p.nb){
		// recopie des adresses
		for(size_t i=0; i<nb; i++) cartes[i]=p.cartes[i];
	}
	
	Plateau& Plateau::operator=(const Plateau& p) {
		if (this != &p) { // on se protège de l'auto-affectation
			if (nbMax < p.nb) agrandirTableau(p.nb);
			for (size_t i = 0; i < p.nb; i++) 
				cartes[i] = p.cartes[i];
			nb = p.nb;
		}
		return *this;
	}

	bool Combinaison::estUnSet() const {
		bool c = (c1->getCouleur() == c2->getCouleur() && 
			      c1->getCouleur() == c3->getCouleur()) 
			|| (c1->getCouleur() != c2->getCouleur() && 
				c1->getCouleur() != c3->getCouleur() && 
				c2->getCouleur() != c3->getCouleur());
		bool n = (c1->getNombre() == c2->getNombre() && c1->getNombre() == c3->getNombre()) || (c1->getNombre() != c2->getNombre() && c1->getNombre() !=c3->getNombre() && c2->getNombre() != c3->getNombre());
		bool f = (c1->getForme() == c2->getForme() && c1->getForme() == c3->getForme()) || (c1->getForme() != c2->getForme() && c1->getForme() != c3->getForme() && c2->getForme() != c3->getForme());
		bool r = (c1->getRemplissage() == c2->getRemplissage() && c1->getRemplissage() == c3->getRemplissage()) || (c1->getRemplissage() != c2->getRemplissage() && c1->getRemplissage() != c3->getRemplissage() && c2->getRemplissage() != c3->getRemplissage());
		return c && n && f && r;
	}

	ostream& operator<<(ostream& f, const Combinaison& c) {
		f << "[" << c.getCarte1() << ","
			<< c.getCarte2() << "," << c.getCarte3() << "]";
		return f;
	}

	void Controleur::distribuer() {
		if (plateau.getNbCartes() < 12)
			while (!pioche->estVide() &&
				plateau.getNbCartes() < 12)
				plateau.ajouterCarte(pioche->piocher());
		else
			if (!pioche->estVide())
				plateau.ajouterCarte(pioche->piocher());
	}

	/*
	//version 1
	const Jeu& Jeu::getInstance() {
		static Jeu j; // instance construite une seule fois
		return j;
	}
	*/

	// version 2
	// définition de l'attribut static
	/*Jeu* Jeu::instance = nullptr;
	
	const Jeu& Jeu::getInstance() {
		if (instance == nullptr) instance = new Jeu;
		return *instance;
	}

	void Jeu::libereInstance() {
		delete instance; 
		instance = nullptr;
	}*/

	// version 3
	// définition de l'attribut static
	Jeu::Handler Jeu::handler = Jeu::Handler();

	const Jeu& Jeu::getInstance() {
		if (handler.instance == nullptr) 
			handler.instance = new Jeu;
		return *handler.instance;
	}

	void Jeu::libereInstance() {
		delete handler.instance;
		handler.instance = nullptr;
	}

	void Plateau::print(ostream& f) const {
		for (size_t i = 0; i < nb; i++) {
			f << *cartes[i] << "\n";
		}
	}

	ostream& operator<<(ostream& f, const Plateau& p) {
		p.print(f);
		return f;
	}

}
#include "set.h"
using namespace Set;

void afficherCartes() {
	for (Jeu::Iterator it = Jeu::getInstance().getIterator(); 
		!it.isDone(); it.next())
			std::cout << it.currentItem() << "\n";
}

void afficherCartes(Forme f) {
	for (Jeu::FormeIterator it = Jeu::getInstance().getIterator(f); !it.isDone(); it
		.next())
		std::cout << it.currentItem() << "\n";
}

void afficherCartes(const Plateau& p) {
	for (Plateau::const_iterator it = p.begin(); it != p.end(); ++it)
		std::cout << *it << "\n";
}

int main() {
	afficherCartes();

	try {
		Controleur c;
		c.distribuer();
		cout << c.getPlateau();
		c.distribuer();
		cout << c.getPlateau();
	}
	catch (SetException& e) {
		std::cout << e.getInfo() << "\n";
	}
	return 0;
}

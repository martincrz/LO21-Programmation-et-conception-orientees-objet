#include "set.h"
using namespace Set;

int main() {
	try {
        Carte c1(Couleur::rouge, Nombre::deux, Forme::losange, Remplissage::hachure);
        std::cout << c1 <<"\n";
        //Carte Tableau[]; >> impossible sans initialisateur : constructeur sans argument
        Carte* pt;  //pointeur n'a pas besoin d'initialisateur
        Carte* tab[5]; //donc c'est possible

		printCouleurs();
		printNombres();
		printFormes();
		printRemplissages();
	}
	catch (SetException& e) {
		std::cout << e.getInfo() << "\n";
	}

	system("pause");
	return 0;
}

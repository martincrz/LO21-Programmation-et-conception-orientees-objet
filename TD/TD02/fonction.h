#include <string>
using namespace std;

void exercice11(void);
void exercice12_q1(int* a, int* b);
void exercice12_q2(int& a, int& b);
void exercice16(void);

struct essai {
    int n;
    float x;
    void raz();
};

struct point {
    int x;
    int y;
    int z;
    void init(int _x = 0, int _y = 0, int _z = 0);
};



void raz_1(essai* e);
void raz_2(essai& e);
void raz(void);

void essai_init(void);


struct personne {
    string nom;
    unsigned int age;
    void raz(void);
    void affiche_struct(void) const;
    void init_struct(const string& str, unsigned int x);
    void copy_struct(const personne& x);
};
void affiche_tab(const personne* tab, size_t n);
void copy_struct(personne& d,const personne& x);
void copy_tab(personne* tabd, const personne* tabs, size_t n);


struct compte {
    string id;
    int solde;
};

int& operation(compte* tab, const string& _id);
void essai_comptes();


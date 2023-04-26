#include <iostream>
#include "fonction.h"

using namespace std;

int main()
{
    //exercice11();

    cout <<"exercice 12 : \n";
    int x=5, y=10;
    exercice12_q1(&x, &y);
    cout <<"x="<<x<<" et y="<<y<<"\n";

    exercice12_q2(x, y);
    cout <<"x="<<x<<" et y="<<y<<"\n\n";

    cout <<"exercice 13 : \n";
    //via adresse
    essai e;
    e.n=5;
    e.x=2.3;
    raz_1(&e);
    cout <<"n="<<e.n<<" et x="<<e.x<<"\n";

    //via ref
    e.n=5;
    e.x=2.3;
    raz_2(e);
    cout <<"n="<<e.n<<" et x="<<e.x<<"\n";

    //via méthode
    e.n=5;
    e.x=2.3;
    e.raz();
    cout <<"n="<<e.n<<" et x="<<e.x<<"\n\n";


    cout <<"exercice 14 : \n\n";
    essai_init();

    cout <<"exercice 16 : \n";
    exercice16();


    cout <<"\nexercice 18 : \n";
    essai_comptes();


    return 0;
}

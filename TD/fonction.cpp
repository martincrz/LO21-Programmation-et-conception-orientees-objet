#include <iostream>
#include <string>
#include <string.h>
#include "fonction.h"
using namespace std;

//Référence - Références const
void exercice11(){
    //rappel : reference

    //double& d1=36;
        //pas valide : référence sur une rvalue > il faut une lvalue pour init
        //rvalue reference : double&& d1=36;
    double d2=36;
    double& ref=d2;
    ref=4;
        //on modifie directement la valeur de la donnée référencée
    const double d3=36;
    const double& d4=36;
        //on crée une référence const qu'on initialise avec 36
        //le compilateur réserve une zone mémoire qui a la même durée de vie que la ref, c'est cette donnée qui est référencée

    const double& d5=d2;
    //d5=21;
        //pas valide : ref const > on ne peut pas modifier la valeur de la donnée référencée
    const double& d6=d3;
    //double& ref2=d6;
        //pas valide : d3 est const, pas de conversion implicite
        //conversion explicite : double& ref2 = const_cast<double&>(d6)
    int i=4;
    //double& d7=i;
        //pas valide : pas de conversion implicite : il faut une exacte correspondance : il faut initilaiser avec une lvalue de même type
    const double& d8=i;
        //conversion possible avec les ref const
    //d8=3;
        //pas valide : ref const

    return;
}

//exercice 12
void exercice12_q1(int* a, int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
    return;
}

void exercice12_q2(int& a, int& b){
    int tmp=a;
    a=b;
    b=tmp;
    return;
}


//exercice13
void raz_1(essai* e){
    e->n=0;
    e->x=0;
    return;
}

void raz_2(essai& e){
    e.n=0;
    e.x=0;
    return;
}

void essai::raz(){
    this->n=0;
    x=0;
    return;
}

//exercice14
void init(point* pt, int _x = 0, int _y = 0, int _z = 0) {
    pt->x=_x; pt->y=_y; pt->z=_z;
}

void point::init(int _x, int _y, int _z){
    x=_x;
    y=_y;
    x=_z;
}

void essai_init() {
    point p;
    init(&p);
    init(&p,1);
    init(&p,1,2);
    init(&p,1,2,3);
    p.init(1,2);
}

//exercice15
void essai_alloc(){
    int* pt_int;
    double* pt_double;
    pt_int= new int;
    pt_double=new double[100];
    delete pt_int;
    delete[] pt_double;
}


//exercice16 modifié à l'exo 17
//Q1
void personne::raz(void){
    //nom[0]='\0';
    nom=""; //nom.clear();
    age=0;
    return;
}

//Q2
void personne::affiche_struct(void) const {
    cout <<"Nom : "<<nom<<" Age : "<<age<<"\n";
    return;
}

void personne::init_struct(const string& str, unsigned int x){
    /*size_t i=0;
    while (str[i]!='\0'){
        nom[i]=str[i];
        i++;
    }
    nom[i]='\0';
    //strcpy(nom, str);
    age = x;*/

    nom=str;
    age=x;
}

void affiche_tab(const personne* tab, size_t n){
    for (size_t i=0 ; i<n ; i++){
        tab[i].affiche_struct();
    }
}

void copy_struct(personne& d,const personne& x){
    size_t i=0;
    while (x.nom[i] != '\0'){
        d.nom[i]=x.nom[i];
        i++;
    }
    d.nom='\0';
    d.age=x.age;

    //strcpy
    //init_struct
}

void personne::copy_struct(const personne& x){
    *this=x;
}

void copy_tab(personne* tabd, const personne* tabs, size_t n){
    for (size_t i=0;i<n;i++) tabd[i]=tabs[i];
}

void exercice16(){
    personne p;
    p.nom="test";
    p.age=46;
    p.affiche_struct();
    p.raz();
    p.affiche_struct();
    p.init_struct("Test", 43);
    p.affiche_struct();

    personne * tab;
    //affiche_tab(&tab, 10);



}

//exercice17

int& operation(compte* tab, const string& _id){
    for (size_t i=0;i<4;i++){
        if (tab[i].id==_id) return tab[i].solde;
    }
}

void essai_comptes(){
    compte tab[4]={{"courant", 0},{"codevi", 1500},{"epargne",200},{"cel",300}};
    operation(tab,"courant")=100;
    operation(tab,"codevi")+=100;
    operation(tab,"cel")-=50;
    for(int i=0; i<4; i++) cout<<tab[i].id<<" : "<<tab[i].solde<<"\n";
}















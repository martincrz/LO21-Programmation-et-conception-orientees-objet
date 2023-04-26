#include <iostream>
#include "fraction.h"

using namespace std;

//void MATH::Fraction::setFraction(int n, int d){}
//ou
namespace MATH{
    Fraction::Fraction(int n, int d):numerateur(n), denominateur(d) {
        std::cout<<"Construction d'une fraction\n";
    };

    void Fraction::setFraction(int n, int d){
        if (d==0) throw FractionException("Denominateur nul");
        numerateur=n; denominateur=d;
    }

    void Fraction::simplification(){
        // si le numerateur est 0, le denominateur prend la valeur 1
        if (numerateur==0) {
            denominateur=1;
            return;
        }

        /* un denominateur ne devrait pas être 0;
        si c’est le cas, on sort de la méthode */
        if (denominateur==0) return;

        /* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun
        Denominateur (PGCD) entre le numerateur et le denominateur */
        int a=numerateur, b=denominateur;
        // on ne travaille qu’avec des valeurs positives...
        if (a<0) a=-a;
        if (b<0) b=-b;
        if (denominateur==1) return;
        while(a!=b){
            if (a>b) a=a-b;
            else b=b-a;
        }
        // on divise le numerateur et le denominateur par le PGCD=a
        numerateur/=a; denominateur/=a;
        // si le denominateur est négatif, on fait passer le signe - au denominateur
        if (denominateur<0) {
            denominateur=-denominateur;
            numerateur=-numerateur;
        }
}

}


//SOMME VIA METHODE
MATH::Fraction MATH::Fraction::Somme(const Fraction& f){
    numerateur = f.denominateur*numerateur + f.numerateur*denominateur;
    denominateur=denominateur * f.denominateur;
    simplification();
}


//SOMME VIA FONCTION
MATH::Fraction MATH::Somme(const Fraction& f1, const Fraction& f2){
        Fraction res(f1.getNumerateur()*f2.getDenominateur()+
                     f2.getNumerateur()*f1.getDenominateur(),
                     f1.getDenominateur()*f2.getDenominateur());
        return res;
    }

MATH::Fraction MATH::Fraction::operator+(const Fraction& f){
    numerateur = f.denominateur*numerateur + f.numerateur*denominateur;
    denominateur=denominateur * f.denominateur;
    simplification();
}

MATH::Fraction MATH::operator-(const Fraction& f1, const Fraction& f2){
        Fraction res(f1.getNumerateur()*f2.getDenominateur()-
                     f2.getNumerateur()*f1.getDenominateur(),
                     f1.getDenominateur()*f2.getDenominateur());
        return res;
    }

//INCREMENTATION : VERSION METHODE
MATH::Fraction& MATH::Fraction::operator++(){  //PREFIXE
    numerateur += denominateur;
    simplification();
    return *this;
}
MATH::Fraction MATH::Fraction::operator++(int){  //POSTFIXE
    Fraction old(numerateur, denominateur);
    numerateur+=denominateur;
    simplification();
    return old;
}

//DECREMENTATION : VERSION FONCTION
MATH::Fraction& MATH::operator--(Fraction& f){  //PREFIXE
    f.setFraction(f.getNumerateur()-f.getDenominateur(), f.getDenominateur());
    return f;

}
MATH::Fraction MATH::operator--(Fraction& f, int){ //POSTFIXE
    Fraction old(f);
    f.setFraction(f.getNumerateur() - f.getDenominateur(), f.getDenominateur());
    return old;
}

std::ostream& operator<<(std::ostream& f, const MATH::Fraction& frac){
    f << frac.getNumerateur();
    if (frac.getDenominateur() !=1)
        f << "/" << frac.getDenominateur();
    return f;
}


#include <iostream>
#include "fraction.h"

using namespace std;
using namespace MATH;


Fraction* myFunction(){
    Fraction fx(7,8);
    Fraction* pfy=new Fraction(2,3);
    return pfy;
}

int q6(){
    Fraction f1(3,4);
    Fraction f2(1,6);
    Fraction* pf3=new Fraction(1,2);
    cout<<"ouverture d’un bloc\n";
    Fraction* pf6;
    {
        Fraction f4(3,8);
        Fraction f5(4,6);
        pf6=new Fraction(1,3);
    }
    cout<<"fin d’un bloc\n";
    cout<<"debut d’une fonction\n";
    Fraction* pf7=myFunction();
    cout<<"fin d’une fonction\n";
    cout<<"desallocations controlee par l’utilisateur :\n";
    delete pf6;
    delete pf7;
    return 0;
}

int main()
{
    try {
        using namespace MATH;
        Fraction f1(1,4);
        Fraction f2=Fraction(1,4);
        Fraction* ptf1=new Fraction(2,3);
        Fraction f3(4);
        f3.setFraction(3,0);

        f3 = Somme(f1, f2); //via fonction
        f3 = f1.Somme(f2); //via méthode
        //f4 = f1+f2; //grace à surchage d'opérateur

        //sq6();
        Fraction f4(2,9);
        f4=f1.operator+(f2);
        f4=operator-(f1,f2);


        cout << f4;


        f4 = f1 + f2;

        cout << f4;
    }
    catch(FractionException e) {cout << "erreur : " << e.get_info() <<"\n";}
    catch(...){std::cout << "il y a eu une exception\n";}




    //f1.setFraction(3,4);
    //cout << f4.getNumerateur() << endl;


    return 0;
}

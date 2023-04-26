#include<iostream>
using namespace std;

const double PI=3.14159;

void exerciceA(){
    int r; double p, s;
    cout<<"donnez le rayon entier d’un cercle: ";
    cin>>r;
    p=2*PI*r;
    s=PI*r*r;
    cout<<"le cercle de rayon "<<r;
    cout<<" a un perimetre de "<<p<<" et une surface de "<<s<<"\n";
}



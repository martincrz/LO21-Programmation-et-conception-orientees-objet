#pragma once

namespace MATH{

    class FractionException{
            std::string info;
    public:
        FractionException(const std::string& s) : info(s){}
        const std::string& get_info() const {return info;}
    };


    class Fraction{
        private :
            int numerateur=0;       //possibilité d'initialiser directement ici
            int denominateur=1;
            void simplification();

        public :
            //CONSTRUCTEURS
            Fraction(int n, int d);
            Fraction(int n): numerateur(n), denominateur(1){}
            //Fraction(int n, int d): numerateur(n), denominateur(d) {}
            //Fraction()= default;

            //DESTRUCTEURS
            ~Fraction()= default;


            //ACCESSEURS                                                                                        //accesseurs en lecture : inline
            inline int getNumerateur() const;                                                                   //accesseurs en écriture définis dans le fichier fraction.cpp
            //int getNumerateur() const {return numerateur;};
            int getDenominateur() const {return denominateur;};
            void setFraction(int n, int d);

            //SOMME SOUS FORME DE METHODE
            Fraction Somme(const Fraction& f);

            //OPERATOR+
            Fraction operator+(const Fraction& f);


            Fraction& operator++(); //prefixe
            Fraction operator++(int); //postfixe

    }; //FIN CLASS FRACTION

    inline int Fraction::getNumerateur() const{
        return numerateur;
    }

    //SOMME SOUS FORME DE FONCTION
    Fraction Somme(const Fraction& f1, const Fraction& f2);

    //OPERATOR-
    Fraction operator-(const Fraction& f1, const Fraction& f2);

    Fraction& operator--(Fraction& f); //prefixe
    Fraction operator--(Fraction&, int); //postfixe

} //FIN NAMESPACE


std::ostream& operator<<(std::ostream& f, const MATH::Fraction& frac);




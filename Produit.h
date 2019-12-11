//
// Created by Jonathan Lignier on 11/12/2019.
//
#include <iostream>

#ifndef ITC313_TP2_PRODUIT_H
#define ITC313_TP2_PRODUIT_H

using namespace std;
class Produit {

    private:
        string m_titre;
        string m_description;
        int m_quantite;
        double m_prix_unitaire;

    public:
        Produit();
        Produit(string titre, string desc, int quantite, double prix);

        string getTitre();
        string getDescription();
        int getQuantite();
        double getPrixUnitaire();
        string toString();
        void modifierQuantite(int quantite);

        friend ostream&operator<< (ostream&output, Produit produit);

};



#endif //ITC313_TP2_PRODUIT_H

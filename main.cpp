//
// Created by Jonathan Lignier on 11/12/2019.
//
#include <iostream>
#include <iomanip>
#include "Magasin.h"

using namespace std;

int main(){



    vector<Produit*> produits;
    Produit* p = new Produit("Titre", "Description", 12, 59.99);
    Produit* p2 = new Produit("Titre2", "Description2", 13, 69.99);

    vector<Client*> clients;
    vector<Commande*> commandes;


    Magasin magasin();
    cout << p << endl;
    cout << p2 << endl;

    return 0;


}
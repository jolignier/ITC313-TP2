//
// Created by Jonathan Lignier on 11/12/2019.
//

#ifndef EASYSHOP_MAGASIN_H
#define EASYSHOP_MAGASIN_H

#include <iostream>
#include <vector>
#include <iostream>

#include "Client.h"
#include "Produit.h"
#include "Client.h"
#include "Commande.h"

using namespace std;

class Magasin {

    private:
        vector<Produit*> m_produits;
        vector<Client*> m_clients;
        vector<Commande*> m_commandes;

        int startIDClient;
        int startIDProduct;

    public:
        Magasin();
        Magasin(vector<Produit*> produits, vector<Client*> clients, vector<Commande*> commandes, int idC = 0, int idP = 0);

        ~Magasin();
        vector<Produit*> getProduits();
        vector<Client*> getClients();
        vector<Commande*> getCommandes();

        Produit* getProduit(string nom);

        void addProduit(Produit* p);
        void displayProducts();
        void displayProduct(string name);
        void updateProductQuantity(Produit* p, int quantity);
        void displayClients();
        void displayClient(int id);
        void displayClient(string name, string surname);

        void addProductToBasket(Client* c, Produit* p);
        void removeProductFromBasket(Client* c, Produit* p);

        void validerCommande(Commande* c);
        void setCommandeStatut(Commande* c, string statut);

        void displayCommandesValidees();

        void displayCommandesClient(Client* client);
        void displayCommandesClient(int id);
        void displayCommandesClient(string prenom, string nom);
};


#endif //EASYSHOP_MAGASIN_H

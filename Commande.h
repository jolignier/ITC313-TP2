//
// Created by Jonathan Lignier on 11/12/2019.
//

#ifndef EASYSHOP_COMMANDE_H
#define EASYSHOP_COMMANDE_H

#include <string>

#include "Client.h"
#include <vector>
#include "Client.h"
#include "Produit.h"

using namespace std;

class Commande {

    public:
        Commande();
        Commande(Client* client, vector<Produit*> produits, string statut, string numero);

        Client* getClient();
        vector<Produit*> getProduits();

        string getStatut();
        string getNumero();
        void setClient(Client* client);
        void setProduits(vector<Produit*> produits);
        void setStatut(string statut);
        void setNumero(string numero);

        friend ostream& operator << (ostream &output, Commande Commande);

    private:
        Client* m_client;
        vector<Produit*> m_produits;
        string m_statut;
        string m_numero;
};

#endif // EASYSHOP_COMMANDE_H
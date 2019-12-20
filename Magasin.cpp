//
// Created by Jonathan Lignier on 11/12/2019.
//

#include "Magasin.h"

Magasin::Magasin() {}

Magasin::Magasin(vector<Produit*> produits, vector<Client*> clients, vector<Commande*> commandes){
   this->m_clients = clients;
   this->m_produits = produits;
   this->m_commandes = commandes;
}


vector<Produit*> Magasin::getProduits(){
    return m_produits;
}
vector<Client* >Magasin::getClients(){
    return m_clients;
}
vector<Commande*> Magasin::getCommandes(){
    return m_commandes;
}

void Magasin::addProduit(Produit *p) {
    m_produits.push_back(p);
}

void Magasin::displayProducts() {

}

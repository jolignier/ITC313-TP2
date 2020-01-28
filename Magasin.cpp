//
// Created by Jonathan Lignier on 11/12/2019.
//
#include <iostream>
#include <iomanip>
#include "Magasin.h"
#include "ConsoleTable.h"

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
    ConsoleTable table{"Nom","Description", "Quantite", "Prix Unitaire"};
    table.addTopLine("Liste des produits du magasin");
    table.setStyle(1);
    for (int i = 0; i < getProduits().size(); ++i) {
        string nom = getProduits().at(i)->getTitre() ;
        string description = getProduits().at(i)->getDescription();
        string quantite = to_string(getProduits().at(i)->getQuantite());

        stringstream stream;
        stream << fixed << setprecision(2) << "$ " << getProduits().at(i)->getPrixUnitaire();
        string prix = stream.str();

        table += {nom, description, quantite, prix};
    }
    table.sort(true);
    cout << table;
}

void Magasin::updateProductQuantity(Produit *p, int quantity) {
    for (int i = 0; i < m_produits.size(); ++i) {
        if (p == m_produits.at(i)){
            p->modifierQuantite(quantity);
        }
    }
}

void Magasin::displayProduct(string name) {
    for (int i = 0; i < m_produits.size(); ++i) {
        if (m_produits.at(i)->getTitre() == name){

            ConsoleTable table{"Nom","Description", "Quantite", "Prix Unitaire"};
            table.addTopLine("Description du produit");
            table.setStyle(1);

            string nom = m_produits.at(i)->getTitre();
            string description = m_produits.at(i)->getDescription();
            string quantite = to_string(m_produits.at(i)->getQuantite());

            stringstream stream;
            stream << fixed << setprecision(2) << "$ " << m_produits.at(i)->getPrixUnitaire();
            string prix = stream.str();

            table += {nom, description, quantite, prix};
            cout << table;
        }
    }
}

void Magasin::displayClients() {
    ConsoleTable table{"ID", "Prenom", "Nom"};
    table.addTopLine("Liste des clients");
    table.setStyle(1);

    for (int i = 0; i < m_clients.size(); ++i) {
        string id = to_string(m_clients.at(i)->getId());
        string prenom = m_clients.at(i)->getPrenom();
        string nom = m_clients.at(i)->getNom();
        table += {id, prenom, nom};
    }
    cout << table;
}

void Magasin::displayClient(int id) {
    for (int i = 0; i < m_clients.size(); ++i) {
        if (m_clients.at(i)->getId() == id){

            ConsoleTable table{"ID", "Prenom", "Nom"};
            table.addTopLine("Liste des clients");
            table.setStyle(1);
            string id = to_string(m_clients.at(i)->getId());
            string prenom = m_clients.at(i)->getPrenom();
            string nom = m_clients.at(i)->getNom();
            table += {id, prenom, nom};
            cout << table;
        }
    }
}

void Magasin::displayClient(string name, string surname) {
    for (int i = 0; i < m_clients.size(); ++i) {
        if (m_clients.at(i)->getPrenom() == name && m_clients.at(i)->getNom() == surname){

            ConsoleTable table{"ID", "Prenom", "Nom"};
            table.addTopLine("Liste des clients");
            table.setStyle(1);
            string id = to_string(m_clients.at(i)->getId());
            string prenom = m_clients.at(i)->getPrenom();
            string nom = m_clients.at(i)->getNom();
            table += {id, prenom, nom};
            cout << table;
        }
    }
}

void Magasin::validerCommande(Commande c) {
    setCommandeStatut(c, "Validée");
}

void Magasin::setCommandeStatut(Commande c, string statut) {
    for (int i = 0; i < m_commandes.size(); ++i) {
        if (c.getNumero() == m_commandes.at(i)->getNumero()){
            m_commandes.at(i)->setStatut(statut);
        }
    }
}

void Magasin::displayCommandesValidee() {

    ConsoleTable table{"Numéro","ID CLient", "Nom Client", "Prix Total"};
    table.addTopLine("Liste des commandes");
    for (int i = 0; i < m_commandes.size(); ++i) {
        double prixTotal = m_commandes.at(i)->getPrixTotal();

        stringstream stream;
        stream << fixed << setprecision(2) << "$ " << prixTotal;
        string prix = stream.str();

//        table += {nom, description, quantite, prix};
    }
}

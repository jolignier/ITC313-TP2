//
// Created by Jonathan Lignier on 11/12/2019.
//

#include <iostream>
#include <iomanip>
#include "Commande.h"
#include "ConsoleTable.h"

using namespace std;

Commande::Commande() : m_client(), m_produits(), m_statut("Non renseigne"), m_numero("00000") {

}


Commande::Commande(Client* client, vector<Produit*> produits, string statut, string numero) {
    this->m_client = client;
    this->m_produits = produits;
    this->m_statut = statut;
    this->m_numero;
}


void Commande::setClient(Client* client){
	this->m_client = client;
}


void Commande::setProduits(vector<Produit*> produits){
	this->m_produits = produits;
}

void Commande::setStatut(string statut){
	this->m_statut = statut;
}

void Commande::setNumero(string numero){
	this->m_numero = numero;
}

Client* Commande::getClient(){
	return this->m_client;
}

vector<Produit*> Commande::getProduits(){
	return this->m_produits;
}

string Commande::getStatut(){
	return this->m_statut;
}

string Commande::getNumero(){
	return this->m_numero;
}

ostream&operator<< (ostream&output,Commande commande){

    ConsoleTable table{"Nom","Description", "Quantite", "Prix"};
    table.setTitle("Details de la commande");
    table.setStyle(1);
    for (int i = 0; i < commande.getProduits().size(); ++i) {
        string nom = commande.getProduits().at(i)->getTitre();
        string description = commande.getProduits().at(i)->getDescription();
        string quantite = to_string(commande.getProduits().at(i)->getQuantite());

        stringstream stream;
        stream << fixed << setprecision(2) << "$ " << commande.getProduits().at(i)->getPrixUnitaire();
        string prix = stream.str();

        table += {nom, description, quantite, prix};
    }
    table.sort(true);
    output << table;
	return output;
}
//
// Created by Jonathan Lignier on 11/12/2019.
//

#include <iostream>
#include "Commande.h" 

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
	output << "-------------------------------------------------------------------------------" <<endl;
	output << "| Détails de la commande                                                      |" << endl;
	output << "-------------------------------------------------------------------------------" << endl;

	output << "| #" << commande.getNumero() << "|" << endl;
	output << "| client :" << commande.getClient()->getId() << "|\t\t|" << endl;
	
	for (int i = 0; i < commande.getProduits().size(); ++i)
	{
		output << "| " << i+1 << " " << commande.getProduits().at(i)->toString() << "\t\t|" << endl;
	}
	
	output << "| statut : " << commande.getStatut() << "\t\t|" << endl;
	
	output << "-------------------------------------------------------------------------------" << endl;
	return output;
}
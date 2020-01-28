//
// Created by Jonathan Lignier on 11/12/2019.
//
#include <iostream>
#include "Magasin.h"

using namespace std;

int main(){

    vector<Produit*> produits;
    Produit* p3 = new Produit("Xbox One", "Console de jeu Microsoft", 15, 179.99);
    Produit* p = new Produit("PS4 ", "Console de jeu Sony", 10, 249.99);
    Produit* p2 = new Produit("Switch", "Console de jeu Nintendo", 20, 299.99);

    produits.push_back(p3);
    produits.push_back(p2);

    int c_id = 253;
    int co_id = 2445;

    vector<Client*> clients;
    Client* client = new Client(++c_id, "Ginhac", "Dom", produits);

    produits.push_back(p);

    Client* client2 = new Client(++c_id, "Gates", "Bill", produits);

    clients.push_back(client);
    clients.push_back(client2);

    vector<Commande*> commandes;
    Commande* co = new Commande(client, client->getPanier(), "En cours de traitement", ++co_id);
    commandes.push_back(co);

    Produit* secret = new Produit("????", "Produit secret du magasin", 1, 999999999.99);
    produits.push_back(secret);

    Magasin magasin(produits,clients, commandes);


    magasin.displayProducts();
    magasin.updateProductQuantity(p2, 25);
    magasin.displayProduct("Switch");

    magasin.displayClients();

    magasin.displayClient("Dom", "Ginhac");
    magasin.displayClient(255);

    magasin.validerCommande(co);
    magasin.displayCommandesValidees();

    magasin.displayCommandesClient(client);

    return 0;


}
//
// Created by Jonathan Lignier on 28/01/2020.
//


// This menu was intended for UNIX systems like
// While running on WINDOWS systems, you may experience some artefacts
// If it's your case, please enable WSL and run this program under bash.exe

#define ANSI_GREEN "\033[0;92m"
#define ANSI_RED   "\033[0;91m"
#define ANSI_RESET "\033[0;0m"

#define SLEEP_DELAY 2

#include <iostream>
#include <limits>
#include <sys/ioctl.h>
#include <unistd.h>

#include "Magasin.h"

using namespace std;


void move(int x, int y){
    // Déplace le curseur en x,y
    string escape_ANSI = "\033["+to_string(y)+";"+to_string(x)+"H";
    printf("%s", escape_ANSI.c_str());
}

void drawInputBox(){
    // Get terminal size on UNIX based systems
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    // Beginning of
    int x = size.ws_col - 15;
    int y = size.ws_row - 3;

    string top = "╔══════════╗";
    string mid = "║          ║";
    string bot = "╚══════════╝";

    // DRAW THE BOX
    move(x,y);
    printf("%s", top.c_str());
    move(x,y+1);
    printf("%s", mid.c_str());
    move(x,y+2);
    printf("%s", bot.c_str());

    // MOVE CURSOR INSIDE THE BOX
    move(x+5, y+1);
}

void displayTitleScreen() {
    system("clear");
    move(5, 2);
    cout << ANSI_GREEN << "███████╗ █████╗ ███████╗██╗   ██╗" << ANSI_RESET << "███████╗██╗  ██╗ ██████╗ ██████╗ ";
    move(5, 3);
    cout << ANSI_GREEN << "██╔════╝██╔══██╗██╔════╝╚██╗ ██╔╝" << ANSI_RESET << "██╔════╝██║  ██║██╔═══██╗██╔══██╗";
    move(5, 4);
    cout << ANSI_GREEN << "█████╗  ███████║███████╗ ╚████╔╝ " << ANSI_RESET << "███████╗███████║██║   ██║██████╔╝";
    move(5, 5);
    cout << ANSI_GREEN << "██╔══╝  ██╔══██║╚════██║  ╚██╔╝  " << ANSI_RESET << "╚════██║██╔══██║██║   ██║██╔═══╝ ";
    move(5, 6);
    cout << ANSI_GREEN << "███████╗██║  ██║███████║   ██║   " << ANSI_RESET << "███████║██║  ██║╚██████╔╝██║     ";
    move(5, 7);
    cout << ANSI_GREEN << "╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝   " << ANSI_RESET << "╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝     " << endl;
    cout << "L'application EASYSHOP Facilite votre vie et vous permet de devenir au moins aussi riche que Elon Musk !"<< endl << endl;
    cout << "1 - Lancer le programme" << endl;
    cout << "2 - Quitter" << endl;
    drawInputBox();
}

void displayMainMenu(){
    system("clear");
    cout << "1 - Gestion du magasin" << endl;
    cout << "2 - Gestion des clients" << endl;
    cout << "3 - Gestion des commandes" << endl;
    cout << "4 - Sauvegarder le magasin" << endl;
    cout << "5 - Charger un magasin" << endl;
    cout << "6 - Retour à l'écran titre" << endl;
    drawInputBox();
}

void displayUserManagement() {
    system("clear");
    cout << "1 - Ajouter un client" << endl;
    cout << "2 - Afficher la liste des clients" << endl;
    cout << "3 - Afficher un client grâce à son ID" << endl;
    cout << "4 - Afficher un client grâce à son nom" << endl;
    cout << "5 - Retour au menu principal" << endl;
    drawInputBox();
}

void displayOrderManagement() {
    system("clear");
    cout << "1 - Afficher la liste des commandes" << endl;
    cout << "2 - Valider une commande grâce à son ID" << endl;
    cout << "3 - Afficher la liste des commandes validées" << endl;
    cout << "4 - Afficher une commande grâce à son ID" << endl;
    cout << "5 - Afficher toutes les commandes d'un certain client grâce à son ID" << endl;
    cout << "6 - Afficher toutes les commandes d'un certain client grâce à son nom" << endl;
    cout << "7 - Retour au menu principal" << endl;
    drawInputBox();
}

void displayShopManagement() {
    system("clear");
    cout << "1 - Ajouter un produit" << endl;
    cout << "2 - Modifier la quantité d'un produit" << endl;
    cout << "3 - Afficher tous les produits du magasin" << endl;
    cout << "4 - Afficher les détails d'un produit grâce à son nom" << endl;
    cout << "5 - Retour au menu principal" << endl;
    drawInputBox();
}

int getInput(){
    int choix;
    cin >> choix;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        choix = -1;
    }
    return choix;
}

void press_to_continue() {
    cout << ANSI_GREEN << "Appuyer sur ENTREE pour continuer ..." << ANSI_RESET << endl;
    system("read var");
}

void to_be_implemented_next() {
    system("clear");
    move(5, 2);
    cout << ANSI_RED << " █████╗     ██╗   ██╗███████╗███╗   ██╗██╗██████╗ " << endl;
    move(5, 3);
    cout <<             "██╔══██╗    ██║   ██║██╔════╝████╗  ██║██║██╔══██╗" << endl;
    move(5, 4);
    cout <<             "███████║    ██║   ██║█████╗  ██╔██╗ ██║██║██████╔╝" << endl;
    move(5, 5);
    cout <<             "██╔══██║    ╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║██╔══██╗" << endl;
    move(5, 6);
    cout <<             "██║  ██║     ╚████╔╝ ███████╗██║ ╚████║██║██║  ██║" << endl;
    move(5, 7);
    cout <<             "╚═╝  ╚═╝      ╚═══╝  ╚══════╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝" << endl;
    move(5,9);
    cout << "Appuyer sur ENTREE pour revenir à l'écran titre ..." << ANSI_RESET << endl;
    system("read var");
}

void init_shop_with_dummy_values(Magasin* shop){
    Produit* p3 = new Produit("Xbox One", "Console de jeu Microsoft", 15, 179.99);
    Produit* p = new Produit("PS4 ", "Console de jeu Sony", 10, 249.99);
    Produit* p2 = new Produit("Switch", "Console de jeu Nintendo", 20, 299.99);

    shop->addProduit(p);
    shop->addProduit(p2);
    shop->addProduit(p3);

    Client* client = new Client(shop->generateClientID(), "Ginhac", "Dom", shop->getProduits());
    Client* client2 = new Client(shop->generateClientID(), "Gates", "Bill", shop->getProduits());

    shop->addClient(client);
    shop->addClient(client2);

    Commande* co = new Commande(client, client->getPanier(), "En cours de traitement", shop->generateOrderID());
    Commande* co2 = new Commande(client2, client->getPanier(), "En cours de traitement", shop->generateOrderID());

    shop->addCommande(co);
    shop->addCommande(co2);
}


int main(){
    // Global scope variables
    int choix = 0, choix2 = 0, choix3 = 0;
    bool quit = false, quit2 = false, quit3 = false;

    vector<Produit*> produits;
    vector<Client*> clients;
    vector<Commande*> commandes;

    int startIDClient = 0; int startIDOrder = 0;

    Magasin easyshop(produits, clients, commandes, startIDClient, startIDOrder);

    init_shop_with_dummy_values(&easyshop);

    // Loop over the menu until user want to quit
    while(!quit) {
        displayTitleScreen();
        choix = getInput();
        switch(choix){
            case 1: // AFFICHAGE DU MENU PRINCIPAL
                displayMainMenu();
                quit2 = false;
                while(!quit2) {
                    choix2 = getInput();
                    switch(choix2) {
                        case 1 : // GESTION DU MAGASIN
                            displayShopManagement();
                            quit3 = false;
                            while(!quit3){
                                choix3 = getInput();
                                switch(choix3) {
                                    case 1: // Ajouter un produit
                                    {
                                        string nom, desc;
                                        int quantite;
                                        double prixU;
                                        cin.ignore();
                                        cout << "Nom du produit : ";
                                        getline(cin, nom);
                                        cout << "Description du produit : ";
                                        getline(cin, desc);
                                        cout << "Quantitée disponible : ";
                                        quantite = getInput();
                                        cout << "Prix unitaire du produit : ";
                                        cin >> prixU;
                                        Produit* p = new Produit(nom, desc, quantite, prixU);
                                        easyshop.addProduit(p);
                                        cout << ANSI_GREEN << "Le produit a été ajouté" << ANSI_RESET << endl;
                                        sleep(SLEEP_DELAY);
                                        displayShopManagement();
                                        break;
                                    }
                                    case 2: // Modifier la quantité d'un produit
                                    {
                                        string nom;
                                        cout << "Nom du produit : ";
                                        cin.ignore();
                                        getline(cin, nom);
                                        cout << "Nouvelle quantité : ";
                                        int quantite = getInput();
                                        easyshop.updateProductQuantity(easyshop.getProduit(nom), quantite);
                                        cout << ANSI_GREEN << "Le produit a été modifié" << ANSI_RESET << endl;
                                        displayShopManagement();
                                        break;
                                    }
                                    case 3: // Afficher tous les produits du magasin
                                        system("clear");
                                        easyshop.displayProducts();
                                        press_to_continue();
                                        displayShopManagement();
                                        break;
                                    case 4: // Afficher les détails d'un produit
                                    {
                                        string nom;
                                        cout << "Nom du produit : ";
                                        cin.ignore();
                                        getline(cin, nom);
                                        system("clear");
                                        easyshop.displayProduct(nom);
                                        press_to_continue();
                                        displayShopManagement();
                                        break;
                                    }
                                    case 5:  // RETOUR AU MENU PRINCIPAL
                                        displayMainMenu();
                                        quit3 = true;
                                        break;
                                    default:
                                        displayShopManagement();
                                        break;
                                }
                            }
                            break;
                        case 2 : // GESTION DES CLIENTS
                            displayUserManagement();
                            quit3 = false;
                            while(!quit3){
                                choix3 = getInput();
                                switch(choix3) {
                                    case 1: // Ajouter un client
                                    {
                                        int id;
                                        string nom, prenom;
                                        vector<Produit*> panier;
                                        id = easyshop.generateClientID();
                                        cout << "Prenom du client : ";
                                        cin.ignore();
                                        getline(cin, prenom);
                                        cout << "Nom de famille du client : ";
                                        getline(cin, nom);
                                        Client* c = new Client(id,nom, prenom, panier);
                                        easyshop.addClient(c);
                                        cout << ANSI_GREEN << "Le client a été ajouté" << ANSI_RESET << endl;
                                        sleep(SLEEP_DELAY);
                                        displayUserManagement();
                                        break;
                                    }
                                    case 2: // Afficher tous les clients
                                        system("clear");
                                        easyshop.displayClients();
                                        press_to_continue();
                                        displayUserManagement();
                                        break;
                                    case 3: // Aficher un client grâce à son ID
                                    {
                                        cout << "ID Du client : ";
                                        int id = getInput();
                                        system("clear");
                                        easyshop.displayClient(id);
                                        press_to_continue();
                                        displayUserManagement();
                                        break;
                                    }
                                    case 4: // Afficher un client grâce à son nom
                                    {
                                        string prenom, nom;
                                        cout << "Prenom du client : ";
                                        cin.ignore();
                                        getline(cin, prenom);
                                        cout << "Nom de famille du client : ";
                                        getline(cin, nom);
                                        system("clear");
                                        easyshop.displayClient(prenom, nom);
                                        press_to_continue();
                                        displayUserManagement();
                                        break;
                                    }
                                    case 5: // RETOUR AU MENU PRINCIPAL
                                        displayMainMenu();
                                        quit3 = true;
                                        break;
                                    default:
                                        displayUserManagement();
                                        break;
                                }
                            }
                            break;
                        case 3 : // GESTION DES COMMANDES
                            displayOrderManagement();
                            quit3 = false;
                            while(!quit3) {
                                choix3 = getInput();
                                switch(choix3) {
                                    case 1: // Afficher toutes les commandes
                                        system("clear");
                                        easyshop.displayCommandes();
                                        press_to_continue();
                                        displayOrderManagement();
                                        break;
                                    case 2 : // Valider une commande grâce à son ID
                                    {
                                        cout << "ID de la commande : ";
                                        int id = getInput();
                                        Commande * c = easyshop.getCommande(id);
                                        if ( easyshop.getCommande(id) != nullptr) {
                                            easyshop.validerCommande(c);
                                            if (easyshop.getCommande(id)->getStatut() == "Validee") {
                                                cout << ANSI_GREEN << "La commande a été validée" << ANSI_RESET << endl;
                                            } else {
                                                cout << ANSI_RED << "La commande n'a pas été validée" << ANSI_RESET << endl;
                                            }
                                        } else {
                                            cout << ANSI_RED << "La commande n'existe pas" << ANSI_RESET << endl;
                                        }
                                        sleep(SLEEP_DELAY);
                                        displayOrderManagement();
                                        break;
                                    }
                                    case 3: // Afficher toutes les commandes validées
                                        system("clear");
                                        easyshop.displayCommandesValidees();
                                        press_to_continue();
                                        displayOrderManagement();
                                        break;
                                    case 4: // Afficher une commande grâce à son ID
                                     {
                                         cout << "ID de la commande : ";
                                         int id = getInput();
                                         system("clear");
                                         easyshop.displayCommande(id);
                                         press_to_continue();
                                         displayOrderManagement();
                                         break;
                                     }
                                    case 5: // Afficher toutes les commandes d'un client grâce à son ID
                                    {
                                        cout << "ID du client : ";
                                        int id = getInput();
                                        system("clear");
                                        easyshop.displayCommandesClient(id);
                                        press_to_continue();
                                        displayOrderManagement();
                                        break;
                                    }
                                    case 6: // Afficher toutes les commandes d'un client grâce à son nom
                                    {
                                        string prenom, nom;
                                        cout << "Prénom du client : ";
                                        cin.ignore();
                                        getline(cin, prenom);
                                        cout << "Nom de famille du client : ";
                                        getline(cin, nom);
                                        system("clear");
                                        easyshop.displayCommandesClient(prenom, nom);
                                        press_to_continue();
                                        displayOrderManagement();
                                        break;
                                    }
                                    case 7: // RETOUR AU MENU PRINCIPAL
                                        displayMainMenu();
                                        quit3 = true;
                                        break;
                                    default:
                                        displayOrderManagement();
                                        break;
                                }
                            }
                            break;
                        case 4 : // SAUVEGARDER LE MAGASIN
                            to_be_implemented_next();
                            quit2 = true;
                            break;
                        case 5 : // CHARGER UN MAGASIN
                            to_be_implemented_next();
                            quit2 = true;
                            break;
                        case 6 : // RETOUR A L'ECRAN TITRE
                            quit2 = true;
                            break;
                        default:
                            displayMainMenu();
                            break;
                    }
                }
                break;
            case 2 : // QUITTER LE PROGRAMME
                quit = true;
                break;
            default:
                displayTitleScreen();
                break;
        }
    }
    system("clear");
}

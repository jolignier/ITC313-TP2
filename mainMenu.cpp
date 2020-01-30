//
// Created by Jonathan Lignier on 28/01/2020.
//


// This menu was intended for UNIX systems like
// While running on WINDOWS systems, you may experience some artefacts
// If it's your case, please enable WSL and run this program under bash.exe

#define ANSI_GREEN "\033[0;92m"
#define ANSI_RESET "\033[0;0m"

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
    cout << "2 - Modifier un client grâce à son ID" << endl;
    cout << "3 - Modifier un client grâce à son nom" << endl;
    cout << "4 - Afficher la liste des clients" << endl;
    cout << "5 - Afficher un client grâce à son ID" << endl;
    cout << "6 - Afficher un client grâce à son nom" << endl;
    cout << "7 - Retour au menu principal" << endl;
    drawInputBox();
}

void displayOrderManagement() {
    system("clear");
    cout << "1 - Ajouter une commande" << endl;
    cout << "2 - Afficher la liste des commandes passées" << endl;
    cout << "3 - Afficher une commande grâce à son ID" << endl;
    cout << "4 - Afficher toutes les commandes d'un certain client grâce à son ID" << endl;
    cout << "5 - Afficher toutes les commandes d'un certain client grâce à son nom" << endl;
    cout << "6 - Retour au menu principal" << endl;
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
    cin.clear();
    cout << ANSI_GREEN << "Appuyer sur une touche pour continuer ..." << ANSI_RESET << endl;
    //cin.get();
    system("pause");
}

int main(){
    // Global scope variables
    int choix = 0, choix2 = 0, choix3 = 0;
    bool quit = false, quit2 = false, quit3 = false;

    vector<Produit*> produits;
    vector<Client*> clients;
    vector<Commande*> commandes;
    int startIDClient = 1; int startIDProduct = 1;

    Magasin easyshop(produits, clients, commandes, startIDClient, startIDProduct);

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

                                        cout << "Nom du produit : ";
                                        cin >> nom;
                                        cout << "Description du produit : ";
                                        cin >> desc;
                                        cout << "Quantitée disponible : ";
                                        quantite = getInput();
                                        cout << "Prix unitaire du produit : ";
                                        cin >> prixU;
                                        Produit* p = new Produit(nom, desc, quantite, prixU);
                                        easyshop.addProduit(p);
                                        cout << ANSI_GREEN << "Le produit à été ajouté" << ANSI_RESET << endl;
                                        sleep(3);
                                        displayShopManagement();
                                        break;
                                    }
                                    case 2: // Modifier la quantité d'un produit
                                    {
                                        string nom;
                                        cout << "Nom du produit : ";
                                        cin >> nom;
                                        cout << "Nouvelle quantité : ";
                                        int quantite = getInput();
                                        easyshop.updateProductQuantity(easyshop.getProduit(nom), quantite);
                                        cout << ANSI_GREEN << "Le produit à été modifié" << ANSI_RESET << endl;
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
                                        cin >> nom;
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
                                        break;
                                    case 2: // Modifier un client grâce à son ID
                                        break;
                                    case 3: // Modifier un client grâce à son nom
                                        break;
                                    case 4: // Afficher tous les clients
                                        break;
                                    case 5: // Aficher un client grâce à son ID
                                        break;
                                    case 6: // Afficher un client grâce à son nom
                                        break;
                                    case 7: // RETOUR AU MENU PRINCIPAL
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
                                    case 1: // Ajouter une commande
                                        break;
                                    case 2: // Afficher toutes les commandes
                                        break;
                                    case 3: // Afficher une commande grâce à son ID
                                        break;
                                    case 4: // Afficher toutes les commandes d'un client grâce à son nom
                                        break;
                                    case 5:
                                        break;
                                    case 6: // RETOUR AU MENU PRINCIPAL
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
                            break;
                        case 5 : // CHARGER UN MAGASIN
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

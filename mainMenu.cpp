//
// Created by Jonathan Lignier on 28/01/2020.
//


// This menu was intended for UNIX systems like
// While running on WINDOWS systems, you may experience some artefacts
// If it's your case, please enable WSL and run this program under bash.exe



#include <iostream>
#include <limits>
#include <sys/ioctl.h>
#include <unistd.h>

#include "Magasin.h"

using namespace std;


void move(int x, int y){
    // Déplace le curseur en x,y
    string escape_ANSI = "\033["+to_string(y)+";"+to_string(x)+"H";
    printf(escape_ANSI.c_str());
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
    printf(top.c_str());
    move(x,y+1);
    printf(mid.c_str());
    move(x,y+2);
    printf(bot.c_str());

    // MOVE CURSOR INSIDE THE BOX
    move(x+5, y+1);
}

void displayTitleScreen() {
    system("clear");
    move(5, 2);
    cout << "███████╗ █████╗ ███████╗██╗   ██╗███████╗██╗  ██╗ ██████╗ ██████╗ ";
    move(5, 3);
    cout << "██╔════╝██╔══██╗██╔════╝╚██╗ ██╔╝██╔════╝██║  ██║██╔═══██╗██╔══██╗";
    move(5, 4);
    cout << "█████╗  ███████║███████╗ ╚████╔╝ ███████╗███████║██║   ██║██████╔╝";
    move(5, 5);
    cout << "██╔══╝  ██╔══██║╚════██║  ╚██╔╝  ╚════██║██╔══██║██║   ██║██╔═══╝ ";
    move(5, 6);
    cout << "███████╗██║  ██║███████║   ██║   ███████║██║  ██║╚██████╔╝██║     ";
    move(5, 7);
    cout << "╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝     " << endl;
    cout << "L'application EASYSHOP Facilite votre vie et vous permet de devenir au moins aussi riche que Elon Musk !"<< endl << endl;
    cout << "1 - Lancer le programme" << endl;
    cout <<         "2 - Quitter" << endl;
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
    cout << "2 - Modifier un client grâce à son nom" << endl;
    cout << "3 - Afficher la liste des clients" << endl;
    cout << "4 - Afficher un client grâce à son ID" << endl;
    cout << "5 - Afficher un client grâce à son nom" << endl;
    cout << "6 - Retour au menu principal" << endl;
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
    cout << "2 - Modifier un produit grâce à son ID" << endl;
    cout << "3 - Modifier un produit grâce à son nom" << endl;
    cout << "4 - Afficher tous les produits du magasin" << endl;
    cout << "5 - Afficher les détails d'un produit grâce à son ID" << endl;
    cout << "6 - Afficher les détails d'un produit grâce à son nom" << endl;
    cout << "7 - Retour au menu principal" << endl;
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

int main(){

    int choix = 0, choix2 = 0, choix3 = 0;
    bool quit = false, quit2 = false, quit3 = false;

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
                                        break;
                                    case 2: // Modifier un produit
                                        break;
                                    case 3:
                                        break;
                                    case 4:
                                        break;
                                    case 5:
                                        break;
                                    case 6:  // RETOUR AU MENU PRINCIPAL
                                        displayMainMenu();
                                        quit3 = true;
                                        break;
                                    default:
                                        displayShopManagement();
                                        choix3 = getInput();
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
                                    case 2: // Modifier un client
                                        break;
                                    case 3: // Afficher tous les clients
                                        break;
                                    case 4: // Aficher un client grâce à son ID
                                        break;
                                    case 5: // Afficher un client grâce à son nom
                                        break;
                                    case 6: // RETOUR AU MENU PRINCIPAL
                                        displayMainMenu();
                                        quit3 = true;
                                        break;
                                    default:
                                        displayUserManagement();
                                        choix3 = getInput();
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
                                        choix3 = getInput();
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
                            choix2 = getInput();
                            break;
                    }
                }
                break;
            case 2 : // QUITTER LE PROGRAMME
                quit = true;
                break;
            default:
                displayTitleScreen();
                choix = getInput();
                break;
        }
    }
    system("clear");
}

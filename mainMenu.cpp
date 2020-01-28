//
// Created by Ipro on 28/01/2020.
//

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

void afficherMenuPrincipal(){
    system("clear");
    cout << "1 - Gestion des produits." << endl;
    cout << "2 - Gestion des clients." << endl;
    cout << "3 - Getion des commandes." << endl;
    cout << "4 - Gestion du magasin." << endl;
    cout << "5 - Sauvegarder le magasin." << endl;
    cout << "6 - Charger un magasin." << endl;
    cout << "7 - Quitter" << endl;
    cout << endl << endl;
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

    int choix = 0;
    bool quit = false;

    while(!quit) {
        afficherMenuPrincipal();
        choix = getInput();
        switch(choix) {
                break;
            case 1 :
                break;
            case 2 :
                break;
            case 3 :
                break;
            case 4 :
                break;
            case 5 :
                break;
            case 6 :
                break;
            case 7 :
                quit = true;
                break;
            default:
                afficherMenuPrincipal();
                choix = getInput();
        }
    }
}


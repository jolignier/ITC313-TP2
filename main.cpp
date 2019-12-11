//
// Created by Jonathan Lignier on 11/12/2019.
//
#include <iostream>
#include <iomanip>
#include "Produit.h"

using namespace std;

int main(){

    Produit p("Titre", "Description", 12, 59.99);
    cout << p << endl;
    return 0;
}
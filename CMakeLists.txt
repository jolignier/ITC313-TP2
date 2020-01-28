cmake_minimum_required(VERSION 3.0)

# Nom du projet
project(EasyShop)

# On crée des variables SRCS et HEADERS avec les fichiers à compiler
set(SRCS
        main.cpp
        Produit.cpp
        Magasin.cpp
        Client.cpp
        Commande.cpp
        ConsoleTable.cpp
        mainMenu.cpp
        )

set(HEADERS
        Produit.h
        Magasin.h
        Client.h
        Commande.h
        ConsoleTable.h
    )

# On indique que l'on veut un exécutable "EasyShop" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(EasyShop ${SRCS} ${HEADERS})
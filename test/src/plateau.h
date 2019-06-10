//
// Created by quent on 23/04/2019.
//

#ifndef PROJETATAXX_PLATEAU_H
#define PROJETATAXX_PLATEAU_H
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "pion.h"

class plateau {

private:
    int grille[7][7];
    joueur1 B;
    joueur2 R;

    int ColonneDepart;
    int ColonneArrivee;
    int LigneDepart;
    int LigneArrivee;

public:
    plateau();
    void initGrille(int grille[7][7]);
    void setGrille(int grille[7][7]);
    int getGrille();
    void afficherGrille();
    void parcoursGrille();

    int getColonneDepart();
    int getColonneArrivee();
    int getLigneDepart();
    int getLigneArrivee();

    void setColonneDepart(int ColonneDepart);
    void setColonneArrivee(int ColonneArrivee);
    void setLigneDepart(int LigneDepart);
    void setLigneArrivee(int LigneArrivee);



    void deplacementPion(int NumeroJoueur);
    int NumeroJoueur(int NumeroJoueur);
    int verificationDistanceRegles(int ColonneDepart, int ColonneArrivee, int LigneDepart, int LigneArrivee);
    int determinationTypeDeplacement(int ColonneDepart, int ColonneArrivee, int LigneDepart, int LigneArrivee);
    void contaminationPion(int ColonneArrivee, int LigneArrivee, int NumeroJoueur);
    void contaminationPionJ2(int ColonneArrivee, int LigneArrivee);
    int endGame();
};


#endif //PROJETATAXX_PLATEAU_H

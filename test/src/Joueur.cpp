//
// Created by quent on 08/06/2019.
//

#include "Joueur.h"


Joueur::Joueur(QWidget *parent):QPushButton(parent) {
    setNumJoueur(0);
}

void Joueur::setNumJoueur(int num) {    //Le numéro du joueur permet de différencier les différents types de cases.
    this->numJoueur = num;
}

int Joueur::getNumJoueur() {
    return this->numJoueur;
}


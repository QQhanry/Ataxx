//
// Created by quent on 08/06/2019.
//

#include "Joueur.h"


Joueur::Joueur(QWidget *parent):QPushButton(parent) {
    setNumJoueur(0);
}

void Joueur::setNumJoueur(int num) {
    this->numJoueur = num;
}

int Joueur::getNumJoueur() {
    return this->numJoueur;
}


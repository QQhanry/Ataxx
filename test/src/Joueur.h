//
// Created by quent on 08/06/2019.
//

#ifndef TP4_JOUEUR_H
#define TP4_JOUEUR_H


#include <QtWidgets/QPushButton>

class Joueur : public QPushButton{
Q_OBJECT

public:
    Joueur(QWidget* parent = nullptr);
    void setNumJoueur(int num);
    int getNumJoueur();

private:
    int numJoueur;
};


#endif //TP4_JOUEUR_H

//
// Created by quent on 28/05/2019.
//

#include <QPushButton>
#include <iostream>
#include <QGraphicsPixmapItem>
#include "AffichageJeu.h"


AffichageJeu::AffichageJeu(QWidget *parent):QLabel(parent) {
    this->setWindowTitle("Ataxx-Game");

    this->setMinimumWidth(1000);
    this->setMinimumHeight(600);
    this->setMaximumWidth(1000);
    this->setMaximumHeight(600);

    this->background = new QPixmap("fondjeu.png");
    this->setPixmap(*background);
    this->setScaledContents(true);
    this->adjustSize();


    this->plateau = new QGridLayout(this);

    QPixmap caseVide("Carre_gris.jpg");
    QPixmap caseJoueur1("Carre_bleu.png");
    QPixmap caseJoueur2("Carre_rouge.jpg");

    setPlateau(caseVide, caseJoueur1, caseJoueur2);

    this->setLayout(plateau);

}

void AffichageJeu::setPlateau(QPixmap caseVide, QPixmap caseJoueur1, QPixmap caseJoueur2) {
    this->plateau->setContentsMargins(250,100,250,100);


    for(int i(0); i< 7;i++){
        for (int j = 0; j < 7; ++j) {
            this->square.insert(i,new QLabel(this));
            this->square[i]->setBackgroundRole(QPalette:: Dark);
            this->square[i]->setScaledContents(true);

            if (j==0 && i ==0){
                this->square[i]->setPixmap(caseJoueur1);
            }else if(j==6 && i==6){
                this->square[i]->setPixmap(caseJoueur2);
            }else{
                this->square[i]->setPixmap(caseVide);
            }
            this->plateau->addWidget(square[i],j,i);
        }

    }
}


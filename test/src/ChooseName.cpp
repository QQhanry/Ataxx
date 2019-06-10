//
// Created by quent on 05/06/2019.
//

#include <QtWidgets/QPushButton>
#include <iostream>
#include <QtWidgets/QMessageBox>
#include "ChooseName.h"

ChooseName::ChooseName(QWidget *parent)
        : QDialog(parent){
    this->setWindowTitle("Ataxx-player's name");    // Création de la fenêtre

    this->setMinimumWidth(200);
    this->setMinimumHeight(100);
    this->setMaximumWidth(200);
    this->setMaximumHeight(100);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *Layout1 = new QHBoxLayout();
    QHBoxLayout *Layout2 = new QHBoxLayout();
    QHBoxLayout *Layout3 = new QHBoxLayout();

    this->nameJ1= new QLabel("Name Player 1");
    Layout1->addWidget(nameJ1);
    this->Text1 = new QLineEdit();
    Layout1->addWidget(Text1);


    this->nameJ2= new QLabel("Name Player 2");
    Layout3->addWidget(nameJ2);
    this->Text2 = new QLineEdit();
    Layout3->addWidget(Text2);
    this->button = new QPushButton("OK");


    mainLayout->addLayout(Layout1);
    mainLayout->addLayout(Layout2);
    mainLayout->addLayout(Layout3);
    mainLayout->addWidget(button);
    this->setLayout(mainLayout);

    setModal(true);

    connect(button,SIGNAL(clicked()),this, SLOT(slotclickok()));
}
ChooseName::~ChooseName(){

}

void ChooseName::slotclickok(){     //Remplissage des champs obligatoire
    QString texte;
    nj1 = Text1->text();
    nj2 = Text2->text();
    if( (nj1=="" && nj2=="")||(nj1=="")||(nj2=="")){
        texte="Remplissez tous les champs";
        QMessageBox::information(this,"Information",texte);
    }else {
        jeu = new AffichageJeu(nullptr, nj1, nj2);
        this->close();
        jeu->show();
    }

}


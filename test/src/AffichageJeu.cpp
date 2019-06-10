//
// Created by quent on 28/05/2019.
//

#include <QPushButton>
#include <iostream>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include "AffichageJeu.h"


AffichageJeu::AffichageJeu(QWidget *parent, QString nameJoueur1, QString nameJoueur2):QLabel(parent) {
    this->setWindowTitle("Ataxx-Game");                     //Création de la fenêtre de jeu

    this->setMinimumWidth(1000);
    this->setMinimumHeight(600);
    this->setMaximumWidth(1000);
    this->setMaximumHeight(600);

    this->background = new QPixmap("fondjeu.png");
    this->setPixmap(*background);
    this->setScaledContents(true);
    this->adjustSize();


    exit= new QPushButton("Exit", this);
    recommencer= new QPushButton("Retry", this);
    joueur1 = new QPushButton(nameJoueur1, this);
    joueur2 = new QPushButton(nameJoueur2, this);
    setButtons(exit,recommencer, joueur1, joueur2);

    moteur = new plateau;


    this->signalMapper = new QSignalMapper(this);

        connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(pionchoice(int)));
        connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(movechoice(int)));




    this->grille = new QGridLayout(this);

    QPixmap caseVide("Carre_gris.jpg");
    QPixmap caseJoueur1("Carre_bleu.png");
    QPixmap caseJoueur2("Carre_rouge.jpg");


    setPlateau(caseVide, caseJoueur1, caseJoueur2);



    this->setLayout(grille);
    connect(exit,SIGNAL(clicked()),this, SLOT(slotclickexit()));
    connect(recommencer,SIGNAL(clicked()),this, SLOT(slotclicktryagain()));
    connect(joueur1,SIGNAL(clicked()),this,SLOT(slotclickinfoj1()));
    connect(joueur2,SIGNAL(clicked()),this,SLOT(slotclickinfoj2()));



}

void AffichageJeu::setPlateau(QPixmap caseVide, QPixmap caseJoueur1, QPixmap caseJoueur2) {
    this->grille->setContentsMargins(250,100,250,100);

    for (int i = 0; i <49; ++i) {                   // Creation de la grille de jeu
        this->square.insert(i,new Joueur(this));
        this->square[i]->setBackgroundRole(QPalette:: Dark);
        this->square[i]->setFixedSize(70,55);
        this->square[i]->setCursor(Qt::PointingHandCursor);

        if (i ==0){
            QSize icon;
            icon.setWidth(100);
            icon.setHeight(100);
            this->square[i]->setIcon(caseJoueur1);
            this->square[i]->setIconSize(icon);
            this->square[i]->setNumJoueur(1);

        }else if(i==48){
            QSize icon;
            icon.setWidth(100);
            icon.setHeight(100);
            this->square[i]->setIcon(caseJoueur2);
            this->square[i]->setIconSize(icon);
            this->square[i]->setNumJoueur(2);
        }else{
            QSize icon;
            icon.setWidth(100);
            icon.setHeight(100);
            this->square[i]->setIcon(caseVide);
            this->square[i]->setIconSize(icon);
            this->square[i]->setNumJoueur(0);
        }
        signalMapper->setMapping(square[i],i);
        connect(square[i], SIGNAL(clicked()), signalMapper, SLOT(map() ));
    }
    for(int i = 0; i < 49; i++){
        this->grille->addWidget(square.at(i),i/7,i%7);

    }
}


void AffichageJeu::setButtons(QPushButton *exit, QPushButton *recommencer, QPushButton *joueur1, QPushButton*joueur2){
    exit->setFont(QFont("Comic Sans MS", 14));              // Création et paramétrages des buttons
    exit->setCursor(Qt::PointingHandCursor);
    exit->setGeometry(850,530,75,40);

    recommencer->setFont(QFont("Comic Sans MS", 14));
    recommencer->setCursor(Qt::PointingHandCursor);
    recommencer->setGeometry(45,530,75,40);

    joueur1->setFont(QFont("Comic Sans MS", 14));
    joueur1->setCursor(Qt::PointingHandCursor);
    joueur1->setGeometry(45,45,75,40);

    joueur2->setFont(QFont("Comic Sans MS", 14));
    joueur2->setCursor(Qt::PointingHandCursor);
    joueur2->setGeometry(850,45,75,40);
}

void AffichageJeu::slotclickexit(){         //gestion du boutton exit
    QPixmap caseVide("Carre_gris.jpg");
    QPixmap caseJoueur1("Carre_bleu.png");
    QPixmap caseJoueur2("Carre_rouge.jpg");

    setPlateau(caseVide, caseJoueur1, caseJoueur2);
    this->close();
}

void AffichageJeu::slotclicktryagain() {    //gestion du bouton retry
    QPixmap caseVide("Carre_gris.jpg");
    QPixmap caseJoueur1("Carre_bleu.png");
    QPixmap caseJoueur2("Carre_rouge.jpg");


    setPlateau(caseVide, caseJoueur1, caseJoueur2);
}

void AffichageJeu::slotclickinfoj1() {              //Affichage des informations relatives aux îons du joueur 1
    int counter = 0;
    QString texte;
    for (int i = 0; i < 49; ++i) {
        if(this->square[i]->getNumJoueur()==1)
            counter++;
    }

    if(counter == 0){
        texte = "Vous n'avez plus de pions.";
    }else if(counter == 1){
        texte = "Vous avez " + QString::number(counter) + " pion.";
    }else{
        texte = "Vous avez " + QString::number(counter) + " pions.";
    }
    QMessageBox::information(this,"Informations Joueur 1",texte);

}

void AffichageJeu::slotclickinfoj2() {          // Affichage des informations relative aux pions du joueur 2
    int counter = 0;
    QString texte;
    for (int i = 0; i < 49; ++i) {
        if(this->square[i]->getNumJoueur()==2)
            counter++;
    }

    if(counter == 0){
        texte = "Vous n'avez plus de pions.";
    }else if(counter == 1){
        texte = "Vous avez " + QString::number(counter) + " pion.";
    }else{
        texte = "Vous avez " + QString::number(counter) + " pions.";
    }
    QMessageBox::information(this,"Informations Joueur 2",texte);
}

void AffichageJeu::pionchoice(int num){     //gestion du clic sur un des pions
    QString texte;

    if((this->square[num]->height()== 55 && this->square[num]->width() == 70)&&(this->square[num]->getNumJoueur()==1 && aQuiLeTour==1)){
        this->square[num]->setFixedSize(59,39);
        this->numD=num;
        determinePosD(numD);

    }else if((this->square[num]->height()== 39 && this->square[num]->width() == 59)&&(this->square[num]->getNumJoueur()==1 && aQuiLeTour==1)){
        this->square[num]->setFixedSize(70,55);

    }else if(this->square[num]->getNumJoueur()==0 && numD==numA==0){
        texte="Ceci n'est pas un pion";

        QMessageBox::information(this,"Information",texte);
    }else if(this->square[num]->getNumJoueur()==2 && aQuiLeTour==1){
        texte="Ce n'est pas ton tour joueur 2";
        QMessageBox::information(this,"Information",texte);
    }

    if((this->square[num]->height()== 55 && this->square[num]->width() == 70)&&(this->square[num]->getNumJoueur()==2&& aQuiLeTour==2)){
        this->square[num]->setFixedSize(59,39);
        this->numD=num;
        determinePosD(numD);

    }else if((this->square[num]->height()== 39 && this->square[num]->width() == 59)&&(this->square[num]->getNumJoueur()==2 && aQuiLeTour==2)){
        this->square[num]->setFixedSize(70,55);

    }else if(this->square[num]->getNumJoueur()==0 && numD==numA==0){
        texte="Ceci n'est pas un pion";
        QMessageBox::information(this,"Information",texte);
    }else if(this->square[num]->getNumJoueur()==1 && aQuiLeTour==2){
        texte="Ce n'est pas ton tour joueur 1";
        QMessageBox::information(this,"Information",texte);
    }


}


void AffichageJeu::movechoice(int num) {        //gestion du déplacement des pions
    this->numA = num;
    determinePosA(num);
    QPixmap caseVide("Carre_gris.jpg");
    QPixmap caseJoueur1("Carre_bleu.png");
    QPixmap caseJoueur2("Carre_rouge.jpg");


    if(moteur->verificationDistanceRegles(this->ColonneDepart,this->ColonneArrivee,this->LigneDepart,this->LigneArrivee)==1 && this->square[num]->getNumJoueur()==0){   //vérification des règles et du type de déplacement

        if(moteur->determinationTypeDeplacement(this->ColonneDepart,this->ColonneArrivee,this->LigneDepart,this->LigneArrivee)==0 && this->square[num]->getNumJoueur()==0){

            if(this->square[numD]->getNumJoueur()==1 ){
                this->square[numA]->setIcon(caseJoueur1);
                this->square[numA]->setNumJoueur(1);
            }else if(this->square[numD]->getNumJoueur()==2){
                this->square[numA]->setIcon(caseJoueur2);
                this->square[numA]->setNumJoueur(2);
            }
            this->square[numD]->setFixedSize(70,55);
            contamination();
             if(aQuiLeTour==1){aQuiLeTour++;}else if(aQuiLeTour==2){aQuiLeTour--;}
            reInitNum();

        }else if(moteur->determinationTypeDeplacement(this->ColonneDepart,this->ColonneArrivee,this->LigneDepart,this->LigneArrivee)==1 && this->square[num]->getNumJoueur()==0){

            if(this->square[numD]->getNumJoueur()==1){
                this->square[numA]->setIcon(caseJoueur1);
                this->square[numD]->setIcon(caseVide);
                this->square[numA]->setNumJoueur(1);
            }else if(this->square[numD]->getNumJoueur()==2){
                this->square[numA]->setIcon(caseJoueur2);
                this->square[numD]->setIcon(caseVide);
                this->square[numA]->setNumJoueur(2);
            }
            this->square[numD]->setNumJoueur(0);
            this->square[numD]->setFixedSize(70,55);
            contamination();
            if(aQuiLeTour==1){aQuiLeTour++;}else if(aQuiLeTour==2){aQuiLeTour--;}
            reInitNum();
        }
    }


}



void AffichageJeu::determinePosA(int num){
    if(num>=0 && num <7){this->LigneArrivee = 0;}
    if (num>=7 && num <14){this->LigneArrivee = 1;}
    if (num>=14 && num <21){this->LigneArrivee = 2;}
    if (num>=21 && num <28){this->LigneArrivee = 3;}
    if (num>=28 && num <35){this->LigneArrivee = 4;}
    if (num>=35 && num <42){this->LigneArrivee = 5;}
    if (num>=42 && num <49){this->LigneArrivee = 6;}


    if(num%7==0){this->ColonneArrivee=0;}
    if(num%7==1){this->ColonneArrivee=1;}
    if(num%7==2){this->ColonneArrivee=2;}
    if(num%7==3){this->ColonneArrivee=3;}
    if(num%7==4){this->ColonneArrivee=4;}
    if(num%7==5){this->ColonneArrivee=5;}
    if(num%7==6){this->ColonneArrivee=6;}

}   //détermination de la position à l'arrivée du pion

void AffichageJeu::determinePosD(int num){
    if(num>=0 && num <7){this->LigneDepart = 0;}
    if (num>=7 && num <14){this->LigneDepart = 1;}
    if (num>=14 && num <21){this->LigneDepart = 2;}
    if (num>=21 && num <28){this->LigneDepart = 3;}
    if (num>=28 && num <35){this->LigneDepart = 4;}
    if (num>=35 && num <42){this->LigneDepart = 5;}
    if (num>=42 && num <49){this->LigneDepart = 6;}


    if(num%7==0){this->ColonneDepart=0;}
    if(num%7==1){this->ColonneDepart=1;}
    if(num%7==2){this->ColonneDepart=2;}
    if(num%7==3){this->ColonneDepart=3;}
    if(num%7==4){this->ColonneDepart=4;}
    if(num%7==5){this->ColonneDepart=5;}
    if(num%7==6){this->ColonneDepart=6;}
}   //détermination au départ du pion

void AffichageJeu::reInitNum() {
    this->numA=this->numD;
    this->numD=0;
}

void AffichageJeu::contamination(){
    QPixmap caseVide("Carre_gris.jpg");
    QPixmap caseJoueur1("Carre_bleu.png");
    QPixmap caseJoueur2("Carre_rouge.jpg");
    int counter1 = 0;
    int counter2=0;
    QString texte;

    for (int i = -1; i < 1; ++i) {                                      //contamination
        if(this->aQuiLeTour == 1){
            if(this->square[numA+i]->getNumJoueur() == 2){
                std::cout<<"numA+i";
                this->square[numA+i]->setNumJoueur(this->aQuiLeTour);
                this->square[numA+i]->setIcon(caseJoueur1);
            }else if(this->square[numA +7 +i]->getNumJoueur() == 2 ){
                std::cout<<"numA+7+i";
                this->square[numA +7 +i]->setNumJoueur(this->aQuiLeTour);
                this->square[numA+i+7]->setIcon(caseJoueur1);
            }else if(this->square[numA -7 +i]->getNumJoueur() == 2){
                std::cout<<"numA -7 +i";
                this->square[numA -7 +i]->setNumJoueur(this->aQuiLeTour);
                this->square[numA+i-7]->setIcon(caseJoueur1);
            }
        }else if(this->aQuiLeTour == 2){
            if(this->square[numA+i]->getNumJoueur()==1){
                std::cout<<"numA+i";
                this->square[numA+i]->setNumJoueur(this->aQuiLeTour);
                this->square[numA+i]->setIcon(caseJoueur2);
            }else if(this->square[numA +7 +i]->getNumJoueur() == 1 ){
                std::cout<<"numA+7+i";
                this->square[numA +7 +i]->setNumJoueur(this->aQuiLeTour);
                this->square[numA+i+7]->setIcon(caseJoueur2);
            }else if(this->square[numA -7 +i]->getNumJoueur() == 1){
                std::cout<<"numA -7 +i";
                this->square[numA -7 +i]->setNumJoueur(this->aQuiLeTour);
                this->square[numA+i-7]->setIcon(caseJoueur2);
            }
        }

    }


    for (int j = 0; j < 49; ++j) {
        if(this->square[j]->getNumJoueur()==1){                 //gestion de victoire
            counter1++;
        }else if(this->square[j]->getNumJoueur()==2){
            counter2++;
        }
    }

    if(counter1==0){                                            //Affichage de victoire
        texte= "Joueur 2 a gagné !!";
        QMessageBox::information(this,"Information",texte);
    }else if(counter2==0){
        texte= "Joueur 1 a gagné !!";
        QMessageBox::information(this,"Information",texte);
    }
}


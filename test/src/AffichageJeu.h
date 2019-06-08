//
// Created by quent on 28/05/2019.
//

#ifndef TP4_AFFICHAGEJEU_H
#define TP4_AFFICHAGEJEU_H

#include <QDialog>
#include <QLabel>
#include <QtWidgets/QGridLayout>
#include <QList>
#include <QRect>
#include <QEvent>
#include <QSignalMapper>
#include "plateau.h"
#include "game.h"
#include "Joueur.h"


class AffichageJeu : public QLabel{
Q_OBJECT

private :
    QPixmap *background;
    QList<Joueur*> square;

    QGridLayout *grille;

    QPushButton *exit;
    QPushButton *recommencer;
    QPushButton *joueur1;
    QPushButton*joueur2;

    int LigneArrivee, ColonneArrivee, LigneDepart, ColonneDepart;
    int numD=0;
    int numA=0;

    int aQuiLeTour = 1;

    QSignalMapper *signalMapper;
    plateau *moteur;


public:
    AffichageJeu(QWidget* parent = nullptr);
    virtual ~AffichageJeu() {};
    void setPlateau(QPixmap pixmap, QPixmap caseJoueur1, QPixmap caseJoueur2);
    void setButtons(QPushButton *exit, QPushButton *recommencer, QPushButton *joueur1, QPushButton*joueur2);
    void determinePosA(int num);
    void determinePosD(int num);
    void reInitNum();
    void setAQuiLeTour();
    void contamination();


public slots:
    void slotclicktryagain();
    void slotclickexit();
    void pionchoice(int num);
    void movechoice(int num);

signals:
    void clicked();

};


#endif //TP4_AFFICHAGEJEU_H

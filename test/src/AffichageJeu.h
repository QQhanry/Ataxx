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
#include "ChooseName.h"

class AffichageJeu : public QLabel {
Q_OBJECT

private :
    QPixmap *background;
    QList<QLabel*> square;
    QGridLayout *plateau;

public:
    AffichageJeu(QWidget* parent = nullptr);
    virtual ~AffichageJeu() {};
    void setPlateau(QPixmap pixmap, QPixmap caseJoueur1, QPixmap caseJoueur2);
    QGridLayout *getPlateau();


};


#endif //TP4_AFFICHAGEJEU_H

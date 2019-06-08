//
// Created by quent on 05/06/2019.
//

#ifndef TP4_CHOOSENAME_H
#define TP4_CHOOSENAME_H

#include "AffichageJeu.h"
#include <QDialog>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>


class ChooseName : public QDialog{
Q_OBJECT
private:
  /*  QString* nameJ1;
    QString* nameJ2;*/

    QLabel *nameJ1;
    QLineEdit *Text1;
    QLabel *nameJ2;
    QLineEdit *Text2;
    QPushButton * button;
    AffichageJeu *jeu;
    QString *nj1;
    QString *nj2;

public:
    ChooseName(QWidget* parent = nullptr);
    ~ChooseName();


public slots:
    void slotclickok();

signals:
    void clicked();

};


#endif //TP4_CHOOSENAME_H

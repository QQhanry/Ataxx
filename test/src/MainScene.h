#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Parametres.h"
#include "AffichageJeu.h"


class MainScene : public QLabel {

    Q_OBJECT

private :
    QLabel *menu;
    QPushButton *button_configure;
    QPushButton *button_play;
    Parametres *fenetre;
    AffichageJeu *jeu;
    ChooseName *name;

public:
    MainScene();
     ~MainScene();

public slots:
    void slotclickconfigure();
    void slotclickplay();

signals:
    void clicked();



};

#endif // MYSCENE_H

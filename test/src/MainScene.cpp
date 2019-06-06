#include "MainScene.h"




MainScene::MainScene() {
    menu = new QLabel;
    menu->setWindowTitle("Ataxx-Accueil");
    menu->setPixmap(QPixmap("decor.png"));
    menu->setScaledContents(true);
    menu->adjustSize();


    button_play= new QPushButton("Play !", menu);
    button_play->setFont(QFont("Comic Sans MS", 14));
    button_play->setCursor(Qt::PointingHandCursor);
    button_play->move(595,350);
    button_play->setGeometry(595,350,100,50);


    button_configure = new QPushButton(menu);
    QPixmap pixmap("parametres.png");
    QIcon ButtonIcon(pixmap);
    QSize icon;
    icon.setWidth(90);
    icon.setHeight(65);
    button_configure->setIcon(ButtonIcon);
    button_configure->setIconSize(icon);
    button_configure->setGeometry(593,203,100,50);

    button_configure->setFlat(true);

    fenetre = new Parametres;

    jeu = new AffichageJeu;
    name = new ChooseName;

    connect(button_configure,SIGNAL(clicked()),this, SLOT(slotclickconfigure()));
    connect(button_play,SIGNAL(clicked()),this, SLOT(slotclickplay()));
    menu->show();

}



void MainScene::slotclickplay(){
    jeu->show();
    name->show();
}

void MainScene::slotclickconfigure() {
    fenetre->show();
}

MainScene::~MainScene() {


}


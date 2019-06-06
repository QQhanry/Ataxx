//
// Created by quent on 05/06/2019.
//

#include <QtWidgets/QPushButton>
#include "ChooseName.h"

ChooseName::ChooseName(QWidget *parent)
        : QDialog(parent){
    this->setWindowTitle("Ataxx-Configure");


    QWidget *mainWidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *Layout1 = new QHBoxLayout();
    QHBoxLayout *Layout2 = new QHBoxLayout();
    QHBoxLayout *Layout3 = new QHBoxLayout();

    this->nameJ1= new QLabel("Name Joueur1");
    Layout1->addWidget(nameJ1);
    this->Text1 = new QLineEdit();
    Layout1->addWidget(Text1);


    this->nameJ2= new QLabel("Name Joueur2");
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

    connect(button,SIGNAL(clicked()),this, SLOT(slotclick(mainWidget)));
}
ChooseName::~ChooseName(){

}
/*void ChooseName::setNameJ1(QString* nameJ1){

}
QString* ChooseName::getNameJ1(){

}
void ChooseName::setNameJ2(QString* nameJ2){

}
QString* ChooseName::getNameJ2(){

}*/

void ChooseName::slotclick(QWidget* mainWidget){
    mainWidget->close();
}
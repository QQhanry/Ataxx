#include <QHBoxLayout>
#include <QVBoxLayout>

#include "Parametres.h"

Parametres::Parametres(QWidget *parent)
    : QDialog(parent)
{

   this->setWindowTitle("Ataxx-Configure");


    QWidget *mainWidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *Layout1 = new QHBoxLayout();
    QHBoxLayout *Layout2 = new QHBoxLayout();
    QHBoxLayout *Layout3 = new QHBoxLayout();

    //Fenêtre paramètre à définir
   /*this->ipAddress= new QLabel("Adresse ip");
    Layout1->addWidget(ipAddress);
    this->Text1 = new QLineEdit();
    Layout1->addWidget(Text1);

    this->user= new QLabel("User");
    Layout2->addWidget(user);
    this->Text2 = new QLineEdit();
    Layout2->addWidget(Text2);

    this->password= new QLabel("Password");
    Layout3->addWidget(password);
    this->Text3 = new QLineEdit();
    Layout3->addWidget(Text3);
    this->button = new QPushButton("OK");*/


    mainLayout->addLayout(Layout1);
    mainLayout->addLayout(Layout2);
    mainLayout->addLayout(Layout3);
    mainLayout->addWidget(button);
    this->setLayout(mainLayout);

    setModal(true);
}



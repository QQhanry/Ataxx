//
// Created by quent on 05/06/2019.
//

#ifndef TP4_CHOOSENAME_H
#define TP4_CHOOSENAME_H

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

public:
    ChooseName(QWidget* parent = nullptr);
    ~ChooseName();
  /*  void setNameJ1(QString* nameJ1);
    QString* getNameJ1();
    void setNameJ2(QString* nameJ2);
    QString* getNameJ2();*/


public slots:
    void slotclick(QWidget* mainWidget);

signals:
    void clicked();
};


#endif //TP4_CHOOSENAME_H

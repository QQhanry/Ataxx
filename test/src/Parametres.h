#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class Parametres : public QDialog
{
    Q_OBJECT

private :
    QDialog *fenetre;

    QLabel *ipAddress;
    QLineEdit *Text1;
    QLabel *user;
    QLineEdit *Text2;
    QLabel *password;
    QLineEdit *Text3;
    QPushButton * button;

public:
    Parametres(QWidget* parent = nullptr);
    virtual ~Parametres() {};



};

#endif // MAINWINDOW_H

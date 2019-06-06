//
// Created by quent on 23/04/2019.
//

#ifndef PROJETATAXX_PION_H
#define PROJETATAXX_PION_H
#include <iostream>
#include <stdio.h>
#include <string.h>


class pion {
private:
    int x;
    int y;

public:
    pion();
    pion(int x, int y);
    virtual ~pion();

    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

    virtual void print() = 0;

};


class joueur1 : public pion{
public:
    joueur1();
    joueur1(int x, int y, std::string couleur);
    virtual ~joueur1();
    void setCouleur(std::string couleur);
    std::string getCouleur();
    virtual void print();
private:
    std::string couleur;

};

class joueur2 : public pion {
public:
    joueur2();
    joueur2(int x, int y, std::string couleur);
    virtual ~joueur2();
    void setCouleur(std::string couleur);
    std::string getCouleur();
    virtual void print();
private:
    std::string couleur;
};
#endif //PROJETATAXX_PION_H

//
// Created by quent on 23/04/2019.
//

#include "pion.h"


//Méthodes classe abstraite pion

pion::pion(){
    setX(0);
    setY(0);
}
pion::pion(int x, int y){
    setX(x);
    setY(y);
}

pion::~pion(){

}

void pion::setX(int x){
    this->x = x;
}

void pion::setY(int y){
    this->y = y;
}

int pion::getX(){
    return this->x;
}

int pion::getY(){
    return this->y;
}



// Méthodes pions joureur1

joueur1::joueur1():pion(){
    setCouleur("blue");
}

joueur1::joueur1(int x, int y, std::string couleur):pion(x,y) {
    setCouleur(couleur);
}


void joueur1::setCouleur(std::string couleur) {
    this->couleur=couleur;
}

std::string joueur1::getCouleur() {
    return this->couleur;
}

joueur1::~joueur1(){

}

void joueur1::print(){
    std::cout<<getX()<<" "<<getY()<<" "<<getCouleur()<<std::endl;
}




//Méthodes pions joueur2
joueur2::joueur2():pion(){
    setCouleur("red");
}

joueur2::joueur2(int x, int y, std::string couleur):pion(x,y) {
    setCouleur(couleur);
}

joueur2::~joueur2(){

}

void joueur2::setCouleur(std::string couleur) {
    this->couleur=couleur;
}

std::string joueur2::getCouleur() {
    return this->couleur;
}



void joueur2::print(){
    std::cout<<getX()<<" "<<getY()<<" "<<getCouleur()<<std::endl;
}


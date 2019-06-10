//
// Created by quent on 23/04/2019.
//

#include "plateau.h"
#include "pion.h"


plateau::plateau(){ //constructeur
    int grille[7][7];
    initGrille(grille);

}

void plateau::initGrille(int grille[7][7]){ //setters getters
    joueur1 B(0,0,"blue");
    joueur2 R(6,6,"red");

    this->B=B;
    this->R=R;

    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {

            grille[i][j] = 0;
            this->grille[i][j]=grille[i][j];
        }
    }

    this->grille[B.getX()][B.getY()]=1; //initialisation des pions du joueur 1

    this->grille[R.getX()][R.getY()]=2; //initialisation des pions du joueur 2

}

void plateau::setGrille(int grille[7][7]){

}

int plateau::getGrille() {
    return this->grille[7][7];
}


int plateau::getColonneDepart(){
    return this->ColonneDepart;
}
int plateau::getColonneArrivee(){
    return this->ColonneArrivee;
}
int plateau::getLigneDepart(){
    return this->LigneDepart;
}
int plateau::getLigneArrivee(){
    return this->LigneArrivee;
}

void plateau::setColonneDepart(int ColonneDepart){
    this->ColonneDepart=ColonneDepart;
}
void plateau::setColonneArrivee(int ColonneArrivee){
    this->ColonneArrivee=ColonneArrivee;
}
void plateau::setLigneDepart(int LigneDepart){
    this->LigneDepart=LigneDepart;
}
void plateau::setLigneArrivee(int LigneArrivee){
    this->LigneArrivee=LigneArrivee;
}




void plateau::afficherGrille(){ // Autres méthodes

    for (int i=0; i < 7; i++) {
        for (int j=0; j < 7; j++) {
            if (this->grille[i][j] == '_' && i == 6)
                std::cout << " ";
            else
                std::cout << this->grille[i][j];
            if (j != 6)
                std::cout << " ";
            else
                std::cout << std::endl;
        }
    }
}


void plateau::deplacementPion(int NumeroJoueur){
    std::cout<<"Colonne de Départ   Ligne de Départ    Colonne d'arrivée   Ligne d'arrivée"<<std::endl;
    std::cin>>ColonneDepart;
    std::cin>>LigneDepart;
    std::cin>>ColonneArrivee;
    std::cin>>LigneArrivee;

    this->ColonneDepart = ColonneDepart - 1;
    this->ColonneArrivee = ColonneArrivee - 1;
    this->LigneDepart = LigneDepart - 1;
    this->LigneArrivee = LigneArrivee - 1;


    if(verificationDistanceRegles(getColonneDepart(), getColonneArrivee(), getLigneDepart(), getLigneArrivee())==1){ //vérification que le déplacement respecte les règles du jeu
        if(this->grille[getLigneArrivee()][getColonneArrivee()]==0 && this->grille[getLigneDepart()][getColonneDepart()]!=0){ //vérification de l'arrivée sur une case vide de pion

            if(determinationTypeDeplacement(this->ColonneDepart, this->ColonneArrivee, this->LigneDepart, this->LigneArrivee)==1){
                if(this->grille[this->LigneDepart][this->ColonneDepart]==1 && NumeroJoueur==1){ //déplacements des pions
                    this->grille[this->LigneDepart][this->ColonneDepart]=0;
                    this->grille[this->LigneArrivee][this->ColonneArrivee]=1;

                } else if(this->grille[this->LigneDepart][this->ColonneDepart]==2 && NumeroJoueur ==2){

                    this->grille[this->LigneDepart][this->ColonneDepart]=0;
                    this->grille[this->LigneArrivee][this->ColonneArrivee]=2;
                }
            } else{
                if(this->grille[this->LigneDepart][this->ColonneDepart]==1 && NumeroJoueur==1){ //ajout d'un pion
                    this->grille[this->LigneArrivee][this->ColonneArrivee]=1;

                } else if(this->grille[this->LigneDepart][this->ColonneDepart]==2 && NumeroJoueur ==2){
                    this->grille[this->LigneArrivee][this->ColonneArrivee]=2;
                }
            }

        }
    }else{
        std::cout<<"Votre choix de déplacement ne respecte pas les règles du jeu"<<std::endl;
    }


}


int plateau::verificationDistanceRegles(int ColonneDepart, int ColonneArrivee, int LigneDepart, int LigneArrivee){      // Vérification de la distance entre la case de départ et d'arrivée

    if(abs(ColonneArrivee-ColonneDepart)<=2 && abs(LigneArrivee-LigneDepart)<=2){
        return 1;
    }else{
        return 0;
    }
}


int plateau::determinationTypeDeplacement(int ColonneDepart, int ColonneArrivee, int LigneDepart, int LigneArrivee){    //Vérification du type de déplacement
    if(abs(ColonneArrivee-ColonneDepart)==2 || abs(LigneArrivee-LigneDepart)==2){
        return 1;
    }else if(abs(ColonneArrivee-ColonneDepart)==1 || abs(LigneArrivee-LigneDepart)==1){
        return 0;
    }
}


void plateau::contaminationPion(int ColonneArrivee, int LigneArrivee, int NumeroJoueur){
    this->ColonneArrivee=ColonneArrivee;
    this->LigneArrivee=LigneArrivee;

    if(NumeroJoueur==1){                                                                                                //conditions sur la contamination des pions
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if(this->ColonneArrivee + i < 0 || this->ColonneArrivee + i >= 7 || this->LigneArrivee + j < 0 || this->LigneArrivee >= 7)
                    continue;

                if(this->grille[this->LigneArrivee + j][this->ColonneArrivee + i] != 0) {
                    this->grille[this->LigneArrivee + j][this->ColonneArrivee + i] = 1;

                }
            }
        }
    }else if(NumeroJoueur==2){
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if(this->ColonneArrivee + i < 0 || this->ColonneArrivee + i >= 7 || this->LigneArrivee + j < 0 || this->LigneArrivee >= 7)
                    continue;

                if(this->grille[this->LigneArrivee + j][this->ColonneArrivee + i] != 0) {
                    this->grille[this->LigneArrivee + j][this->ColonneArrivee + i] = 2;
                }
            }
        }
    }
}


int plateau::endGame(){
    int compteur1=0;
    int compteur2=0;

    for (int i = 0; i < 7; ++i) {               //Comptage du nombre de pions de chaque joueurs
        for (int j = 0; j < 7; ++j) {

            if(this->grille[i][j]==1){
                compteur1++;
            }else if(this->grille[i][j]==2){
                compteur2++;
            }
        }
    }


    if(compteur1==0 || compteur2==0){           //Détermination de vainqueur
        std::cout<<"La partie est finie"<<std::endl;
        if(compteur1==0){
            std::cout<<"Joueur 2 a gagné"<<std::endl;

        }else if(compteur2==0){
            std::cout<<"Joueur 1 a gagné"<<std::endl;
        }
        return 1;
    }else{
        return 0;
    }
}
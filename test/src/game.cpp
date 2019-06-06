//
// Created by quent on 23/04/2019.
//

#include "game.h"


game::game(){
    plateau Tableau;

}
game::~game(){

}




void game::Menu() {
    int choix;

    std::cout<<"Tapez 1 pour jouer"<<std::endl;
    std::cout<<"Tapez 2 pour lire les règles"<<std::endl;
    std::cin>>choix;

    switch(choix){
        case 1:
            while( this->Tableau.endGame()==0){
                std::cout<<"Joueur 1"<<std::endl;
                this->Tableau.afficherGrille();
                this->Tableau.deplacementPion(1);
                std::cout<<"coucou";
                this->Tableau.contaminationPion(Tableau.getColonneArrivee(),Tableau.getLigneArrivee(),1);

                std::cout<< "Joueur 2" << std::endl;
                this->Tableau.afficherGrille();
                this->Tableau.deplacementPion(2);
                this->Tableau.contaminationPion(Tableau.getColonneArrivee(),Tableau.getLigneArrivee(),2);

            }
            break;
        case 2:
            std::cout<<"Coucou";
            break;
    }
}


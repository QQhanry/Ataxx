#include "MainScene.h"
#include "game.h"

#include <QApplication>
#include <QTime>
#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {


    if(strncmp(argv[1],"--graphicmode",13) == 0){
        QApplication application(argc, argv);
        MainScene menu;
        return application.exec();

    }else if(strncmp(argv[1],"--terminalmode",14) == 0){
        game Game;
        Game.Menu();
        return EXIT_SUCCESS;
    }

}

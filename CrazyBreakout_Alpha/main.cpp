
#include <QApplication>
#include "mainwindow.h"
#include "Game.h"

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.showMaximized();
    game = new Game();

    return a.exec();
}

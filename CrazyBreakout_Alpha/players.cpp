#include "players.h"
#include "ui_players.h"


server* Players::_Connecion = new server();
Players::Players(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Players)
{
    ui->setupUi(this);
    setWindowTitle("CrazyBreakout");
    ui->pushButton->setText("1 JUGADOR");
    ui->pushButton_2->setText("MULTIJUGADOR");
    ui->pushButton_3->setText("VOLVER");
}

Players::~Players()
{
    delete ui;
}

void Players::on_pushButton_clicked()
{
    Game *game = new Game();
    game->showMaximized();
    game->start();
    this->close();

}

void Players::on_pushButton_3_clicked()
{
    this->close();
    MainWindow *menu = new MainWindow();
    menu->showMaximized();

}

void Players::on_pushButton_2_clicked()
{
            pthread_t hilo;
            int data = 0;
            pthread_create(&hilo,0,SocketThread,(void*)&data);
            pthread_detach(hilo);
            this->close();
            while(!_Connecion->getIsconnect()){

            }
            Game *game = new Game();
            game->showMaximized();
            game->start();

}

void* Players::SocketThread(void* obj){
    _Connecion->run();
}

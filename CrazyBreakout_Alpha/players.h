#ifndef PLAYERS_H
#define PLAYERS_H
#include "Game.h"
#include "mainwindow.h"
#include "server.h"

#include <QDialog>

namespace Ui {
class Players;
}

class Players : public QDialog
{
    Q_OBJECT

public:
    explicit Players(QWidget *parent = 0);
    ~Players();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Players *ui;
    static void* SocketThread(void *obj);
    static server* _Connecion;
};

#endif // PLAYERS_H

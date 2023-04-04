#include "play_room.h"
#include "ui_play_room.h"

Play_room::Play_room(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Play_room)
{
    ui->setupUi(this);
}

Play_room::~Play_room()
{
    delete ui;
}

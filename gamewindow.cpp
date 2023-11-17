#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPixmap>
#include <windows.h>
gamewindow::gamewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint );
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->show();
}

gamewindow::~gamewindow()
{
    delete ui;
}

void gamewindow::SetLoadingLine(double  precent) {
    ui->loading_line->setStyleSheet("background:white;border-radius:7px;border:3.3px solid white;background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(145, 102, 206, 255), stop:"+QString::number(precent-0.01)+" rgba(145, 102, 206, 255), stop:"+QString::number(precent)+" rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));");
}

void gamewindow::SetSelectedSkin(int id) {
    ui->selected_skin->setStyleSheet("background: url(:/resources/img/"+QString::number(id)+".png) center/top;border-radius:20px;border:6px solid white;");
}

void gamewindow::SetSelectedNick(std::string nick) {
    ui->selected_nick->setText("<html><head/><body><p align=\"center\">"+QString::fromStdString(nick)+"</p></body></html>");
}

void gamewindow::on_start_game_clicked()
{
    double procent = 1;
    SetLoadingLine(procent/100);
    SetSelectedSkin(188);
    SetSelectedNick("ivan_Pivan");
}



void gamewindow::on_close_btn_clicked()
{
    exit(0);
}


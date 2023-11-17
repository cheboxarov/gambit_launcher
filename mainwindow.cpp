#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <iostream>
#include "stdlib.h"
#include "gamewindow.h"

class User{
private:
    std::string selectnick;
    std::string ucp;
    std::vector<std::string> nicks;
    int count_nicks;
    std::string password;
public:
    User() {
        this->count_nicks = 0;
    }
    std::string GetPass() {
        return this->password;
    }
    void SetPassword(std::string password) {
        this->password = password;
    }
    std::string GetNick() {
        return this->selectnick;
    }
    void SetNick(std::string selectnick) {
        this->selectnick = selectnick;
    }
    std::string GetUcp() {
        return this->ucp;
    }
    void SetUcp(std::string ucp) {
        this->ucp = ucp;
    }
    std::vector<std::string> GetNicks() {
        return this->nicks;
    }
    void AppendNick(std::string nick) {
        this->nicks[count_nicks] = nick;
        this->count_nicks = this->count_nicks + 1;
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint );
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->show();
    ui->login_line->setAlignment(Qt::AlignCenter);
    ui->password_line->setAlignment(Qt::AlignCenter);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_close_btn_clicked()
{
    exit(0);
}


void MainWindow::on_start_btn_clicked()
{
    User user;
    user.SetUcp(ui->login_line->text().toStdString());
    user.SetPassword(ui->password_line->text().toStdString());
    if(user.GetUcp() == "wlovem") {
        if (user.GetPass() == "123") {
            std::cout << user.GetUcp() << std::endl;
            gwin = new gamewindow();
            gwin->setModal(true);
            gwin->show();
            hide();
        } else {
            ui->auth_lab->setText("Неправильный пароль!");
        }
    } else {
        ui->auth_lab->setText("Такой логин не найден!");
    }
}


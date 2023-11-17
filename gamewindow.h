#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>

namespace Ui {
class gamewindow;
}

class gamewindow : public QDialog
{
    Q_OBJECT
public:
    explicit gamewindow(QWidget *parent = nullptr);
    ~gamewindow();
    void SetLoadingLine(double proc);
    void SetSelectedSkin(int id);
    void SetSelectedNick(std::string nick);
private slots:
    void on_start_game_clicked();

    void on_close_btn_clicked();

private:
    Ui::gamewindow *ui;
};

#endif // GAMEWINDOW_H

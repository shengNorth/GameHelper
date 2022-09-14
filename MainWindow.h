#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>

#include <QMainWindow>
#include <QWidget>

#include "InputDriver/Player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void GrabGameScreen(HWND hwnd);
    bool FindWindowHwnd(const std::wstring& windowTitle);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    HWND m_gameHwnd;
    Player* m_player;

};
#endif // MAINWINDOW_H

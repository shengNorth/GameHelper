#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <Windows.h>
#include <QDebug>
#include <QScreen>
#include <QMessageBox>

#include <QKeyEvent>

#include "InputDriver/Player.h"

using namespace std;

const int InitSuccess = 1;
const std::string srcImage = "F:/src.png";
const std::string dstImage = "F:/dst.png";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::wstring path = L"G:/master/DD94687.64.dll";
    m_player = new Player(path);

    int result = m_player->Initialize();
    if (result != InitSuccess)
    {
        QMessageBox::critical(this, "Tips", QString("Initialize Driver Failed: %1").arg(QString::number(result)));
        return;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GrabGameScreen(HWND hwnd)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    screen->grabWindow((WId)hwnd).save(QString::fromStdString(dstImage),"jpg");
//    screen->grabWindow(0).save(QString::fromStdString(dstImage),"png");
}

bool MainWindow::FindWindowHwnd(const wstring &windowTitle)
{
    m_gameHwnd = FindWindow(NULL, windowTitle.c_str());
    if (m_gameHwnd != nullptr)
    {
        qDebug() << "FindWindow success" << (WId)m_gameHwnd;
        ShowWindow(m_gameHwnd, SW_RESTORE );//激活并置顶窗口，ShowWindow里面的参数可以网上搜一下，不同功能不同参数
        return  true;
    }
    return false;
}


void MainWindow::on_pushButton_clicked()
{
    if(FindWindowHwnd(L"地下城与勇士"))
    {
        GrabGameScreen(m_gameHwnd);
        for (int i = 0; i < 100; ++i)
        {
            m_player->KeyClick(GameKey_Down);
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Down)
    {
        qDebug() << "Down";
    }
    return QWidget::keyPressEvent(event);
}

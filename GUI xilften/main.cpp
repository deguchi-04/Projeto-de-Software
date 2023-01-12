#include "mainwindow.h"
#include <QSplashScreen>
#include <QTimer>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *screenSplash = new QSplashScreen();
    screenSplash->setPixmap(QPixmap(":/splash/xilften.png"));
    screenSplash->show();
    MainWindow w;

    QTimer::singleShot(3000, screenSplash, SLOT(close()));
    QTimer::singleShot(4000, &w, SLOT(show()));
    //w.show();
    return a.exec();
}

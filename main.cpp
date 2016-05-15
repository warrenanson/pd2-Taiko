#include "mainwindow.h"
#include "form.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    Form f;
    w.setFixedSize(1200,675);
    w.show();
    return a.exec();
}

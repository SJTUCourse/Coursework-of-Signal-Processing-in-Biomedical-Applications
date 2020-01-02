#include "mainproject.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainProject w;
    w.show();
    return a.exec();
}

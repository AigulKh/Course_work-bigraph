#include "taxi.h"
#include <QtGui/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /* Настройки кодировки */
    QTextCodec *tc=QTextCodec::codecForName("CP1251");
    QTextCodec::setCodecForCStrings(tc);
    Taxi w;
    w.show();
    return a.exec();
}

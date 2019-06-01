#include "taxi.h"
#include "graphwidget.h"

#include <QtGui/QApplication>
#include <QTextCodec>
#include <QTime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /* Настройки кодировки */
    QTextCodec *tc=QTextCodec::codecForName("CP1251");
    QTextCodec::setCodecForCStrings(tc);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    GraphWidget widget;
    widget.show();

    Taxi w;
    w.show();
    return a.exec();
}

#include "taxi.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Taxi w;
	w.show();
	return a.exec();
}

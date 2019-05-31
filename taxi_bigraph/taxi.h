#ifndef TAXI_H
#define TAXI_H

#include <QtGui/QMainWindow>
#include "ui_taxi.h"

class Taxi : public QMainWindow
{
	Q_OBJECT

public:
	Taxi(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Taxi();

private:
	Ui::TaxiClass ui;
};

#endif // TAXI_H

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

	// ���������� ���������� ��� ��������� ���������� ������
	void checkAdminControlActivity();
	// �������� ���������� ��������� ���������� ������ �� ��������� ���������� ����� ������
	void toggleAddNewCarActivity(bool isCreating);

	private slots:
		void userMode();		// ����� ������������
		void adminMode();		// ����� ��������������

		// ������� ��������������:
		// ���������� ����� ������
		void addNewCar();		// ��������� �������� �������� ������
		void createCar();		// �������� ���� ������
		void cancelAddCar();	// ������ ���������� ������
		// ���������� ��������
		void deleteOrder();		// �������� ������
		void assignOrder();		// ���������� ������
		// ����������� �������
		void clearAll();		// ������� �����
		// ����������� ������� ��� ��������������
		void saveGraph();		// ��������� ���� � ����
		void saveExit();		// ��������� ���� � ���� � ����� �� ���������
		void exitApp();			// ����� �� ���������
		
		// ������� ������������
		void createOrder();		// �������� ������
		
};

#endif // TAXI_H

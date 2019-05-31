#include "taxi.h"

Taxi::Taxi(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	/*
	* ���� ��������� �������� �� ��������� ���������� � ������-������������:
	* connect(	������� ��� ����������� ������,
	*			SIGNAL(������ ������� ���������()),
	*			this,
	*			SLOT(�����-����������())
	* )
	*/
	connect(ui.userModeButton,SIGNAL(clicked()),this,SLOT(userMode()));
	connect(ui.adminModeButton,SIGNAL(clicked()),this,SLOT(adminMode()));

	connect(ui.addNewCarButton,SIGNAL(clicked()),this,SLOT(addNewCar()));
	connect(ui.createCarButton,SIGNAL(clicked()),this,SLOT(createCar()));
	connect(ui.cancelAddCarButton,SIGNAL(clicked()),this,SLOT(cancelAddCar()));

	connect(ui.deleteOrderButton,SIGNAL(clicked()),this,SLOT(deleteOrder()));
	connect(ui.assignOrderButton,SIGNAL(clicked()),this,SLOT(assignOrder()));
	connect(ui.clearAllButton,SIGNAL(clicked()),this,SLOT(clearAll()));

	connect(ui.saveButton,SIGNAL(clicked()),this,SLOT(saveGraph()));
	connect(ui.saveAndExitButton,SIGNAL(clicked()),this,SLOT(saveExit()));
	connect(ui.exitButtonAdmin,SIGNAL(clicked()),this,SLOT(exitApp()));

	connect(ui.createOrderButton,SIGNAL(clicked()),this,SLOT(createOrder()));
	connect(ui.exitButtonUser,SIGNAL(clicked()),this,SLOT(exitApp()));
}

Taxi::~Taxi()
{

}


/*
* ����� �������� ����
*/
void Taxi::userMode()
{
	// ������� ������� �������� �������� mainStackedWidget �� 1
	ui.mainStackedWidget->setCurrentIndex(1);
	// ������� �������� stackedWidget �� 1
	ui.stackedWidget->setCurrentIndex(1);
	// ��������� ��� ������ � ���-����� �� �������
	ui.carTypeUser->setCurrentIndex(0);
}

void Taxi::adminMode()
{
	// ������� ������� �������� �������� mainStackedWidget �� 1
	ui.mainStackedWidget->setCurrentIndex(1);
	// ������� �������� stackedWidget �� 0
	ui.stackedWidget->setCurrentIndex(0);

	// ���������� �������� ��� ����������� ��������� � ����������� �� �������� �����
	checkAdminControlActivity();
}

void Taxi::addNewCar()
{
	toggleAddNewCarActivity(true);
}

void Taxi::createCar()
{
	// ������� ���� ����� � ������
	// ���������� ����� ����
	toggleAddNewCarActivity(false);
}

void Taxi::cancelAddCar()
{
	toggleAddNewCarActivity(false);
}

void Taxi::deleteOrder()
{
	// ������� ���� ����� � ������
	// ������� ���� ������������� �����
	// ������� ��������� � ��� �����
}

void Taxi::assignOrder()
{
	// ������� ����� ����� ������ � ������
	// ���������� ����� ����� ���������
}

void Taxi::clearAll()
{
	// �������� ���� � ������
	// �������� ���������
	// ���������� ���������� ������
	checkAdminControlActivity();
}

void Taxi::saveGraph()
{
	// �������� ������� ���� � ����
}

void Taxi::saveExit()
{
	// �������� ������� ����
	// ����� �� ��������� (��� �� ��������� �����?)
	ui.mainStackedWidget->setCurrentIndex(0);
}

void Taxi::exitApp()
{
	// ����� �� ��������� ��� �� ��������� ����� (��� ����������)
	ui.mainStackedWidget->setCurrentIndex(0);
}

void Taxi::createOrder()
{
	// �������� ���� ������ � ����
	// ���������� ����� ���� �����
}


/*
* ������ ������
*/
void Taxi::checkAdminControlActivity()
{
	// ���� ���� �����..
	// ������ ������ � �������� �������
	// �����..
	// ������ ������ � �������� ���������

	// ���������� ��� ������ �� �������
	ui.carTypeAdmin->setCurrentIndex(0);
}

void Taxi::toggleAddNewCarActivity(bool isCreating)
{
	// �������� ���������� ��������� � ����������� ����� ������
	ui.addMachineGroupBox->setEnabled(isCreating);
	// �������� ���������� ������ ���������� ����� ������
	ui.addNewCarButton->setEnabled(!isCreating);
	// �������� ���������� ������ ������ � ��������
	ui.orderControlGroupBox->setEnabled(!isCreating);
}
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
	connect(ui.exitButtonAdmin,SIGNAL(clicked()),this,SLOT(exitApp()));
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
	// ������� �������� stackedWidget �� 1
}

void Taxi::adminMode()
{
	// ������� ������� �������� �������� mainStackedWidget �� 1
	// ������� �������� stackedWidget �� 0

	// ���������� �������� ��� ����������� ��������� � ����������� �� �������� �����
	checkAdminControlActivity();
}

void Taxi::addNewCar()
{
	// ������� ����������� ������ ������ � ��������
	// ������� ���������� ������ ���������� ����� ������
	// ������� �������� �������� � ����������� ����� ������
}

void Taxi::createCar()
{
	// ������� ���� ����� � ������
	// ���������� ����� ����
	exitAddNewCar();
}

void Taxi::cancelAddCar()
{
	exitAddNewCar();
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
}

void Taxi::saveGraph()
{
	// �������� ������� ���� � ����
}

void Taxi::saveExit()
{
	// �������� ������� ����
	// ����� �� ��������� (��� �� ��������� �����?)
}

void Taxi::exitApp()
{
	// ����� �� ��������� ��� �� ��������� ����� (��� ����������)
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
}

void Taxi::exitAddNewCar()
{
	// ������� ���������� �������� � ����������� ����� ������
	// ������� �������� ������ ���������� ����� ������
	// ������� �������� ������ ������ � ��������
}
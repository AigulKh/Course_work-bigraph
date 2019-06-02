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

    checkAdminControlActivity();
    currentState = calm;
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

    // ���������� �������� ��� ����������� ��������� � ����������� �� �������� �����
    checkAdminControlActivity();
}

void Taxi::adminMode()
{
    // ������� ������� �������� �������� mainStackedWidget �� 1
    ui.mainStackedWidget->setCurrentIndex(1);
    // ������� �������� stackedWidget �� 0
    ui.stackedWidget->setCurrentIndex(0);

    // ���������� �������� ��� ����������� ��������� � ����������� �� �������� �����
    checkAdminControlActivity();
    // ���������� ��� ������ �� �������
    ui.carTypeAdmin->setCurrentIndex(0);
}

void Taxi::addNewCar()
{
    toggleAddNewCarActivity(true);
}

void Taxi::createCar()
{
    // ���������� ��� ����������� ������
    QString carName = ui.carTypeAdmin->currentText();
    // ������� ���� ����� � ������
    ui.graphicsView->addNode(carName, true);
    // �������������� ��������� ���������
    toggleAddNewCarActivity(false);
}

void Taxi::cancelAddCar()
{
    toggleAddNewCarActivity(false);
}

void Taxi::deleteOrder()
{
    bool isEnabled;
    if(currentState == calm){
        currentState = deletingNodes;
        isEnabled = false;
    }
    else if (currentState == deletingNodes){
        currentState = calm;
        isEnabled = true;
    }

    ui.graphicsView->toggleDeleteOrdersMode();
    ui.assignOrderButton->setEnabled(isEnabled);
    ui.addNewCarButton->setEnabled(isEnabled);
    checkAdminControlActivity();
}

void Taxi::assignOrder()
{
    bool isEnabled;
    if(currentState == calm){
        currentState = creatingEdges;
        isEnabled = false;
    }
    else if (currentState == creatingEdges){
        currentState = calm;
        isEnabled = true;
    }

    ui.graphicsView->toggleCreateEdgesMode();
    ui.deleteOrderButton->setEnabled(isEnabled);
    ui.addNewCarButton->setEnabled(isEnabled);
}

void Taxi::clearAll()
{
    // �������� ���� � ������
    // �������� ���������
    ui.graphicsView->clearEverything();
    // ���������� ���������� ������
    checkAdminControlActivity();
    // ���������� ��� ������ �� �������
    ui.carTypeAdmin->setCurrentIndex(0);
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
    // ���������� ��� ������������ ������
    QString orderName = ui.carTypeUser->currentText();
    // ������� ���� ����� � ������
    ui.graphicsView->addNode(orderName, false);

    if(!ui.deleteOrderButton->isEnabled() && !ui.assignOrderButton->isEnabled()){
        ui.deleteOrderButton->setEnabled(true);
        ui.assignOrderButton->setEnabled(true);
    }
}


/*
* ������ ������
*/
void Taxi::checkAdminControlActivity()
{
    // ���� ��� �������, �� ������ ������ � ���� �������
    // ����� �� ������� ��-�� ��������� � ���������� ���������
    bool hasOrders = ui.graphicsView->containsOrders();
    if(!hasOrders){
        ui.deleteOrderButton->setEnabled(false);
        ui.assignOrderButton->setEnabled(false);
    }    
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
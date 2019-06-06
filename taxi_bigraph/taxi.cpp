#include "taxi.h"

Taxi::Taxi(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);

    /*
    * Блок коннектов сигналов от элементов интерфейса к слотам-обработчикам:
    * connect(	элемент гуи отправивший сигнал,
    *			SIGNAL(сигнал который произошел()),
    *			this,
    *			SLOT(метод-обработчик())
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

    connect(ui.bigraphButton, SIGNAL(clicked()), this, SLOT(checkBigraph()));
    //connect(ui.pairsButton, SIGNAL(clicked()), this, SLOT(checkPairs()));

    //checkAdminControlActivity();
    currentState = calm;

    ui.graphicsView->loadNodes();
}

Taxi::~Taxi()
{

}


/*
* Слоты главного окна
*/

void Taxi::checkBigraph()
{
    bool isBigraph = ui.graphicsView->isBigraph();
    QString infoMessage;
    if(isBigraph)
        infoMessage = "Граф является двудольным";
    else
        infoMessage = "Граф не является двудольным";

    QMessageBox::information(0,"Двудольность графа",infoMessage);
}

void Taxi::userMode()
{
    // Сменить текущую активную страницу mainStackedWidget на 1
    ui.mainStackedWidget->setCurrentIndex(1);
    // Сменить страницу stackedWidget на 1
    ui.stackedWidget->setCurrentIndex(1);
    // Поставить тип машины в чек-боксе на базовый
    ui.carTypeUser->setCurrentIndex(0);

    // Установить контроль над управлением элементов в зависимости от текущего графа
    //checkAdminControlActivity();
}

void Taxi::adminMode()
{
    // Сменить текущую активную страницу mainStackedWidget на 1
    ui.mainStackedWidget->setCurrentIndex(1);
    // Сменить страницу stackedWidget на 0
    ui.stackedWidget->setCurrentIndex(0);

    // Установить контроль над управлением элементов в зависимости от текущего графа
    //checkAdminControlActivity();
    // Установить тип машины на базовый
    ui.carTypeAdmin->setCurrentIndex(0);
}

void Taxi::addNewCar()
{
    toggleAddNewCarActivity(true);
}

void Taxi::createCar()
{
    // Определяем тип создаваемой машины
    QString carName = ui.carTypeAdmin->currentText();
    // Создать узел графа в памяти
    ui.graphicsView->addNode(carName, true);
    // Отрегулировать видимость элементов
    toggleAddNewCarActivity(false);
}

void Taxi::cancelAddCar()
{
    toggleAddNewCarActivity(false);
}

void Taxi::deleteOrder()
{
    bool isEnabled = true;
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
    //checkAdminControlActivity();
}

void Taxi::assignOrder()
{
    bool isEnabled = true;
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
    // Очистить граф в памяти
    // Очистить отрисовку
    ui.graphicsView->clearEverything();
    // Установить активность кнопок
    //checkAdminControlActivity();
    // Установить тип машины на базовый
    ui.carTypeAdmin->setCurrentIndex(0);
}

void Taxi::saveGraph()
{
    // Записать текущий граф в файл
    ui.graphicsView->saveNodes();
}

void Taxi::saveExit()
{
    // Записать текущий граф
    ui.graphicsView->saveNodes();
    // Выйти из программы (или на стартовый экран?)
    ui.mainStackedWidget->setCurrentIndex(0);
}

void Taxi::exitApp()
{
    // Выйти из программы или на стартовый экран (без сохранения)
    ui.mainStackedWidget->setCurrentIndex(0);
}

void Taxi::createOrder()
{
    // Определяем тип создаваемого заказа
    QString orderName = ui.carTypeUser->currentText();
    // Создать узел графа в памяти
    ui.graphicsView->addNode(orderName, false);

    if(!ui.deleteOrderButton->isEnabled() && !ui.assignOrderButton->isEnabled()){
        ui.deleteOrderButton->setEnabled(true);
        ui.assignOrderButton->setEnabled(true);
    }
}


/*
* Методы класса
*/
void Taxi::checkAdminControlActivity()
{
    // Если нет заказов, то кнопки работы с ними активны
    // Иначе не сделать из-за конфликта с настройкой состояний
    bool hasOrders = ui.graphicsView->containsOrders();
    if(!hasOrders){
        ui.deleteOrderButton->setEnabled(false);
        ui.assignOrderButton->setEnabled(false);
    }    
}

void Taxi::toggleAddNewCarActivity(bool isCreating)
{
    // Обновить активность групбокса с добавлением новой машины
    ui.addMachineGroupBox->setEnabled(isCreating);
    // Обновить активность кнопки добавления новой машины
    ui.addNewCarButton->setEnabled(!isCreating);
    // Обновить активность кнопок работы с заказами
    ui.orderControlGroupBox->setEnabled(!isCreating);
}

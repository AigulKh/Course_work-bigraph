#include "taxi.h"

Taxi::Taxi(QWidget *parent, Qt::WFlags flags)
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
}

Taxi::~Taxi()
{

}


/*
* Слоты главного окна
*/
void Taxi::userMode()
{
	// Сменить текущую активную страницу mainStackedWidget на 1
	ui.mainStackedWidget->setCurrentIndex(1);
	// Сменить страницу stackedWidget на 1
	ui.stackedWidget->setCurrentIndex(1);
	// Поставить тип машины в чек-боксе на базовый
	ui.carTypeUser->setCurrentIndex(0);
}

void Taxi::adminMode()
{
	// Сменить текущую активную страницу mainStackedWidget на 1
	ui.mainStackedWidget->setCurrentIndex(1);
	// Сменить страницу stackedWidget на 0
	ui.stackedWidget->setCurrentIndex(0);

	// Установить контроль над управлением элементов в зависимости от текущего графа
	checkAdminControlActivity();
}

void Taxi::addNewCar()
{
	toggleAddNewCarActivity(true);
}

void Taxi::createCar()
{
	// Создать узел графа в памяти
	// Отрисовать новый узел
	toggleAddNewCarActivity(false);
}

void Taxi::cancelAddCar()
{
	toggleAddNewCarActivity(false);
}

void Taxi::deleteOrder()
{
	// Удалить узел графа в памяти
	// Удалить узел нарисованного графа
	// Удалить связанные с ним ребра
}

void Taxi::assignOrder()
{
	// Создать связь между узлами в памяти
	// Отрисовать ребро между вершинами
}

void Taxi::clearAll()
{
	// Очистить граф в памяти
	// Очистить отрисовку
	// Установить активность кнопок
	checkAdminControlActivity();
}

void Taxi::saveGraph()
{
	// Записать текущий граф в файл
}

void Taxi::saveExit()
{
	// Записать текущий граф
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
	// Добавить узел заказа в граф
	// Отрисовать новый узел графа
}


/*
* Методы класса
*/
void Taxi::checkAdminControlActivity()
{
	// Если есть заказ..
	// Кнопки работы с заказами активны
	// Иначе..
	// Кнопки работы с заказами неактивны

	// Установить тип машины на базовый
	ui.carTypeAdmin->setCurrentIndex(0);
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
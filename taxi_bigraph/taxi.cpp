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
	connect(ui.exitButtonAdmin,SIGNAL(clicked()),this,SLOT(exitApp()));
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
	// Сменить страницу stackedWidget на 1
}

void Taxi::adminMode()
{
	// Сменить текущую активную страницу mainStackedWidget на 1
	// Сменить страницу stackedWidget на 0

	// Установить контроль над управлением элементов в зависимости от текущего графа
	checkAdminControlActivity();
}

void Taxi::addNewCar()
{
	// Сделать неактивными кнопки работы с заказами
	// Сделать неактивной кнопку добавления новой машины
	// Сделать активным групбокс с добавлением новой машины
}

void Taxi::createCar()
{
	// Создать узел графа в памяти
	// Отрисовать новый узел
	exitAddNewCar();
}

void Taxi::cancelAddCar()
{
	exitAddNewCar();
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
}

void Taxi::saveGraph()
{
	// Записать текущий граф в файл
}

void Taxi::saveExit()
{
	// Записать текущий граф
	// Выйти из программы (или на стартовый экран?)
}

void Taxi::exitApp()
{
	// Выйти из программы или на стартовый экран (без сохранения)
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
}

void Taxi::exitAddNewCar()
{
	// Сделать неактивным групбокс с добавлением новой машины
	// Сделать активной кнопку добавления новой машины
	// Сделать активной кнопки работы с заказами
}
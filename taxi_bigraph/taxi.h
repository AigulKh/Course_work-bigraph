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

	// Установить активность для элементов управления админа
	void checkAdminControlActivity();
	// Обновить активность элементов управления админа по состоянию добавления новой машины
	void toggleAddNewCarActivity(bool isCreating);

	private slots:
		void userMode();		// Режим пользователя
		void adminMode();		// Режим администратора

		// Функции администратора:
		// Добавление новой машины
		void addNewCar();		// Активация виджетов создания машины
		void createCar();		// Создание узла машины
		void cancelAddCar();	// Отмена добавления машины
		// Управление заказами
		void deleteOrder();		// Удаление заказа
		void assignOrder();		// Назначение заказа
		// Специальные функции
		void clearAll();		// Очистка графа
		// Программные функции для администратора
		void saveGraph();		// Сохранить граф в файл
		void saveExit();		// Сохранить граф в файл и выйти из программы
		void exitApp();			// Выйти из программы
		
		// Функции пользователя
		void createOrder();		// Создание заказа
		
};

#endif // TAXI_H

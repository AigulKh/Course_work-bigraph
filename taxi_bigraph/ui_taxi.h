/********************************************************************************
** Form generated from reading UI file 'taxi.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAXI_H
#define UI_TAXI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphwidget.h"

QT_BEGIN_NAMESPACE

class Ui_TaxiClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *mainStackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *userModeButton;
    QFrame *line;
    QPushButton *adminModeButton;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QPushButton *clearAllButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *saveAndExitButton;
    QPushButton *exitButtonAdmin;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addNewCarButton;
    QGroupBox *addMachineGroupBox;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QComboBox *carTypeAdmin;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *createCarButton;
    QPushButton *cancelAddCarButton;
    QGroupBox *orderControlGroupBox;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout;
    QPushButton *deleteOrderButton;
    QPushButton *assignOrderButton;
    QSpacerItem *verticalSpacer;
    QWidget *page_4;
    QGridLayout *gridLayout_10;
    QPushButton *exitButtonUser;
    QGroupBox *creatingOrderGroupBox;
    QGridLayout *gridLayout_9;
    QPushButton *createOrderButton;
    QComboBox *carTypeUser;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    GraphWidget *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TaxiClass)
    {
        if (TaxiClass->objectName().isEmpty())
            TaxiClass->setObjectName(QString::fromUtf8("TaxiClass"));
        TaxiClass->resize(740, 460);
        TaxiClass->setMinimumSize(QSize(740, 460));
        centralWidget = new QWidget(TaxiClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mainStackedWidget = new QStackedWidget(centralWidget);
        mainStackedWidget->setObjectName(QString::fromUtf8("mainStackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        userModeButton = new QPushButton(page);
        userModeButton->setObjectName(QString::fromUtf8("userModeButton"));

        horizontalLayout_2->addWidget(userModeButton);

        line = new QFrame(page);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        adminModeButton = new QPushButton(page);
        adminModeButton->setObjectName(QString::fromUtf8("adminModeButton"));

        horizontalLayout_2->addWidget(adminModeButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        mainStackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        stackedWidget = new QStackedWidget(page_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_7 = new QGridLayout(page_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        clearAllButton = new QPushButton(page_3);
        clearAllButton->setObjectName(QString::fromUtf8("clearAllButton"));

        gridLayout_6->addWidget(clearAllButton, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        saveButton = new QPushButton(page_3);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout->addWidget(saveButton);

        saveAndExitButton = new QPushButton(page_3);
        saveAndExitButton->setObjectName(QString::fromUtf8("saveAndExitButton"));

        horizontalLayout->addWidget(saveAndExitButton);

        exitButtonAdmin = new QPushButton(page_3);
        exitButtonAdmin->setObjectName(QString::fromUtf8("exitButtonAdmin"));

        horizontalLayout->addWidget(exitButtonAdmin);


        gridLayout_6->addLayout(horizontalLayout, 4, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        addNewCarButton = new QPushButton(page_3);
        addNewCarButton->setObjectName(QString::fromUtf8("addNewCarButton"));

        verticalLayout_3->addWidget(addNewCarButton);

        addMachineGroupBox = new QGroupBox(page_3);
        addMachineGroupBox->setObjectName(QString::fromUtf8("addMachineGroupBox"));
        addMachineGroupBox->setEnabled(false);
        gridLayout_5 = new QGridLayout(addMachineGroupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label = new QLabel(addMachineGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        carTypeAdmin = new QComboBox(addMachineGroupBox);
        carTypeAdmin->addItem(QString());
        carTypeAdmin->addItem(QString());
        carTypeAdmin->addItem(QString());
        carTypeAdmin->addItem(QString());
        carTypeAdmin->addItem(QString());
        carTypeAdmin->setObjectName(QString::fromUtf8("carTypeAdmin"));

        gridLayout_5->addWidget(carTypeAdmin, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        createCarButton = new QPushButton(addMachineGroupBox);
        createCarButton->setObjectName(QString::fromUtf8("createCarButton"));

        horizontalLayout_3->addWidget(createCarButton);

        cancelAddCarButton = new QPushButton(addMachineGroupBox);
        cancelAddCarButton->setObjectName(QString::fromUtf8("cancelAddCarButton"));

        horizontalLayout_3->addWidget(cancelAddCarButton);


        gridLayout_5->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        verticalLayout_3->addWidget(addMachineGroupBox);


        gridLayout_6->addLayout(verticalLayout_3, 0, 0, 1, 1);

        orderControlGroupBox = new QGroupBox(page_3);
        orderControlGroupBox->setObjectName(QString::fromUtf8("orderControlGroupBox"));
        gridLayout_8 = new QGridLayout(orderControlGroupBox);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        deleteOrderButton = new QPushButton(orderControlGroupBox);
        deleteOrderButton->setObjectName(QString::fromUtf8("deleteOrderButton"));

        verticalLayout->addWidget(deleteOrderButton);

        assignOrderButton = new QPushButton(orderControlGroupBox);
        assignOrderButton->setObjectName(QString::fromUtf8("assignOrderButton"));

        verticalLayout->addWidget(assignOrderButton);


        gridLayout_8->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_6->addWidget(orderControlGroupBox, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_10 = new QGridLayout(page_4);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        exitButtonUser = new QPushButton(page_4);
        exitButtonUser->setObjectName(QString::fromUtf8("exitButtonUser"));

        gridLayout_10->addWidget(exitButtonUser, 2, 0, 1, 1);

        creatingOrderGroupBox = new QGroupBox(page_4);
        creatingOrderGroupBox->setObjectName(QString::fromUtf8("creatingOrderGroupBox"));
        gridLayout_9 = new QGridLayout(creatingOrderGroupBox);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        createOrderButton = new QPushButton(creatingOrderGroupBox);
        createOrderButton->setObjectName(QString::fromUtf8("createOrderButton"));

        gridLayout_9->addWidget(createOrderButton, 2, 0, 1, 1);

        carTypeUser = new QComboBox(creatingOrderGroupBox);
        carTypeUser->addItem(QString());
        carTypeUser->addItem(QString());
        carTypeUser->addItem(QString());
        carTypeUser->addItem(QString());
        carTypeUser->addItem(QString());
        carTypeUser->setObjectName(QString::fromUtf8("carTypeUser"));

        gridLayout_9->addWidget(carTypeUser, 1, 0, 1, 1);

        label_2 = new QLabel(creatingOrderGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_9->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_10->addWidget(creatingOrderGroupBox, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_2, 1, 0, 1, 1);

        stackedWidget->addWidget(page_4);

        gridLayout_4->addWidget(stackedWidget, 0, 1, 1, 1);

        graphicsView = new GraphWidget(page_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(360, 360));

        gridLayout_4->addWidget(graphicsView, 0, 0, 1, 1);

        mainStackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(mainStackedWidget, 0, 0, 1, 1);

        TaxiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TaxiClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 740, 21));
        TaxiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TaxiClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TaxiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TaxiClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TaxiClass->setStatusBar(statusBar);

        retranslateUi(TaxiClass);

        mainStackedWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TaxiClass);
    } // setupUi

    void retranslateUi(QMainWindow *TaxiClass)
    {
        TaxiClass->setWindowTitle(QApplication::translate("TaxiClass", "\320\227\320\260\320\272\320\260\320\267 \321\202\320\260\320\272\321\201\320\270", nullptr));
        label_3->setText(QApplication::translate("TaxiClass", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\200\320\265\320\266\320\270\320\274 \321\200\320\260\320\261\320\276\321\202\321\213 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213:", nullptr));
        userModeButton->setText(QApplication::translate("TaxiClass", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        adminModeButton->setText(QApplication::translate("TaxiClass", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        clearAllButton->setText(QApplication::translate("TaxiClass", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\201\321\205\320\265\320\274\321\203", nullptr));
        saveButton->setText(QApplication::translate("TaxiClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        saveAndExitButton->setText(QApplication::translate("TaxiClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270 \320\262\321\213\320\271\321\202\320\270", nullptr));
        exitButtonAdmin->setText(QApplication::translate("TaxiClass", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        addNewCarButton->setText(QApplication::translate("TaxiClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\274\320\260\321\210\320\270\320\275\321\203", nullptr));
        addMachineGroupBox->setTitle(QApplication::translate("TaxiClass", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\274\320\260\321\210\320\270\320\275\321\213", nullptr));
        label->setText(QApplication::translate("TaxiClass", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\270\320\277 \320\274\320\260\321\210\320\270\320\275\321\213:", nullptr));
        carTypeAdmin->setItemText(0, QApplication::translate("TaxiClass", "\320\255\320\272\320\276\320\275\320\276\320\274", nullptr));
        carTypeAdmin->setItemText(1, QApplication::translate("TaxiClass", "\320\232\320\276\320\274\321\204\320\276\321\200\321\202", nullptr));
        carTypeAdmin->setItemText(2, QApplication::translate("TaxiClass", "\320\221\320\270\320\267\320\275\320\265\321\201", nullptr));
        carTypeAdmin->setItemText(3, QApplication::translate("TaxiClass", "\320\234\320\270\320\275\320\270\320\262\321\215\320\275", nullptr));
        carTypeAdmin->setItemText(4, QApplication::translate("TaxiClass", "\320\224\320\265\321\202\321\201\320\272\320\270\320\271", nullptr));

        createCarButton->setText(QApplication::translate("TaxiClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        cancelAddCarButton->setText(QApplication::translate("TaxiClass", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        orderControlGroupBox->setTitle(QApplication::translate("TaxiClass", "\320\236\320\277\320\265\321\200\320\260\321\206\320\270\320\270 \321\201 \320\267\320\260\320\272\320\260\320\267\320\260\320\274\320\270", nullptr));
        deleteOrderButton->setText(QApplication::translate("TaxiClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        assignOrderButton->setText(QApplication::translate("TaxiClass", "\320\235\320\260\320\267\320\275\320\260\321\207\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        exitButtonUser->setText(QApplication::translate("TaxiClass", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        creatingOrderGroupBox->setTitle(QApplication::translate("TaxiClass", "\320\241\320\264\320\265\320\273\320\260\320\271\321\202\320\265 \320\267\320\260\320\272\320\260\320\267", nullptr));
        createOrderButton->setText(QApplication::translate("TaxiClass", "\320\236\321\204\320\276\321\200\320\274\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        carTypeUser->setItemText(0, QApplication::translate("TaxiClass", "\320\255\320\272\320\276\320\275\320\276\320\274", nullptr));
        carTypeUser->setItemText(1, QApplication::translate("TaxiClass", "\320\232\320\276\320\274\321\204\320\276\321\200\321\202", nullptr));
        carTypeUser->setItemText(2, QApplication::translate("TaxiClass", "\320\221\320\270\320\267\320\275\320\265\321\201", nullptr));
        carTypeUser->setItemText(3, QApplication::translate("TaxiClass", "\320\234\320\270\320\275\320\270\320\262\321\215\320\275", nullptr));
        carTypeUser->setItemText(4, QApplication::translate("TaxiClass", "\320\224\320\265\321\202\321\201\320\272\320\270\320\271", nullptr));

        label_2->setText(QApplication::translate("TaxiClass", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\270\320\277 \320\274\320\260\321\210\320\270\320\275\321\213:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaxiClass: public Ui_TaxiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAXI_H

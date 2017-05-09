/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *totalOrigin;
    QLineEdit *lineEdit;
    QLabel *totalOrigin_2;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(750, 477);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 110, 151, 91));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 110, 161, 91));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(470, 110, 161, 91));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 150, 59, 16));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 150, 59, 16));
        label_2->setFont(font);
        totalOrigin = new QLabel(centralWidget);
        totalOrigin->setObjectName(QStringLiteral("totalOrigin"));
        totalOrigin->setGeometry(QRect(30, 250, 171, 21));
        QFont font1;
        font1.setPointSize(18);
        totalOrigin->setFont(font1);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 250, 113, 21));
        totalOrigin_2 = new QLabel(centralWidget);
        totalOrigin_2->setObjectName(QStringLiteral("totalOrigin_2"));
        totalOrigin_2->setGeometry(QRect(30, 300, 171, 21));
        totalOrigin_2->setFont(font1);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(220, 300, 113, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ch\341\273\215n file string.xml", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Ch\341\273\215n file d\341\273\213ch (xml)", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Chuy\341\273\203n \304\221\341\273\225i", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "->", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "->", Q_NULLPTR));
        totalOrigin->setText(QApplication::translate("MainWindow", "T\341\273\225ng s\341\273\221 t\341\273\253 c\341\272\247n d\341\273\213ch:", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        totalOrigin_2->setText(QApplication::translate("MainWindow", "T\341\273\225ng s\341\273\221 t\341\273\253 \304\221\303\243 d\341\273\213ch:", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

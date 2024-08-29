/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *commandLine;
    QPushButton *executeButton;
    QTextEdit *outputRes;
    QPlainTextEdit *textTitle;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        commandLine = new QLineEdit(centralwidget);
        commandLine->setObjectName("commandLine");
        commandLine->setGeometry(QRect(50, 60, 301, 31));
        executeButton = new QPushButton(centralwidget);
        executeButton->setObjectName("executeButton");
        executeButton->setGeometry(QRect(360, 60, 83, 29));
        outputRes = new QTextEdit(centralwidget);
        outputRes->setObjectName("outputRes");
        outputRes->setGeometry(QRect(50, 100, 711, 451));
        textTitle = new QPlainTextEdit(centralwidget);
        textTitle->setObjectName("textTitle");
        textTitle->setGeometry(QRect(270, 20, 241, 31));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        executeButton->setText(QCoreApplication::translate("MainWindow", "Execute", nullptr));
        textTitle->setPlainText(QCoreApplication::translate("MainWindow", "Assist-S- Your own AI assistant", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

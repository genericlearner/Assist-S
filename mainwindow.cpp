#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , assistant(new Assistant(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete assistant;
}

void MainWindow::on_executeButton_clicked()
{
    QString text = ui->commandLine->text();
    assistant->openNotepadAndType(text);
}

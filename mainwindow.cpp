#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    form = new Form();
    form->show();
    form->setFixedSize(1200,675);
    form->movelabel();
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

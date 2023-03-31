#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox->setTitle("Группировка");
    ui->radioButton->setText("Выбор 1");
    ui->radioButton_2->setText("Выбор 2");

    QStringList my_items = {"Один", "Два", "Три", "Четыре", "Пять", "Шесть", "Семь", "Восемь", "Девять", "Десять"};
    ui->comboBox->addItems(my_items);

    ui->pushButton->setText("Нажми меня!");
    ui->pushButton->setCheckable(true);

    ui->progressBar->setRange(0, 10);
    ui->progressBar->setFormat("%v");
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    if (!checked)
    {
        ui->pushButton->setText("Нажми меня!");
    }
    else ui->pushButton->setText("Я нажата!");
    if (ui->progressBar->value() == 10) ui->progressBar->setValue(0);
    else ui->progressBar->setValue((ui->progressBar->value()+1));
}

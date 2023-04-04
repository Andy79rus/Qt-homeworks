#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pb_round_counter->setEnabled(false);
    ui->lb_time->setText("00:00:00,0");
    my_watch = new Stopwatch(this);
    connect(my_watch, &Stopwatch::time_changed, this, &MainWindow::lb_time_refresh);
    connect(this, &MainWindow::send_start_stop_command, my_watch, &Stopwatch::startstop);
    connect(this, &MainWindow::send_next_command, my_watch, &Stopwatch::nextroundcounter);
    connect(this, &MainWindow::send_clear_command, my_watch, &Stopwatch::clear);
    connect(my_watch, &Stopwatch::next_round, this, &MainWindow::tb_timer_logs_refresh);
}

MainWindow::~MainWindow()
{
    delete my_watch;
    delete ui;
}

void MainWindow::on_pb_start_stop_clicked()
{
    if (ui->pb_start_stop->text() == "Стоп")
        {
            ui->pb_start_stop->setText("Старт");
            ui->pb_round_counter->setEnabled(false);
        }
    else
        {
            ui->pb_start_stop->setText("Стоп");
            ui->pb_round_counter->setEnabled(true);
        }
    emit send_start_stop_command();
}

void MainWindow::on_pb_clear_clicked()
{
    ui->pb_start_stop->setText("Старт");
    ui->pb_round_counter->setEnabled(false);
    ui->lb_time->setText("00:00:00,0");
    emit send_clear_command();
}

void MainWindow::on_pb_round_counter_clicked()
{
    emit send_next_command();   
}

void MainWindow::lb_time_refresh(const QString& time)
{
    ui->lb_time->setText(time);
}

void MainWindow::tb_timer_logs_refresh(const QString& round)
{
    ui->tb_timer_logs->append(round);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

signals:
    void send_start_stop_command();
    void send_next_command();
    void send_clear_command();

private slots:
    void on_pb_start_stop_clicked();
    void on_pb_clear_clicked();
    void on_pb_round_counter_clicked();
    void lb_time_refresh(const QString& time);
    void tb_timer_logs_refresh(const QString& round);

private:
    Ui::MainWindow* ui;
    Stopwatch* my_watch;
};
#endif // MAINWINDOW_H

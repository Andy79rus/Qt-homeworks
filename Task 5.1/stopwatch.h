#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QTimer>
#include <QObject>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    Stopwatch(QObject* parent = nullptr);
    ~Stopwatch();

private:
    QTimer* my_timer;
    int round_cnt;
    int current_time;
    int hours;
    int minutes;
    int seconds;
    int decseconds;
    int prev_hours;
    int prev_minutes;
    int prev_seconds;
    int prev_decseconds;

signals:
    void time_changed(const QString& time);
    void next_round(const QString& round);

public slots:
    void startstop();
    void nextroundcounter();
    void clear();

private slots:
    void update_time();

};

#endif // STOPWATCH_H

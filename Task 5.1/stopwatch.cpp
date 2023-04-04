#include "stopwatch.h"

Stopwatch::Stopwatch(QObject* parent) : QObject(parent), round_cnt(0), current_time(0),
    hours(0), minutes(0), seconds(0), decseconds(0),
    prev_hours(0), prev_minutes(0), prev_seconds(0), prev_decseconds(0)
{
    my_timer = new QTimer(this);
    my_timer->setTimerType(Qt::PreciseTimer);
    connect(my_timer, &QTimer::timeout, this, &Stopwatch::update_time);
}

Stopwatch::~Stopwatch()
{
    delete my_timer;
}

void Stopwatch::startstop()
{
    if (!(my_timer->isActive()))
                my_timer->start(100);
    else my_timer->stop();
}

void Stopwatch::nextroundcounter()
{
    ++round_cnt;
    int delta = (((hours-prev_hours)*60+(minutes-prev_minutes))*60+(seconds-prev_seconds))*10+(decseconds-prev_decseconds);
    prev_hours = hours;
    prev_minutes = minutes;
    prev_seconds = seconds;
    prev_decseconds = decseconds;
    int delta_decseconds = delta%10;
    delta /= 10;
    int delta_seconds = delta%60;
    delta /= 60;
    int delta_minutes = delta%60;
    int delta_hours = delta/60;

    emit next_round("Круг " + QString::number(round_cnt) +
                    ", Время: " + QString("%1:%2:%3,%4")
                    .arg(delta_hours, 2, 10, QLatin1Char('0'))
                    .arg(delta_minutes, 2, 10, QLatin1Char('0'))
                    .arg(delta_seconds, 2, 10, QLatin1Char('0'))
                    .arg(delta_decseconds, 1, 10, QLatin1Char('0')));
}

void Stopwatch::clear()
{
    my_timer->stop();
    round_cnt = 0;
    hours = 0;
    minutes = 0;
    seconds = 0;
    decseconds = 0;
    prev_hours = hours;
    prev_minutes = minutes;
    prev_seconds = seconds;
    prev_decseconds = decseconds;
    emit time_changed("00:00:00,0");
}

void Stopwatch::update_time()
{
    if (10 == ++decseconds)
    {
        decseconds = 0;
        if (60 == ++seconds)
            {
                seconds = 0;
                if (60 == ++minutes)
                    {
                        minutes = 0;
                        ++hours;
                    }
            }
    }

    QString time_string = QString("%1:%2:%3,%4")
            .arg(hours, 2, 10, QLatin1Char('0'))
            .arg(minutes, 2, 10, QLatin1Char('0'))
            .arg(seconds, 2, 10, QLatin1Char('0'))
            .arg(decseconds, 1, 10, QLatin1Char('0'));
    emit time_changed(time_string);
}

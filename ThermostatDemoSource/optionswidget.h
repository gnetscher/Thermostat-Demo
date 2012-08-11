#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include <QtGui>
#include "awayscreen.h"
#include "schedulescreen.h"
#include "settingscreen.h"

class optionswidget : public QWidget
{
    Q_OBJECT
public:
    explicit optionswidget(QWidget *parent = 0);
    
signals:
    void valueChanged();
    void cityChanged(QString);
    void currentTempChanged();

public slots:

private:
    QPushButton *settingsButton;
    QPushButton *calendarButton;
    QPushButton *awayButton;
    awayscreen *awayScreen;
    schedulescreen *scheduleScreen;
    settingscreen *settingScreen;
};

#endif // OPTIONSWIDGET_H

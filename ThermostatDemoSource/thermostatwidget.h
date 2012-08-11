#ifndef THERMOSTATWIDGET_H
#define THERMOSTATWIDGET_H

#include <QtGui>

class thermostatwidget : public QWidget
{
    Q_OBJECT
public:
    explicit thermostatwidget(QWidget *parent = 0);
    static int currentTempStatic;
    QLabel *currentTemp;

public slots:
    void updateUnit();
    
signals:
    void timeout();
    void setpointIsReached(bool);
    
private slots:
    void increaseTemp();
    void decreaseTemp();
    void update();

private:
    int currentTempInt;
    int setpointTempInt;
    QLabel *setpointTemp;
    QPushButton *increaseTempButton;
    QPushButton *decreaseTempButton;
    QTimer *updateTimer;
    bool setpointReached;
};

#endif // THERMOSTATWIDGET_H

#include "thermostatwidget.h"
#include "settingscreen.h"

int thermostatwidget::currentTempStatic;

thermostatwidget::thermostatwidget(QWidget *parent) :
    QWidget(parent)
{
    // create new thermostat widget with default values in case internet options are disabled
    setpointReached = false;
    currentTempInt = 72;
    currentTempStatic = 72;
    currentTemp = new QLabel(QString::number(currentTempInt)+"°");
    setpointTempInt = 72;
    setpointTemp = new QLabel("");
    setpointTemp->setMinimumWidth(77);
    increaseTempButton = new QPushButton("+");
    increaseTempButton->setFocusPolicy(Qt::NoFocus);
    decreaseTempButton = new QPushButton("-");
    decreaseTempButton->setFocusPolicy(Qt::NoFocus);

    currentTemp->setObjectName("currentTemp");
    setpointTemp->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    increaseTempButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    decreaseTempButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    // provide push button functionality
    connect(increaseTempButton,SIGNAL(clicked()),this,SLOT(increaseTemp()));
    connect(decreaseTempButton,SIGNAL(clicked()),this,SLOT(decreaseTemp()));

    // create layout
    QHBoxLayout *setpointLayout = new QHBoxLayout;
    setpointLayout->addWidget(decreaseTempButton);
    setpointLayout->addWidget(setpointTemp);
    setpointLayout->addWidget(increaseTempButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(currentTemp);
    mainLayout->addLayout(setpointLayout);

    // set layout
    setLayout(mainLayout);

    // provide timer to let current temp follow set point
    updateTimer = new QTimer(this);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(update()));
    connect(updateTimer, SIGNAL(timeout()), this, SIGNAL(timeout()));
    updateTimer->start(10000);

}

void thermostatwidget::increaseTemp()
{
    // provide function to increase current setpoint
    setpointTempInt++;
    if (setpointTempInt == currentTempInt) {
        // setpoint should disappear when reached
        setpointTemp->setText("");
        setpointReached = true;
        emit setpointIsReached(setpointReached);
    } else {
        setpointTemp->setText(QString::number(setpointTempInt)+"°");
        setpointReached = false;
        emit setpointIsReached(setpointReached);
    }
}

void thermostatwidget::decreaseTemp()
{
    // provid functino to decrease current setpoint
    setpointTempInt--;
    if (setpointTempInt == currentTempInt) {
        // setpoint should disappear when reached
        setpointTemp->setText("");
        setpointReached = true;
        emit setpointIsReached(setpointReached);
    } else {
        setpointTemp->setText(QString::number(setpointTempInt)+"°");
        setpointReached = false;
        emit setpointIsReached(setpointReached);
    }
}

void thermostatwidget::update()
{
    // when timer fires (every 10 seconds), have current temperature approach setpoint temperature by one degree
    if (currentTempInt < setpointTempInt) {
        currentTempInt++;
    }
    if (currentTempInt > setpointTempInt) {
        currentTempInt--;
    }
    currentTempStatic = currentTempInt;
    currentTemp->setText(QString::number(currentTempInt)+"°");
    // if setpoint is reached, have setpoint disappear
    if (setpointTempInt == currentTempInt) {
        setpointTemp->setText("");
        setpointReached = true;
        emit setpointIsReached(setpointReached);
    }
}

void thermostatwidget::updateUnit()
{
    // provide switch between Fahrenheit and Celsius based on current settings
    if(settingscreen::unit) {
        // true means F
        // we want Fahrenheit, but currently in Celsius
        currentTempInt = ((currentTempInt*1.8)+32);
        setpointTempInt = ((setpointTempInt*1.8)+32);
    } else {
        // false means C
        // we want Celsius, but currently in Fahrenheit
        currentTempInt = ((currentTempInt - 32) * 5)/9;
        setpointTempInt = ((setpointTempInt - 32) * 5)/9;
    }
    currentTempStatic = currentTempInt;
    currentTemp->setText(QString::number(currentTempInt)+"°");
    setpointTemp->setText(QString::number(setpointTempInt)+"°");
    update();
}

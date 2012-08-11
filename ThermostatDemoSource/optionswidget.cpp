#include "optionswidget.h"
#include "awayscreen.h"
#include "thermostatwidget.h"
#include "schedulescreen.h"
#include "settingscreen.h"

optionswidget::optionswidget(QWidget *parent) :
    QWidget(parent)
{
    // create settings button
    settingsButton = new QPushButton();
    settingsButton->setIcon(QIcon(":/Images/glossy-blue-orb-icon-gears.png"));
    settingsButton->setIconSize(QSize(80,80));
    settingsButton->setFocusPolicy(Qt::NoFocus);

    // create settings screen
    settingScreen = new settingscreen;
    // when settings button is clicked, show settings screen
    connect(settingsButton,SIGNAL(clicked()),settingScreen,SLOT(showFullScreen()));
    // pass C/F value from settings screen to options widget and out to main window
    connect(settingScreen, SIGNAL(valueChanged()), this, SIGNAL(valueChanged()));
    // pass new city string value from settings screen to options widget and out to main window
    connect(settingScreen, SIGNAL(cityChanged(QString)), this, SIGNAL(cityChanged(QString)));

    // create new calender button
    calendarButton = new QPushButton();
    calendarButton->setIcon(QIcon(":/Images/glossy-blue-orb-icon-calendar.png"));
    calendarButton->setIconSize(QSize(80,80));
    calendarButton->setFocusPolicy(Qt::NoFocus);

    // create new schedule screen
    scheduleScreen = new schedulescreen;
    connect(calendarButton,SIGNAL(clicked()),scheduleScreen,SLOT(showFullScreen()));
    connect(settingScreen, SIGNAL(valueChanged()), scheduleScreen, SIGNAL(valueChanged()));

    // create new away button
    awayButton = new QPushButton();
    awayButton->setIcon(QIcon(":/Images/glossy-blue-orb-icon-airplane.png"));
    awayButton->setIconSize(QSize(80,80));
    awayButton->setFocusPolicy(Qt::NoFocus);

    // create new away screen
    awayScreen = new awayscreen;
    connect(awayButton,SIGNAL(clicked()),awayScreen,SLOT(showFullScreen()));
    connect(this, SIGNAL(currentTempChanged()), awayScreen, SLOT(updateCurrentTemp()));
    connect(settingScreen, SIGNAL(valueChanged()), awayScreen, SLOT(updateUnit()));

    // create layout
    QHBoxLayout *optionsLayout = new QHBoxLayout;
    optionsLayout->addWidget(settingsButton);
    optionsLayout->addWidget(calendarButton);
    optionsLayout->addWidget(awayButton);
    optionsLayout->setSpacing(0);

    // show layout
    setLayout(optionsLayout);

}

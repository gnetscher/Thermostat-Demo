#include "awayscreen.h"
#include "thermostatwidget.h"
#include "settingscreen.h"

awayscreen::awayscreen(QWidget *parent) :
    QWidget(parent)
{
    // the away screen provides the user an AWAY MODE with the tap of a button
    // it is meant to be used for long periods of away time (i.e. vacation)
    // it is called from the mainwindow

    // title
    awayLabel = new QLabel("System is using energy saving AWAY MODE");
    awayLabel->setAlignment(Qt::AlignHCenter);
    awayLabel->setObjectName("awayLabel");

    // green leaf
    ecoLabel = new QLabel();
    ecoLabel->setAlignment(Qt::AlignHCenter);
    QPixmap *ecoLeaf = new QPixmap(":/Images/eco-leaf.png");
    *ecoLeaf = ecoLeaf->scaled(60,60,Qt::KeepAspectRatio);
    ecoLabel->setPixmap(*ecoLeaf);
    ecoLabel->setObjectName("ecoLabel");
    ecoLabel->setAlignment(Qt::AlignTop);

    // provides current temp - same value as listed in mainwindow adjust dynamically
    currentTempLabel = new QLabel;
    currentTempLabel->setText(QString::number(thermostatwidget::currentTempStatic)+"°");
    currentTempLabel->setAlignment(Qt::AlignHCenter);
    currentTempLabel->setObjectName("currentTemp");
    currentTempLabel->setMargin(0);

    // inside label
    QLabel *insideLabel = new QLabel("Inside");
    insideLabel->setAlignment(Qt::AlignHCenter);
    insideLabel->setMargin(0);

    // layout for current temp
    QVBoxLayout *currentLayout = new QVBoxLayout;
    currentLayout->addStretch();
    currentLayout->addWidget(insideLabel);
    currentLayout->addWidget(currentTempLabel);
    currentLayout->addStretch();

    // upper bound control widget
    upperBound = new QSpinBox;
    upperBound->setValue(84);
    upperBound->setSuffix("°");
    upperBound->findChild<QLineEdit*>()->setReadOnly(true);

    // lower bound control widget
    lowerBound = new QSpinBox;
    lowerBound->setValue(60);
    lowerBound->setSuffix("°");
    lowerBound->findChild<QLineEdit*>()->setReadOnly(true);

    // upper and lower bound labels
    QLabel *heatTo = new QLabel("Heat to");
    heatTo->setAlignment(Qt::AlignHCenter);
    QLabel *coolTo = new QLabel("Cool to");
    coolTo->setAlignment(Qt::AlignHCenter);

    // combines upper and lower bounds into one layout
    QVBoxLayout *boundsLayout = new QVBoxLayout;
    boundsLayout->addStretch();
    boundsLayout->addWidget(coolTo);
    boundsLayout->addWidget(upperBound);
    boundsLayout->addWidget(heatTo);
    boundsLayout->addWidget(lowerBound);
    boundsLayout->addStretch();

    // combines current temp layout and bounds layout
    QHBoxLayout *centerLayout = new QHBoxLayout;
    centerLayout->addStretch();
    centerLayout->addLayout(currentLayout);
    centerLayout->addSpacing(20);
    centerLayout->addLayout(boundsLayout);
    centerLayout->addStretch();

    // combines center layout with title
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(awayLabel);
    rightLayout->insertSpacing(1,10);
    rightLayout->addLayout(centerLayout);

    // combines existing layout with green leaf
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(ecoLabel);
    topLayout->addLayout(rightLayout);

    // button to return to main screen
    QPushButton *backButton = new QPushButton("I'm Back!");
    backButton->setFocusPolicy(Qt::NoFocus);
    connect(backButton,SIGNAL(clicked()),this,SLOT(close()));

    // adds back button to provide final layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->insertSpacing(2,10);
    mainLayout->addWidget(backButton);
    mainLayout->setAlignment(centerLayout,Qt::AlignHCenter);

    // show final layout
    setLayout(mainLayout);
}

void awayscreen::updateCurrentTemp()
{
    // updates current temp in away screen based on current temp in main window
    // connects to 10 second update timer within thermostat widget
    currentTempLabel->setText(QString::number(thermostatwidget::currentTempStatic)+"°");
}

void awayscreen::updateUnit()
{
    // provides for Fahrenheit/Celsius conversion
    int FInt, CInt;
    float FFloat, CFloat;
    QString FString, CString;

    if(settingscreen::unit) {
        // true means F
        // we want Fahrenheit, but currently in Celsius
        CString = currentTempLabel->text();
        CString.chop(1);  // removes degree symbol
        CFloat = CString.toFloat();
        FInt = (int)((CFloat*1.8)+32);
        FString = QString::number(FInt);
        currentTempLabel->setText(FString+"°");
        lowerBound->setValue((lowerBound->value()*1.8)+32);
        upperBound->setValue((upperBound->value()*1.8)+32);
    } else {
        // false means C
        // we want Celsius, but currently in Fahrenheit
        FString = currentTempLabel->text();
        FString.chop(1);  // removes degree symbol
        FFloat = FString.toFloat();
        CInt = (int)(((FFloat - 32) * 5)/9);
        CString = QString::number(CInt);
        currentTempLabel->setText(CString+"°");
        lowerBound->setValue(((lowerBound->value() - 32) * 5)/9);
        upperBound->setValue(((upperBound->value() - 32) * 5)/9);
    }
}

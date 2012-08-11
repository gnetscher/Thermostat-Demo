#include "proxysetupdialog.h"
#include "keyboard/keyboard.h"
#include "mainwindow.h"

#include <QtGui>

QString webdata::proxyName;

proxySetupDialog::proxySetupDialog(QWidget *parent) :
    QDialog(parent)
{
    // create title
    title = new QLabel("Network Proxy");
    title->setAlignment(Qt::AlignHCenter);

    // create proxy label
    proxyLabel = new QLabel("HTTP Proxy:");

    // create proxy line edit with default to TI proxy
    proxyLineEdit = new QLineEdit("wwwgate.ti.com");

    // create okay button
    okayButton = new QPushButton("Launch!");

    // create close button
    closeButton = new QPushButton("Cancel");

    // create keyboard
    lineEditkeyboard = new Keyboard();

    // provide button functionality
    connect(proxyLineEdit,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(closeButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(okayButton, SIGNAL(clicked()), this, SLOT(setupProxy()));

    // create layout
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(proxyLabel);
    topLayout->addWidget(proxyLineEdit);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(okayButton);
    bottomLayout->addWidget(closeButton);
    bottomLayout->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addWidget(title);
    mainLayout->addStretch();
    mainLayout->addLayout(topLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(bottomLayout);
    mainLayout->addStretch();

    setLayout(mainLayout);

}

void proxySetupDialog::run_keyboard_lineEdit()
{
    // display keyboard when line edit is changed
    QLineEdit *line = (QLineEdit *)sender();
    lineEditkeyboard->setLineEdit(line);
    lineEditkeyboard->showFullScreen();
}

void proxySetupDialog::setupProxy()
{
    // provide proxy information based on input from line edit
    webdata::proxyName = proxyLineEdit->text();
    mainwindow *window = new mainwindow;
    window->showFullScreen();

}

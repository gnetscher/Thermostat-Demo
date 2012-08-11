#include "openingscreen.h"
#include "mainwindow.h"
#include "webdata.h"
#include "proxysetupdialog.h"
#include <QtGui>

// these static variables are contained within the openingscreen class versus
// regular variables that are contained within objects of that class
bool openingscreen::webFlag;
bool openingscreen::proxyFlag;

openingscreen::openingscreen(QWidget *parent) :
    QWidget(parent)
{

    // message provides the first dialog concerning internet connectivity
    QMessageBox *message = new QMessageBox;

    int r = QMessageBox::question(message, "Thermostat Demo Connectivity",
                                 "To launch the thermostat demo, "
                                 "please provide the following information:"
                                 "\n\n1. Are you connected to the internet?",
                                 QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    if(r == QMessageBox::Yes) {
        // we have internet
        webFlag = true;

        // the second message provides the dialog concerning proxy status
        int s = QMessageBox::question(message, "Thermostat Demo Connectivity",
                                     "To launch the thermostat demo, "
                                     "please provide the following information:"
                                     "\n\n2. Are you connected through a proxy?",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if(s == QMessageBox::Yes) {
            // show proxy setup screen
            proxyFlag = true;

            proxySetupDialog *dialog = new proxySetupDialog;
            dialog->showFullScreen();


        } else if(s == QMessageBox::Cancel) {
            exit(0);
        } else if(s == QMessageBox::No) {
            proxyFlag = false;
            mainwindow *window = new mainwindow;
            window->showFullScreen();
        }

    } else if (r == QMessageBox::Cancel) {
        exit(0);
    } else if (r == QMessageBox::No) {
        webFlag = false;
        mainwindow *window = new mainwindow;
        window->showFullScreen();
    }

}

void QMessageBox::showEvent(QShowEvent *)
{
    this->showFullScreen();
}


#include <QtGui>

#include "mainwindow.h"
#include "weatherwidget.h"
#include "thermostatwidget.h"
#include "optionswidget.h"
#include "webdata.h"
#include "openingscreen.h"

#include <QtDebug>

int main(int argc, char *argv[])
{

    // If you're looking for where to start reading this code,
    // check out STARTHERE.h
    QApplication app(argc, argv);

    // read style sheet and apply pararmeters
    QFile file(":/qss/thermostatdemo.qss");
    file.open(QFile::ReadOnly);
    app.setStyleSheet(file.readAll());

    // create opening dialog for internet and proxy settings
    new openingscreen;

    // enter application loop
    return app.exec();
}


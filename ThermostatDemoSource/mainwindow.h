#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "webdata.h"
#include "weatherwidget.h"

class mainwindow : public QWidget
{
    Q_OBJECT
public:
    explicit mainwindow(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    
signals:
    
public slots:
    void updateUnit();
    void changeCity(QString);

private:
    webdata *webData;
    QPushButton *energyButton;
    QPushButton *timeButton;
    QPushButton *dateButton;
    QPushButton *closeButton;
    QTimer *clockTimer;
    QTime clock;
    void setBackground(QString);
    weatherwidget *weatherWidget;
    void getWebData();

private slots:
    void updateClock();
    void energySaving(bool);
    
};

#endif // MAINWINDOW_H

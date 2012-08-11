#ifndef SCHEDULESCREEN_H
#define SCHEDULESCREEN_H

#include <QtGui>
#include "schedulepoint.h"

class schedulescreen : public QWidget
{
    Q_OBJECT
public:
    explicit schedulescreen(QWidget *parent = 0);
    
signals:
    void valueChanged();
    void clicked();
    
public slots:
    void shiftLeft();
    void shiftRight();
    void increaseTemp();
    void decreaseTemp();
    void showButtons(schedulepoint *);
    void showPoints(int);
    void removeAllBlur();

private:
    QCheckBox *MondayButton;
    QCheckBox *TuesdayButton;
    QCheckBox *WednesdayButton;
    QCheckBox *ThursdayButton;
    QCheckBox *FridayButton;
    QCheckBox *SaturdayButton;
    QCheckBox *SundayButton;
    QButtonGroup *daysButtonGroup;
    QGraphicsScene *scene;
    QGraphicsView *view;
    void addSchedulePoints();
    int seqNumber;
    QGraphicsProxyWidget *proxyLeftButton;
    QGraphicsProxyWidget *proxyRightButton;
    QGraphicsProxyWidget *proxyUpButton;
    QGraphicsProxyWidget *proxyDownButton;
    QList <schedulepoint *> pointList;
    schedulepoint *point0;
    schedulepoint *point1;
    schedulepoint *point2;
    schedulepoint *point3;
    schedulepoint *point4;
    schedulepoint *point5;
    schedulepoint *point6;
    schedulepoint *point7;
    schedulepoint *point8;
    schedulepoint *point9;
    schedulepoint *point10;
    schedulepoint *point11;
    schedulepoint *point12;
    schedulepoint *point13;
    schedulepoint *point14;
    schedulepoint *point15;
    schedulepoint *point16;
    schedulepoint *point17;
    schedulepoint *point18;
    schedulepoint *point19;
    schedulepoint *point20;
    schedulepoint *point21;
    schedulepoint *point22;
    schedulepoint *point23;
    schedulepoint *point24;
    schedulepoint *point25;
    schedulepoint *point26;
    schedulepoint *point27;
    schedulepoint *currentPoint;
    void showPoint(schedulepoint *);
    void hidePoints();
    void hideButtons();
    void shiftVerticalButtonsLeft();
    void shiftVerticalButtonsRight();
    void shiftHorizontalButtonsLeft();
    void shiftHorizontalButtonsRight();
    void shiftButtonsLeft();
    void shiftButtonsRight();
    QLabel *currentTime;
    void blur();

protected:
    void mousePressEvent(QMouseEvent */* event */);

};

#endif // SCHEDULESCREEN_H

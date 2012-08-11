#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include <QtGui>

#include <QtSvg/QSvgWidget>

class QLabel;

class weatherwidget : public QWidget
{
    Q_OBJECT
public:
    explicit weatherwidget(QWidget *parent = 0);
    void setCurrentTemp(QString);
    void setCurrentIcon(QString);
    void setDay1Icon(QString);
    void setDay2Icon(QString);
    void setDay3Icon(QString);
    void setDay1(QString);
    void setDay2(QString);
    void setDay3(QString);
    void setDay1High(QString);
    void setDay2High(QString);
    void setDay3High(QString);
    void setDay1Low(QString);
    void setDay2Low(QString);
    void setDay3Low(QString);
    QString getCurrentTemp();
    QString getDay1High();
    QString getDay2High();
    QString getDay3High();
    QString getDay1Low();
    QString getDay2Low();
    QString getDay3Low();
    void setCity(QString);
    void setClock(QTime);

signals:

public slots:


protected:

private:
    QLabel *currentTemp;
    QLabel *currentIcon;
    QLabel *currentCity;
    QLabel *day1Label;
    QLabel *day1Icon;
    QLabel *day1Low;
    QLabel *day1High;
    QLabel *day2Label;
    QLabel *day2Icon;
    QLabel *day2Low;
    QLabel *day2High;
    QLabel *day3Label;
    QLabel *day3Icon;
    QLabel *day3Low;
    QLabel *day3High;
    QString weatherStyleSheet;
    QTime *clock;
    
};

#endif // WEATHERWIDGET_H

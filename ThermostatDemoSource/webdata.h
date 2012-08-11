#ifndef WEBDATA_H
#define WEBDATA_H

#include <QObject>
#include <QtNetwork>
#include <QUrl>

class webdata : public QObject
{
    Q_OBJECT
public:
    explicit webdata(QObject *parent = 0);
    QString date();
    QString time();
    QString temp();
    QString currentIcon();
    QString day1Icon();
    QString day2Icon();
    QString day3Icon();
    QString day1();
    QString day2();
    QString day3();
    QString day1High();
    QString day1Low();
    QString day2High();
    QString day2Low();
    QString day3High();
    QString day3Low();
    QTime clockObject();
    static QString proxyName;
    void changeCity(QString);
    
signals:
    
public slots:

private slots:
    void parseXML();

private:
    QNetworkAccessManager *manager;
    QNetworkRequest *request;
    QNetworkReply *reply;
    QXmlStreamReader reader;
    QString currentDate;
    QString currentTime;
    QTime clock;
    QString currentTemp;
    QStringList forecastIconList;
    QStringList weekdayList;
    QStringList forecastTempList;
    QString unitConversion(QString);

    
};

#endif // WEBDATA_H

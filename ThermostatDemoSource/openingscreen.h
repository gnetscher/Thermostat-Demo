#ifndef OPENINGSCREEN_H
#define OPENINGSCREEN_H

#include <QWidget>

class openingscreen : public QWidget
{
    Q_OBJECT
public:
    explicit openingscreen(QWidget *parent = 0);
    static bool webFlag;
    static bool proxyFlag;
    
signals:
    
private slots:

private:

};

#endif // OPENINGSCREEN_H

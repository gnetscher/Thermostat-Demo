#ifndef SETTINGSCREEN_H
#define SETTINGSCREEN_H

#include <QtGui>

class settingscreen : public QWidget
{
    Q_OBJECT
public:
    explicit settingscreen(QWidget *parent = 0);
    static bool unit;
    
signals:
    void valueChanged();
    void cityChanged(QString);
    
public slots:
    void unitIsF();
    void unitIsC();

private:
    QPushButton *FButton;
    QPushButton *CButton;
    
};

#endif // SETTINGSCREEN_H

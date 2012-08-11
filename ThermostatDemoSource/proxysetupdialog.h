#ifndef PROXYSETUPDIALOG_H
#define PROXYSETUPDIALOG_H

#include <QtGui>
#include "keyboard/keyboard.h"

class proxySetupDialog : public QDialog
{
    Q_OBJECT
public:
    explicit proxySetupDialog(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    QLabel *title;
    QLabel *proxyLabel;
    QLineEdit *proxyLineEdit;
    QPushButton *okayButton;
    QPushButton *closeButton;
    Keyboard *lineEditkeyboard;
    
private slots:
    void run_keyboard_lineEdit();
    void setupProxy();
};

#endif // PROXYSETUPDIALOG_H

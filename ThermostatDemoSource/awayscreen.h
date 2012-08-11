#ifndef AWAYSCREEN_H
#define AWAYSCREEN_H

#include <QtGui>

class awayscreen : public QWidget
{
    Q_OBJECT
public:
    explicit awayscreen(QWidget *parent = 0);
    
signals:
    
public slots:
    void updateCurrentTemp();
    void updateUnit();

private:
    QLabel *awayLabel;
    QLabel *ecoLabel;
    QLabel *currentTempLabel;
    QSpinBox *upperBound;
    QSpinBox *lowerBound;

};

#endif // AWAYSCREEN_H

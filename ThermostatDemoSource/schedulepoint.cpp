#include "schedulepoint.h"
#include "schedulescreen.h"
#include "settingscreen.h"
#include <QtGui>

schedulepoint::schedulepoint(int seqNumber)
{
    // create schedule point with necessary information
    ID = seqNumber;
    myBackgroundColor = Qt::blue;
    temp = 72;
    myText = QString::number(temp)+QString("°");
    setFlags(ItemIsSelectable);
    location=0;
}

schedulepoint::~schedulepoint()
{
    // destructor
}

void schedulepoint::setText(const QString &text)
{
    // add new text
    prepareGeometryChange();
    myText = text;
    update();
}

QRectF schedulepoint::outlineRect() const
{
    // define outline rectangle
    const int padding = 3;
    QFontMetricsF metrics = qApp->font();
    QRectF rect = metrics.boundingRect(myText);
    rect.adjust(-padding, -padding, +padding, +padding);
    rect.translate(-rect.center());
    return rect;
}

QRectF schedulepoint::boundingRect() const
{
    // provide size of each point for collision detection
    const int margin = 1;
    return outlineRect().adjusted(-margin, -margin, +margin, +margin);
}

QPainterPath schedulepoint::shape() const
{
    // provide shape of each point
    QRectF rect = outlineRect();
    QPainterPath path;
    path.addRoundRect(rect,roundness(rect.width()), roundness(rect.height()));
    return path;
}

void schedulepoint::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option, QWidget * /*widget*/)
{
    // draw point itself
    QPen pen(Qt::white); // outline color
    if(option->state & QStyle::State_Selected) {

    }
    painter->setPen(pen);
    painter->setBrush(myBackgroundColor);

    QRectF rect = outlineRect();
    painter->drawRoundRect(rect, roundness(rect.width()), roundness(rect.height()));

    painter->drawText(rect, Qt::AlignCenter, myText);
}

void schedulepoint::mousePressEvent(QGraphicsSceneMouseEvent * /* event */)
{
    // provide event handler for mouse click
    emit clicked(this);

}

int schedulepoint::roundness(double size) const
{
    // rounded edges for rectangle
    const int diameter = 12;
    return 100 * diameter / int(size);
}


void schedulepoint::shiftLeft()
{
    // provide a slot to allow point shifting to the left
    location--;
    this->moveBy(-3.4, 0.0);
    update();
}

void schedulepoint::shiftRight()
{
    // provide a slot to allow point shifting to the right
    location++;
    this->moveBy(+3.4, 0.0);
    update();
}

void schedulepoint::increaseTemp()
{
    // provide a slot to increase point temperature
    temp++;
    myText = QString::number(temp)+QString("°");
    update();
}

void schedulepoint::decreaseTemp()
{
    // provide a slot to decrease temperature
    temp--;
    myText = QString::number(temp)+QString("°");
    update();
}

int schedulepoint::getID()
{
    // provide point's unique ID number
    return ID;
}

void schedulepoint::setID(int seqNumber)
{
    // give point a unique ID number
    ID = seqNumber;
}

void schedulepoint::setLocation(int num)
{
    // track point's horizontal movement from starting position
    location=num;
}

int schedulepoint::getLocation()
{
    // return how much point has moved from start
    return location;
}

QString schedulepoint::time()
{
    // output the current time represnted by this point's location
    int hours = ((15/3.4)*(this->pos().x()+12.7)) / 60;
    int minutes = (int)((15/3.4)*(this->pos().x()+12.7)) % 60;
    QTime *time = new QTime(hours, minutes);
    return time->toString("h:mm AP");
}

void schedulepoint::updateUnit()
{
    // provide switch between celsius and fahrenheit
    if(settingscreen::unit) {
        // true means F
        // we want Fahrenheit, but currently in Celsius
        temp = (temp*1.8)+32;
    } else {
        // false means C
        // we want Celsius, but currently in Fahrenheit
        temp = ((temp - 32) * 5) / 9;
    }
    myText = QString::number(temp)+QString("°");
    update();
}

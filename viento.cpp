#include "viento.h"

Viento::Viento()
{

}

Viento::Viento(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=30;
    setPos(posx,posy);

}

QRectF Viento::boundingRect() const
{
    return QRectF(-radio,-radio,radio+90,radio+90);
}

void Viento::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawEllipse(boundingRect());
    QPixmap pxMap("viento.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}

void Viento::Mover(int posx, int posy)
{
   setPos(posx,-posy);
}


#include "enemigo.h"

Enemigo::Enemigo()
{

}

Enemigo::Enemigo(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=10;
    setPos(posx,posy);

}

QRectF Enemigo::boundingRect() const
{
    return QRectF(-radio,-radio,radio+90,radio+90);
}

void Enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawEllipse(boundingRect());
    QPixmap pxMap("borra.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}

void Enemigo::Mover(int posx, int posy)
{
   setPos(posx,-posy);
}


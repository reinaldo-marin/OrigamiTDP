#include "bala.h"

Bala::Bala()
{

}

Bala::Bala(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=10;
    setPos(posx,posy);

}

QRectF Bala::boundingRect() const
{
    return QRectF(-radio,-radio,radio+50,radio+50);
}

void Bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawEllipse(boundingRect());
    QPixmap pxMap("bola.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}

void Bala::Mover(int posx, int posy)
{
   setPos(posx,-posy);
}


#include "cuerpo.h"

int Cuerpo::getR() const
{
    return r;
}
int Cuerpo::setR(int radio)
{
    r=radio;
}
Cuerpo::Cuerpo()
{

}

QRectF Cuerpo::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r) ;
}

void Cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void Cuerpo::Mover(int posx, int posy)
{
    setPos(posx,-posy);
}

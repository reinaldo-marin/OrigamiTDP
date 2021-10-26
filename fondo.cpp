#include "fondo.h"

Fondo::Fondo()
{

}

Fondo::Fondo(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=10;
    setPos(posx,posy);

}
int Fondo::GetPosx()
{
    return posx;
}

int Fondo::GetPosy()
{
    return posy;
}
QRectF Fondo::boundingRect() const
{
    return QRectF(-radio,-radio,800,2000);
}

void Fondo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawEllipse(boundingRect());
    QPixmap pxMap("calle.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}

void Fondo::Mover(int posx, int posy)
{
   setPos(posx,posy);
}
void Fondo::Setxy(int xd, int yd)
{
   posx=xd;
   posy=yd;
}

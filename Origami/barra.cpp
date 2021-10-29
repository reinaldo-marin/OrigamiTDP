#include "barra.h"

Barra::Barra()
{

}

Barra::Barra(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=10;
    setPos(posx,posy);

}
int Barra::GetPosx()
{
    return posx;
}

int Barra::GetPosy()
{
    return posy;
}
QRectF Barra::boundingRect() const
{
    return QRectF(-radio,-radio,300,100);
}

void Barra::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawEllipse(boundingRect());
    if (radio==5)
    {
       QPixmap pxMap("vidaverde.png");
       painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
    }
    else
    {
       QPixmap pxMap("vidaroja.png");
       painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
    }

}

void Barra::Mover(int posx, int posy)
{
   setPos(posx,posy);
}
void Barra::Setxy(int xd, int yd)
{
   posx=xd;
   posy=yd;
}

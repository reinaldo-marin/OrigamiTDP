#include "jugador.h"
string Jugador::getUsu() const
{
    return usu;
}

void Jugador::setUsu(const string &value)
{
    usu = value;
}
string Jugador::getContra() const
{
    return contra;
}

void Jugador::setContra(string value)
{
    contra = value;
}
string Jugador::getNivel() const
{
    return contra;
}

void Jugador::setNivel(string value)
{
    contra = value;
}

Jugador::Jugador()
{

}

Jugador::Jugador(string usu, string contra, string nivel)
{
    this->usu=usu;
    this->contra=contra;
    this->nivel=nivel;

}
Jugador::Jugador(int x, int y, int r)
{

    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=30;
    setPos(posx,posy);
}

QRectF Jugador::boundingRect() const
{
    return QRectF(-radio,-radio,radio+80,radio+80);
}

void Jugador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawEllipse(boundinsgRect());
    if (radio == 60 )
    {
        QPixmap pxMap("avion.png");
        painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
    }
    else
    {
        QPixmap pxMap("bat.png");
        painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
    }

}

void Jugador::MoveRight()
{
    this->posx+=velocidad;
    setPos(posx,posy);
}

void Jugador::MoveLeft()
{
    this->posx-=velocidad;
    setPos(posx,posy);
}

void Jugador::MoveUp()
{
    this->posy-=velocidad;
    setPos(posx,posy);

}

int Jugador::GetPosx()
{
    return posx;
}

int Jugador::GetPosy()
{
    return posy;
}

void Jugador::MoveDown()
{
    this->posy+=velocidad;
    setPos(posx,posy);

}

void Jugador::Disparar()
{

}

void Jugador::SetPos(int xd, int yd)
{
   setPos(xd,yd);
}

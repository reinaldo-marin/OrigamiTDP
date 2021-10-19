#include "movimiento.h"
#include <vector>
double Movimiento::getPosx() const
{
    return posx;
}

double Movimiento::getPosy() const
{
    return posy;
}
double Movimiento::getMasa() const
{
    return masa;
}

Movimiento::Movimiento()
{

}
void Movimiento::SetAngulo(int value)
{
    ang = value;
}
void Movimiento::SetAceleracionx(int value)
{
    ax = value;
}
void Movimiento::SetAceleraciony(int value)
{
    ay = value;
}
Movimiento::Movimiento(double x, double y, double m, double r, double vx, double vy)
{
    this->posx=x;
    this->posy=y;
    this->masa=m;
    this->radio=r;
    this->vx=vx;
    this->vy=vy;

}

void Movimiento::CalcularVelocidad()
{
    vx = vx+(ax*DT);
    vy = vy+(ay*DT);
}

void Movimiento::CalcularPosicion()
{
    posx=posx+vx*DT+((ax*(DT*DT))/2);
    posy=posy+vy*DT+((ay*(DT*DT))/2);

}

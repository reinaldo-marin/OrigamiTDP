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

void Movimiento::SetPosi(int value, int value2)
{
    posx = value;
    posy = value2;
}

Movimiento::Movimiento()
{

}

Movimiento::Movimiento(double x, double y, double r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;

}

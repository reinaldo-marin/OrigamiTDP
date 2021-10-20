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

Movimiento::Movimiento()
{

}

Movimiento::Movimiento(double x, double y, double r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;

}

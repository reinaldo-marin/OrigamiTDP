#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <math.h>
#include <vector>
#define DT 0.05

class Movimiento
{

    double posx,posy,masa,radio,vx,vy,ang,ax,ay;

public:
    Movimiento();
    Movimiento(double x,double y, double masa, double radio, double vx, double vy);
    void CalcularVelocidad();
    void CalcularPosicion();
    double getPosx() const;
    double getMasa() const;
    double getPosy() const;
    void SetAngulo(int value);
    void SetAceleracionx(int value);
    void SetAceleraciony(int value);
};

#endif // MOVIMIENTO_H

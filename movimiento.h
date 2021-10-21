#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <math.h>
#include <vector>
#define DT 1

class Movimiento
{

    double posx,posy,radio;

public:
    Movimiento();
    Movimiento(double x,double y, double radio);
    void CalcularVelocidad();
    void CalcularPosicion();
    double getPosx() const;
    double getMasa() const;
    double getPosy() const;
    void SetAngulo(int value);
    void SetAceleracionx(int value);
    void SetAceleraciony(int value);
    void SetPosi(int value, int value2);
};

#endif // MOVIMIENTO_H

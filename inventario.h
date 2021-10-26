#ifndef Inventario_H
#define Inventario_H
#include <movimiento.h>
#include <bala.h>
#include <vector>
#include <fstream>

class Inventario
{
    std::vector<Movimiento*>Cuerpos;
    std::vector<Movimiento*>Balas;

public:
    Inventario();
    bool AgregarCuerpo(Movimiento *Cuerpo);
    bool AgregarBalas(Movimiento *Bala);
    int ContarCuerpos();
    std::vector<Movimiento*>getCuerpos();
    std::vector<Movimiento*>getBalas();

};

#endif // Inventario_H

#ifndef Inventario_H
#define Inventario_H
#include <movimiento.h>
#include <viento.h>
#include <bala.h>
#include <vector>
#include <fstream>

class Inventario
{
    std::vector<Movimiento*>Cuerpos;
    std::vector<Movimiento*>Balas;
    std::vector<Movimiento*>Vientos;

public:
    Inventario();
    bool AgregarCuerpo(Movimiento *Cuerpo);
    bool AgregarBalas(Movimiento *Bala);
    bool AgregarVientos(Movimiento *Viento);
    int ContarCuerpos();
    std::vector<Movimiento*>getCuerpos();
    std::vector<Movimiento*>getBalas();
    std::vector<Movimiento*>getVientos();

};

#endif // Inventario_H

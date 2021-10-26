#include "inventario.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;
Inventario::Inventario()
{

}

bool Inventario::AgregarCuerpo(Movimiento *Cuerpo)
{
        Cuerpos.push_back(Cuerpo);
        return true;
}
bool Inventario::AgregarBalas(Movimiento *Bala)
{
        Balas.push_back(Bala);
        return true;
}


std::vector<Movimiento *> Inventario::getCuerpos()
{
    return Cuerpos;
}
std::vector<Movimiento *> Inventario::getBalas()
{
    return Balas;
}
int Inventario::ContarCuerpos()
{
    unsigned i = 0;
    for(i=0; i<Cuerpos.size(); i++)
   {

   }
    return i;
}


#ifndef Inventory_H
#define Inventory_H
#include <enemigo.h>
#include <vector>
#include <fstream>

class Inventory
{
    std::vector<Enemigo*>Tumulto;

public:
    Inventory();
    bool AgregarEnemigo(Enemigo *Enemigo);
    int CargarInventory();
    int ContarEnemigos();
    std::vector<Enemigo*>getEnemigos();

};

#endif // Inventory_H

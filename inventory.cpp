#include "inventory.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;
Inventory::Inventory()
{

}

bool Inventory::AgregarEnemigo(Enemigo *Enemigo)
{
        Tumulto.push_back(Enemigo);
        return true;
}


std::vector<Enemigo *> Inventory::getEnemigos()
{
    return Tumulto;
}
int Inventory::ContarEnemigos()
{
    unsigned i = 0;
    for(i=0; i<Tumulto.size(); i++)
   {

   }
    return i;
}


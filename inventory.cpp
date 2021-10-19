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

bool Inventory::AgregarCorpu(Cuerpo *Corpu)
{
        Corpus.push_back(Corpu);
        return true;
}


std::vector<Cuerpo *> Inventory::getCorpus()
{
    return Corpus;
}
int Inventory::ContarCorpus()
{
    unsigned i = 0;
    for(i=0; i<Corpus.size(); i++)
   {

   }
    return i;
}


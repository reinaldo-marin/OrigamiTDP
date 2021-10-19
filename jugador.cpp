#include "jugador.h"
#include <string>
string Jugador::getUsu() const
{
    return usu;
}

void Jugador::setUsu(const string &value)
{
    usu = value;
}
string Jugador::getContra() const
{
    return contra;
}

void Jugador::setContra(string value)
{
    contra = value;
}
string Jugador::getNivel() const
{
    return contra;
}

void Jugador::setNivel(string value)
{
    contra = value;
}

Jugador::Jugador()
{

}

Jugador::Jugador(string usu, string contra, string nivel)
{
    this->usu=usu;
    this->contra=contra;
    this->nivel=nivel;
}

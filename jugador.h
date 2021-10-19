#ifndef JUGADOR_H
#define JUGADOR_H
#include <vector>
#include <string>
using namespace  std;
class Jugador
{
   //atributos
   string usu;
   string contra;
   string nivel;

    //Metodos
public:
    Jugador();
    Jugador(string nombre,string contra, string nivel);
    string getUsu() const;
    void setUsu(const string &value);
    string getContra() const;
    void setContra(string value);
    string getNivel() const;
    void setNivel(string value);

};
#endif // JUGADOR_H

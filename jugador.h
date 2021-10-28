#ifndef JUGADOR_H
#define JUGADOR_H
#include <vector>
#include <string>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
using namespace  std;
class Jugador: public QGraphicsItem
{
   //atributos
   string usu;
   string contra;
   string nivel;
   int posx;
   int posy;
   int radio;
   int velocidad;
   int viento = 20;

    //Metodos
public:
    Jugador();
    Jugador(string nombre,string contra, string nivel);
    Jugador(int x, int y , int r);
    string getUsu() const;
    void setUsu(const string &value);
    string getContra() const;
    void setContra(string value);
    string getNivel() const;
    void setNivel(string value);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    void MoveRight();
    void MoveLeft();
    void MoveUp();
    int GetPosx();
    int GetViento();
    int GetVelocidad();
    int GetPosy();
    void MoveDown();
    void Disparar();
    void SetPos(int xd, int yd);
    void SetViento(int v);
    void SetVelocidad(int vel);

};
#endif // JUGADOR_H

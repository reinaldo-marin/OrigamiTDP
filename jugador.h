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
    void MoveDown();
    void Disparar();

};
#endif // JUGADOR_H

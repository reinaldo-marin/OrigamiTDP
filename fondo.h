#ifndef FONDO_H
#define FONDO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class Fondo : public QGraphicsItem
{

    int posx;
    int posy;
    int radio;
    int velocidad;


public:
    Fondo();
    Fondo(int x, int y , int r);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    void Mover(int posx, int posy);
    int GetPosx();
    int GetPosy();
    void Setxy(int xd, int yd);


};

#endif // BOLITA_H

#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class Enemigo : public QGraphicsItem
{

    int posx;
    int posy;
    int radio;
    int velocidad;


public:
    Enemigo();
    Enemigo(int x, int y , int r);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    void Mover(int posx, int posy);


};

#endif // BOLITA_H

#ifndef VIENTO_H
#define VIENTO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class Viento: public QGraphicsItem
{

    int posx;
    int posy;
    int radio;
    int velocidad;


public:
    Viento();
    Viento(int x, int y , int r);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    void Mover(int posx, int posy);


};

#endif // BOLITA_H

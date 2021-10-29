#ifndef BALA_H
#define BALA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class Bala : public QGraphicsItem
{

    int posx;
    int posy;
    int radio;
    int velocidad;


public:
    Bala();
    Bala(int x, int y , int r);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    void Mover(int posx, int posy);


};

#endif // BOLITA_H

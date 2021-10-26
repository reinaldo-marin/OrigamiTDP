#ifndef CUERPO_H
#define CUERPO_H
#include <QGraphicsItem>
#include <QPainter>

class Cuerpo: public QGraphicsItem
{
    int r;
public:
    Cuerpo();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem
               *option, QWidget *widget = nullptr);
    void Mover(int posx, int posy);
    int getR() const;
    int setR(int r);
};

#endif // CUERPO_H

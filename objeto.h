#ifndef OBJETO_H
#define OBJETO_H
#include <QGraphicsItem>
#include <QPainter>

class pared : public QGraphicsItem
{
public:
    int posx;
    int posy;
    int w;
    int h;
    pared();
    pared(int x, int y, int w, int h);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
};

#endif // PARED_H

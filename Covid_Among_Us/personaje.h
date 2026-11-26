#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<QGraphicsPixmapItem>

class Personaje
{
private:
    float x,y, vx, vy;
        int vida;
    float radio;

    QGraphicsPixmapItem *item;
public:
    Personaje(float x0, float y0, float r, int vida0, QGraphicsPixmapItem* it);
    virtual ~Personaje() {}
    float getX() ;
    float getY();
    float getRadio();
    int   getVida();
    void mover(float dt);
    void recibirDano(int d) { vida -= d; }
    bool colisionaCon(const Personaje& otro) const;

};

#endif // PERSONAJE_H

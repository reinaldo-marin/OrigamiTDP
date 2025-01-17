#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <movimiento.h>
#include <cuerpo.h>
#include <inventario.h>
#include <inventory.h>
#include <enemigo.h>
#include <objeto.h>
#include <fondo.h>
#include <jugador.h>
#include <viento.h>
#include <bala.h>
#include <barra.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QLabel>
#include <QWidget>
#include <QKeyEvent>
#include <QString>
#include <QCoreApplication>
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <QCoreApplication>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLabel *labeludo;
    QLabel *puntaje;
    QLabel *puntajer;
    QString stringo;
    QString stringp;
    int contador = 0;
    int entra;
    int conta = 1;
    int njugadores = 1;
    int restantes = 1;
    int intento = 1;
    int record;
    int posiposi;
    bool EvaluarColision(Jugador *Jugador);
    bool EvaluarViento(Jugador *Jugador);
    bool EvaluarBala();
    int PosColi(Jugador *bola);
    int PosViento(Jugador *bola);
    int PosBala();
    int PosBalin();

private slots:
    void on_bntIniSesi_clicked();
    void Mover();
    void MoverBala();
    void JugadorHP();
    void MoverFondo();
    void MoverViento();
    void Control_Enemigos1();
    void Control_Vientos();
    void on_btnRegis_clicked();

    void on_bntnvl1_clicked();

    void on_radioButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QAction *bntFull;
    QGraphicsScene *Scene;
    QGraphicsScene *Scene2;
    QGraphicsScene *Scene3;
    QGraphicsScene *Scene4;
    QTimer *timer;
    QTimer *timerhp;
    QTimer *timer2;
    QTimer *timerv;
    QTimer *timer2v;
    QTimer *timerfondo;
    QTimer *timerbala;
    Cuerpo *cuerpo;
    Movimiento *movimiento;
     Movimiento *movimientob;
    Inventario miInventario;
    QList<pared*>paredes;
    QList<Enemigo*>enemigous;
    QList<Bala*>balas;
    QList<Viento*>vientos;
    Inventory miInventory;
    Enemigo *enemigo;
    void keyPressEvent(QKeyEvent *evento);
    Jugador *ball;
    Jugador *ball2;
    Barra *barra;
    Barra *barra2;
    Fondo *fondo;
    Fondo *fondo2;
    Fondo *fondo3;
    Fondo *fondo4;

};
#endif // MAINWINDOW_H

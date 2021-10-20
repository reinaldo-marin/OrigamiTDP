#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <movimiento.h>
#include <cuerpo.h>
#include <inventario.h>
#include <inventory.h>
#include <enemigo.h>
#include <objeto.h>
#include <jugador.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QLabel>
#include <QWidget>
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
    QString stringo;
    int contador;
    int entra;

private slots:
    void on_bntIniSesi_clicked();
    void Mover();
    void Control_Enemigos1();
    void on_btnRegis_clicked();

    void on_bntnvl1_clicked();

private:
    Ui::MainWindow *ui;
    QAction *bntFull;
    QGraphicsScene *Scene;
    QGraphicsScene *Scene2;
    QTimer *timer;
    QTimer *timer2;
    Cuerpo *cuerpo;
    Movimiento *movimiento;
    Inventario miInventario;
    QList<pared*>paredes;
    Inventory miInventory;
    Enemigo *enemigo;

};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <movimiento.h>
#include <inventario.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <cstring>
#include <string.h>
#include <string>
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <conio.h>
#include <cstdlib>
using namespace std;
int acelerax (int m2, int x1, int x2, int y1, int y2)
{
    double rd = sqrt((pow(x2-x1,2))+(pow(y2-y1,2)));
    double dy = y2-y1;
    double dx = x2-x1;
    double te = atan2(dy,dx);
    double rad=(te*3.141598)/180;
    double k = 0.0000000000667384;
    int ax = ((k*m2)/(pow(rd,2)))*cos(rad);
    return ax;
}
int aceleray (int m2, int x1, int x2, int y1, int y2)
{
    double rd = sqrt((pow(x2-x1,2))+(pow(y2-y1,2)));
    double dy = y2-y1;
    double dx = x2-x1;
    double te = atan2(dy,dx);
    double rad=(te*3.141598)/180;
    double k = 0.0000000000667384;
    int ay = ((k*m2)/(pow(rd,2)))*sin(rad);
    return ay;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=  new QTimer;
    timer2=  new QTimer;
    Scene = new QGraphicsScene;
    Scene2 = new QGraphicsScene;
    ui->graphicsView->setScene(Scene);
    Scene->setSceneRect(-400,-450,800,810);
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(Control_Enemigos1()));
    labeludo = new QLabel(stringo,this);
    labeludo->setGeometry(20,900,900,70);
    labeludo->setFont(QFont("Comic Sans MS", 20));
    entra = 0;
    ball = new Jugador(400,600,30);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bntIniSesi_clicked()
{
    string usu,contra;
    usu=ui->le_usu->text().toStdString();
    contra=ui->le_contra->text().toStdString();
    ifstream admin("usuarioycontra.txt");
    string lineas;
    int c = 0;

    for(c ;getline(admin, lineas);c++)
    {

        if (lineas == usu)
         {
           break;
         }
        else
        {
            labeludo->setText("Usuario o clave incorrecta");
            break;
        }

    }
    ifstream f("usuarioycontra.txt");
    string lineaus;
    for(int z = 0;getline(f, lineaus);z++)
    {
        if (z == c+1)
         {
           if (lineaus == contra )
           {
               entra = 1;
               labeludo->setText("Bienvenido");
               break;
           }
           else
           {
               labeludo->setText("Usuario o clave incorrecta");
               break;
           }
         }

    }


}


void MainWindow::Control_Enemigos1()
{
    int xr = rand()%(800-50);
    int xy = rand()%(600-200);
    if (conta%2==0)
    {

    }
    else
    {
        enemigo = new Enemigo(xr,xy,50);
        movimiento= new Movimiento(xr,xy,50);
    }

    if(miInventario.AgregarCuerpo(movimiento))
    {

    }
    if(miInventory.AgregarEnemigo(enemigo))
    {

    }
    int tot = miInventory.ContarEnemigos();
    Scene2->addItem(enemigo);
    for (int s = 0; s<tot; s++)
    {
        miInventario.getCuerpos()[s]->SetPosi(miInventario.getCuerpos()[s]->getPosx(),miInventario.getCuerpos()[s]->getPosy()-20);
        miInventory.getEnemigos()[s]->Mover(miInventario.getCuerpos()[s]->getPosx(),miInventario.getCuerpos()[s]->getPosy());
    }
    conta++;

}


void MainWindow::Mover()
{

}

void MainWindow::on_btnRegis_clicked()
{
    string usu,contra;
    usu=ui->le_usu->text().toStdString();
    contra=ui->le_contra->text().toStdString();
    int repitis=0;
    string linea;
    ifstream archivo;
    archivo.open("usuarioycontra.txt");
    while(archivo.good())
    {
       getline(archivo,linea);
       string substr;
       vector<string>campos;
       vector<string> s;
       if (linea == usu)
       {
           repitis = 1;
       }
    }
    archivo.close();
    if (repitis == 1)
    {
        labeludo->setText("El usuario ingresado ya existe");
    }
    else
    {
        ofstream filep;
        ifstream in_file;
        filep.open("usuarioycontra.txt",ios::app);
        filep<<usu<<endl;
        filep<<contra<<endl;
        filep<<"1"<<endl;
    }




}


void MainWindow::on_bntnvl1_clicked()
{
    int repitis=0;
    string linea;
    ifstream archivo;
    archivo.open("usuarioycontra.txt");
    while(archivo.good())
    {
       getline(archivo,linea);
       int posInit=0;
       int posFound=0;
       string substr;
       vector<string>campos;
       vector<string> s;
       while(posFound>=0)
       {
           posFound=linea.find(';',posInit);
           substr=linea.substr(posInit,posFound-posInit);
           posInit=posFound+1;
           campos.push_back(substr);
       }
       if (campos[0] == "1")
       {
           repitis = 1;
       }

    }
    archivo.close();
    if(entra == 1)
    {
        timer2->start(1000);
        ui->graphicsView->setScene(Scene2);
        Scene2->setSceneRect(0,0,800,810);
        Scene2->addItem(ball);

    }
    else
    {
        labeludo->setText("Debes iniciar sesión primero");
    }

}
bool MainWindow::EvaluarColision()
{
    int tot = miInventory.ContarEnemigos();
    for(int it=0;it<tot;it++)
    {
        if((miInventory.getEnemigos()[it])->collidesWithItem(ball))
            return true;
    }
    return false;
}
int MainWindow::PosColi()
{
    int tot = miInventory.ContarEnemigos();
    int pos;
    for(int it=0;it<tot;it++)
    {
        if((miInventory.getEnemigos()[it])->collidesWithItem(ball))
        {
            pos = it-tot;
            return pos;
        }
    }
    return false;
}
void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_D)
    {
        if(EvaluarColision())
        {
           ball->MoveLeft();
           Scene2->removeItem(miInventory.getEnemigos()[PosColi()]);
        }
        else
           ball->MoveRight();

    }
    else if(evento->key()==Qt::Key_A)
     {
        if(EvaluarColision())
        {
            ball->MoveRight();
            Scene2->removeItem(miInventory.getEnemigos()[PosColi()]);
        }
        else
            ball->MoveLeft();
     }
    else if(evento->key()==Qt::Key_W)
    {
      if(EvaluarColision())
      {
            ball->MoveDown();
            Scene2->removeItem(miInventory.getEnemigos()[PosColi()]);
      }
        else
            ball->MoveUp();
    }
    else if(evento->key()==Qt::Key_S)
    {
        if(EvaluarColision())
        {
            ball->MoveUp();
            Scene2->removeItem(miInventory.getEnemigos()[PosColi()]);
        }
        else
           ball->MoveDown();

    }

}


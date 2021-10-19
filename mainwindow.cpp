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
    Scene = new QGraphicsScene;
    Scene2 = new QGraphicsScene;
    ui->graphicsView->setScene(Scene);
    Scene->setSceneRect(-400,-450,800,810);
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    labeludo = new QLabel(stringo,this);
    labeludo->setGeometry(20,900,900,70);
    labeludo->setFont(QFont("Comic Sans MS", 20));
    entra = 0;
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
    ifstream archivo("usuarioycontra.txt");
    string linea;
    archivo.open("usuarioycontra.txt",ios::app);
    int repe = 0;
    enemigo = new Enemigo(0,0,2000);
    Scene->addItem(enemigo);
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
       if (campos[0] == usu)
       {
          labeludo->setText("Bienvenido");
          repe = 1;

       }
       else
       {
         labeludo->setText("Error");
       }

    }
    archivo.close();
    if (repe == 1)
    {
        entra = 1;
        ofstream filep;
        ifstream in_file;
        filep.open("entra.txt",ios::app);
        filep<<"1"<<endl;
    }


}




void MainWindow::Mover()
{
    int tot = miInventario.ContarCuerpos();
    for (int p = 0; p<tot;p++)
      {
          int acex = 0;
          int acey = 0;
          for (int k = 0; k<tot;k++)
          {
            if (p == k)
            {

            }
            else
            {
               int xr = acelerax(miInventario.getCuerpos()[k]->getMasa(),miInventario.getCuerpos()[p]->getPosx(),miInventario.getCuerpos()[k]->getPosx(),miInventario.getCuerpos()[p]->getPosy(),miInventario.getCuerpos()[k]->getPosy());
               int xy = aceleray(miInventario.getCuerpos()[k]->getMasa(),miInventario.getCuerpos()[p]->getPosx(),miInventario.getCuerpos()[k]->getPosx(),miInventario.getCuerpos()[p]->getPosy(),miInventario.getCuerpos()[k]->getPosy());
               acex += xr;
               acey += xy;
            }
          }
          miInventario.getCuerpos()[p]->SetAceleracionx(acex);
          miInventario.getCuerpos()[p]->SetAceleraciony(acey);
      }
    for(int plopi = 0;plopi<tot;plopi++)
    {
        miInventario.getCuerpos()[plopi]->CalcularVelocidad();
        miInventario.getCuerpos()[plopi]->CalcularPosicion();
        miInventory.getCorpus()[plopi]->Mover(miInventario.getCuerpos()[plopi]->getPosx(),miInventario.getCuerpos()[plopi]->getPosy());

    }
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
       if (campos[0] == usu)
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
        filep<<usu<<";"<<contra<<";"<<"1"<<endl;
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
        ui->graphicsView->setScene(Scene2);
        Scene2->setSceneRect(-400,-450,800,810);
        enemigo = new Enemigo(0,0,20);
        Scene2->addItem(enemigo);
        paredes.push_back(new pared(0,0,600,10));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(0,200,600,10));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(0,0,10,150));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(0,130,10,150));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(300,0,10,150));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(300,130,10,150));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(0,70,130,10));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(0,130,130,10));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(240,130,130,10));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(240,70,130,10));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(150,0,10,90));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(30,25,60,40));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(90,25,60,40));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(190,25,60,40));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(245,25,60,40));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(125,120,110,10));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(122,100,10,50));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(179,100,10,50));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(125,155,100,10));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(150,155,10,50));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(200,175,100,10));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(200,155,10,50));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(47,175,100,10));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(97,155,10,50));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(125,70,120,10));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(151,70,10,50));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(90,90,10,55));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(210,90,10,55));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(60,70,10,120));
        Scene2->addItem(paredes.back());
        paredes.push_back(new pared(240,70,10,120));
        Scene2->addItem(paredes.back());
    }
    else
    {
        labeludo->setText("Debes iniciar sesión primero");
    }

}


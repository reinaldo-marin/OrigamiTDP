#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <movimiento.h>
#include <inventario.h>
#include <bala.h>
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
    timerbala=  new QTimer;
    Scene = new QGraphicsScene;
    Scene2 = new QGraphicsScene;
    ui->graphicsView->setScene(Scene);
    Scene->setSceneRect(-400,-450,800,810);
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(Control_Enemigos1()));
    connect(timerbala,SIGNAL(timeout()),this,SLOT(MoverBala()));
    labeludo = new QLabel(stringo,this);
    labeludo->setGeometry(20,900,900,70);
    labeludo->setFont(QFont("Comic Sans MS", 20));
    stringp = " ";
    puntaje = new QLabel(stringp,this);
    puntaje->setGeometry(1020,800,900,70);
    puntaje->setFont(QFont("Comic Sans MS", 20));
    entra = 0;
    ball = new Jugador(400,600,60);
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
    int xr = rand()%(800-90);
    int xy = rand()%(600-200);
    enemigous.push_back(new Enemigo(xr,xy,100));
    Scene2->addItem(enemigous.back());
    movimiento= new Movimiento(xr,xy,50);


    if(miInventario.AgregarCuerpo(movimiento))
    {

    }
    conta++;

}


void MainWindow::Mover()
{
    QList<Enemigo*>::Iterator it;
    int s = 0;
    for(it=enemigous.begin();it!=enemigous.end();it++)
    {
        miInventario.getCuerpos()[s]->SetPosi(miInventario.getCuerpos()[s]->getPosx(),miInventario.getCuerpos()[s]->getPosy()-20);
        (*it)->Mover(miInventario.getCuerpos()[s]->getPosx(),miInventario.getCuerpos()[s]->getPosy());
        s++;
    }
}
void MainWindow::MoverBala()
{
    QList<Bala*>::Iterator it;
    int s = 0;
    for(it=balas.begin();it!=balas.end();it++)
    {
        miInventario.getBalas()[s]->SetPosi(miInventario.getBalas()[s]->getPosx(),miInventario.getBalas()[s]->getPosy()-10);
        (*it)->Mover(miInventario.getBalas()[s]->getPosx(),miInventario.getBalas()[s]->getPosy()*-1);
        s++;
    }
    if(EvaluarBala() && balas.at(PosBalin())->scene() != NULL)
    {
        Scene2->removeItem(enemigous.at(PosBala()));
        Scene2->removeItem(balas.at(PosBalin()));
        contador+=100;
        puntaje->setText(QString::number(contador));
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
        puntaje->setText(QString::number(contador));
        timer2->start(3000);
        timer->start(1000);
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
    QList<Enemigo*>::Iterator it;
    for(it=enemigous.begin();it!=enemigous.end();it++)
    {
        if((*it)->collidesWithItem(ball) or (ball)->collidesWithItem(*it))
            return true;
    }
    return false;
}
bool MainWindow::EvaluarBala()
{
    QList<Bala*>::Iterator it;
    QList<Enemigo*>::Iterator enes;
    for(it=balas.begin();it!=balas.end();it++)
    {
        for(enes=enemigous.begin();enes!=enemigous.end();enes++)
        {
            if((*it)->collidesWithItem(*enes) or (*enes)->collidesWithItem(*it))
                return true;
        }

    }
    return false;
}
int MainWindow::PosBala()
{
    QList<Bala*>::Iterator it;
    QList<Enemigo*>::Iterator enes;
    int pos;
    for(it=balas.begin();it!=balas.end();it++)
    {
        for(enes=enemigous.begin();enes!=enemigous.end();enes++)
        {
            if((*it)->collidesWithItem(*enes) or (*enes)->collidesWithItem(*it))
            {
                pos = enes-enemigous.begin();
                return pos;
            }

        }

    }

}
int MainWindow::PosBalin()
{
    QList<Bala*>::Iterator it;
    QList<Enemigo*>::Iterator enes;
    int pos;
    for(it=balas.begin();it!=balas.end();it++)
    {
        for(enes=enemigous.begin();enes!=enemigous.end();enes++)
        {
            if((*it)->collidesWithItem(*enes) or (*enes)->collidesWithItem(*it))
            {
                pos = it-balas.begin();
                return pos;
            }

        }

    }

}
int MainWindow::PosColi()
{
    QList<Enemigo*>::Iterator it;
    int pos;
    for(it=enemigous.begin();it!=enemigous.end();it++)
    {
        if((*it)->collidesWithItem(ball) or (ball)->collidesWithItem(*it))
        {
            pos = it-enemigous.begin();
            return pos;
        }
    }

}
void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_D)
    {
        if(ball->GetPosx()>800)
        {
          ball->SetPos(ball->GetPosx()-20,ball->GetPosy());
        }
        if(EvaluarColision() && enemigous.at(PosColi())->scene() != NULL)
        {
           ball->SetPos(ball->GetPosx()-20,ball->GetPosy());
           Scene2->removeItem(enemigous.at(PosColi()));
           contador-=100;
           puntaje->setText(QString::number(contador));
        }
        else
           ball->MoveRight();

    }
    else if(evento->key()==Qt::Key_A)
     {
        if(ball->GetPosx()<50)
        {
           ball->SetPos(ball->GetPosx()+20,ball->GetPosy());
        }
        if(EvaluarColision() && enemigous.at(PosColi())->scene() != NULL)
        {
            ball->SetPos(ball->GetPosx()+20,ball->GetPosy());
            Scene2->removeItem(enemigous.at(PosColi()));
            contador-=100;
            puntaje->setText(QString::number(contador));
        }
        else
            ball->MoveLeft();
     }
    else if(evento->key()==Qt::Key_W)
    {
      if(ball->GetPosy()<200)
      {
          ball->SetPos(ball->GetPosx(),ball->GetPosy()-20);
      }
      if(EvaluarColision() && enemigous.at(PosColi())->scene() != NULL)
      {
            ball->SetPos(ball->GetPosx(),ball->GetPosy()-20);
            Scene2->removeItem(enemigous.at(PosColi()));
            contador-=100;
            puntaje->setText(QString::number(contador));
      }
        else
            ball->MoveUp();
    }
    else if(evento->key()==Qt::Key_S)
    {
        if(ball->GetPosy()>600)
        {
            ball->SetPos(ball->GetPosx(),ball->GetPosy()+20);
        }
        if(EvaluarColision() && enemigous.at(PosColi())->scene() != NULL)
        {
            ball->SetPos(ball->GetPosx(),ball->GetPosy()+20);
            Scene2->removeItem(enemigous.at(PosColi()));
            contador-=100;
            puntaje->setText(QString::number(contador));
        }
        else
           ball->MoveDown();

    }
    else if(evento->key()==Qt::Key_G)
     {
        balas.push_back(new Bala(ball->GetPosx(),ball->GetPosy()-100,25));
        Scene2->addItem(balas.back());
        movimientob = new Movimiento(ball->GetPosx(),ball->GetPosy()-100,25);
        if(miInventario.AgregarBalas(movimientob))
        {

        }
        timerbala->start(50);

     }

}


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
    timerhp=  new QTimer;
    timer2=  new QTimer;
    timerv=  new QTimer;
    timer2v=  new QTimer;
    timerfondo=  new QTimer;
    timerbala=  new QTimer;
    Scene = new QGraphicsScene;
    Scene2 = new QGraphicsScene;
    Scene3 = new QGraphicsScene;
    Scene4 = new QGraphicsScene;
    fondo = new Fondo(300,-900,300);
    fondo2 = new Fondo(-100,-150,301);
    fondo3 = new Fondo(50,0,302);
    fondo4 = new Fondo(-95,-150,303);
    ui->graphicsView->setScene(Scene);
    ui->graphicsView_2->setScene(Scene3);
    Scene->setSceneRect(-400,-450,800,810);
    Scene4->setSceneRect(-400,-450,800,810);
    Scene4->addItem(fondo4);
    Scene3->setSceneRect(0,0,400,300);
    Scene->addItem(fondo2);
    Scene3->addItem(fondo3);
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    connect(timerhp,SIGNAL(timeout()),this,SLOT(JugadorHP()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(Control_Enemigos1()));
    connect(timerv,SIGNAL(timeout()),this,SLOT(MoverViento()));
    connect(timer2v,SIGNAL(timeout()),this,SLOT(Control_Vientos()));
    connect(timerfondo,SIGNAL(timeout()),this,SLOT(MoverFondo()));
    connect(timerbala,SIGNAL(timeout()),this,SLOT(MoverBala()));
    labeludo = new QLabel(stringo,this);
    labeludo->setGeometry(20,900,900,70);
    labeludo->setFont(QFont("Comic Sans MS", 20));
    stringp = " ";
    puntaje = new QLabel(stringp,this);
    puntaje->setGeometry(1020,800,900,70);
    puntaje->setFont(QFont("Comic Sans MS", 20));
    entra = 0;
    ball = new Jugador(300,600,60);
    ball2 = new Jugador(500,600,61);
    barra = new Barra(15,700,5);
    barra2 = new Barra(500,700,6);

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
    int xr = rand()%(800-160);
    int xy = rand()%(600-100);
    enemigous.push_back(new Enemigo(xr,xy,100));
    Scene2->addItem(enemigous.back());
    movimiento= new Movimiento(xr,xy,50);


    if(miInventario.AgregarCuerpo(movimiento))
    {

    }
    conta++;

}
void MainWindow::Control_Vientos()
{
    int xr = rand()%(800-161);
    int xy = rand()%(600-101);
    vientos.push_back(new Viento(xr,xy,5));
    Scene2->addItem(vientos.back());
    movimiento= new Movimiento(xr,xy,5);


    if(miInventario.AgregarVientos(movimiento))
    {

    }
    conta++;

}
void MainWindow::MoverViento()
{
    QList<Viento*>::Iterator it;
    int s = 0;
    for(it=vientos.begin();it!=vientos.end();it++)
    {
        miInventario.getVientos()[s]->SetPosi(miInventario.getVientos()[s]->getPosx(),miInventario.getVientos()[s]->getPosy()-60);
        (*it)->Mover(miInventario.getVientos()[s]->getPosx(),miInventario.getVientos()[s]->getPosy());
        s++;
    }
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

void MainWindow::JugadorHP()
{
    ball->SetViento(ball->GetViento()-1);
    barra->Setxy(barra->GetPosx()-16,barra->GetPosy());
    barra->Mover(barra->GetPosx(),barra->GetPosy());
    ball->SetVelocidad(ball->GetVelocidad()-1);
    if (njugadores==2)
    {
        ball2->SetViento(ball2->GetViento()-1);
        barra2->Setxy(barra2->GetPosx()+16,barra2->GetPosy());
        barra2->Mover(barra2->GetPosx(),barra2->GetPosy());
        ball2->SetVelocidad(ball2->GetVelocidad()-1);
    }
    if (ball->GetViento()==0 and restantes>0)
    {
        Scene2->removeItem(ball);
        restantes -= 1;
    }
    if (njugadores==2 and ball2->GetViento()==0)
    {
        Scene2->removeItem(ball2);
        restantes -= 1;
    }
    if(restantes == 0)
    {
      ui->graphicsView->setScene(Scene4);
    }
}

void MainWindow::MoverFondo()
{
    fondo->Setxy(fondo->GetPosx(),fondo->GetPosy()+3);
    fondo->Mover(fondo->GetPosx(),fondo->GetPosy());
    if (fondo->GetPosy()>200)
    {
        fondo->Setxy(fondo->GetPosx(),-900);
        fondo->Mover(fondo->GetPosx(),fondo->GetPosy());
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
        filep<<"0"<<endl;
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
        labeludo->setText("¡Elimina tantos demonios como puedas!");
        Scene2->addItem(fondo);
        puntaje->setText(QString::number(contador));
        timerfondo->start(100);
        timer2->start(3000);
        timer->start(1000);
        timerv->start(1000);
        timerhp->start(1000);
        ui->graphicsView->setScene(Scene2);
        Scene2->setSceneRect(0,0,800,810);
        Scene2->addItem(ball);
        Scene2->addItem(barra);
        restantes = 1;
        if (njugadores==2)
        {
           restantes = 2;
           Scene2->addItem(ball2);
           Scene2->addItem(barra2);
           timer2v->start(4500);
        }
        else
        {
            timer2v->start(9000);
        }

    }
    else
    {
        labeludo->setText("Debes iniciar sesión primero");
    }

}
bool MainWindow::EvaluarColision(Jugador *bola)
{
    QList<Enemigo*>::Iterator it;
    for(it=enemigous.begin();it!=enemigous.end();it++)
    {
        if((*it)->collidesWithItem(bola) or (bola)->collidesWithItem(*it))
            return true;
    }
    return false;
}
bool MainWindow::EvaluarViento(Jugador *bola)
{
    QList<Viento*>::Iterator it;
    for(it=vientos.begin();it!=vientos.end();it++)
    {
        if((*it)->collidesWithItem(bola) or (bola)->collidesWithItem(*it))
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
int MainWindow::PosColi(Jugador *bola)
{
    QList<Enemigo*>::Iterator it;
    int pos;
    for(it=enemigous.begin();it!=enemigous.end();it++)
    {
        if((*it)->collidesWithItem(bola) or (bola)->collidesWithItem(*it))
        {
            pos = it-enemigous.begin();
            return pos;
        }
    }

}
int MainWindow::PosViento(Jugador *bola)
{
    QList<Viento*>::Iterator it;
    int pos;
    for(it=vientos.begin();it!=vientos.end();it++)
    {
        if((*it)->collidesWithItem(bola) or (bola)->collidesWithItem(*it))
        {
            pos = it-vientos.begin();
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
        if(EvaluarColision(ball) && enemigous.at(PosColi(ball))->scene() != NULL)
        {
           ball->SetPos(ball->GetPosx()-20,ball->GetPosy());
           Scene2->removeItem(enemigous.at(PosColi(ball)));
           contador-=100;
           puntaje->setText(QString::number(contador));
        }
        if(EvaluarViento(ball) && vientos.at(PosViento(ball))->scene() != NULL)
        {
           Scene2->removeItem(vientos.at(PosViento(ball)));
           ball->SetViento(10);
           ball->SetVelocidad(30);
           barra->Setxy(15,700);
           barra->Mover(barra->GetPosx(),barra->GetPosy());
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
        if(EvaluarColision(ball) && enemigous.at(PosColi(ball))->scene() != NULL)
        {
            ball->SetPos(ball->GetPosx()+20,ball->GetPosy());
            Scene2->removeItem(enemigous.at(PosColi(ball)));
            contador-=100;
            puntaje->setText(QString::number(contador));
        }
        if(EvaluarViento(ball) && vientos.at(PosViento(ball))->scene() != NULL)
        {
           Scene2->removeItem(vientos.at(PosViento(ball)));
           ball->SetViento(10);
           ball->SetVelocidad(30);
           barra->Setxy(15,700);
           barra->Mover(barra->GetPosx(),barra->GetPosy());
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
      if(EvaluarColision(ball) && enemigous.at(PosColi(ball))->scene() != NULL)
      {
            ball->SetPos(ball->GetPosx(),ball->GetPosy()-20);
            Scene2->removeItem(enemigous.at(PosColi(ball)));
            contador-=100;
            puntaje->setText(QString::number(contador));
      }
      if(EvaluarViento(ball) && vientos.at(PosViento(ball))->scene() != NULL)
      {
         Scene2->removeItem(vientos.at(PosViento(ball)));
         ball->SetViento(10);
         ball->SetVelocidad(30);
         barra->Setxy(15,700);
         barra->Mover(barra->GetPosx(),barra->GetPosy());
      }
        else
            ball->MoveUp();
    }
    else if(evento->key()==Qt::Key_S)
    {
        if(ball->GetPosy()>500)
        {
            ball->SetPos(ball->GetPosx(),ball->GetPosy()-20);
        }
        if(EvaluarColision(ball) && enemigous.at(PosColi(ball))->scene() != NULL)
        {
            ball->SetPos(ball->GetPosx(),ball->GetPosy()+20);
            Scene2->removeItem(enemigous.at(PosColi(ball)));
            contador-=100;
            puntaje->setText(QString::number(contador));
        }
        if(EvaluarViento(ball) && vientos.at(PosViento(ball))->scene() != NULL)
        {
           Scene2->removeItem(vientos.at(PosViento(ball)));
           ball->SetViento(10);
           ball->SetVelocidad(30);
           barra->Setxy(15,700);
           barra->Mover(barra->GetPosx(),barra->GetPosy());
        }
        else
           ball->MoveDown();

    }
    else if(evento->key()==Qt::Key_R)
     {
        balas.push_back(new Bala(ball->GetPosx(),ball->GetPosy()-100,25));
        Scene2->addItem(balas.back());
        movimientob = new Movimiento(ball->GetPosx(),ball->GetPosy()-100,25);
        if(miInventario.AgregarBalas(movimientob))
        {

        }
        timerbala->start(50);

     }
    if(evento->key()==Qt::Key_L)
    {
        if(ball2->GetPosx()>800)
        {
          ball2->SetPos(ball2->GetPosx()-20,ball2->GetPosy());
        }
        if(EvaluarColision(ball2) && enemigous.at(PosColi(ball2))->scene() != NULL)
        {
           ball2->SetPos(ball2->GetPosx()-20,ball2->GetPosy());
           Scene2->removeItem(enemigous.at(PosColi(ball2)));
           contador-=100;
           puntaje->setText(QString::number(contador));
        }
        if(EvaluarViento(ball2) && vientos.at(PosViento(ball2))->scene() != NULL)
        {
           Scene2->removeItem(vientos.at(PosViento(ball2)));
           ball2->SetViento(10);
           ball2->SetVelocidad(30);
           ball->SetVelocidad(30);
           barra2->Setxy(500,700);
           barra2->Mover(barra2->GetPosx(),barra2->GetPosy());
        }
        else
           ball2->MoveRight();

    }
    else if(evento->key()==Qt::Key_J)
     {
        if(ball2->GetPosx()<50)
        {
           ball2->SetPos(ball2->GetPosx()+20,ball2->GetPosy());
        }
        if(EvaluarColision(ball2) && enemigous.at(PosColi(ball2))->scene() != NULL)
        {
            ball2->SetPos(ball2->GetPosx()+20,ball2->GetPosy());
            Scene2->removeItem(enemigous.at(PosColi(ball2)));
            contador-=100;
            puntaje->setText(QString::number(contador));
        }
        if(EvaluarViento(ball2) && vientos.at(PosViento(ball2))->scene() != NULL)
        {
           Scene2->removeItem(vientos.at(PosViento(ball2)));
           ball2->SetViento(10);
           ball2->SetVelocidad(30);
           barra2->Setxy(500,700);
           barra2->Mover(barra2->GetPosx(),barra2->GetPosy());
        }
        else
            ball2->MoveLeft();
     }
    else if(evento->key()==Qt::Key_I)
    {
      if(ball2->GetPosy()<200)
      {
          ball2->SetPos(ball2->GetPosx(),ball2->GetPosy()-20);
      }
      if(EvaluarColision(ball2) && enemigous.at(PosColi(ball2))->scene() != NULL)
      {
            ball2->SetPos(ball2->GetPosx(),ball2->GetPosy()-20);
            Scene2->removeItem(enemigous.at(PosColi(ball2)));
            contador-=100;
            puntaje->setText(QString::number(contador));
      }
      if(EvaluarViento(ball2) && vientos.at(PosViento(ball2))->scene() != NULL)
      {
         Scene2->removeItem(vientos.at(PosViento(ball2)));
         ball2->SetViento(10);
         ball2->SetVelocidad(30);
         barra2->Setxy(500,700);
         barra2->Mover(barra2->GetPosx(),barra2->GetPosy());
      }
        else
            ball2->MoveUp();
    }
    else if(evento->key()==Qt::Key_K)
    {
        if(ball2->GetPosy()>600)
        {
            ball2->SetPos(ball2->GetPosx(),ball2->GetPosy()+20);
        }
        if(EvaluarColision(ball2) && enemigous.at(PosColi(ball2))->scene() != NULL)
        {
            ball2->SetPos(ball2->GetPosx(),ball2->GetPosy()+20);
            Scene2->removeItem(enemigous.at(PosColi(ball)));
            contador-=100;
            puntaje->setText(QString::number(contador));
        }
        if(EvaluarViento(ball2) && vientos.at(PosViento(ball2))->scene() != NULL)
        {
           Scene2->removeItem(vientos.at(PosViento(ball2)));
           ball2->SetViento(10);
           ball2->SetVelocidad(30);
           barra2->Setxy(500,700);
           barra2->Mover(barra2->GetPosx(),barra2->GetPosy());
        }
        else
           ball2->MoveDown();

    }
    else if(evento->key()==Qt::Key_P)
     {
        balas.push_back(new Bala(ball2->GetPosx(),ball2->GetPosy()-100,25));
        Scene2->addItem(balas.back());
        movimientob = new Movimiento(ball2->GetPosx(),ball2->GetPosy()-100,25);
        if(miInventario.AgregarBalas(movimientob))
        {

        }
        timerbala->start(50);

     }

}


void MainWindow::on_radioButton_toggled(bool checked)
{
    labeludo->setText("Jugador 2 añadido");
    njugadores=2;
}


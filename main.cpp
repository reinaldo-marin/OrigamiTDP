
#include "mainwindow.h"

#include <QApplication>
#include <vector>
#include <iostream>
#include<fstream>
#include <movimiento.h>
#include <inventario.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

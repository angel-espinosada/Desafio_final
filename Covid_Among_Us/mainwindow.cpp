#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include<QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Among Us Covid_19");

     portada = new QGraphicsScene(this);
    ui->graphicsView->setScene(portada);

portada->setSceneRect(0, 0, 800, 600);


QPixmap bgPixmap(":/imagenes/fondo_principal.png");
    if (bgPixmap.isNull()) {
        qDebug() << "No se pudo cargar la imagen";
    }
QGraphicsPixmapItem *bgItem = portada->addPixmap(bgPixmap);
bgItem->setZValue(-100); // Asegura que quede al fondo


// Botones
crearBoton("Nivel 1", 100, 1);
crearBoton("Nivel 2", 150, 2);
crearBoton("Nivel 3", 200, 3);
crearBoton("Salir",   250, 4);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crearBoton(const QString &texto, int y, int nivel)
{
    // Rectángulo del botón
        QGraphicsRectItem *rect = new QGraphicsRectItem(150, y, 300, 60);
    rect->setBrush(Qt::red);
    rect->setPen(QPen(Qt::white, 3));
    rect->setData(0, nivel);


    // Texto centrado dentro del rectángulo
    QGraphicsTextItem *label = new QGraphicsTextItem(texto);
    label->setDefaultTextColor(Qt::white);
    label->setFont(QFont("Arial", 22));


    // Posición ABSOLUTA: dentro del rectángulo
    double anchotexto=label->boundingRect().width();
    double altotexto=label->boundingRect().height();
    double xcentro=150+(300/2)-(anchotexto/2);
    double ycentro= y+(60/2)-(altotexto/2);
    label->setPos(xcentro,ycentro);
    label->setZValue(1);;

    //Añadir directamente a la escena
    portada->addItem(rect);
    portada->addItem(label);
}

void MainWindow::Nivel1()
{

}

void MainWindow::Nivel2()
{

}

void MainWindow::salir()
{

}

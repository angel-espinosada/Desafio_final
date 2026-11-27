#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include<QDebug>
#include <QPushbutton>


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

connect(crearBoton("Nivel 1", 100), &QPushButton::clicked, this, &MainWindow::Nivel1);
connect(crearBoton("Nivel 2", 170), &QPushButton::clicked, this, &MainWindow::Nivel2);
connect(crearBoton("Salir",   240), &QPushButton::clicked, this, &MainWindow::salir);

}


MainWindow::~MainWindow()
{
    delete ui;
}

QPushButton *MainWindow::crearboton(const QString &texto, int y)
{
    QPushButton *botn= new QPushButton(texto);
    botn->setGeometry(150, y,300, 60);
    botn->setStyleSheet("background-color: red; color: white;"
                        "border: 3px solid white; font: 22pt 'Arial';");
    portada->addWidget(botn);
    return botn;
}

/*
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
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
class QGraphicsScene;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *portada = nullptr;
    QPushButton* crearBoton(const QString &texto, int y);

private slots:
    void Nivel1();
    void Nivel2();
    void salir();


};
#endif // MAINWINDOW_H

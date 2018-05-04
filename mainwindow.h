#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "headers.h"
#include <QMainWindow>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QLineEdit* LE_COM;
    QLineEdit* LE_speed;
    float speed;
    bool subm;
    Serial hSerial;
    int readVar;
    void mousePressEvent(QMouseEvent *);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //    paintEvent(QPaintEvent*);
    void mainCircle();

private:
protected:
     void paintEvent(QPaintEvent *e);
public slots:
     void setSpeed();
     void waitCOM_Subm();
     void send();
     void drawing();

};

#endif // MainWindow_H

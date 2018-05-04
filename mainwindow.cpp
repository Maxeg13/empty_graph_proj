#include "MainWindow.h"
#include <QTimer>
#include<QDebug>
#include "serial.h"
#include <QMouseEvent>


//#include "vars.h"
int bufShowSize=3000;
int nodes_N=340;
int lines_N=5;
float f;
Serial hSerial;

QTimer *timer;
QString qstr;
//work* WK;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    LE_COM=new QLineEdit;
    LE_speed=new QLineEdit;
    LE_speed->setText(QString("Fluid flow [mkl/sec]: 100"));

    qstr=QString("COM5");
    LE_COM->setText(qstr);

    int frame_width=4;
    QGridLayout* GL=new QGridLayout();
    GL->addWidget(LE_COM,0/frame_width,0%frame_width);
    GL->addWidget(LE_speed,0,1);

    QWidget *centralWidget1=new QWidget();
    centralWidget1->setLayout(GL);
    setCentralWidget(centralWidget1);


    timer=new QTimer(this);

    connect(LE_speed,SIGNAL(returnPressed()),this,SLOT(setSpeed()));
    connect(LE_COM,SIGNAL(returnPressed()),this,SLOT(waitCOM_Subm()));
    timer->start(100);
    this->update();

    setSpeed();
}

void MainWindow::drawing()
{
    this->update();
}

void MainWindow::setSpeed()
{
    speed=LE_speed->text().remove(0,21).toFloat();

}

void MainWindow::waitCOM_Subm()
{
    std::string str1=qstr.toUtf8().constData();
    std::wstring str(str1.begin(),str1.end());
    hSerial.InitCOM(str.c_str());//was L"COM5"

    connect(timer, SIGNAL(timeout()), this, SLOT(send()));
}

void MainWindow::send()
{
    uint8_t speedU=speed;
    qDebug()<<speedU;
    hSerial.write(speedU);
}

void MainWindow::mousePressEvent(QMouseEvent *)
{

}

//void MainWindow::mainCircLE_COM()
//{



//}

void MainWindow::paintEvent(QPaintEvent* e)
{
//    static float t=1;
//    t+=.06;
//    if(t>10)t=10;
//    for (int i=0;i<t;i++)
//        mainCircLE_COM();

//    QPainter* painter=new QPainter(this);
//    painter->setRenderHint(QPainter::Antialiasing, 1);
//    QPen pen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
//    painter->setPen(pen);
//    painter->scaLE_COM(1.5,1.5);



//    deLE_COMte painter;
}

MainWindow::~MainWindow()
{

}

#include "dialog.h"
#include <QPainter>
#include <QTimer>
#include <QThread>
#include<QDebug>
//#include "work.h"


#include <QMouseEvent>
//#include "vars.h"
int nodes_N=340;
int lines_N=5;
float f;
QTimer *timer;
//work* WK;



Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(drawing()));
    timer->start(40);
    this->update();
    //    QThread* thread = new QThread( );
    //    WK=new work();
    //    WK->moveToThread(thread);
    //    connect(thread,SIGNAL(started()),WK,SLOT(doWork()));
    //    thread->start();

}

void Dialog::drawing()
{
    this->update();
}

void Dialog::mousePressEvent(QMouseEvent *)
{

}

void Dialog::mainCircle()
{



}

void Dialog::paintEvent(QPaintEvent* e)
{
    static float t=1;
    t+=.06;
    if(t>10)t=10;
    for (int i=0;i<t;i++)
        mainCircle();

    QPainter* painter=new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing, 1);
    QPen pen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter->setPen(pen);
    painter->scale(1.5,1.5);

//    for(int j=0;j<lines_N;j++)
//        painter->drawLine(ML[j].x[0],ML[j].y[0],ML[j].x[1],ML[j].y[1]);

//    pen=QPen(Qt::black, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);


//    for(int j=0;j<nodes_N;j++)
//    {
//        pen.setColor(QColor(_node[j].clr[0],_node[j].clr[1],_node[j].clr[2]));
//        painter->setPen(pen);
//        painter->drawPoint(_node[j].x,_node[j].y);
//    }
    delete painter;
}

Dialog::~Dialog()
{

}

void Dialog::drawingInit(QwtPlot* d_plot, QString title)
{

    //        setCentralWidget(MW);

    //canvas().resize(925,342)
    //    d_plot->canvas()->resize(100,150);
    //d_plot->autoRefresh();
    d_plot->setAutoReplot();
    //_______232

    // настройка функций
    QwtPlotPicker *d_picker =
            new QwtPlotPicker(
                QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
                QwtPlotPicker::CrossRubberBand, // стиль перпендикулярных линий
                QwtPicker::ActiveOnly, // включение/выключение
                d_plot->canvas() ); // ассоциация с полем
    // Цвет перпендикулярных линий
    d_picker->setRubberBandPen( QColor( Qt::red ) );

    // цвет координат положения указателя
    d_picker->setTrackerPen( QColor( Qt::black ) );

    // непосредственное включение вышеописанных функций
    d_picker->setStateMachine( new QwtPickerDragPointMachine() );

    // Включить возможность приближения/удаления графика
    // #include <qwt_plot_magnifier.h>
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(d_plot->canvas());
    // клавиша, активирующая приближение/удаление
    magnifier->setMouseButton(Qt::MidButton);
    // Включить возможность перемещения по графику
    // #include <qwt_plot_panner.h>
    QwtPlotPanner *d_panner = new QwtPlotPanner( d_plot->canvas() );
    // клавиша, активирующая перемещение
    d_panner->setMouseButton( Qt::RightButton );
    // Включить отображение координат курсора и двух перпендикулярных
    // линий в месте его отображения

    QwtText* qwtt=new QwtText(title);
    qwtt->setFont(QFont("Helvetica", 11,QFont::Normal));

    d_plot->setAxisScale(1,-500,500,200);
    d_plot->setTitle( *qwtt ); // заголовок
    d_plot->setCanvasBackground( Qt::white ); // цвет фона


    // Включить сетку
    // #include <qwt_plot_grid.h>
    //    QwtPlotGrid *grid = new QwtPlotGrid(); //

    //    grid->setMajorPen(QPen( Qt::gray, 2 )); // цвет линий и толщина
    //    grid->attach( d_plot ); // добавить сетку к полю графика


    d_plot->setMinimumSize(150,140);

}

#ifndef DIALOG_H
#define DIALOG_H
#include "headers.h"
#include <QDialog>



class Dialog : public QDialog
{
    Q_OBJECT

public:
    void drawingInit(QwtPlot* d_plot, QString title);
    void mousePressEvent(QMouseEvent *);
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    //    paintEvent(QPaintEvent*);
    void mainCircle();
private:
protected:
     void paintEvent(QPaintEvent *e);
public slots:
     void drawing();

};

#endif // DIALOG_H

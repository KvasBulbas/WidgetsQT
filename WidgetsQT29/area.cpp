#include "area.h"
#include<QTimerEvent>
#include <iostream>

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200));
    myline=new MyLine(80,100,50);
    myrect=new MyRect(220,100,50);
    alpha=0;
    std::cout<< "create area" << std::endl;
}
void Area::showEvent(QShowEvent *)
{
    std::cout << "showEvent"<< std::endl;
    myTimer=startTimer(50); // создать таймер

}
void Area::paintEvent(QPaintEvent *)
{
    std::cout << "paintEevent"<< std::endl;
    QPainter painter(this);
    painter.setPen(Qt::red);
    myline->move(alpha,&painter);
    myrect->move(alpha*(-0.5),&painter);

}
void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha=alpha+0.2;
        update(); // обновить внешний вид
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной
    // обработки
    std::cout << "timerEvent"<< std::endl;
}
void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer); // уничтожить таймер
    std::cout << "killTimer" << std::endl;
}
Area::~Area()
{
    delete myline;
    delete myrect;
}


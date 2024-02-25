#include "widget.h"
#include <QTextCodec>
#include <QPushButton>
#include <QVBoxLayout>

Widget::Widget()
{

    this->setWindowTitle("Обработка событий");
    area = new Area(this );
    btn = new QPushButton("Завершить",this );
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
};

Widget::~Widget()
{
}


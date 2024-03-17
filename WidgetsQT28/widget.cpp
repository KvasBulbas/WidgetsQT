#include "widget.h"
#include <QTextCodec>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <iostream>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Счетчик");
    label1 = new QLabel("Cчет по 1",this);
    label2 = new QLabel("Cчет по 5",this);
    edit1 = new Counter("0",this);
    edit2 = new Counter("0",this);
    calcbutton=new QPushButton("+1",this);
    exitbutton=new QPushButton("Выход",this);

    QHBoxLayout *layout1 = nullptr;
    QHBoxLayout *layout2 = new QHBoxLayout();
    QHBoxLayout *layout3 = new QHBoxLayout();
    QVBoxLayout *layout4 = new QVBoxLayout(this);
    if(layout1 != nullptr && layout2 != nullptr && layout3 != nullptr && layout4 != nullptr)
    {
        layout1->addWidget(label1);
        layout1->addWidget(label2);
        layout2->addWidget(edit1);
        layout2->addWidget(edit2);
        layout3->addWidget(calcbutton);
        layout3->addWidget(exitbutton);
        layout4->addLayout(layout1);
        layout4->addLayout(layout2);
        layout4->addLayout(layout3);
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Information,
                           ("Компиляция."),
                           ("Не выделена память под менеджер компановки"),
                           QMessageBox::Ok);
        msgBox.exec();
    }

    // связь сигнала нажатия кнопки и слота закрытия окна
    connect(calcbutton,QPushButton::clicked, edit1, Counter::add_one);
    connect(edit1,Counter::tick_signal, edit2,Counter::add_one);
    connect(exitbutton,QPushButton::clicked, this, QWidget::close);



}




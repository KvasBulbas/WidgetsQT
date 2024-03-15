#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <iostream>
#include <limits>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    codec = QTextCodec::codecForName("Windows-1251");
    setWindowTitle(codec->toUnicode("Squaring"));
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);
    inputLabel = new QLabel(codec->toUnicode("Enter a number:"),
                            this);
    inputEdit = new QLineEdit("",this);
    StrValidator *v=new StrValidator(inputEdit);
    inputEdit->setValidator(v);
    outputLabel = new QLabel(codec->toUnicode("Result:"),
                             this);
    outputEdit = new QLineEdit("",this);
    nextButton = new QPushButton(codec->toUnicode("Next"),
                                 this);
    exitButton = new QPushButton(codec->toUnicode("Exit"),
                                 this);
    // компоновка приложения выполняется согласно рисунку 2.
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin();
    connect(exitButton,QPushButton::clicked,
            this,QWidget::close);
    connect(nextButton,QPushButton::clicked,
            this,Widget::begin);
    connect(inputEdit,QLineEdit::returnPressed,
            this,Widget::calc);




}

Widget::~Widget()
{
}

void Widget::begin()
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void Widget::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();
    a=str.toDouble(&Ok);

    if (Ok)
    {
        r=a*a;
        if(r <= std::numeric_limits<float>::max())
        {
            str.setNum(r);
            outputEdit->setText(str);
            inputEdit->setEnabled(false);
            outputLabel->setVisible(true);
            outputEdit->setVisible(true);
            nextButton->setDefault(true);
            nextButton->setEnabled(true);
            nextButton->setFocus();
        }
        else
        {
            QMessageBox msgBox(QMessageBox::Information,
                              codec->toUnicode("Squaring."),
                              codec->toUnicode("The number is too high."),
                              QMessageBox::Ok);
            msgBox.exec();
        }
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,
                               codec->toUnicode("Squaring."),
                               codec->toUnicode("Invalid value entered."),
                               QMessageBox::Ok);
            msgBox.exec();
        }
}


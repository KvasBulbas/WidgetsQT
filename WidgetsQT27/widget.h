#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTextCodec>
#include<QFrame>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QValidator>


class Widget : public QWidget
{
    Q_OBJECT
protected:
    QTextCodec *codec;
    QFrame *frame; // рамка
    QLabel *inputLabel; // метка ввода
    QLineEdit *inputEdit; // строчный редактор ввода
    QLabel *outputLabel; // метка вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *nextButton; // кнопка Следующее
    QPushButton *exitButton; // кнопка Выход
public:
    w(QWidget *parent = 0); // конструктор
public slots:
    void begin(); // метод начальной настройки интерфейса
    void calc(); // метод реализации вычислений


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};



class StrValidator:public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent):QValidator(parent){}
    virtual State validate(QString &str,int &pos)const
    {
        return Acceptable; // метод всегда принимает вводимую строку
    }
};


#endif // WIDGET_H

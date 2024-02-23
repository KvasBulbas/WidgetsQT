#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include<QString>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    class Counter:public QLineEdit
    {
        Q_OBJECT
    public:
        Counter(const QString & contents, QWidget *parent=0):
            QLineEdit(contents,parent){}
    signals:
        void tick_signal();
    public slots:
        void add_one()
        {
            QString str=text();
            int r=str.toInt();
            if (r!=0 && r%5 ==0) emit tick_signal();
            r++;
            str.setNum(r);
            setText(str);
        }
    }
};
#endif // WIDGET_H

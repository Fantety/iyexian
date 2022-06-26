#include "actbutton.h"

void ActButton::enterEvent(QEnterEvent *)
{
    this->setCursor(Qt::PointingHandCursor);
    if(this->is_clicked == SELECT) return;
    in_ani->start();
}

void ActButton::leaveEvent(QEvent *)
{
    this->setCursor(Qt::ArrowCursor);
    if(this->is_clicked == SELECT) return;
    out_ani->start();
}

ActButton::ActButton(QWidget* parent,int og_width,int og_height, int width,int height)
{
    this->setFixedSize(og_width,og_height);
    in_ani = new QPropertyAnimation(this,"minimumSize");
    in_ani->setDuration(300);
    in_ani->setKeyValueAt(0,QSize(og_width,og_height));
    in_ani->setKeyValueAt(1,QSize(width,height));
    in_ani->setEasingCurve(QEasingCurve::InOutQuad);

    out_ani = new QPropertyAnimation(this,"minimumSize");
    out_ani->setDuration(300);
    out_ani->setKeyValueAt(0,QSize(width,height));
    out_ani->setKeyValueAt(1,QSize(og_width,og_height));
    out_ani->setEasingCurve(QEasingCurve::InOutQuad);
}

void ActButton::Reduction()
{
    out_ani->start();
}

void ActButton::Change()
{
    in_ani->start();
}

void ActButton::SetStatus(bool status)
{
    this->is_clicked = status;
}

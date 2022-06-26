#ifndef ACTBUTTON_H
#define ACTBUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>

#define SELECT true
#define UNSELECT false

class ActButton : public QPushButton
{
    Q_OBJECT
private:
    bool is_clicked = false;

protected:
    void enterEvent(QEnterEvent *) override;
    void leaveEvent(QEvent *) override;

    QPropertyAnimation* in_ani;
    QPropertyAnimation* out_ani;
public:
    ActButton(QWidget* parent,int og_width,int og_height, int width,int height);
    void Reduction();
    void Change();
    void SetStatus(bool status);
signals:
    void hover();
    void leave();
};

#endif // ACTBUTTON_H

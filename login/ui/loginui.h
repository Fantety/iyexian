#ifndef LOGINUI_H
#define LOGINUI_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QApplication>
#include <QMovie>
#include <QImageReader>
#include <QTimer>
#include <QPixmap>
#include "../../common/component/actbutton.h"
class LoginUI : public QWidget
{
    Q_OBJECT
    QPoint current_wpos, current_mpos, relative_pos;
    QString qss;
    QImageReader* img_reader = new QImageReader;
    QTimer* timer = new QTimer(this);
    int image_size;
    QWidget* bottom_widget = new QWidget(this);

    QLabel* id_label, *passwd_label;
    QLineEdit* id_edit, *passwd_edit;
    QLabel* img;
    QPushButton *close_btn;
    ActButton* login_btn;
    QVBoxLayout* input_layout;
    QHBoxLayout* id_layout, *passwd_layout, *login_layout, *title_layout;
public:
    explicit LoginUI(QWidget *parent = nullptr);

private:
    void initLayout();
    void initObjectName();
    void initSSConnect();
    void initComponent();
    void initComponentStyle();
    void loadQSS();
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

signals:

private slots:
    void changeImg();

};

#endif // LOGINUI_H

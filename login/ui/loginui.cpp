#include "loginui.h"

LoginUI::LoginUI(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setObjectName("login_widget");   
    this->setFixedSize(QSize(490, 300));
    initComponent();
    initObjectName();
    initLayout();
    initSSConnect();
    loadQSS();
    img_reader->setFileName(":/img/img.gif");
    timer->start(25);
}


void LoginUI::initLayout()
{
    id_layout->addWidget(id_label);
    id_layout->addWidget(id_edit);
    id_layout->setSpacing(5);
    passwd_layout->addWidget(passwd_label);
    passwd_layout->addWidget(passwd_edit);
    passwd_layout->setSpacing(5);
    title_layout->addWidget(close_btn,0 ,Qt::AlignRight|Qt::AlignTop);
    title_layout->setSpacing(0);
    title_layout->setContentsMargins(0,0,0,0);
    input_layout->addLayout(title_layout);
    input_layout->addLayout(id_layout);
    input_layout->addLayout(passwd_layout);
    input_layout->addWidget(login_btn, 0, Qt::AlignHCenter);
    input_layout->setContentsMargins(20,10,20,0);
    input_layout->setSpacing(30);
    login_layout->addWidget(img,1);
    login_layout->addLayout(input_layout,2);
    login_layout->setContentsMargins(0,0,0,20);
    bottom_widget->setLayout(login_layout);
}

void LoginUI::initObjectName()
{
    close_btn->setObjectName("login_close_btn");
    img->setObjectName("login_img");
    id_edit->setObjectName("login_id_edit");
    passwd_edit->setObjectName("login_passwd_edit");
    id_label->setObjectName("login_id_label");
    passwd_label->setObjectName("login_passwd_label");
    login_btn->setObjectName("login_btn");
    bottom_widget->setObjectName("login_bottom_widget");
}

void LoginUI::initSSConnect()
{
    connect(close_btn, SIGNAL(clicked()), this, SLOT(close()));
    connect(timer, SIGNAL(timeout()), this, SLOT(changeImg()));
}

void LoginUI::initComponent()
{
    id_label = new QLabel(this);
    passwd_label = new QLabel(this);
    id_edit = new QLineEdit(this);
    passwd_edit = new QLineEdit(this);
    img = new QLabel(this);
    login_btn = new ActButton(this,200,50,230,50);
    close_btn = new QPushButton(this);
    input_layout = new QVBoxLayout;
    id_layout = new QHBoxLayout;
    passwd_layout = new QHBoxLayout;
    login_layout = new QHBoxLayout;
    title_layout = new QHBoxLayout;
    img->setScaledContents(true);
    initComponentStyle();

}

void LoginUI::initComponentStyle()
{
    close_btn->setFixedSize(QSize(40,40));
    close_btn->setIcon(QIcon(":/icon/close.svg"));
    close_btn->setIconSize(QSize(30,30));

    id_edit->setFixedSize(QSize(200,40));
    passwd_edit->setFixedSize(QSize(200,40));

    img->setFixedSize(QSize(200,300));
    id_label->setText(QStringLiteral("工号"));
    passwd_label->setText(QStringLiteral("密码"));
    id_label->setFixedSize(QSize(40,40));
    passwd_label->setFixedSize(QSize(40,40));

    login_btn->setText(QStringLiteral("登    录"));
    bottom_widget->setFixedSize(QSize(490, 300));
}

void LoginUI::loadQSS()
{
    QFile file(":/qss/login.css");
    file.open(QIODevice::ReadOnly);
    if(file.isOpen())
    {
        QString strFile = file.readAll();
        qApp->setStyleSheet(strFile);
        file.close();
    }

}




void LoginUI::mousePressEvent(QMouseEvent *event)
{
    this->current_wpos = this->pos();
    this->current_mpos = event->globalPosition().toPoint();
    this->relative_pos = current_mpos - current_wpos;

}

void LoginUI::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPosition().toPoint() - relative_pos);
}

void LoginUI::changeImg()
{
    if(img_reader->canRead())
    {
        img->setPixmap(QPixmap::fromImage(img_reader->read()));
    }
    img_reader->jumpToNextImage();
    if(img_reader->currentImageNumber() == 149)
    {
        delete img_reader;
        img_reader = new QImageReader(":/img/img.gif");
    }

}

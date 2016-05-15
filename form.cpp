#include "form.h"
#include "ui_form.h"


Form::Form(QWidget *_callparent, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form),callparent(_callparent)
{
    ui->setupUi(this);
    Time = 30;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(changeTime()));
    timer->start(1000);
}

Form::~Form()
{
    delete ui;
}

void Form::changeTime()
{
    Time--;
    ui->label_3->setText(QString::number(Time));
    ui->label_6->setText(QString::number(score));
    if(Time <= 0)
        restart();
}

void Form::restart()
{
    timer->stop();
//        dialog.show();
        QMessageBox message(QMessageBox::Warning, "Times up!", "Do you want to play again?", QMessageBox::Yes | QMessageBox::No ,NULL);
        if(message.exec() == QMessageBox::Yes)
        {
            Time=31;
            timer->start(1000);
            score=0;
            ui->drum_1->move(1200,215);
            ui->drum_2->move(1200,215);
        }
        else
        {
            close();
        }
}

void Form::movelabel()
{
    int x = 4;
    int a,speed;
    srand(time(NULL));
    if(Time > 0)
    {
        ui->drum_1->show();
        ui->drum_2->show();
        while(1)
        {
            a=(rand()%2)+1;
            speed=(rand()%10)+5;
            if(a==1)
            {
                while(ui->drum_1->x() > 0)
                {
                    ui->drum_1->move(ui->drum_1->x()-x,ui->drum_1->y());
                    QTime t;
                    t.start();
                    while(t.elapsed() < 15)
                        QCoreApplication::processEvents();

                    if(ui->drum_1->x() < 200)
                    {
                        ui->drum_1->hide();
                        ui->drum_1->move(1200,215);
                        ui->drum_1->show();
          //              break;
                    }
                    break;
                 //   continue;
                }
       //         break;
            }

            else if(a==2)
            {
                while(ui->drum_2->x() > 0)
                {
                    ui->drum_2->move(ui->drum_2->x()-x,ui->drum_2->y());
                    QTime t;
                    t.start();
                    while(t.elapsed() < 15)
                        QCoreApplication::processEvents();

                    if(ui->drum_2->x() < 200)
                    {
                        ui->drum_2->hide();
                        ui->drum_2->move(1200,215);
                        ui->drum_2->show();
             //           break;
                    }
                    break;
         //           continue;
                }
        //    break;
            }
        }
    }
}

void Form::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_J)
    {
        if(ui->drum_1->x() >= 270 && 310 >= ui->drum_1->x())
        {
            ui->drum_1->hide();
            ui->drum_1->move(1200,215);
            ui->drum_1->show();
            score++;
        }
        event->accept();
    }

    else if(event->key() == Qt::Key_K)
    {
        if(ui->drum_2->x() >= 270 && 310 >= ui->drum_2->x())
        {
            ui->drum_2->hide();
            ui->drum_2->move(1200,215);
            ui->drum_2->show();
            score++;
        }
        event->accept();
    }
}


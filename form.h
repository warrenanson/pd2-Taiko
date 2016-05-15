#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "dialog.h"
#include <QTimer>
#include <QTime>
#include <QKeyEvent>
#include <QMessageBox>
#include <QString>
#include <time.h>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *_callparent = 0, QWidget *parent = 0);
    ~Form();
    QTimer * timer;
    void movelabel();

public slots:

    void changeTime();
    void restart();



private:
    Ui::Form *ui;
    int Time;
    int score=0;
    QWidget *callparent;
    Dialog dialog;
    void keyPressEvent(QKeyEvent *);
};

#endif // FORM_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>



#define LIVRE 1
#define OCUPADO 0

sem_t mutex;

int   estadoTrilho[7];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int i;
    ui->setupUi(this);

    trem1 = new Trem(1,60,90, ui->horizontalSlider->value());
    trem2 = new Trem(2,460,30, ui->horizontalSlider_2->value());
    trem3 = new Trem(3,870,90, ui->horizontalSlider_3->value());
    trem4 = new Trem(4,335,270, ui->horizontalSlider_4->value());
    trem5 = new Trem(5,605,270, ui->horizontalSlider_5->value());


    connect(trem1,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int,int)),SLOT(updateInterface(int,int,int)));


    connect(trem1,SIGNAL(entrarTrilho(int,int)),SLOT(entrarTrilho(int,int)));
    connect(trem2,SIGNAL(entrarTrilho(int,int)),SLOT(entrarTrilho(int,int)));
    connect(trem3,SIGNAL(entrarTrilho(int,int)),SLOT(entrarTrilho(int,int)));
    connect(trem4,SIGNAL(entrarTrilho(int,int)),SLOT(entrarTrilho(int,int)));
    connect(trem5,SIGNAL(entrarTrilho(int,int)),SLOT(entrarTrilho(int,int)));


    connect(trem1,SIGNAL(sairTrilho(int)),SLOT(sairTrilho(int)));
    connect(trem2,SIGNAL(sairTrilho(int)),SLOT(sairTrilho(int)));
    connect(trem3,SIGNAL(sairTrilho(int)),SLOT(sairTrilho(int)));
    connect(trem4,SIGNAL(sairTrilho(int)),SLOT(sairTrilho(int)));
    connect(trem5,SIGNAL(sairTrilho(int)),SLOT(sairTrilho(int)));


    sem_init(&mutex, 0, 1);
    for(i= 0; i < 7 ;i++ ){
        estadoTrilho[i] = LIVRE;
    }


    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();

}


void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1:
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2:
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3:
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4:
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5:
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}




void MainWindow::entrarTrilho(int id, int rail){
    sem_wait(&mutex);
    if(id == 1){
        if(rail == 0){
            if(estadoTrilho[0] == LIVRE && !(estadoTrilho[5] == OCUPADO && estadoTrilho[1] == OCUPADO && estadoTrilho[2] == OCUPADO && estadoTrilho[6] == OCUPADO) && !(estadoTrilho[2] == OCUPADO && estadoTrilho[4] == OCUPADO && estadoTrilho[6] == OCUPADO) && (estadoTrilho[2] == LIVRE || estadoTrilho[3] == LIVRE)){
                estadoTrilho[0] = OCUPADO;
                trem1->setX(ui->label_trem1->x()+10);
            }
        }
        else if(rail == 2){
            if(estadoTrilho[2] == LIVRE){
                estadoTrilho[2] = OCUPADO;
                trem1->setY(ui->label_trem1->y()+10);
            }
        }
    }
    else if(id == 2){
        if(rail == 0){
            if(estadoTrilho[0] == LIVRE){
                estadoTrilho[0] = OCUPADO;
                trem2->setX(ui->label_trem2->x()-10);
            }
        }
        else if(rail == 1){
            if(estadoTrilho[1] == LIVRE && !(estadoTrilho[0] == OCUPADO && estadoTrilho[5] == OCUPADO && estadoTrilho[2] == OCUPADO && estadoTrilho[6] == OCUPADO) && !(estadoTrilho[3] == OCUPADO && estadoTrilho[5] == OCUPADO && estadoTrilho[6] == OCUPADO) && (estadoTrilho[4] == LIVRE || estadoTrilho[5] == LIVRE)){
                estadoTrilho[1] = OCUPADO;
                trem2->setX(ui->label_trem2->x()+10);
            }
        }
        else if(rail == 4){
            if(estadoTrilho[4] == LIVRE && !(estadoTrilho[0] == OCUPADO && estadoTrilho[2] == OCUPADO && estadoTrilho[6] == OCUPADO) && (estadoTrilho[3] == LIVRE || estadoTrilho[6] == LIVRE)){
                estadoTrilho[4] = OCUPADO;
                trem2->setY(ui->label_trem2->y()+10);
            }
        }
        else if(rail == 3){
            if(estadoTrilho[3] == LIVRE && (estadoTrilho[0] == LIVRE || estadoTrilho[2] == LIVRE)){
                estadoTrilho[3] = OCUPADO;
                trem2->setX(ui->label_trem2->x()-10);
            }
        }
    }
    if(id == 3){
        if(rail == 5){
            if(estadoTrilho[5] == LIVRE && !(estadoTrilho[0] == OCUPADO && estadoTrilho[1] == OCUPADO && estadoTrilho[2] == OCUPADO && estadoTrilho[6] == OCUPADO) && !(estadoTrilho[1] == OCUPADO && estadoTrilho[3] == OCUPADO && estadoTrilho[6] == OCUPADO) && (estadoTrilho[1] == LIVRE || estadoTrilho[4] == LIVRE)){
                estadoTrilho[5] = OCUPADO;
                trem3->setX(ui->label_trem3->x()-10);
            }
        }
        else if(rail == 1){
            if(estadoTrilho[1] == LIVRE){
                estadoTrilho[1] = OCUPADO;
                trem3->setX(ui->label_trem3->x()-10);
            }
        }
    }
    if(id == 4){
        if(rail == 2){
            if(estadoTrilho[2] == LIVRE && !(estadoTrilho[0] == OCUPADO && estadoTrilho[1] == OCUPADO && estadoTrilho[5] == OCUPADO && estadoTrilho[6] == OCUPADO) && !(estadoTrilho[0] == OCUPADO && estadoTrilho[4] == OCUPADO && estadoTrilho[6] == OCUPADO) && (estadoTrilho[0] == LIVRE || estadoTrilho[3] == LIVRE)){
                estadoTrilho[2] = OCUPADO;
                trem4->setY(ui->label_trem4->y()-10);
            }
        }
        else if(rail == 3){
            if(estadoTrilho[3] == LIVRE && !(estadoTrilho[1] == OCUPADO && estadoTrilho[5] == OCUPADO && estadoTrilho[6] == OCUPADO) && (estadoTrilho[4] == LIVRE || estadoTrilho[6] == LIVRE)){
                estadoTrilho[3] = OCUPADO;
                trem4->setX(ui->label_trem4->x()+10);
            }
        }
        else if(rail == 6){
            if(estadoTrilho[6] == LIVRE){
                estadoTrilho[6] = OCUPADO;
                trem4->setX(ui->label_trem4->x()+10);
            }
        }
    }
    if(id == 5){
        if(rail == 4){
            if(estadoTrilho[4] == LIVRE && (estadoTrilho[1] == LIVRE || estadoTrilho[5] == LIVRE)){
                estadoTrilho[4] = OCUPADO;
                trem5->setY(ui->label_trem5->y()-10);
            }
        }
        else if(rail == 5){
            if(estadoTrilho[5] == LIVRE){
                estadoTrilho[5] = OCUPADO;
                trem5->setX(ui->label_trem5->x()+10);
            }
        }
        else if(rail == 6){
            if(estadoTrilho[6] == LIVRE && !(estadoTrilho[0] == OCUPADO && estadoTrilho[1] == OCUPADO && estadoTrilho[2] == OCUPADO && estadoTrilho[5] == OCUPADO) && !(estadoTrilho[1] == OCUPADO && estadoTrilho[3] == OCUPADO && estadoTrilho[5] == OCUPADO) && !(estadoTrilho[0] == OCUPADO && estadoTrilho[2] == OCUPADO && estadoTrilho[4] == OCUPADO) && (estadoTrilho[3] == LIVRE || estadoTrilho[4] == LIVRE)){
                estadoTrilho[6] = OCUPADO;
                trem5->setX(ui->label_trem5->x()-10);
            }
        }
    }
    sem_post(&mutex);
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sairTrilho(int rail){
    sem_wait(&mutex);
    estadoTrilho[rail] = LIVRE;
    sem_post(&mutex);
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    trem1->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    trem2->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    trem3->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_4_valueChanged(int value)
{
    trem4->setVelocidade(value);
}

void MainWindow::on_horizontalSlider_5_valueChanged(int value)
{
    trem5->setVelocidade(value);
}

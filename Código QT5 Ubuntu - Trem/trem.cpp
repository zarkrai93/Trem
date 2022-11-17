#include "trem.h"
#include <QtCore>


Trem::Trem(int ID, int x, int y, int velocidade){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = velocidade;
}

void Trem::setX(int valor){
    x = valor;
}

void Trem::setY(int valor){
    y = valor;
}

void Trem::setVelocidade(int valor){
    velocidade = valor;
}

void Trem::run(){
    while(true){
        if(velocidade > 0){
            switch(ID){
            case 1:
                if(y == 30 && x == 310){
                    emit entrarTrilho(ID,0);
                }
                else if(y == 150 && x == 310){
                    emit sairTrilho(0);
                    x-=10;
                }
                else if(y == 130 && x == 330){
                    emit entrarTrilho(ID,2);
                }
                else if(y == 150 && x == 190){
                    emit sairTrilho(2);
                    x-=10;
                }
                else if (y == 30 && x <330)
                    x+=10;
                else if (x == 330 && y < 150)
                    y+=10;
                else if (x > 60 && y == 150)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x, y, velocidade);
                break;

            case 2:
                if(y == 150 && x == 350){
                    emit entrarTrilho(ID,0);
                }
                else if(y == 30 && x == 350){
                    emit sairTrilho(0);
                    x+=10;
                }
                else if(y == 30 && x == 580){
                    emit entrarTrilho(ID,1);
                }
                else if(y == 150 && x == 590){
                    emit sairTrilho(1);
                    x-=10;
                }
                else if(y == 120 && x == 600){
                    emit entrarTrilho(ID,4);
                }
                else if(y == 150 && x == 450){
                    emit sairTrilho(4);
                    x-=10;
                }
                else if(y == 150 && x == 490){
                    emit entrarTrilho(ID,3);
                }
                else if(y == 150 && x == 330){
                    emit sairTrilho(3);
                    y-=10;
                }
                else if (y == 30 && x <600)
                    x+=10;
                else if (x == 600 && y < 150)
                    y+=10;
                else if (x > 330 && y == 150)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y, velocidade);
                break;


            case 3:
                if(y == 30 && x == 620){
                    emit sairTrilho(1);
                    x+=10;
                }
                else if(y == 150 && x == 620){
                    emit entrarTrilho(ID,1);
                }
                else if(y == 150 && x == 600){
                    emit sairTrilho(5);
                    y-=10;
                }
                else if(y == 150 && x == 770){
                    emit entrarTrilho(ID,5);
                }
                else if (y == 30 && x <870)
                    x+=10;
                else if (x == 870 && y < 150)
                    y+=10;
                else if (x > 600 && y == 150)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y, velocidade);
                break;
            case 4: //Trem 4
                if(y == 150 && x == 445){
                    emit entrarTrilho(ID,6);
                }
                else if(y == 270 && x == 465){
                    emit sairTrilho(6);
                    x-=10;
                }
                else if(y == 170 && x == 195){
                    emit entrarTrilho(ID,2);
                }
                else if(y == 150 && x == 335){
                    emit sairTrilho(2);
                    x+=10;
                }
                else if(y == 150 && x == 305){
                    emit entrarTrilho(ID,3);
                }
                else if(y == 150 && x == 465){
                    emit sairTrilho(3);
                    y+=10;
                }
                else if (y == 150 && x <465)
                    x+=10;
                else if (x == 465 && y < 270)
                    y+=10;
                else if (x > 195 && y == 270)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y, velocidade);
                break;


            case 5:
                if(y == 270 && x == 485){
                    emit entrarTrilho(ID,6);
                }
                else if(y == 150 && x == 465){
                    emit sairTrilho(6);
                    x+=10;
                }
                else if(y == 170 && x == 465){
                    emit entrarTrilho(ID,4);
                }
                else if(y == 150 && x == 615){
                    emit sairTrilho(4);
                    x+=10;
                }
                else if(y == 150 && x == 565){
                    emit entrarTrilho(ID,5);
                }
                else if(y == 160 && x == 735){
                    emit sairTrilho(5);
                    y+=10;
                }
                else if (y == 150 && x <735)
                    x+=10;
                else if (x == 735 && y < 270)
                    y+=10;
                else if (x > 465 && y == 270)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y, velocidade);
                break;
            default:
                break;
            }


            msleep(200-velocidade);
        }
    }
}

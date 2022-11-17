#ifndef TREM_H

#define TREM_H


#include <QThread>


class Trem: public QThread{

 Q_OBJECT

public:

    void setX(int value);

    void setY(int value);

    void setVelocidade(int);

    Trem(int,int,int,int);

    void run();



signals:

    void updateGUI(int,int,int,int);

    void sairTrilho(int);

    void entrarTrilho(int,int);


private:

   int ID;

   int velocidade;

   int x;

   int y;

};

#endif

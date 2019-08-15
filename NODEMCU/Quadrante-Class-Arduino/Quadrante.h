#ifndef QUADRANTE_H
#define QUADRANTE_H

#include <Arduino.h>

class Quadrante{
    private:
        int led, ir, tempo;
    
    public:
        Quadrante(int l, int i, int t);
        void acenderQuadrante();
        void apagarQuadrante();
        void acionamento();
        void setTempo(int t);
};
#endif
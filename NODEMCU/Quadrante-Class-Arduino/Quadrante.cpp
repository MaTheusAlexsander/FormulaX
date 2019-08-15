#include "Quadrante.h"

Quadrante::Quadrante(int l, int i, int t){
    led=l;
    ir=i;
    tempo=t*1000;
    pinMode(led, OUTPUT);
}

void Quadrante::acenderQuadrante(){
    digitalWrite(led, HIGH);
}

void Quadrante::apagarQuadrante(){
    digitalWrite(led, LOW);
}

void Quadrante::acionamento(){
    acenderQuadrante();
    delay(tempo);
    apagarQuadrante();
}

void Quadrante::setTempo(int t){
    tempo=t*1000;
}
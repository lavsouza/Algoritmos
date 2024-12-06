#include <iostream>
#include "../Pratica02\veiculo.h"
using namespace std;

void Veiculo::mover() {
    cout << "Veiculo moveu" << endl;
}


int Terrestre::getCapPass(){
    return cap_pass;
}

void Terrestre::setCapacidadeMax(int capacidade) {
    cap_pass = capacidade;
}

void Terrestre::mover() {
    cout << "Veiculo Terrestre Moveu" << endl;
}


float Aereo::getVelMax(){
  return vel_max;
}

void Aereo::setVelocidadeMax(float velocidade){
  vel_max = velocidade;
}

void Aereo::mover() {
    cout << "Veiculo Aereo Moveu" << endl;
}

float Aquatico::getCargaMax(){
  return carga_max;
}

void Aquatico::setCargaMax(float carga){
  carga_max = carga;
}

void Aquatico::mover() {
    cout << "Veiculo Aquatico Moveu" << endl;
}

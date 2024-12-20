#include <iostream>
#include "../Pratica02\veiculo.h"
using namespace std;

void Veiculo::mover() {
    cout << "Veiculo moveu" << endl;
}

int Terrestre::getCapacidadeMax(){
    return cap_pass;
}

void Terrestre::setCapacidadeMax(int cap_pass) {
    this->cap_pass = cap_pass;
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

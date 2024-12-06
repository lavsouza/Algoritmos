//
// Created by lucas on 06/12/2024.
//
#include <iostream>

#include "../Pratica02/veiculo.cpp"

using namespace std;

int main() {
    Veiculo * terr = new Terrestre("VT1");
    dynamic_cast<Terrestre*>(terr)->setCapacidadeMax(45);
    terr->mover();


    Veiculo * aqua = new Aquatico("VQ1");
    dynamic_cast<Aquatico*>(aqua)->setCargaMax(12.5);
    aqua->mover();

    Anfibio * anfi = new Anfibio("AF1");
    anfi->mover();

    Veiculo * aereo = new Aereo("VA1");
    ((Aereo *)aereo)->setVelocidadeMax(1040.5);
    aereo->mover();

    delete terr;
    delete aqua;
    delete aereo;
    delete anfi;
}

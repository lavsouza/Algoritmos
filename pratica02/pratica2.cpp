#include <iostream>
#include "../Pratica02/veiculo.cpp"

using namespace std;

int main() {
    Veiculo *terr = new Terrestre("VT1");
    dynamic_cast<Terrestre*>(terr)->setCapacidadeMax(45);
    terr->mover();
    cout << "Capacidade maxima de passageiros: " << dynamic_cast<Terrestre*>(terr)->getCapacidadeMax() << endl << endl;


    Veiculo * aqua = new Aquatico("VQ1");
    dynamic_cast<Aquatico*>(aqua)->setCargaMax(12.5);
    aqua->mover();
    cout << "Carga maxima: " << dynamic_cast<Aquatico*>(aqua)->getCargaMax() << endl << endl;

    Veiculo * aereo = new Aereo("VA1");
    ((Aereo *)aereo)->setVelocidadeMax(1040.5);
    aereo->mover();
    cout << "Velocidade maxima: " << dynamic_cast<Aereo*>(aereo)->getVelMax() << endl << endl;

    Veiculo * anfi = new Anfibio("AF1");
    dynamic_cast<Anfibio*>(anfi)->mover();


    delete terr;
    delete aqua;
    delete aereo;
    delete anfi;
}

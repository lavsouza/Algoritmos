#include <iostream>
#include "veiculo.h"
using namespace std;


int Veiculo::getNumRodas(){
	return num_rodas;
}

void Veiculo::setNumRodas(int r) {
	num_rodas = r;
	delete [] rodas;
	rodas = new Roda[r];
}

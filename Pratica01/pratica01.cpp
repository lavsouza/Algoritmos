#include <iostream>
#include "veiculo.h"
using namespace std;

int main() {
//	{
//		Veiculo veiculo1("v1");
//		{
//			Veiculo veiculo2("v2");
//			{
//				Veiculo veiculo3("v3");
//			}
//		}
//	}

//	Veiculo * obj1 = new Veiculo("v1");
//
//	delete obj1;

	Veiculo veiculo1("v1");

	veiculo1.setNumRodas(4);
	cout << veiculo1.getNumRodas() << endl;

	return 0;
}

#include <iostream>
#include "veiculo.cpp"

using namespace std;

int main() {
	// {
	// 	Veiculo veiculo1("v1");
	// 	{
	// 		Veiculo veiculo2("v2");
	// 		{
	// 			Veiculo veiculo3("v3");
	// 		}
	// 	}
	// }

	Veiculo * obj1 = new Veiculo("v1");

	delete obj1;

	Veiculo veiculo1("v1");

	cout << veiculo1.getNumRodas() << endl;
	veiculo1.setNumRodas(4);
	veiculo1.setNumRodas(4);

	return 0;
}

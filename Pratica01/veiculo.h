#include <iostream>
using namespace std;

class Roda {

	public:
		Roda() {
			cout << "Roda Construida" << endl;
		}

		~Roda(){
			cout << "Roda Destruida" << endl;
		}
};


class Veiculo {
	private:
		string nome;
		int num_rodas;
		Roda *rodas;

	public:
		//Construtor
		Veiculo(const char * param) { // @suppress("Class members should be properly initialized")
			this->nome = string(param);
			this->rodas = NULL;
			cout << "Veículo: " << nome << " Construido" << endl;
		}

		//Destrutor
		~Veiculo(){
			delete[] rodas;
			cout << "Veículo: " << nome << " Destruido" << endl;
		}

		//Metodos
		int getNumRodas();

		void setNumRodas(int rodas);

};


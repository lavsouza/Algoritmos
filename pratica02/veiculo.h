#ifndef VEICULO_H
#define VEICULO_H

#include <string>
using namespace std;

// Classe base Veiculo
class Veiculo {
private:
    string nome;

protected:
    Veiculo(int num) {
        cout << "Construtor protegido de Veiculo com num: " << num << endl;
    }

public:
    Veiculo(const char * param){
      this->nome = string(param);
      cout << "Veiculo: " << nome << " constructor" << endl;
    }
    virtual ~Veiculo() {
      cout << "Veiculo: " << nome << " destructor" << endl;
    }

    virtual void mover() = 0;
};

class Terrestre : public virtual Veiculo {
private:
    int cap_pass;

protected:
    Terrestre(int num) : Veiculo(num) {
        cout << "Terrestre constructor protected" << endl;
    }

public:
    Terrestre(const char * nome, int capacidade = 5): Veiculo(nome) {
        this->cap_pass = capacidade;
        cout << "Terrestre constructor" << endl;
        cout << "Capacidade: " << cap_pass << endl;
    }

    virtual ~Terrestre() {
      cout << "Terrestre destructor" << endl;
    }

    int getCapPass();
    void setCapacidadeMax(int capacidade);
    void mover() override;

};

class Aquatico : public virtual Veiculo {
private:
    float carga_max;

protected:
    Aquatico(int num): Veiculo(num) {
        cout << "Aquatico constructor protected" << endl;
    }

public:
    Aquatico(const char * nome, float carga = 10): Veiculo(nome) {
        this->carga_max = carga;
        cout << "Aquatico constructor" << endl;
        cout << "Carga max: " << carga_max << endl;
    }

    virtual ~Aquatico() {
      cout << "Aquatico destructor" << endl;
    }
    float getCargaMax();
    void setCargaMax(float carga);
    void mover() override;

};

class Aereo : public Veiculo {
private:
    float vel_max;
public:
    Aereo(const char * nome, float velocidade = 100): Veiculo(nome) {
        this->vel_max = velocidade;
        cout << "Aereo constructor" << endl;
        cout << "Velocidade: " << vel_max << endl;
    }

    virtual ~Aereo() {
      cout << "Aereo destructor" << endl;
    }
    float getVelMax();
    void setVelocidadeMax(float velocidade);
    void mover();

};

class Anfibio : public Terrestre, Aquatico {
private:
    string nome;

public:
    Anfibio (const char * nome, int num) : Veiculo(nome), Terrestre(nome), Aquatico(nome) {
        cout << "Anfibio constructor" << endl;
    }

    void mover() override {
        Terrestre::mover();
        Aquatico::mover();
    }

};

#endif

#ifndef VEICULO_H
#define VEICULO_H

#include <string>

using namespace std;

// Classe base Veiculo
class Veiculo {

protected:
    string nome;
    Veiculo() {
        cout << "Construtor protegido de Veiculo" << endl;
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
    Terrestre() : Veiculo("Default"), cap_pass(5) {
        cout << "Terrestre constructor protected" << endl;
    }

public:
    Terrestre(const char * nome, int cap_pass = 5): Veiculo(nome), cap_pass(cap_pass){
        cout << "Terrestre constructor" << endl;
    }

    virtual ~Terrestre() {
      cout << "Terrestre destructor" << endl;
    }

    int getCapacidadeMax();
    void setCapacidadeMax(int cap_pass);
    void mover() override;

};

class Aquatico : public virtual Veiculo {
private:
    float carga_max;

protected:
    Aquatico(): Veiculo("Default"), carga_max(10) {
        cout << "Aquatico constructor protected" << endl;
    }

public:
    Aquatico(const char * nome, float carga = 10): Veiculo(nome) {
        this->carga_max = carga;
        cout << "Aquatico constructor" << endl;
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

class Anfibio : public Terrestre, public Aquatico {
private:
    string nome;

public:
    Anfibio (const char * nome) : Veiculo(nome), Terrestre(), Aquatico() {
        cout << "Anfibio constructor" << endl;
    }

    virtual ~Anfibio() {
        cout << "Anfibio destructor" << endl;
    }

    void mover() override {
        Terrestre::mover();
        Aquatico::mover();
    }

};

#endif

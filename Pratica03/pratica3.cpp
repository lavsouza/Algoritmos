#include <iostream>
#include "funcoes.h"
#include "arranjo.h"
#include "aluno.h"

using namespace funcoes;
using namespace std;

int main(){
    string x = "Teste", y = "Teste1";
    float z = 30.7;

    cout << "Antes: x = " << x << ", y = " << y << endl;
    trocar(x, y);
    cout << "Depois : x = " << x << ", y = " << y << endl;
    cout << "Minimo de " << x << " e "<< y << ": " << minimo(x, y) << endl;
    cout << "Maximo de " << x << " e "<< y << ": " << maximo(x, y) << endl;

    Arranjo<int> arr1(10);
    arr1.set(4, 5);
    arr1.set(7, 15);
    arr1.set(8, 22);
    arr1.exibir();

    Arranjo<float> arr(5);
    arr.set(4, 5.7);
    arr.set(2, 7.7);
    arr.set(1, 5981.1);
    arr.exibir();

    try {
        Arranjo<float> arr(5);

        arr.set(4, 10); // Válido
        arr.set(1, 20); // Inválido
        arr.set(0, 30); // Inválido
        cout << arr.get(4) << endl; // Válido
        arr.exibir();
    } catch (const IndiceInvalido& e) {
        cout << "Erro: " << e.erro() << endl;
    }

    Arranjo<Aluno> turma(3);
    turma.set(0, Aluno("Joao","1234"));
    turma.set(1, Aluno("Maria","5235"));
    turma.set(2, Aluno("Jose","2412"));
    turma.exibir();

}
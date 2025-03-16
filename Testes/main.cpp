#include <iostream>
using namespace std;

// Função para realizar a busca binária e contar os loops
int binarySearch(int array[], int size, int target) {
    int start = 0;
    int end = size - 1;
    int loopCount = 0;  // Variável para contar os loops

    while (start <= end) {
        loopCount++;  // Incrementa a cada execução do loop

        // Calcula o ponto médio
        int mid = start + (end - start) / 2;

        // Verifica se o alvo foi encontrado
        if (array[mid] == target) {
            cout << "Total de loops: " << loopCount << endl;
            return mid; // Retorna o índice
        }
        // Se o alvo é menor, procure na metade esquerda
        else if (array[mid] > target) {
            end = mid - 1;
        }
        // Se o alvo é maior, procure na metade direita
        else {
            start = mid + 1;
        }
    }

    cout << "Total de loops: " << loopCount << endl;
    return -1; // Retorna -1 se não encontrar
}

void somesort(int * array, int size){
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (array[min] > array[j])
                min = j;
        }
        swap(array[min], array[i]);
    }
}


int main() {
    // Array ordenado de exemplo
    int array[] = {3,6,7,11,15,25,32,45,59,61,67,74,81,82,87,94};
    int size = sizeof(array) / sizeof(array[0]);

    // Chama a função de busca binária
    int result = binarySearch(array, size, target);



    if (result != -1) {
        cout << "Elemento encontrado no índice: " << result << endl;
    } else {
        cout << "Elemento não encontrado!" << endl;
    }

    return 0;
}

#include <iostream>
#include <chrono>

void alocarDinamicamenteECalcularSoma(int N) {
    // Alocação dinâmica de memória para uma matriz N x N
    int** matriz = new int*[N];
    for (int i = 0; i < N; ++i) {
        matriz[i] = new int[N];
    }

    // Inicializa a matriz e calcula a soma dos elementos
    int soma = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz[i][j] = i + j;  // Exemplo de inicialização
            soma += matriz[i][j];
        }
    }

    std::cout << "Soma usando alocação dinâmica manual: " << soma << std::endl;

    // Liberação da memória alocada dinamicamente
    for (int i = 0; i < N; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

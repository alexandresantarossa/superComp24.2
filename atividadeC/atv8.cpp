#include <iostream>

int main() {
    int matriz[3][3];

    std::cout << "Digite os elementos da matriz 3x3:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> matriz[i][j];
        }
    }

    int somaDiagonal = 0;
    for (int i = 0; i < 3; ++i) {
        somaDiagonal += matriz[i][i];
    }

    std::cout << "A soma dos elementos da diagonal principal é: " << somaDiagonal << std::endl;
    return 0;
}

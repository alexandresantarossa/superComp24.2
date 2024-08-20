#include <iostream>
#include <vector>

int main() {
    std::vector<int> numeros(5);
    int soma = 0;

    std::cout << "Digite 5 números:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cin >> numeros[i];
        soma += numeros[i];
    }

    std::cout << "A soma dos números é: " << soma << std::endl;
    return 0;
}

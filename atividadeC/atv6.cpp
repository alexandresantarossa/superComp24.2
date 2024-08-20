#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numeros(10);

    std::cout << "Digite 10 números:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cin >> numeros[i];
    }

    int maior = *std::max_element(numeros.begin(), numeros.end());
    std::cout << "O maior número é: " << maior << std::endl;

    return 0;
}

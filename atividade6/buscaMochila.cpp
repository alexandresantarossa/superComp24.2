#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

int knapsack(int capacidade, const std::vector<int>& pesos, const std::vector<int>& valores, int n) {
    if (n == 0 || capacidade == 0) {
        return 0; // caso 0
    }

    if (pesos[n - 1] > capacidade) {
        return knapsack(capacidade, pesos, valores, n - 1); 
    } else {
        int incluir = valores[n - 1] + knapsack(capacidade - pesos[n - 1], pesos, valores, n - 1);
        int nao_incluir = knapsack(capacidade, pesos, valores, n - 1);
        return std::max(incluir, nao_incluir);
    }
}

int main() {
    std::ifstream arquivo("entrada.txt");

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return 1;
    }

    int n, capacidade;
    arquivo >> n >> capacidade;

    std::vector<int> pesos(n);
    std::vector<int> valores(n);

    for (int i = 0; i < n; i++) {
        arquivo >> pesos[i] >> valores[i];
    }

    arquivo.close();

    int max_valor = knapsack(capacidade, pesos, valores, n);
    std::cout << "Valor máximo: " << max_valor << std::endl;

    return 0;
}

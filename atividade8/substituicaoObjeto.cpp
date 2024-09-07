#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>
#include <chrono>

struct Item {
    int peso;
    int valor;
};

int preencherMochila(int capacidade, std::vector<Item>& itens, int& pesoAtual, std::vector<bool>& estadoMochila) {
    int valorMax = 0;
    pesoAtual = 0;

    for (size_t i = 0; i < itens.size(); ++i) {
        if (itens[i].peso + pesoAtual <= capacidade) {
            pesoAtual += itens[i].peso;
            valorMax += itens[i].valor;
            estadoMochila[i] = true; 
        }
    }
    return valorMax;
}

int otimizarSubstituicao(int capacidade, std::vector<Item>& itens, std::vector<bool>& estadoMochila, int& pesoAtual, int valorMax) {
    bool houveSubstituicao = true;

    while (houveSubstituicao) {
        houveSubstituicao = false;

        for (size_t i = 0; i < itens.size(); ++i) {
            if (!estadoMochila[i]) { 
                for (size_t j = 0; j < itens.size(); ++j) {
                    if (estadoMochila[j] && itens[i].peso <= itens[j].peso) { 
                        int novoPeso = pesoAtual - itens[j].peso + itens[i].peso;
                        int novoValor = valorMax - itens[j].valor + itens[i].valor;

                        if (novoPeso <= capacidade && novoValor > valorMax) {
                            estadoMochila[i] = true;
                            estadoMochila[j] = false;
                            pesoAtual = novoPeso;
                            valorMax = novoValor;
                            houveSubstituicao = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    return valorMax;
}

void carregarDados(const std::string& caminhoArquivo, int& capacidade, std::vector<Item>& itens) {
    std::ifstream arquivo(caminhoArquivo);
    if (!arquivo) {
        std::cerr << "Não foi possível abrir o arquivo: " << caminhoArquivo << std::endl;
        exit(1);
    }
    int n;
    arquivo >> n >> capacidade;
    itens.resize(n);
    for (int i = 0; i < n; ++i) {
        arquivo >> itens[i].peso >> itens[i].valor;
    }
    arquivo.close();
}

int main() {
    std::vector<std::string> arquivosEntrada = {"entrada1.txt", "entrada2.txt", "entrada3.txt", "entrada4.txt"};
    std::random_device rd;
    std::mt19937 randomGenerator(rd());

    for (const auto& caminhoArquivo : arquivosEntrada) {
        int capacidade;
        std::vector<Item> itens;
        carregarDados(caminhoArquivo, capacidade, itens);

        std::shuffle(itens.begin(), itens.end(), randomGenerator);

        std::vector<bool> estadoMochila(itens.size(), false); 
        int pesoAtual = 0;

        auto tempoInicio = std::chrono::high_resolution_clock::now();

        int valorMax = preencherMochila(capacidade, itens, pesoAtual, estadoMochila);

        valorMax = otimizarSubstituicao(capacidade, itens, estadoMochila, pesoAtual, valorMax);

        auto tempoFinal = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracao = tempoFinal - tempoInicio;

        std::cout << "Arquivo: " << caminhoArquivo << std::endl;
        std::cout << "Peso: " << pesoAtual << " kg" << std::endl;
        std::cout << "Valor máximo: " << valorMax << " unidades" << std::endl;
        std::cout << "Tempo de execução: " << duracao.count() << " segundos" << std::endl;
        std::cout << "------------------" << std::endl;
    }

    return 0;
}

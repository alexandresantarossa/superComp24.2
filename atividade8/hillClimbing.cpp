#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>

struct Item {
    int peso;
    int valor;
};

int calcularValor(const std::vector<Item>& itens, const std::vector<bool>& estadoMochila, int capacidade, int& pesoAtual) {
    int valorTotal = 0;
    pesoAtual = 0;

    for (size_t i = 0; i < itens.size(); ++i) {
        if (estadoMochila[i]) {
            pesoAtual += itens[i].peso;
            if (pesoAtual > capacidade) {
                return 0;  
            }
            valorTotal += itens[i].valor;
        }
    }

    return valorTotal;
}

int hillClimbing(int capacidade, std::vector<Item>& itens, int& pesoAtual, std::vector<bool>& melhorEstado) {
    std::random_device rd;
    std::mt19937 randomGenerator(rd());

    std::vector<bool> estadoMochila(itens.size(), false);
    for (size_t i = 0; i < estadoMochila.size(); ++i) {
        estadoMochila[i] = (std::uniform_int_distribution<>(0, 1)(randomGenerator) == 1);
    }
    int valorAtual = calcularValor(itens, estadoMochila, capacidade, pesoAtual);

    melhorEstado = estadoMochila;
    int melhorValor = valorAtual;

    bool encontrouMelhor = true;

    while (encontrouMelhor) {
        encontrouMelhor = false;

        for (size_t i = 0; i < itens.size(); ++i) {
            estadoMochila[i] = !estadoMochila[i];
            int novoPeso;
            int novoValor = calcularValor(itens, estadoMochila, capacidade, novoPeso);

            if (novoValor > melhorValor && novoPeso <= capacidade) {
                melhorValor = novoValor;
                melhorEstado = estadoMochila;
                pesoAtual = novoPeso;
                encontrouMelhor = true;
            } else {
                estadoMochila[i] = !estadoMochila[i]; 
            }
        }
    }

    return melhorValor;
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

    for (const auto& caminhoArquivo : arquivosEntrada) {
        int capacidade;
        std::vector<Item> itens;
        carregarDados(caminhoArquivo, capacidade, itens);

        std::vector<bool> melhorEstado(itens.size(), false);
        int pesoAtual = 0;

        auto tempoInicio = std::chrono::high_resolution_clock::now();
        int melhorValor = hillClimbing(capacidade, itens, pesoAtual, melhorEstado);
        auto tempoFinal = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracao = tempoFinal - tempoInicio;

        std::cout << "Arquivo: " << caminhoArquivo << std::endl;
        std::cout << "Peso: " << pesoAtual << " kg" << std::endl;
        std::cout << "Valor máximo: " << melhorValor << " unidades" << std::endl;
        std::cout << "Tempo de execução: " << duracao.count() << " segundos" << std::endl;
        std::cout << "------------------" << std::endl;
    }

    return 0;
}

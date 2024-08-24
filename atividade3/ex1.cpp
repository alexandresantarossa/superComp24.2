#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Função que lê números de um arquivo e os armazena em um vetor.
void lerArquivo(const std::string& nomeArquivo, std::vector<int>& numeros) {
    std::ifstream arquivo(nomeArquivo);
    int numero;

    if (arquivo.is_open()) {
        while (arquivo >> numero) {
            numeros.push_back(numero);
        }
        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << std::endl;
    }
}

// Função que dobra os valores de um vetor de números, passando o vetor original por referência.
void dobrarValoresReferencia(const std::vector<int>& numerosOriginais, std::vector<int>& numerosDobrados) {
    numerosDobrados.clear();
    for (int numero : numerosOriginais) {
        numerosDobrados.push_back(numero * 2);
    }
}

// Função que dobra os valores de um vetor de números, passando o vetor original por ponteiro.
void dobrarValoresPonteiro(const std::vector<int>* numerosOriginais, std::vector<int>* numerosDobrados) {
    numerosDobrados->clear();
    for (int numero : *numerosOriginais) {
        numerosDobrados->push_back(numero * 2);
    }
}

// Função que escreve os números de um vetor em um arquivo.
void escreverArquivo(const std::string& nomeArquivo, const std::vector<int>& numeros) {
    std::ofstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        for (int numero : numeros) {
            arquivo << numero << std::endl;
        }
        arquivo.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << std::endl;
    }
}

int main() {
    std::vector<int> numeros, numerosDobrados;

    lerArquivo("entrada.txt", numeros);

    dobrarValoresReferencia(numeros, numerosDobrados);
    escreverArquivo("saida_referencia.txt", numerosDobrados);

    dobrarValoresPonteiro(&numeros, &numerosDobrados);
    escreverArquivo("saida_ponteiro.txt", numerosDobrados);

    return 0;
}

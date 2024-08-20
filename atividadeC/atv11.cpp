#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

int main() {
    std::ifstream arquivoEntrada("texto.txt");
    if (!arquivoEntrada) {
        std::cerr << "Erro ao abrir o arquivo de entrada." << std::endl;
        return 1;
    }

    std::unordered_map<std::string, int> frequenciaPalavras;
    std::string linha;
    int totalPalavras = 0;
    int totalLinhas = 0;

    while (std::getline(arquivoEntrada, linha)) {
        std::istringstream streamLinha(linha);
        std::string palavra;
        while (streamLinha >> palavra) {
            ++frequenciaPalavras[palavra];
            ++totalPalavras;
        }
        ++totalLinhas;
    }

    arquivoEntrada.close();

    std::string palavraMaisFrequente;
    int maxFrequencia = 0;
    for (const auto& par : frequenciaPalavras) {
        if (par.second > maxFrequencia) {
            maxFrequencia = par.second;
            palavraMaisFrequente = par.first;
        }
    }

    double mediaPalavrasPorLinha = static_cast<double>(totalPalavras) / totalLinhas;

    std::ofstream arquivoSaida("estatisticas.txt");
    if (!arquivoSaida) {
        std::cerr << "Erro ao abrir o arquivo de saída." << std::endl;
        return 1;
    }

    arquivoSaida << "Número total de palavras: " << totalPalavras << std::endl;
    arquivoSaida << "Número total de linhas: " << totalLinhas << std::endl;
    arquivoSaida << "Número médio de palavras por linha: " << mediaPalavrasPorLinha << std::endl;
    arquivoSaida << "Palavra mais frequente: " << palavraMaisFrequente << " (" << maxFrequencia << " vezes)" << std::endl;

    arquivoSaida.close();

    return 0;
}

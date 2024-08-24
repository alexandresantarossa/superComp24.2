#include <iostream>
#include <stdexcept>  // Para lançar exceções

class Vector {
public:
    // Construtor que inicializa o vetor com um tamanho inicial
    Vector(int tamanho)
        : tam(0), capacidade(tamanho) {
        dados = new int[capacidade];
    }

    // Destrutor que libera a memória alocada dinamicamente
    ~Vector() {
        delete[] dados;
    }

    // Inicializa todos os elementos do vetor com um valor específico
    void inicializa(int valor) {
        for (int i = 0; i < capacidade; ++i) {
            dados[i] = valor;
        }
        tam = capacidade;  // Considera que todos os slots foram preenchidos
    }

    // Retorna o valor no índice especificado
    int get(int index) const {
        if (index < 0 || index >= tam) {
            throw std::out_of_range("Índice fora do intervalo.");
        }
        return dados[index];
    }

    // Define o valor no índice especificado
    void set(int index, int valor) {
        if (index < 0 || index >= tam) {
            throw std::out_of_range("Índice fora do intervalo.");
        }
        dados[index] = valor;
    }

    // Insere um valor em um índice específico, redimensionando o vetor se necessário
    void inserir(int index, int valor) {
        if (index < 0 || index > tam) {
            throw std::out_of_range("Índice fora do intervalo.");
        }

        if (tam == capacidade) {
            redimensiona(capacidade * 2);  // Redimensiona para o dobro da capacidade atual
        }

        for (int i = tam; i > index; --i) {
            dados[i] = dados[i - 1];
        }

        dados[index] = valor;
        ++tam;
    }

    // Remove um elemento no índice especificado
    void remover(int index) {
        if (index < 0 || index >= tam) {
            throw std::out_of_range("Índice fora do intervalo.");
        }

        for (int i = index; i < tam - 1; ++i) {
            dados[i] = dados[i + 1];
        }

        --tam;

        if (tam < capacidade / 4) {
            redimensiona(capacidade / 2);  // Redimensiona para metade da capacidade atual se necessário
        }
    }

    // Imprime o vetor
    void imprime() const {
        for (int i = 0; i < tam; ++i) {
            std::cout << dados[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int* dados;        // Ponteiro para os dados do vetor
    int tam;           // Número atual de elementos no vetor
    int capacidade;    // Capacidade máxima atual do vetor

    // Redimensiona o vetor para uma nova capacidade
    void redimensiona(int novaCapacidade) {
        int* novosDados = new int[novaCapacidade];
        for (int i = 0; i < tam; ++i) {
            novosDados[i] = dados[i];
        }

        delete[] dados;
        dados = novosDados;
        capacidade = novaCapacidade;
    }
};

// Teste da classe Vector
int main() {
    Vector vec(5);
    vec.inicializa(0);
    vec.imprime();

    vec.set(2, 10);
    vec.imprime();

    vec.inserir(1, 20);
    vec.imprime();

    vec.remover(3);
    vec.imprime();

    return 0;
}

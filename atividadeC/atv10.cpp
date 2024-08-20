#include <iostream>
#include <vector>
#include <string>

struct Item {
    std::string nome;
    int quantidade;
};

class Estoque {
public:
    void adicionarItem(const std::string& nome, int quantidade) {
        for (auto& item : itens) {
            if (item.nome == nome) {
                item.quantidade += quantidade;
                return;
            }
        }
        itens.push_back({nome, quantidade});
    }

    void removerItem(const std::string& nome, int quantidade) {
        for (auto& item : itens) {
            if (item.nome == nome) {
                if (item.quantidade >= quantidade) {
                    item.quantidade -= quantidade;
                } else {
                    std::cout << "Quantidade insuficiente no estoque." << std::endl;
                }
                return;
            }
        }
        std::cout << "Item não encontrado no estoque." << std::endl;
    }

    void visualizarEstoque() const {
        std::cout << "Estoque atual:" << std::endl;
        for (const auto& item : itens) {
            std::cout << "Item: " << item.nome << ", Quantidade: " << item.quantidade << std::endl;
        }
    }

private:
    std::vector<Item> itens;
};

int main() {
    Estoque estoque;
    estoque.adicionarItem("Maçã", 10);
    estoque.adicionarItem("Banana", 5);
    estoque.visualizarEstoque();

    estoque.removerItem("Maçã", 3);
    estoque.visualizarEstoque();

    return 0;
}

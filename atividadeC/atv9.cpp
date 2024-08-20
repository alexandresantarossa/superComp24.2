#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string texto;
    std::cout << "Digite uma string: ";
    std::getline(std::cin, texto);

    std::string textoReverso = texto;
    std::reverse(textoReverso.begin(), textoReverso.end());

    if (texto == textoReverso) {
        std::cout << "A string é um palíndromo." << std::endl;
    } else {
        std::cout << "A string não é um palíndromo." << std::endl;
    }

    return 0;
}

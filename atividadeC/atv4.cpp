#include <iostream>
#include <string>

int main() {
    std::string texto;
    std::cout << "Digite uma string: ";
    std::getline(std::cin, texto);

    std::cout << "O número de caracteres na string '" << texto << "' é: " << texto.length() << std::endl;
    return 0;
}

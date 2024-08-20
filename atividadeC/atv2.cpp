#include <iostream>

int main() {
    double num1, num2;
    char operacao;

    std::cout << "Digite o primeiro número: ";
    std::cin >> num1;
    std::cout << "Digite o segundo número: ";
    std::cin >> num2;
    std::cout << "Digite a operação (+, -, *, /): ";
    std::cin >> operacao;

    double resultado;
    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } 
            break;
    }

    std::cout << "Resultado: " << resultado << std::endl;
    return 0;
}

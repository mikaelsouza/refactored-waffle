#include <iostream>
#include <string>

std::string deslocamentoDireita(std::string texto){
    int i;
    for(i = 0; i < texto.size(); i++){
        if((texto[i] >= 'A' and texto[i] <= 'Z') or (texto[i] >= 'a' and texto[i] <= 'z')){
            texto[i] += 3;
        }
    }
    return texto;
}

std::string inversao(std::string texto){
    char aux;
    int i;
    for(i = 0; i < texto.size() / 2; i++){
        aux = texto[i];
        texto[i] = texto[texto.size() - 1 - i];
        texto[texto.size() - 1 - i] = aux;
    }
    return texto;
}

std::string deslocamentoEsquerda(std::string texto){
    int i;
    for(i = texto.size() / 2; i < texto.size(); i++){
        texto[i] -= 1;
    }
    return texto;
}

int main(){

    int qnt_entradas;
    std::string texto;

    std::cin >> qnt_entradas;
    getchar();

    while(qnt_entradas > 0){
        getline(std::cin, texto);
        std::cout << deslocamentoEsquerda(inversao(deslocamentoDireita(texto))) << std::endl;
        qnt_entradas -= 1;
    }

}

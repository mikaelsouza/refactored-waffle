#include <iostream>
#include <unordered_map>

int main(){

    int palavras;
    int qnt_testes;
    std::string palavra;
    int valor;
    std::unordered_map<std::string, int> valores;


    std::cin >> palavras >> qnt_testes;

    while(palavras){
        std::cin >> palavra >> valor;
        valores[palavra] = valor;
        palavras -= 1;
    }

    while(qnt_testes){

        valor = 0;

        std::cin >> palavra;
        while(palavra != "."){
            valor += valores[palavra];
            std::cin >> palavra;
        }
        std::cout << valor << std::endl;
        qnt_testes -= 1;
    }
}

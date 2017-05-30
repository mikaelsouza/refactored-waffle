#include <iostream>
#include <unordered_map>

int main(){

    int qnt_idiomas;
    int qnt_criancas;

    std::unordered_map<std::string, std::string> traducoes;

    std::cin >> qnt_idiomas;
    std::string idioma;
    std::string traducao;
    std::string nome;
    getchar();
    while(qnt_idiomas > 0){
        getline(std::cin, idioma);
        getline(std::cin, traducao);
        traducoes[idioma] = traducao;
        qnt_idiomas -= 1;
    }

    std::cin >> qnt_criancas;
    getchar();
    while(qnt_criancas > 0){
        getline(std::cin, nome);
        getline(std::cin, idioma);
        std::cout << nome << std::endl;
        std::cout << traducoes[idioma] << std::endl << std::endl;
        qnt_criancas -= 1;
    }
}

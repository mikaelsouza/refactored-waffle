#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

std::vector<std::string> splitLine(std::string linha){

    int i;
    std::vector<std::string> palavras;
    std::string palavra = "";

    for(i = 0; i < linha.size(); i++){
        if(linha[i] != ' '){
            palavra += linha[i];
        } else {
            palavras.push_back(palavra);
            palavra = "";
        }
    }
    palavras.push_back(palavra);
    return palavras;
}

int main(){

    int i;
    int qnt_casos;
    int traducoes;
    int linhas_musicais;

    std::string japa;
    std::string ptbr;
    std::string letra_musica;

    std::vector<std::string> palavras;

    std::unordered_map<std::string, std::string> dicionario;

    std::cin >> qnt_casos;

    while(qnt_casos > 0){
        std::cin >> traducoes >> linhas_musicais;
        getchar();

        while(traducoes > 0){
            std::cin >> japa;
            getchar();
            getline(std::cin, ptbr);
            dicionario[japa] = ptbr;
            traducoes -= 1;
        }
        while(linhas_musicais > 0){
            getline(std::cin, letra_musica);
            palavras = splitLine(letra_musica);
            for(i = 0; i < palavras.size() - 1; i++){
                if(dicionario[palavras[i]] == ""){
                   std::cout << palavras[i] << " ";
                } else {
                   std::cout << dicionario[palavras[i]] << " ";
                }
            }
            if(dicionario[palavras[i]] == ""){
               std::cout << palavras[i];
            } else {
               std::cout << dicionario[palavras[i]];
            }
            std::cout << std::endl;
            linhas_musicais -= 1;
        }
        std::cout << std::endl;
        dicionario.clear();
        qnt_casos -= 1;
    }
}

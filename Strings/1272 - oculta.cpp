#include <iostream>
#include <string>

std::string getFirstLetters(std::string texto){

    bool vazio = true;
    int i;
    std::string palavra = "";
    for(i = 0; i < texto.size(); i++){
        if(texto[i] >= 'a' and texto[i] <= 'z' and vazio){
            palavra += texto[i];
            vazio = false;
        } else if(texto[i] == ' '){
            vazio = true;
        }
    }
    return palavra;
}

int main(){

    int qnt_casos;
    std::string linha;

    std::cin >> qnt_casos;
    getchar();

    while(qnt_casos > 0){
        getline(std::cin, linha);
        std::cout << getFirstLetters(linha) << std::endl;
        qnt_casos -= 1;
    }
}

#include <iostream>
#include <stack>
#include <cstring>

bool analise_parentesis(char* entrada, int tamanho_entrada){

    int i;
    std::stack<char> pilha;

    for(i = 0; i < tamanho_entrada; i++){
        if(entrada[i] == '(' or entrada[i] == '['){
            pilha.push(entrada[i]);
        } else if(pilha.size() and entrada[i] == ')' and pilha.top() == '('){
            pilha.pop();
        } else if(pilha.size() and entrada[i] == ']' and pilha.top() == '['){
            pilha.pop();
        } else if(entrada[i] != ' '){
            return false;
        }
    }

    if(pilha.size() > 0){
        return false;
    } else {
        return true;
    }
}

int main(){

    int qnt_entradas;
    int tamanho_entrada;
    char s[140];

    // Especificamente para o problema..//
    std::cin >> qnt_entradas;
    getchar();
    //.................................//

    while(qnt_entradas > 0){

        // Especificamente para o problema..//
        fgets(s, 140, stdin);
        tamanho_entrada = strlen(s) - 1;
        //..................................//

        if(analise_parentesis(s, tamanho_entrada)){
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
        qnt_entradas -= 1;
    }
    return 0;
}

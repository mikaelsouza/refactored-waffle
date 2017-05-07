#include <iostream>
#include <stack>
#include <string>

bool parentesis_corretos(char *expressao){
    int i;
    std::stack<int> parentesis;

    for(i = 0; expressao[i] != '\0'; i++){
    // Se o caractere atual for um '(', adiciona-lo a pilha.
    // Se o caractere atual for um ')', verificar se a pilha está vazia.
    // Caso a pilha esteja vazia, quer dizer que o ')'
    // Não possui um '(' correspondente para fecha-lo.
        if(expressao[i] == '('){
            parentesis.push(1);
        } else if(expressao[i] == ')'){
            if(parentesis.empty()){
                return false;
            } else {
                parentesis.pop();
            }
        }
    }

    // Ao terminar verificação da expressão, verificar se
    // A pilha está vazia. Se não estiver, quer dizer que
    // Existe '(' sem fechamento faltando.
    if(parentesis.empty()){
        return true;
    } else {
        return false;
    }
}

int main(){
    char expressao[1001];
    while(scanf("%s", expressao) != EOF){
        if(parentesis_corretos(expressao)){
            std::cout << "correct" << std::endl;
        } else {
            std::cout << "incorrect" << std::endl;
        }
    }
    return 0;
}
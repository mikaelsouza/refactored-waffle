#include <iostream>
#include <stack>
#include <cstring>

#define MAX_SIZE 130

bool analise_parentesis(char* entrada, int tamanho_entrada){

    int i;
    std::stack<char> pilha;

    for(i = 0; i < tamanho_entrada; i++){
        //Insere os caracteres '(' e '[' na pilha.
        if(entrada[i] == '(' or entrada[i] == '['){
            pilha.push(entrada[i]);
        //Remove os caracteres correspondentes.
        } else if(!pilha.empty() and entrada[i] == ')' and pilha.top() == '('){
            pilha.pop();
        } else if(!pilha.empty() and entrada[i] == ']' and pilha.top() == '['){
            pilha.pop();
        //Ignora espaços em branco e retorna falso para qualquer outra entrada.
        } else if(entrada[i] != ' '){
            return false;
        }
    }
    //Se a fila não estiver vazia, a entrada não é válida.
    if(pilha.size() > 0){
        return false;
    } else {
        return true;
    }
}

int main(){

    int qnt_entradas;
    int tamanho_entrada;
    char s[MAX_SIZE];

    // Especificamente para o problema...............//
    std::cin >> qnt_entradas;
    getchar();
    //Para realizar leitura de linhas com espaços...//

    while(qnt_entradas > 0){

        // Especificamente para o problema..................//
        fgets(s, MAX_SIZE, stdin);
        tamanho_entrada = strlen(s) - 1;
        //Realiza leitura de linhas com espaço em branco...//
        //Subtrai 1 do tamanho para ignorar o enter........//

        if(analise_parentesis(s, tamanho_entrada)){
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
        qnt_entradas -= 1;
    }
    return 0;
}

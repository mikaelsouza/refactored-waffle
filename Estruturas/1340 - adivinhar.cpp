#include <iostream>
#include <queue>
#include <stack>

int main(){

    int casos;
    int comando;
    int entrada;

    bool pr = true;
    bool fi = true;
    bool pi = true;

    while (scanf("%d", &casos) != EOF){

        std::priority_queue<int> prioridade;
        std::queue<int> fila;
        std::stack<int> pilha;

        while(casos > 0){
            std::cin >> comando >> entrada;
            if(comando == 1){
                prioridade.push(entrada);
                fila.push(entrada);
                pilha.push(entrada);
            } else {
                if(prioridade.top() != entrada) {
                    pr = false;
                }
                if(fila.front() != entrada) {
                    fi = false;
                }
                if(pilha.top() != entrada){
                    pi = false;
                }
                prioridade.pop();
                fila.pop();
                pilha.pop();
            }
            casos -= 1;
        }
        if(pr + fi + pi > 1){
            std::cout << "not sure" << std::endl;
        } else if(pr){
            std::cout << "priority queue" << std::endl;
        } else if(pi){
            std::cout << "stack" << std::endl;
        } else if(fi){
            std::cout << "queue" << std::endl;
        } else {
            std::cout << "impossible" << std::endl;
        }
        pr = true;
        fi = true;
        pi = true;
    }
}

#include <iostream>
#include <string>
#include <list>
#include <vector>

int main(){
    
    int i;
    int tamanho;
    int numero_extraido;
    std::list<int> lista_numeros;
    std::vector<int> cartas_descartadas;
    
    std::cin >> tamanho;
    while(tamanho > 0){
        
        // Cria uma lista de numeros de 1 até o tamanho
        // Inserindo no inicio começando do maior número
        // Até 1.
        while(tamanho > 0){
            lista_numeros.push_front(tamanho);
            tamanho -= 1;
        }

        while(lista_numeros.size() > 1){
            // Remove o número da frente
            numero_extraido = lista_numeros.front();
            lista_numeros.pop_front();
            cartas_descartadas.push_back(numero_extraido);

            // Coloca o próximo no final
            lista_numeros.push_back(lista_numeros.front());
            lista_numeros.pop_front();
        }
        
        // Impressão na tela
        std::cout << "Discarded cards: ";

        for(i = 0; i < cartas_descartadas.size() - 1; i++){
            std::cout << cartas_descartadas[i] << ", ";
        }
        std::cout << cartas_descartadas[i] << std::endl;

        std::cout << "Remaining card: " << lista_numeros.front() << std::endl;

        // Limpa estruturas para próxima entrada;
        lista_numeros.clear();
        cartas_descartadas.clear();
        std::cin >> tamanho;
    }
}
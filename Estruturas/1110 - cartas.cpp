#include <iostream>
#include <string>
#include <list>

int main(){

    int i;
    int tamanho;
    int numero_extraido;
    int cartas_descartadas[50];
    int pos_cartas_descartadas;

    std::list<int> lista_cartas;
    std::cin >> tamanho;

    while(tamanho > 0){
        pos_cartas_descartadas = 0;
        // Cria uma lista de numeros de 1 até o tamanho
        // Inserindo no inicio começando do maior número
        // Até 1.
        while(tamanho > 0){
            lista_cartas.push_front(tamanho);
            tamanho -= 1;
        }

        while(lista_cartas.size() > 1){
            // Remove o número da frente
            numero_extraido = lista_cartas.front();
            lista_cartas.pop_front();
            cartas_descartadas[pos_cartas_descartadas] = numero_extraido;
            pos_cartas_descartadas += 1;

            // Coloca o próximo no final
            lista_cartas.push_back(lista_cartas.front());
            lista_cartas.pop_front();
        }

        // Impressão na tela
        std::cout << "Discarded cards: ";

        for(i = 0; i < pos_cartas_descartadas - 1; i++){
            std::cout << cartas_descartadas[i] << ", ";
        }
        std::cout << cartas_descartadas[i] << std::endl;

        std::cout << "Remaining card: " << lista_cartas.front() << std::endl;

        // Limpa estruturas para próxima entrada;
        lista_cartas.clear();
        std::cin >> tamanho;
    }
}

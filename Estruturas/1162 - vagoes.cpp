#include <iostream>

void swap(int &a, int &b){
    int aux;
    aux = a;
    a = b;
    b = aux;
}

int main(){

    int i;
    int qnt_entradas;
    int qnt_vagoes;
    int total_trocas;
    bool troca;

    // Leitura da quantidade de entradas
    std::cin >> qnt_entradas;

    while(qnt_entradas > 0){
        // Leitura da quantidade de vagoes e criacao do vetor de vagoes
        std::cin >> qnt_vagoes;
        int vagoes[qnt_vagoes];

        for(i = 0; i < qnt_vagoes; i++){
            std::cin >> vagoes[i];
        }

        troca = true;
        total_trocas = 0;
        // Realiza bubblesort e para cada troca, somar no total de trocas
        while(troca){
            troca = false;
            for(i = 0; i < qnt_vagoes - 1; i++){
                if(vagoes[i] > vagoes[i + 1]){
                    swap(vagoes[i], vagoes[i + 1]);
                    troca = true;
                    total_trocas += 1;
                }
            }
        }
        std::cout << "Optimal train swapping takes " << total_trocas << " swaps.\n";
        qnt_entradas -= 1;
    }
}

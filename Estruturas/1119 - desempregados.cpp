#include <iostream>
#include <queue>
#include <iomanip>
#include <stdio.h>

int pessoas[20];

int main() {

    int N, K, M;
    int selecionado1, selecionado2, cont, i;
    int pos1, pos2;

    std::cin >> N >> K >> M;

    while(N > 0){
        // Preenche vetor de pessoas e indica primeira
        // E ultima posição como iniciais para busca.
        pos1 = 0;
        pos2 = N-1;

        for(i = 0;i < N; i++){
            pessoas[i] = i + 1;
        }
        cont = 0;
        while(cont < N){
            // Busca o elemento em direção a direita.
            i = K;
            while (i > 0){
                //Verifica se o elemento não já foi removido.
                if(pessoas[pos1] > 0){
                    i -= 1;
                }
                // Se i for 0, o atual é o selecionado.
                if(i == 0){
                    selecionado1 = pos1;
                }
                // Passa a nova posicao pro proximo.
                pos1 = (pos1 + 1) % N;
            }
            // Busca o elemento em direção a esquerda.
            i = M;
            while(i > 0){
                //Verifica se o elemento não já foi removido.
                if(pessoas[pos2] > 0){
                    i -= 1;
                }
                // Se i for 0, o atual é o selecionado.
                if(i == 0){
                    selecionado2 = pos2;
                }
                // Passa a nova posicao pro anterior.
                pos2 = (pos2 + N - 1) % N;
            }
            // Verifica se não é o ultimo para adicionar ',' na impressão.
            if(cont > 0){
                std::cout << ",";
            }
            // Se forem diferentes, imprime os dois valores com os
            // Espaços necessários dividindo-os.
            if(selecionado1 != selecionado2){
                printf("%3d%3d",pessoas[selecionado1], pessoas[selecionado2]);
                cont += 2;
            } else {
                printf("%3d", pessoas[selecionado1]);
                cont++;
            }
            // Remove selecionados da lista.
            pessoas[selecionado1] = 0;
            pessoas[selecionado2] = 0;
        }
        std::cout << std::endl;
        std::cin >> N >> K >> M;
    }
}

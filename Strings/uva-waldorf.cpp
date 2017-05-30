#include <iostream>
#include <string>
#include <vector>


bool buscaAuxiliar(std::string palavra, std::vector<std::string> matriz, int pos_x, int pos_y, int i, int j){

    int count = 0;
    int q = 0;
    while(pos_x >= 0 and pos_x < matriz.size() and pos_y >= 0 and pos_y < matriz[0].size()){
        if(matriz[pos_x][pos_y] == palavra[q]){
            pos_x += i;
            pos_y += j;
            q += 1;
            count += 1;
        } else {
            break;
        }
    }
    return count == palavra.size();
}

void buscaElementos(std::string palavra, std::vector<std::string> matriz){
    int i, j;
    for(i = 0; i < matriz.size(); i++){
        for(j = 0; j < matriz[i].size(); j++){
            if(matriz[i][j] == palavra[0]){
                if(buscaAuxiliar(palavra, matriz, i, j, 0, 1) or buscaAuxiliar(palavra, matriz, i, j, 1, 0) or
                buscaAuxiliar(palavra, matriz, i, j, 1, 1) or buscaAuxiliar(palavra, matriz, i, j, -1, 0) or
                buscaAuxiliar(palavra, matriz, i, j, 0, -1) or buscaAuxiliar(palavra, matriz, i, j, -1, -1) or
                buscaAuxiliar(palavra, matriz, i, j, 1, -1) or buscaAuxiliar(palavra, matriz, i, j, -1, 1)){
                    std::cout << i + 1 << " " << j + 1 << std::endl;
                    return;
                }
            }
        }
    }
}

std::string lower(std::string linha){
    int i;
    for (i = 0; i < linha.size(); i++){
        if(linha[i] < 'a'){
            linha[i] += 32;
        }
    }
    return linha;
}

int main(){

    // Implementação usando Vector e String do C++
    // Poderia ser melhor se utilizasse apenas uma matriz de char.

    int i;
    int qnt_casos;
    int linhas, colunas;
    int qnt_buscas;
    std::string linha_branca;
    std::string aux;
    std::vector<std::string> matriz;

    scanf("%d", &qnt_casos);

    while(qnt_casos > 0){

        scanf("%d %d", &linhas, &colunas);

        for(i = 0; i < linhas; i++){
            std::cin >> aux;
            matriz.push_back(lower(aux));
        }

        std::cin >> qnt_buscas;

        while(qnt_buscas > 0){
            std::cin >> aux;
            buscaElementos(lower(aux), matriz);
            qnt_buscas -= 1;
        }
        matriz.clear();
        if(qnt_casos > 1){
            std::cout << std::endl;
        }
        qnt_casos -= 1;
    }
}

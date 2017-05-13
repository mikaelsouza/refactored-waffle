#include <iostream>
#include <vector>
#include <numeric>

int main(){
    int qnt_individuos;
    int qnt_casos;
    int saltos;
    int i;
    int caso_atual;

    std::vector<int> lista_individuos;
    std::cin >> qnt_casos;

    caso_atual = 1;

    while(caso_atual <= qnt_casos){
        // Leitura das quantidade de indivíduos e o tamanho do salto.
        std::cin >> qnt_individuos >> saltos;

        // Criando lista de pessoas com seus respectivos números.
        for(i = 1; i <= qnt_individuos; i++){
            lista_individuos.push_back(i);
        }

        // Contando o elemento atual como um salto e tratando o caso
        // do tamanho do salto ser maior que a vector de indivíduos.
        i = saltos - 1;
        i = i % lista_individuos.size();

        // Enquanto houver mais de 1 pessoa, eliminar a pessoa da posicao
        // i e calcular o próximo alvo.
        while(lista_individuos.size() > 1){
            lista_individuos.erase(lista_individuos.begin() + i);
            i += saltos - 1;
            i = i % lista_individuos.size();
        }

        // Imprime indivíduo remanescente, reseta estrutura.
        std::cout << "Case " << caso_atual << ": " << lista_individuos[0] << std::endl;
        lista_individuos.clear();
        caso_atual += 1;
    }
}

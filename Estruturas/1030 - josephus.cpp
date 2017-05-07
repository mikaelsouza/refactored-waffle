#include <iostream>
#include <vector>
#include <numeric>

int main(){
    int qnt_individuos;
    int qnt_casos;
    int saltos;
    int i;
    int j;

    std::cin >> qnt_casos;

    j = 0;

    while(j < qnt_casos){
        std::cin >> qnt_individuos >> saltos;
        std::vector<int> lista_individuos(qnt_individuos);

        iota(begin(lista_individuos), end(lista_individuos), 1);
        i = saltos - 1;
        i = i % lista_individuos.size();

        while(lista_individuos.size() > 1){
            lista_individuos.erase(lista_individuos.begin() + i);
            i += (saltos - 1);
            i = i % lista_individuos.size();
        }

        for(auto v:lista_individuos){
            std::cout << "Case " << j + 1 << ": " << v << std::endl;
        }

        j += 1;
    }
    return 0;
}

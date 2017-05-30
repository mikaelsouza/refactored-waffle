#include <iostream>
#include <unordered_map>

int main(){

    int qnt_casos;
    int qnt_valores;
    int qnt_compras;
    float valor;
    int qnt;
    float total;
    std::string fruta;

    std::unordered_map<std::string, double> precos;

    std::cin >> qnt_casos;

    while(qnt_casos > 0){
        total = 0;
        std::cin >> qnt_valores;
        while(qnt_valores > 0){
            std::cin >> fruta >> valor;
            precos[fruta] = valor;
            qnt_valores -= 1;
        }
        std::cin >> qnt_compras;
        while(qnt_compras > 0){
            std::cin >> fruta >> qnt;
            total += precos[fruta] * qnt;
            qnt_compras -= 1;
        }
        printf("R$ %.2f\n", total);
        qnt_casos -= 1;
    }
}

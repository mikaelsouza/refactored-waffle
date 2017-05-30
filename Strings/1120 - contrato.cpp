#include <iostream>
#include <string>

std::string removeZeroes(std::string numero){
    int qnt = 0;
    int i;
    for(i = 0; i < numero.size(); i++){
        if(numero[i] == '0'){
            qnt += 1;
        } else {
            break;
        }
    }
    numero.erase(0, qnt);
    if(numero == ""){
        numero = "0";
    }
    return numero;
}

int main(){

    std::string primeira, segunda;
    std::cin >> primeira >> segunda;
    int pos;

    while(primeira != "0" and segunda != "0"){
        pos = segunda.find(primeira);
        while(pos != -1){
            segunda.erase(pos, 1);
            pos = segunda.find(primeira);
        }
        std::cout << removeZeroes(segunda) << std::endl;
        std::cin >> primeira >> segunda;
    }
}

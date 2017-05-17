#include <iostream>
#include <vector>
#include <algorithm>


int busca_binaria(int valor, std::vector<int> &elementos){
    int i = 0;
    int j = elementos.size() - 1;
    int meio;
    while(i <= j){
	meio = (i + j) / 2;
	if (valor < elementos[meio]){
	    j = meio - 1;
	} else if(valor > elementos[meio]){
	    i = meio + 1;
	}
	else if(valor == elementos[meio]){
	    return meio;
	}

    }
    return -1;
}

int main(){

    int qnt_marmores, qnt_tentativas;
    int aux;
    int found;
    int casos = 1;
    std::vector<int> marmores;
    std::vector<int> buscas;
    
    std::cin >> qnt_marmores >> qnt_tentativas;
    
    while (qnt_marmores > 0 && qnt_tentativas > 0){
	
	while(qnt_marmores > 0){
	    std::cin >> aux;
	    marmores.push_back(aux);
	    qnt_marmores -= 1;
	}

	std::sort(marmores.begin(), marmores.end());


	while(qnt_tentativas > 0){

	    std::cin >> aux;
	    buscas.push_back(aux);
	    qnt_tentativas -= 1;
	}

	std::cout << "CASE# " << casos << ":" << std::endl;
	
	for(auto v :buscas) {
	    aux = v;

	    found = busca_binaria(aux, marmores);
	    if(found > -1){
		while(marmores[found] == aux){
		    found -= 1;
		}
		found += 1;
	    }
	    
	    if(found != -1){
		std::cout << aux << " found at " << found + 1 << std::endl;
		
	    } else {
		std::cout << aux << " not found" << std::endl;
	    }
	    
	}
	
	buscas.clear();
	marmores.clear();
	casos += 1;
	std::cin >> qnt_marmores >> qnt_tentativas;
    }
    return 0;
}

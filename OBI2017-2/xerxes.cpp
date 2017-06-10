#include <iostream>
#include <vector>
#include <algorithm>

int main(){

	int qnt_jogadas;
	std::cin >> qnt_jogadas;

	std::vector<std::vector<int> >grafinho(5);

	for(int i = 0; i < 5; i++){
		for(int j = i; j < i + 2; j++){
			grafinho[i].push_back((j + 1) % 5);
		}
	}
	
	int dario;
	int xerxes;
	
	int d_win = 0;
	int x_win = 0;

	while(qnt_jogadas--){
		std::cin >> dario >> xerxes;
		std::vector<int>::iterator it;
		it = std::find(grafinho[dario].begin(), grafinho[dario].end(), xerxes);
		if(it != grafinho[dario].end()){
			d_win += 1;
		} else {
			x_win += 1;
		}
		
	}
	
	if(d_win > x_win){
		std::cout << "dario" << std::endl;
	} else {
		std::cout << "xerxes" << std::endl;
	}
}

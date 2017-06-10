#include <iostream>
#include <vector>

int coord_x;
int coord_y;

bool percorre_matriz(char** matriz, int linhas, int colunas, int x, int y){
	if(x < 0 || y < 0 || x >= linhas || y >= colunas){
		return false;
	}

	if(matriz[x][y] == 'H'){
		coord_x = x;
		coord_y = y;
		matriz[x][y] = '.';

	return (percorre_matriz(matriz, linhas, colunas, x + 1, y) or percorre_matriz(matriz, linhas, colunas, x - 1, y) or percorre_matriz(matriz, linhas, colunas, x, y + 1) or percorre_matriz(matriz, linhas, colunas, x,  y - 1));

	} else {
		return false;
	}


	
}


int main(){

	int linhas;
	int colunas;

	std::cin >> linhas >> colunas;

	char **matriz = (char**)malloc(sizeof(char*) * linhas);

	for(int i = 0; i < linhas; i++){
		matriz[i] = (char*)malloc(sizeof(char) * colunas);
	}
	int x, y;

	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			scanf(" %c", &matriz[i][j]);
			if(matriz[i][j] == 'o'){
				x = i;
				y = j;
				matriz[i][j] = 'H';
			}
		}
	}

	percorre_matriz(matriz, linhas, colunas, x, y);
	std::cout << coord_x + 1 << " "<< coord_y + 1 << std::endl;
}



#include <stdio.h>
#include <stdlib.h>

int stringlen(char *texto){
    int size;
    for(size = 0; texto[size] != '\0'; size++);
    return size;
}

int stringcompare(char *palavra1, char *palavra2){

    int i;
    int palavra1_tam = stringlen(palavra1);
    int palavra2_tam = stringlen(palavra2);

    if(palavra1_tam == palavra2_tam){
        for(i = 0; i < palavra1_tam; i++){
            if(palavra1[i] != palavra2[i]){
                return -1;
            }
        }
        return 0;
    }
    return -1;
}

int find(char letra, char *palavra){

    int i;
    int tamanho_palavra = stringlen(palavra);

    for(i = 0; i < tamanho_palavra; i++){
        if(palavra[i] == letra){
            return i;
        }
    }
    return -1;
}

void erase(int posicao, char *palavra){

    int i;
    int tamanho_palavra = stringlen(palavra);

    for(i = posicao; i < tamanho_palavra; i++){
        palavra[i] = palavra[i + 1];
    }
}

void removeZero(char *palavra){

    int tamanho_palavra = stringlen(palavra);
    int i, j;

    for(i = 0; i < tamanho_palavra; i++){
        if(palavra[i] != '0'){
            break;
        }
    }

    for(j = 0; j + i < tamanho_palavra + 1; j++){
        palavra[j] = palavra[j + i];
    }

    if(stringlen(palavra) == 0){
        palavra[0] = '0';
        palavra[1] = '\0';
    }
}

int main(){

    char digito;
    char *numero = malloc(sizeof(char) * 1001);
    int posicao;

    scanf(" %c %s", &digito, numero);

    while(digito != '0' && stringcompare(numero, "0")){
        posicao = find(digito, numero);
        while(posicao != -1){
            erase(posicao, numero);
            posicao = find(digito, numero);
        }
        removeZero(numero);
        printf("%s\n", numero);
        scanf(" %c %s", &digito, numero);
    }
}

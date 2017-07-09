#include <stdio.h>
#include <stdlib.h>

int stringlen(char *texto){
    int size;
    for(size = 0; texto[size] != '\0'; size++);
    return size;
}

void primeirasLetras(char *linha){

    char palavra[100] = "";
    int tam_palavra = 0;

    int i;
    char vazio = 1;

    int tamanho_linha = stringlen(linha);
    for(i = 0; i < tamanho_linha; i++){
        if(linha[i] >= 'a' && linha[i] <= 'z' && vazio){
            palavra[tam_palavra] = linha[i];
            palavra[tam_palavra + 1] = '\0';
            tam_palavra += 1;
            vazio = 0;
        } else if(linha[i] == ' '){
            vazio = 1;
        }
    }
    printf("%s\n", palavra);
}

int main(){

    int qnt_casos;
    char linha[100];

    scanf("%d", &qnt_casos);
    getchar();

    while(qnt_casos--){
        fgets(linha, 100, stdin);
        primeirasLetras(linha);
    }
}

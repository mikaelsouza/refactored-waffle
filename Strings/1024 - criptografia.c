#include <stdio.h>

int stringlen(char *texto){
    int size;
    for(size = 0; texto[size] != '\n'; size++);
    return size;
}

void deslocamentoDireita(char* texto){
    int i;
    int tam_texto = stringlen(texto);
    for(i = 0; i < tam_texto; i++){
        if((texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z')){
            texto[i] += 3;
        }
    }
}

void inversao(char* texto){
    char aux;
    int i;
    int tam_texto = stringlen(texto);
    for(i = 0; i < tam_texto / 2; i++){
        aux = texto[i];
        texto[i] = texto[tam_texto - 1 - i];
        texto[tam_texto - 1 - i] = aux;
    }
}

void deslocamentoEsquerda(char* texto){
    int i;
    int tam_texto = stringlen(texto);
    for(i = tam_texto / 2; i < tam_texto; i++){
        texto[i] -= 1;
    }
}

int main(){

    int qnt_entradas;
    int buffer_size = 1002;
    char texto[buffer_size];
    scanf("%d", &qnt_entradas);
    getchar();

    while(qnt_entradas > 0){
        fgets(texto, buffer_size, stdin);
        deslocamentoDireita(texto);
        inversao(texto);
        deslocamentoEsquerda(texto);
        printf("%s", texto);
        qnt_entradas -= 1;
    }
}

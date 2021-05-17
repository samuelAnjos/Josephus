#include <stdio.h>
#include <stdlib.h>

typedef struct no{
   char nome[20];
   struct no *proxNo;
}tipoNo;

typedef struct listaGerenciadora{
    tipoNo *fim;
    int qtdade;
}tipoLista;

void inicializarLista(tipoLista *lista){
    lista->fim = NULL;
    lista->qtdade = 0;
}

int main(){

    //Josephus
    return 0;
}

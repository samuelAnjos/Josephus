#include <stdio.h>
#include <stdlib.h>

typedef struct no{
   char *nome;
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

int inserirListaVazia(tipoLista *lista, char *nome){
    tipoNo *novoNome;
    novoNome = (tipoNo *) malloc(sizeof(novoNome));

    if(novoNome == NULL){
        return 0;
    }else{
        novoNome->nome = nome;
        novoNome->proxNo = novoNome;
        lista->fim = novoNome;
        lista->qtdade++;
        return 1;
    }
}

void mostrarLista(tipoLista *lista){ // tem que mostrar o que saiu no momento
    tipoNo *atual;
    atual=lista->fim->proxNo;
    printf(" %d ", atual->nome);
    while(atual!=lista->fim){
        atual = atual->proxNo;
        printf(" %d ", atual->nome);
    }
}

int main(){

    tipoLista lista;
    int op;
    char aux;
    inicializarLista(&lista);
    do{
        printf("\nMenu");
        printf("\n1 - nInserir Lista Vazia");
        //printf("\n2 - Insere na frente\n3 - Insere no fim");
        printf("\n9 - Exibe a lista");
        printf("\n0 - Sai do programa");
        printf("\nDigite sua opcao:");
        scanf("%d",&op);
        switch(op){
        case 1:
            printf("\nDigite outro numero inteiro:");
            gets(aux);
            if(inserirListaVazia(&lista,&aux);
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");
            break
        case 2:
            /*printf("\nDigite outro numero inteiro:");
            scanf("%d",&aux);
            if(insereNaFrente(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");*/

        case 9: mostrarLista(&lista);
            break;
        case 0: printf("\nEncerrando programa");
            //destruirLista(&lista);
            break;
        default: printf("\nOpcao invalida!");
        }
    }while(op != 0);
    return 0;
}

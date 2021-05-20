#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

int gerarNumero(){
    srand(time(NULL));
    int x;
    //eu botei 10 pois ele vai gera numeros de 0 a 10,
    //e como so vai ter 10 participantes
    x = rand()%10;

    return x;
}
int inserirListaVazia(tipoLista *lista, char nome[20]){
    tipoNo *novoNome;
    novoNome = (tipoNo *) malloc(sizeof(novoNome));

    if(novoNome == NULL){
        return 0;
    }else{
        strcpy(novoNome->nome, nome);
        novoNome->proxNo = novoNome;
        lista->fim = novoNome;
        lista->qtdade++;
        return 1;
    }
}

void mostrarLista(tipoLista *lista){ // tem que mostrar o que saiu no momento
    tipoNo *atual;
    atual=lista->fim->proxNo;
    printf(" %s ", atual->nome);
    while(atual!=lista->fim){
        atual = atual->proxNo;
        printf(" %s ", atual->nome);
    }
}

int main(){

    tipoLista lista;
    int op, numAleatorio;
    char aux[20];
    inicializarLista(&lista);
    do{
        printf("\nMenu");
        printf("\n1 - nInserir Lista Vazia");
        //printf("\n2 - Insere na frente");
        //n3 - Insere no fim");
        printf("\n4 - Gerar numero");
        printf("\n9 - Exibe a lista");
        printf("\n0 - Sai do programa");
        printf("\nDigite sua opcao:");
        scanf("%d",&op);
        switch(op){
        case 1:
            printf("\nDigite outro numero inteiro:");
            scanf("%s", &aux);
            if(inserirListaVazia(&lista,aux)){
                printf("\nDado inserido com sucesso");
            }else{
                printf("\nInsercao nao efetuada");
            }
            break;
        case 2:
            /*printf("\nDigite outro numero inteiro:");
            scanf("%d",&aux);
            if(insereNaFrente(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");*/
            break;
        case 4:
            //so pra testar a funcao
            numAleatorio = gerarNumero();
            printf("numero: %d", numAleatorio);
            break;
        case 9:
            mostrarLista(&lista);
            break;
        case 0: printf("\nEncerrando programa");
            //destruirLista(&lista);
            break;
        default: printf("\nOpcao invalida!");
        }
    }while(op != 0);
    return 0;
}

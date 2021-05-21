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
    //foi colocando 10 pois ele vai gera numeros de 0 a 10,
    //e como so vai ter 10 participantes
    x = rand()%10;

    return x;
}

// feita hoje

char* removerInicio(tipoLista *lista){ // remove do inicio
   tipoNo *que_sera_apagado;
   que_sera_apagado = lista->fim->proxNo;
   lista->fim->proxNo= lista->fim->proxNo->proxNo; // inicio aponta para o proximo dele
   if(lista->qtdade==1)
       lista->fim = NULL;
   return que_sera_apagado;
}

char* removerFim(tipoLista *lista){
   tipoNo *atual, *anterior;
   atual = lista->fim->proxNo;

   if(lista->qtdade == 1){ //atual->proxNo ==  atual
      lista->fim = NULL;
      lista->qtdade--;
   }else{
      while(atual != lista->fim){
          anterior = atual;
          atual = atual->proxNo;
      }
      anterior->proxNo = lista->fim->proxNo; //atual->proxNo
      lista->fim = anterior;
   }
    return atual;

}
void removerDeterminadaPosicao(tipoLista *listt, int pos){
   tipoNo *anterior, *atual;
   atual = listt->fim->proxNo;

   if(pos > 0 && pos <= listt->qtdade){
      if(pos == 1){
         atual = removerInicio(listt);
      }else if(pos == listt->qtdade){ // lista->qtdade
         atual = removerFim(listt);
      }else if(pos != 1 && pos != listt->qtdade){
         for(int x=1; x<=pos-1; x++){
            anterior=atual;
            atual=atual->proxNo;
          }
        anterior->proxNo = atual->proxNo;
      }

   } //if geral
    printf("\nnome: %s \n", atual->nome);
    free(atual);
    listt->qtdade--;
}

int InserirFrente(tipoLista *lista, char nome[20]){

    tipoNo *novoNome;

    if(lista->fim == NULL){
        inserirListaVazia(lista, nome);
    }
    else{
        novoNome = (tipoNo *) malloc(sizeof(tipoNo));
        if(novoNome == NULL)
            return 0;
        strcpy(novoNome->nome, nome);
        novoNome->proxNo = lista->fim->proxNo;
        lista->fim->proxNo = novoNome;
        lista->qtdade++;

        return 1;

    }
}

int inserirListaVazia(tipoLista *lista, char nome[20]){
    tipoNo *novoNome;
    novoNome = (tipoNo *) malloc(sizeof(novoNome));

    if(novoNome == NULL){
        return 0;
    }else{
        strcpy(novoNome->nome, nome);//strcpy passar o que tem dentro de nome para novoNome->nome
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
    int op, numAleatorio, x;//o x aqui é so pra testar
    char aux[20];
    inicializarLista(&lista);
    do{
        printf("\nMenuno");
        printf("\n1 - Inserir Lista Vazia");
        printf("\n2 - Insere na frente");
        //n3 - Insere no fim");
        printf("\n4 - Gerar numero");
        printf("\n5- remover da posicao");
        printf("\n9 - Exibe a lista");
        printf("\n0 - Sai do programa");
        printf("\nDigite sua opcao:");
        scanf("%d",&op);
        switch(op){
        case 1:
            printf("\nDigite outro nome: ");
            scanf("%s", &aux);
            if(inserirListaVazia(&lista,aux)){
                printf("\nDado inserido com sucesso");
            }else{
                printf("\nInsercao nao efetuada");
            }
            break;
        case 2:
            printf("\nDigite outro nome: ");
            scanf("%s",&aux);
            if(InserirFrente(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");
            break;
        case 4:
            //so pra testar a funcao
            numAleatorio = gerarNumero();
            printf("numero: %d", numAleatorio);
            break;
        case 5:
            printf("Digite uma posicao que deseja remover: ");
            scanf("%d", &x);
            removerDeterminadaPosicao(&lista, x);
        case 9:
            mostrarLista(&lista);
            break;
        case 0: printf("\nEncerrando programa");

            break;
        default: printf("\nOpcao invalida!");
        }
    }while(op != 0);

}




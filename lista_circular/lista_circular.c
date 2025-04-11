#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

//criar lista circular vazia
Lista* criar_lista(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->fim = NULL;
    
    return lista;
}

// Insere um valor no inicio da lista
void inserir_inicio(Lista* lista, int valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;

    //verificar
    if(lista->fim == NULL){
        novo->proximo = valor;
        lista->fim = novo;
    }else{
        novo->proximo = lista->fim->proximo;
        lista->fim->proximo = novo;
    }
}
// Insere valor no final da lista
void inserir_fim(Lista* lista, int valor){

    inserir_inicio(lista, valor);
    lista->fim = lista->fim->proximo;
}
// Exibi elementos da lista
void exibir_lista(Lista* lista){
    if(lista->fim == NULL){
        printf("Lista vazia.\n");
        return;
    }

    No* atual = lista->fim->proximo;

    do{

        printf("%d ->",atual->valor);
        atual = atual->proximo;

    }while(atual != lista->fim->proximo);

    printf("volta ao inicio.\n");

}
// Libera memoria na lista
void liberar_lista(Lista* lista){

    if(lista->fim == NULL){
        free(lista);
        return;
    }

    No* atual = lista->fim->proximo;
    No* temp;

    do{
        temp = atual;
        atual = atual->proximo;
        free(temp);

    }while(atual != lista->fim->proximo);

    free(lista);
}

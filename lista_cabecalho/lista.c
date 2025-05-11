#include <stdio.h>

#include <stdlib.h>

#include "lista.h"


Lista* criarLista() {

Lista* lista = (Lista*)malloc(sizeof(Lista));

lista->cabeca = (No*)malloc(sizeof(No)); // nó de cabeçalho

lista->cabeca->prox = NULL;

return lista;

}


void inserirInicio(Lista* lista, int valor) {

No* novo = (No*)malloc(sizeof(No));

novo->dado = valor;

novo->prox = lista->cabeca->prox;

lista->cabeca->prox = novo;

}
void imprimirLista(Lista* lista) {

No* atual = lista->cabeca->prox;

while (atual != NULL) {

printf("%d -> ", atual->dado);

atual = atual->prox;

}

printf("NULL\n");

}


int remover(Lista* lista, int valor) {

No* ant = lista->cabeca;

No* atual = ant->prox;


while (atual != NULL && atual->dado != valor) {

ant = atual;

atual = atual->prox;

}


if (atual == NULL) return 0; // não encontrado


ant->prox = atual->prox;

free(atual);

return 1; // removido com sucesso

}


void liberarLista(Lista* lista) {

No* atual = lista->cabeca;

while (atual != NULL) {

No* temp = atual;

atual = atual->prox;

free(temp);

}

free(lista);

}

//No* novo = (No*)malloc(sizeof(No));
void reverterLista(Lista* lista){
    No* anterior =(No*)malloc(sizeof(No));
    No* atual =(No*)malloc(sizeof(No));
    No* proximo =(No*)malloc(sizeof(No));

    anterior = NULL;
    proximo = NULL
    atual = lista->cabeca->prox;

    while(atual != NULL){
        proximo = atual->prox; 
        atual->prox = anterior; //inverte o ponteiro

        //mover
        anterior = atual;
        atual = proximo;


    }

    lista->cabeca->prox = anterior;


}

int obterMaior(Lista* lista){
    int maior = 0;
    No* atual = lista->cabeca->prox;

    if(!estaVazia(lista)){
        maior = atual->dado;

        while (atual != NULL) {
        if(atual->dado > maior){
            maior = atual->dado;
        }

        atual = atual->prox;
        }

    return maior;
    }
}

int obterMenor(Lista* lista){
    int menor = 0;
    No* atual = lista->cabeca->prox;

    if(!estaVazia(lista)){
        menor = atual->dado;

        while (atual != NULL) {
        if(atual->dado < menor){
            menor = atual->dado;
        }

        atual = atual->prox;
    }

    return menor
    }
}

int estaVazia(Lista* lista){
    if(lista->cabeca->prox == NULL){
        return 1;
    }
    return 0;
}

Lista* copiarLista(Lista* lista){
    Lista* copia = criar_lista();

    No* atual = lista->cabeca->prox;
    No* atual_copia = copia->cabeca;

    while(atual != NULL){
        //cria novo no para ser inserido na copia lista
        No* novo = (No*)malloc(sizeof(No));
        novo->dado = atual->dado; // copia os dados
        novo->prox = NULL;

        atual_copia->prox = novo;
        atual_copia = novo;
        
        atual = atual->prox;
    }

    return copia;
}


void concatenarListas(Lista* l1, Lista* l2){
    No* atual_l1 = l1->cabeca;
    No* atual_l2 = l2->cabeca->prox;
    //verifica se l2 nao esta vazia
    if(atual_l2 != NULL){ 
            // se nao estiver vai ate o final da lista l1 
            while( atual_l1->prox != NULL){
                atual_l1 = atual_l1->prox;
            }    
        }
    // e liga o primeiro no de l2 no final de l1
    atual_l1->prox = atual_l2;
    //libera l2
    liberarLista(l2);
}

void removerDuplicatas(Lista* lista){
    //ponteiro q percorre a lista do inicio ate o fim
    No* atual = lista->cabeca->prox;
    while (atual != NULL) {
        No* anterior = atual;
        No* comparar = atual->prox;
        //compara se o anterior é igual o atual
        while (comparar != NULL) {
            if (comparar->dado == atual->dado) {
                //se sim guarda o prox no anterior
                anterior->prox = comparar->prox;
                //remove
                free(comparar);
                comparar = anterior->prox; // avança 
            } else {
                anterior = comparar;
                comparar = comparar->prox;
            }
        }

    atual = atual->prox;
}
}

//No* novo = (No*)malloc(sizeof(No));
void inserirFim(Lista* lista, int valor){
    No* atual = lista->cabeca;
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
        //percorre ate o final da lista
        while(atual->prox != NULL){
            atual = atual->prox;
        }
    //no final adc novo valor
    atual->prox = novo;  
}

int contarElementos(Lista* lista){

    No* atual = lista->cabeca->prox;

    int tamanho_lista = 0;
        while (atual != NULL) {
            tamanho_lista++;
            atual = atual->prox;
        }
    return tamanho_lista;

}

int buscar(Lista* lista, int valor){

    No* atual = lista->cabeca->prox;

    //verifica se a lista nao esta vazia
    if(!estaVazia(lista)){
        //faz um loop na lista ate encontrar o valor caso contrario retorna -1
        while(atual != NULL){
            if(atual->dado == valor){
                return atual->dado;
            }
            atual = atual->prox;
        }


    }
    return -1;

}
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

void reverterLista(Lista* lista);

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

    return maior
    

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

int estaVazia(Lista* lista){
    if(lista->cabeca->prox == NULL){
        return 1;
    }
    return 0;
}

Lista* copiarLista(Lista* lista);

void concatenarListas(Lista* l1, Lista* l2);

void removerDuplicatas(Lista* lista);

void inserirFim(Lista* lista, int valor);

int contarElementos(Lista* lista){

    No* atual = lista->cabeca->prox;

    int tamanho_lista = 0;
        while (atual != NULL) {
            tamanho_lista++;
            atual = atual->prox;
        }
    return tamanho_lista;

}

int buscar(Lista* lista, int valor);
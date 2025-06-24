#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"
// Cria uma nova lista vazia
Lista* criar_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista) {
        lista->cabeca = NULL;
        lista->cauda = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

// Insere um valor no início da lista
void inserir_inicio(Lista* lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return;

    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = lista->cabeca;

    if (lista->cabeca != NULL)
        lista->cabeca->anterior = novo;
    else
        lista->cauda = novo; // Era a primeira inserção

    lista->cabeca = novo;
    lista->tamanho++;
}

// Insere um valor no fim da lista
void inserir_fim(Lista* lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return;

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->cauda;

    if (lista->cauda != NULL)
        lista->cauda->proximo = novo;
    else
        lista->cabeca = novo; // Era a primeira inserção

    lista->cauda = novo;
    lista->tamanho++;
}

// Exibe a lista do início ao fim
void exibir_lista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Exibe a lista da frente para trás
void exibirFrente(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Exibe a lista de trás para frente
void exibirTras(Lista* lista) {
    No* atual = lista->cauda;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

// Libera todos os nós da lista e a própria lista
void liberar_lista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}

// Insere um valor em uma posição específica da lista
void inserir_posicao(Lista* lista, int valor, int posicao) {
    if (posicao < 0 || posicao > lista->tamanho) {
        printf("Posição inválida.\n");
        return;
    }

    if (posicao == 0) {
        inserir_inicio(lista, valor);
        return;
    }

    if (posicao == lista->tamanho) {
        inserir_fim(lista, valor);
        return;
    }

    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return;

    novo->valor = valor;

    No* atual = lista->cabeca;
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    novo->proximo = atual;
    novo->anterior = atual->anterior;

    if (atual->anterior)
        atual->anterior->proximo = novo;
    atual->anterior = novo;

    lista->tamanho++;
}

// Remove o nó da posição especificada
void remover_posicao(Lista* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posição inválida.\n");
        return;
    }

    No* atual = lista->cabeca;

    if (posicao == 0) {
        lista->cabeca = atual->proximo;
        if (lista->cabeca)
            lista->cabeca->anterior = NULL;
        else
            lista->cauda = NULL; // Lista ficou vazia
        free(atual);
        lista->tamanho--;
        return;
    }

    if (posicao == lista->tamanho - 1) {
        atual = lista->cauda;
        lista->cauda = atual->anterior;
        if (lista->cauda)
            lista->cauda->proximo = NULL;
        else
            lista->cabeca = NULL; // Lista ficou vazia
        free(atual);
        lista->tamanho--;
        return;
    }

    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    atual->anterior->proximo = atual->proximo;
    atual->proximo->anterior = atual->anterior;
    free(atual);
    lista->tamanho--;
}

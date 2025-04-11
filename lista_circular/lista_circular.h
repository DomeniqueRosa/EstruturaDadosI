#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct No{
    int valor;
    struct No* proximo;
}No;

typedef struct Lista{
    No* fim; // ponteiro para o ultimo nó
}Lista;

Lista* criar_lista();
void inserir_inicio(Lista* lista, int valor);
void inserir_fim(Lista* lista, int valor);
void exibir_lista(Lista* lista);
void liberar_lista(Lista* lista);

#endif
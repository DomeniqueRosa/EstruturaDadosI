#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct No{
    int valor;
    struct No* anterior;
    struct No* proximo;
}No;

typedef struct Lista{
    No* cabeca;   // Ponteiro para o primeiro nó da lista
    No* cauda;    // Ponteiro para o último nó da lista
    int tamanho;
}Lista;

Lista* criar_lista();
void inserir_inicio(Lista* lista, int valor);
void inserir_fim(Lista* lista, int valor);
void exibir_lista(Lista* lista);
void liberar_lista(Lista* lista);
void exibirFrente(Lista* lista);
void exibirTras(Lista* lista);
void inserir_posicao(Lista* lista, int valor, int posicao);
void remover_posicao(Lista* lista, int posicao);

#endif
#ifndef ESTRUTURA_FILAS_H
#define ESTRUTURA_FILAS_H

#include <stdbool.h>

#define MAX 100


// EXERCÍCIO 1 – Fila de Clientes


typedef struct {
    int numero;
    char nome[50];
    int tempo_atendimento; // em minutos
} Cliente;

typedef struct {
    Cliente clientes[MAX];
    int frente;
    int tras;
    int tamanho;
} Fila;

// Funções da fila de clientes
void inicializa_fila(Fila* f);
bool adicionar_cliente(Fila* f, Cliente c);
bool atender_cliente(Fila* f, Cliente* c);
float tempo_medio_espera(Fila f);


//  EXERCÍCIO 2 – Verificador de Palíndromos (Fila + Pilha)


typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

typedef struct {
    char itens[MAX];
    int frente, tras, tamanho;
} FilaChar;

// Pilha
void inicializa_pilha(Pilha* p);
bool empilha(Pilha* p, char ch);
bool desempilha(Pilha* p, char* ch);

// Fila de caracteres
void inicializa_fila_char(FilaChar* f);
bool enfileira(FilaChar* f, char ch);
bool desenfileira(FilaChar* f, char* ch);

// Verificação de palíndromo
bool eh_palindromo(char* palavra);


//  EXERCÍCIO 3 – Fila de Prioridade Simples


typedef struct {
    char dado[50];
    int prioridade; // 1 = alta, 2 = média, 3 = baixa
} ItemPrioridade;

typedef struct {
    ItemPrioridade itens[MAX];
    int tamanho;
} FilaPrioridade;

// Funções da fila de prioridade
void inicializa_fila_prioridade(FilaPrioridade* f);
bool fila_enqueue_prioridade(FilaPrioridade* f, ItemPrioridade item);

#endif 
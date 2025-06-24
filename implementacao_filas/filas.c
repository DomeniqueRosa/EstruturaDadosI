#include <stdio.h>
#include <string.h>
#include "filas.h"


// EXERCÍCIO 1 – Fila de Clientes


void inicializa_fila(Fila* f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

bool adicionar_cliente(Fila* f, Cliente c) {
    if (f->tamanho == MAX) return false;
    f->tras = (f->tras + 1) % MAX;
    f->clientes[f->tras] = c;
    f->tamanho++;
    return true;
}

bool atender_cliente(Fila* f, Cliente* c) {
    if (f->tamanho == 0) return false;
    *c = f->clientes[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return true;
}

float tempo_medio_espera(Fila f) {
    if (f.tamanho == 0) return 0;
    int total = 0;
    for (int i = 0; i < f.tamanho; i++) {
        total += f.clientes[(f.frente + i) % MAX].tempo_atendimento;
    }
    return (float)total / f.tamanho;
}
// EXERCÍCIO 2 – Verificador de Palíndromos (Fila + Pilha)


bool enfileira(FilaChar* f, char ch) {
    if (f->tamanho == MAX) {
        return false;  // Fila cheia
    }

    f->tras = (f->tras + 1) % MAX;
    f->itens[f->tras] = ch;
    f->tamanho++;
    return true;
}

bool desenfileira(FilaChar* f, char* ch) {
    if (f->tamanho == 0) {
        return false;  // Fila vazia
    }

    *ch = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return true;
}



void inicializa_pilha(Pilha* p) {
    p->topo = -1;
}

bool empilha(Pilha* p, char ch) {
    if (p->topo == MAX - 1) return false;
    p->itens[++p->topo] = ch;
    return true;
}

bool desempilha(Pilha* p, char* ch) {
    if (p->topo == -1) return false;
    *ch = p->itens[p->topo--];
    return true;
}

void inicializa_fila_char(FilaChar* f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}
#include <ctype.h>  // Para isalpha() e tolower()

bool eh_palindromo(char* palavra) {
    Pilha p;
    FilaChar f;
    inicializa_pilha(&p);
    inicializa_fila_char(&f);

    for (int i = 0; palavra[i] != '\0'; i++) {
        char ch = tolower(palavra[i]);
        if (isalpha(ch)) { // Ignora espaços e pontuação
            empilha(&p, ch);
            enfileira(&f, ch);
        }
    }

    char a, b;
    while (p.topo != -1 && f.tamanho > 0) {
        desempilha(&p, &a);
        desenfileira(&f, &b);
        if (a != b) return false;
    }
    return true;
}
void inicializa_fila_prioridade(FilaPrioridade* f) {
    f->tamanho = 0;
}
bool fila_enqueue_prioridade(FilaPrioridade* f, ItemPrioridade item) {
    if (f->tamanho == MAX) return false;

    int i = f->tamanho - 1;

    // Inserção ordenada por prioridade (1 = alta, 3 = baixa)
    while (i >= 0 && f->itens[i].prioridade > item.prioridade) {
        f->itens[i + 1] = f->itens[i];
        i--;
    }

    f->itens[i + 1] = item;
    f->tamanho++;
    return true;
}

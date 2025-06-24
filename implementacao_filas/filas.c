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

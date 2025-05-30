#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stlib.h>
#include <stdbool.h>

// definicao do tipo de dado que a fila armazena
typedef int TipoItem;

// estrutura da fila
typedef struct fila Fila;

//prototicos das operacooes do TAD
Fila* fila_criar();
void fila_destruir(Fila* fila);
bool fila_inserir(Fila* fila, TipoItem item);
bool fila_remover(Fila* fila, TipoItem* item);
bool fila_front(Fila* fila, TipoItem* item);
bool fila_vazio(Fila* fila);
int fila_size(Fila* fila);
void fila_imprimir(Fila* fila);

#endif
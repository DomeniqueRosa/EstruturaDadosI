#include <stdio.h>
#include <stdbool.h>

#include "pilhas.h"



void inicializar(PilhaChar *p) {
    p->topo = -1;
}

bool pushChar(PilhaChar *p, char c) {
    if (p->topo >= 49) return false; // pilha cheia
    p->dados[++(p->topo)] = c;
    return true;
}

char popChar(PilhaChar *p) {
    if (p->topo < 0) return '\0'; // pilha vazia
    return p->dados[(p->topo)--];
}

char topChar(PilhaChar *p) {
    if (p->topo < 0) return '\0';
    return p->dados[p->topo];
}

bool vazia(PilhaChar *p) {
    return (p->topo == -1);
}

void exibir(PilhaChar *p) {
    if (vazia(p)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Topo -> ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%c ", p->dados[i]);
    }
    printf("\n");
}

// --- JogoHanoi com PilhaChar ---

void inicializarHanoi(JogoHanoi* jogo, int n) {
    jogo->num_discos = n;
    // Inicializa as 3 torres
    for (int i = 0; i < 3; i++) {
        inicializar(&jogo->torre[i]);
    }
    // Discos representados por caracteres 'n' a '1' (maior para menor)
    for (char disco = '0' + n; disco >= '1'; disco--) {
        pushChar(&jogo->torre[0], disco);
    }
}

bool moverDisco(JogoHanoi* jogo, int origem, int destino) {
    if (vazia(&jogo->torre[origem])) return false;

    char disco = topChar(&jogo->torre[origem]);
    if (!vazia(&jogo->torre[destino])) {
        char destinoTopo = topChar(&jogo->torre[destino]);
        if (disco > destinoTopo) return false; // não pode colocar disco maior sobre menor
    }
    popChar(&jogo->torre[origem]);
    pushChar(&jogo->torre[destino], disco);
    return true;
}

void resolverHanoi(JogoHanoi* jogo, int n, int origem, int destino, int auxiliar) {
    if (n == 1) {
        moverDisco(jogo, origem, destino);
        return;
    }
    resolverHanoi(jogo, n - 1, origem, auxiliar, destino);
    moverDisco(jogo, origem, destino);
    resolverHanoi(jogo, n - 1, auxiliar, destino, origem);
}

// Função para exibir todas as torres do jogo Hanoi
void exibirJogoHanoi(JogoHanoi* jogo) {
    printf("\nEstado atual das torres:\n");
    for (int i = 0; i < 3; i++) {
        printf("Torre %c: ", 'A' + i);
        if (vazia(&jogo->torre[i])) {
            printf("(vazia)");
        } else {
            for (int j = jogo->torre[i].topo; j >= 0; j--) {
                printf("%c ", jogo->torre[i].dados[j]);
            }
        }
        printf("\n");
    }
}
#ifndef PILHAS_H
#define PILHAS_H

// Estrutura para pilha de caracteres

typedef struct
{

    char dados[50];

    int topo;

} PilhaChar;

typedef struct
{

    PilhaChar torre[3]; // Três torres (A, B, C)

    int num_discos;

} JogoHanoi;
// Funções a implementar:

void inicializar(PilhaChar *p);

bool pushChar(PilhaChar *p, char c);

char popChar(PilhaChar *p);

char topChar(PilhaChar *p);

bool vazia(PilhaChar *p);

void exibir(PilhaChar *p);

void inicializarHanoi(JogoHanoi* jogo, int n);

bool moverDisco(JogoHanoi* jogo, int origem, int destino);

void resolverHanoi(JogoHanoi* jogo, int n, int origem, int destino, int auxiliar);

void exibirJogoHanoi(JogoHanoi* jogo);
#endif
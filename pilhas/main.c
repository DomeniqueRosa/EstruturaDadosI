#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilhas.h" 

void menu() {
    printf("\n--- MENU PILHA DE CARACTERES ---\n");
    printf("1. Inicializar pilha\n");
    printf("2. Inserir caractere (push)\n");
    printf("3. Remover caractere (pop)\n");
    printf("4. Ver topo da pilha\n");
    printf("5. Verificar se está vazia\n");
    printf("6. Exibir todos os elementos\n");
    printf("7- jogar hanoi");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    

    PilhaChar pilha;
    int opcao;
    int n;
    char caractere;
    char topo;

    int inicializada = 0;

    do {
        menu();
        scanf("%d", &opcao);
        getchar(); // limpa o '\n' deixado pelo scanf

        switch (opcao) {
            case 1:
                inicializar(&pilha);
                inicializada = 1;
                printf("Pilha inicializada com sucesso.\n");
                break;

            case 2:
                if (!inicializada) {
                    printf("Inicialize a pilha primeiro.\n");
                    break;
                }
                printf("Digite um caractere para empilhar: ");
                scanf("%c", &caractere);
                if (pushChar(&pilha, caractere)) {
                    printf("Caractere '%c' inserido.\n", caractere);
                } else {
                    printf("Erro: Pilha cheia.\n");
                }
                break;

            case 3:
                if (!inicializada) {
                    printf("Inicialize a pilha primeiro.\n");
                    break;
                }
                if (!vazia(&pilha)) {
                    caractere = popChar(&pilha);
                    printf("Caractere removido: %c\n", caractere);
                } else {
                    printf("Pilha vazia.\n");
                }
                break;

            case 4:
                if (!inicializada) {
                    printf("Inicialize a pilha primeiro.\n");
                    break;
                }
                if (!vazia(&pilha)) {
                    topo = topChar(&pilha);
                    printf("Topo da pilha: %c\n", topo);
                } else {
                    printf("Pilha vazia.\n");
                }
                break;

            case 5:
                if (!inicializada) {
                    printf("Inicialize a pilha primeiro.\n");
                    break;
                }
                printf("A pilha está %s.\n", vazia(&pilha) ? "vazia" : "com elementos");
                break;

            case 6:
                if (!inicializada) {
                    printf("Inicialize a pilha primeiro.\n");
                    break;
                }
                exibir(&pilha);
                break;
            case 7:
                printf("Digite o número de discos (até 9): ");
                scanf("%d", &n);
                if (n < 1 || n > 9) {
                    printf("Número inválido.\n");
                    break;
                }
                JogoHanoi jogo;
                inicializarHanoi(&jogo, n);
                printf("\nResolvendo Torres de Hanoi...\n");
                resolverHanoi(&jogo, n, 0, 2, 1);
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

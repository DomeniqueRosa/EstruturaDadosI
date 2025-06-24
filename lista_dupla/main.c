#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

int main() {
    Lista* lista = criar_lista();
    int opcao, valor, posicao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no fim\n");
        printf("3. Inserir em posição específica\n");
        printf("4. Remover de posição específica\n");
        printf("5. Exibir lista da frente\n");
        printf("6. Exibir lista de trás\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir no início: ");
                scanf("%d", &valor);
                inserir_inicio(lista, valor);
                break;

            case 2:
                printf("Digite o valor a inserir no fim: ");
                scanf("%d", &valor);
                inserir_fim(lista, valor);
                break;

            case 3:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                printf("Digite a posição (0 a %d): ", lista->tamanho);
                scanf("%d", &posicao);
                inserir_posicao(lista, valor, posicao);
                break;

            case 4:
                if (lista->tamanho == 0) {
                    printf("A lista está vazia.\n");
                    break;
                }
                printf("Digite a posição para remover (0 a %d): ", lista->tamanho - 1);
                scanf("%d", &posicao);
                remover_posicao(lista, posicao);
                break;

            case 5:
                printf("Lista (frente): ");
                exibirFrente(lista);
                break;

            case 6:
                printf("Lista (trás): ");
                exibirTras(lista);
                break;

            case 7:
                printf("Encerrando e liberando memória...\n");
                liberar_lista(lista);
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 7);

    return 0;
}

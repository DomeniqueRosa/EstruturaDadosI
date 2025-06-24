#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filas.h"



// Função para exibir o menu
void exibir_menu() {
    printf("\n========= MENU =========\n");
    printf("1. Adicionar cliente à fila\n");
    printf("2. Atender próximo cliente\n");
    printf("3. Mostrar tempo médio de espera\n");
    printf("4. Verificar palíndromo\n");
    printf("5. Inserir item na fila de prioridade\n");
    printf("6. Sair\n");
    printf("========================\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Fila fila_clientes;
    FilaPrioridade fila_prioridade;
    Cliente atendido;
    int opcao;

    inicializa_fila(&fila_clientes);
    inicializa_fila_prioridade(&fila_prioridade);

    do {
        exibir_menu();
        scanf("%d ", &opcao);
        

        switch (opcao) {
            case 1: {
                Cliente c;
                printf("Número do cliente: ");
                scanf("%d ", &c.numero);
              

                printf("Nome do cliente: ");
                fgets(c.nome, sizeof(c.nome), stdin);
                c.nome[strcspn(c.nome, "\n")] = '\0'; // Remove '\n'

                printf("Tempo de atendimento (minutos): ");
                scanf("%d ", &c.tempo_atendimento);
              

                if (adicionar_cliente(&fila_clientes, c))
                    printf("Cliente adicionado com sucesso.\n");
                else
                    printf("Fila cheia! Não foi possível adicionar.\n");
                break;
            }

            case 2: {
                if (atender_cliente(&fila_clientes, &atendido))
                    printf("Cliente atendido: %s\n", atendido.nome);
                else
                    printf("Fila vazia!\n");
                break;
            }

            case 3: {
                float media = tempo_medio_espera(fila_clientes);
                printf("Tempo médio de espera: %.2f minutos\n", media);
                break;
            }

            case 4: {
                char palavra[100];
                printf("Digite a palavra: ");
                fgets(palavra, sizeof(palavra), stdin);
                palavra[strcspn(palavra, "\n")] = '\0';

                if (eh_palindromo(palavra))
                    printf("É um palíndromo.\n");
                else
                    printf("Não é um palíndromo.\n");
                break;
            }

            case 5: {
                ItemPrioridade item;
                printf("Dado (string): ");
                fgets(item.dado, sizeof(item.dado), stdin);
                item.dado[strcspn(item.dado, "\n")] = '\0';

                printf("Prioridade (1 = alta, 2 = média, 3 = baixa): ");
                scanf("%d ", &item.prioridade);
                

                if (fila_enqueue_prioridade(&fila_prioridade, item))
                    printf("Item inserido na fila de prioridade.\n");
                else
                    printf("Fila de prioridade cheia.\n");

                printf("Fila de prioridade atual:\n");
                for (int i = 0; i < fila_prioridade.tamanho; i++) {
                    printf("-> [%d] %s\n", fila_prioridade.itens[i].prioridade,
                                             fila_prioridade.itens[i].dado);
                }
                break;
            }

            case 6:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 6);

    return 0;
}

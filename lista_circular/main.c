#include <stdio.h>
#include "lista_circular.h"

int main(){

    Lista* lista = criar_lista();

    inserir_fim(lista,10);
    inserir_fim(lista,20);
    inserir_inicio(lista,5);
    inserir_fim(lista,30);

    printf("Conteudo da lista circular\n");
    exibir_lista(lista);

    printf("liberar lista\n");
    liberar_lista(lista);

    return 0;
}
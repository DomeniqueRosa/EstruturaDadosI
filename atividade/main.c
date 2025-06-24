#include <stdio.h>
#include <stdbool.h>

// Função para imprimir um array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Busca linear
int buscaLinear(int arr[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == valor)
            return i;
    }
    return -1;
}

// Bubble sort
void bubbleSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Busca binária (array deve estar ordenado)
int buscaBinaria(int arr[], int tamanho, int valor) {
    int esquerda = 0, direita = tamanho - 1;
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (arr[meio] == valor)
            return meio;
        else if (arr[meio] < valor)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }
    return -1;
}

int main() {
    int numeros[] = {88, 42, 17, 95, 23, 56, 71, 3, 39, 64};
    int tamanho = 10;

    printf("Array original:\n");
    imprimirArray(numeros, tamanho);

    // Busca linear por 23
    int valorBusca = 23;
    int indiceLinear = buscaLinear(numeros, tamanho, valorBusca);
    if (indiceLinear != -1)
        printf("Busca Linear: Valor %d encontrado no índice %d.\n", valorBusca, indiceLinear);
    else
        printf("Busca Linear: Valor %d não encontrado.\n", valorBusca);

    printf("\nOrdenando array...\n");
    bubbleSort(numeros, tamanho);

    printf("Array ordenado:\n");
    imprimirArray(numeros, tamanho);

    // Busca binária por 23
    int indiceBinario = buscaBinaria(numeros, tamanho, valorBusca);
    if (indiceBinario != -1)
        printf("Busca Binária: Valor %d encontrado no índice %d.\n", valorBusca, indiceBinario);
    else
        printf("Busca Binária: Valor %d não encontrado.\n", valorBusca);

    return 0;
}

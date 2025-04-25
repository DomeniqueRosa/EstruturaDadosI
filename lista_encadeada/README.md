# Lista Duplamente encadeada
- armazena um ponteiro para o próximo nó
- armazena um ponteiro para o nó anterior
- assim podemos avançar para o próximo elemento e retroceder para o elemento anterior

## Estrutura de um nó na lista dupla
- typedef struct No{
    int dado; - armazena valor do no
    struct no* anterior;
    struct no* proximo;
}No

null -> [5] ->[10] -> [20] -> null

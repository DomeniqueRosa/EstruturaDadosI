# Lista circulares

Os elementos estão organizados sequencialmente, onde o último elemento aponta para o primeiro, formando um circulo.
Não há um fim definido na lista diferente das listas lineares

# Caractéristicas

- Cada nó possui um ponteiro que aponta para o próximo elemento.
- Último nó aponta para o primeiro, fechando o circulo.
- Percurso feito em uma direção

# Vantagens

- Acesso cíclico
- Econômia de memória
- Flexibilidade

# Desvantagens

- Complexidade para implementar
- Risco com loops infinitos
- Necessita de controle adicional para identificar quando o ciclo é concluído

# Uso

- Armazenamento temporario em streaming(buffer)
- Jogos de turnos alternados
- Implementação de playlist
- Gerenciamento de tarefas

# Implementação

1) Nó: que representa cada elemento da lista
   - valor: o que vai ser armazenado
   - proximo: que é ponteiro que aponta para o proximo valor
2) Lista Circular: Estrutura que gerencia a lista
    - ultimo: ponteiro para o ultimo nó da lista (remete ao primeiro)
    - tamanho: número de elementos da lista

# Características da implementação

1) Acesso ao primeiro elemento:  ```lista->ultimo->primeiro```
   para o último, precisamos manter um ponteiro, pois apartir dele, acessamos o primeiro.

2) Lista vazia: Está vazia quando ```último == NULL```

3) Lista com um elemento: Esse elemento aponta para si 
    ``` nó->proximo == nó ```

4) Percorrer lista: Começamos em um nó e continua até voltar ao ponto de partida.

# Arquivos

- cabeçalho(lista_circular.h): Contém especificações das operações
- implementação(lista_circular.c): Contém o codígo das funções
- programa principal(main.c): Responsavél em utilizar a lista 
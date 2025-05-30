# FILAS
- fifo (first in first out) : primeiro elemento a entrar é o primeiro a sair, estrutura de dados linear
- Ex: fila de impressão

### CARACTERÍSTICAS
- Inserção(enqueue): no final da fila
- Remoção(dequeue): no inicio da fila
- Acesso sequencial: não há acesso direto aos elementos intermediarios
- Ordem preservada: mantém a ordem de cheganda dos elementos

### OPERAÇOES BASICAS
- inserir: inseri um elemento no final da fila com complexidade O(n)
- remover: no inicio da fila
- front: consulta primeiro elemento
- vazio: verifica  se a fila esta vazia
- size: retorna a quantidade de elementos na fila

### VANTAGENS
- Garante operacoes constantes 0(1) quando bem implementada
- Serve de base para estruturas mais complexas

### DESVANTAGENS
- Sem acesso aleatorios aos elementos
- Tamanho ilimitado na implementação estatica
- Overhead de ponteiros na implementação dinamica


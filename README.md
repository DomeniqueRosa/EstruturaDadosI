## Prova 16/05 sobre lista/TAD

### Introdução a Estrutura Dados Celes Cerqueira e Rangel
- cap. 5, p.58 - 70
- cap. 9, p.123 - 133
- cap. 10, p.134 - 160

### Estrutura de Dados Fundamentais Silvia Lago Pereira
- cap. 1, p.15 - 20
- cap. 2, p.21 - 28
- cap. 7, p.89 - 106
- cap. 8, p.107 - 118

### Questoes serão objetivas com 5 alternativas discursivas

### Revisao

# TAD: define uma descrição lógica da estrutura de dados
- foca no comportamento (funções) o que faz
- e não na implementação fisica (usuario nao precisa preocupar como é feita)
- possui três arquivos sua implementação

## Feito por
- Vetor(array): Acesso direto por meio de um índice, tendo a coleção de elementos ordenados
- Lista encadeada simples: É uma coleção de nós conectados
- Lista circular:  É uma variação da lista simples onde o último nó aponta para o primeiro, formando um circulo.

## Caracteristicas
- vetor estatico: Acesso direto, tamanho fixo, indice
- lista encadeada: Acesso sequencial, tamanho dinamico, nao tem indice, mais flexivel mas com acesso sequencial
- lista circular: Acesso sequencial, tamanho dinamico, não tem indice, percorre continuamente

## Questão
- Imagine que estamos percorrendo uma lista simples e, depois de avançar dois nós, decidimos voltar ao no anterior - como fariamos isso?
- R: É preciso reinicar a lista e percorrer ela ate chegar ao elemento desejado


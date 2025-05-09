## Lista Encadeada com cabecalho


### Lista encadeada
```
tydefstruct No{
    int dado;
    struct *No proximo;
}No

```

* ponteiro para primeiro nó representa a lista

-> tratativas especiais

* se a lista esta vazia precisa de verificações constantes
* gera dificuldade em manter o codigo uniforme

## Caracteristicas lista com cabecalho

### Nó de cabecalho

-> não armazena dados uteis
-> não precisa de tratativas especiais e mantem um codigo uniforme
-> facilita a escrita do código: sempre tem um primeiro nó
-> primeiro nó serve de ponto de partida para lista
-> ponteiro para primeiro nó dos dados uteis
-> nunca é removido pois é um auxiliar para implementar a lista (mesmo que a lista esteja vazia)

### Exemplo sem cabeçalho

Joao -> Maria -> Carlos -> Null

* verificação - if(lista == Null)
* trata os processos de implementação de forma especial

### Exemplo de lista com cabeça~lho

nomes (nó) -> Joao -> Maria -> Carlos -> Null

* lista sempre iniciada com primeiro nó que nao representa ninguem mas tem a função de controlar a fila da lista
* permite adicionar ou remover dados de forma mais simples
 
### Estrutura da implementação de uma lista com cabeçalho

* estrutura do No
```
typedef struct No{
    int dado;
    struct No* proximo;
}No

```

* estrutura do cabecalho
```
typedef struct{
    No* cabeca;
}Lista;

```
* Lista começa em lista -> cabeça, mas os dados do usuário só começam apartir de cabeca->proximo 


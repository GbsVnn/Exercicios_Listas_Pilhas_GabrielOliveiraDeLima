#include <stdio.h>
#define MAX 5

typedef struct { int itens[MAX]; int inicio; int fim; } Fila;

void iniciarFila(Fila *f) { f->inicio = 0; f->fim = 0; }

void enfileirar(Fila *f, int valor) {
    if (f->fim == MAX) printf("A fila esta cheia!\n");
    else { f->itens[f->fim++] = valor; printf("%d entrou na fila.\n", valor); }
}

void desenfileirar(Fila *f) {
    if (f->inicio == f->fim) printf("A fila esta vazia!\n");
    else printf("%d saiu da fila.\n", f->itens[f->inicio++]);
}

void consultarInicio(Fila *f) {
    if (f->inicio == f->fim) printf("A fila esta vazia.\n");
    else printf("Proximo elemento: %d\n", f->itens[f->inicio]);
}

void mostrarQuantidade(Fila *f) {
    printf("Quantidade aguardando: %d\n", f->fim - f->inicio);
}

void mostrarFila(Fila *f) {
    if (f->inicio == f->fim) { printf("Fila vazia.\n"); return; }
    for (int i = f->inicio; i < f->fim; i++) printf("%d ", f->itens[i]);
    printf("\n");
}

int main(void) {
    Fila f; int opcao, valor; iniciarFila(&f);
    do {
        printf("\n1 Inserir\n2 Remover\n3 Mostrar fila\n4 Consultar proximo\n5 Quantidade\n0 Sair\nOpcao: ");
        if (scanf("%d", &opcao) != 1) return 1;
        switch (opcao) {
            case 1: printf("Valor: "); scanf("%d", &valor); enfileirar(&f, valor); break;
            case 2: desenfileirar(&f); break;
            case 3: mostrarFila(&f); break;
            case 4: consultarInicio(&f); break;
            case 5: mostrarQuantidade(&f); break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
    return 0;
}

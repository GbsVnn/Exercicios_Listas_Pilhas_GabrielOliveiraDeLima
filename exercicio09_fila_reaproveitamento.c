#include <stdio.h>
#define MAX 5

typedef struct { int itens[MAX]; int inicio; int fim; } Fila;

void iniciarFila(Fila *f) { f->inicio = 0; f->fim = 0; }

void enfileirar(Fila *f, int valor) {
    if (f->fim == MAX) printf("Fila cheia!\n");
    else { f->itens[f->fim++] = valor; printf("%d inserido.\n", valor); }
}

/* Remove o primeiro e desloca os restantes para manter inicio igual a zero. */
int desenfileirar(Fila *f, int *valor) {
    if (f->inicio == f->fim) return 0;
    *valor = f->itens[0];
    for (int i = 1; i < f->fim; i++) f->itens[i - 1] = f->itens[i];
    f->fim--;
    f->inicio = 0;
    return 1;
}

void mostrarFila(Fila *f) {
    if (f->fim == 0) { printf("Fila vazia.\n"); return; }
    printf("Inicio -> ");
    for (int i = 0; i < f->fim; i++) printf("%d ", f->itens[i]);
    printf("<- Fim\n");
}

int main(void) {
    Fila f; int opcao, valor; iniciarFila(&f);
    do {
        printf("\n1 Inserir\n2 Remover\n3 Mostrar fila\n0 Sair\nOpcao: ");
        if (scanf("%d", &opcao) != 1) return 1;
        switch (opcao) {
            case 1: printf("Valor: "); scanf("%d", &valor); enfileirar(&f, valor); break;
            case 2:
                if (desenfileirar(&f, &valor)) printf("%d removido.\n", valor);
                else printf("Fila vazia!\n");
                break;
            case 3: mostrarFila(&f); break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
    return 0;
}
/* Teste: inserir 1,2,3,4,5; remover 1 e 2; inserir 6 e 7.
   Resultado: 3,4,5,6,7 (as novas insercoes sao aceitas). */

#include <stdio.h>
#define MAX 5

typedef struct { int itens[MAX]; int inicio; int fim; } Fila;

void iniciarFila(Fila *f) { f->inicio = 0; f->fim = 0; }

int adicionarTrabalho(Fila *f, int id) {
    if (f->fim == MAX) { printf("Fila de impressao cheia.\n"); return 0; }
    f->itens[f->fim++] = id;
    printf("Trabalho %d adicionado.\n", id);
    return 1;
}

int imprimirProximo(Fila *f, int *id) {
    if (f->inicio == f->fim) return 0;
    *id = f->itens[f->inicio++];
    return 1;
}

void listarPendentes(Fila *f) {
    if (f->inicio == f->fim) { printf("Nao ha trabalhos pendentes.\n"); return; }
    printf("Trabalhos pendentes: ");
    for (int i = f->inicio; i < f->fim; i++) printf("%d ", f->itens[i]);
    printf("\n");
}

void imprimirTodos(Fila *f) {
    int id, algum = 0;
    while (imprimirProximo(f, &id)) {
        printf("Imprimindo trabalho %d...\n", id);
        algum = 1;
    }
    if (!algum) printf("Nao ha trabalhos para imprimir.\n");
}

int main(void) {
    Fila f; int opcao, id; iniciarFila(&f);
    do {
        printf("\n=== FILA DE IMPRESSAO ===\n1 Adicionar trabalho\n2 Imprimir proximo\n3 Listar pendentes\n4 Imprimir todos\n0 Sair\nOpcao: ");
        if (scanf("%d", &opcao) != 1) return 1;
        switch (opcao) {
            case 1: printf("Identificador: "); scanf("%d", &id); adicionarTrabalho(&f, id); break;
            case 2:
                if (imprimirProximo(&f, &id)) printf("Imprimindo trabalho %d...\n", id);
                else printf("Nao ha trabalhos para imprimir.\n");
                break;
            case 3: listarPendentes(&f); break;
            case 4: imprimirTodos(&f); break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
    return 0;
}
/* Exemplo: trabalhos 45, 12 e 78 sao impressos nessa mesma ordem. */

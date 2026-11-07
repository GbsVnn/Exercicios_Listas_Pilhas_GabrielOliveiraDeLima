#include <stdio.h>
#define MAX 5

typedef struct { int itens[MAX]; int inicio; int fim; } Fila;

void iniciarFila(Fila *f) { f->inicio = 0; f->fim = 0; }

int enfileirar(Fila *f, int tarefa) {
    if (f->fim == MAX) return 0;
    f->itens[f->fim++] = tarefa;
    return 1;
}

/* A remocao desloca os elementos; assim, libera uma posicao imediatamente. */
int desenfileirar(Fila *f, int *tarefa) {
    if (f->fim == 0) return 0;
    *tarefa = f->itens[0];
    for (int i = 1; i < f->fim; i++) f->itens[i - 1] = f->itens[i];
    f->fim--;
    f->inicio = 0;
    return 1;
}

void mostrarFila(Fila *f) {
    if (f->fim == 0) { printf("Nenhuma tarefa pendente.\n"); return; }
    printf("Fila: ");
    for (int i = 0; i < f->fim; i++) printf("%d ", f->itens[i]);
    printf("\n");
}

void executarRodada(Fila *f) {
    int tarefa, concluida;
    if (!desenfileirar(f, &tarefa)) { printf("Nao ha tarefas para executar.\n"); return; }
    printf("Executando tarefa %d.\n", tarefa);
    printf("A tarefa foi concluida? (1 = sim, 0 = nao): ");
    if (scanf("%d", &concluida) != 1) return;
    if (concluida == 1) printf("Tarefa %d concluida e removida da fila.\n", tarefa);
    else if (concluida == 0) {
        /* A remocao anterior abriu uma posicao, mesmo se a fila estava cheia. */
        enfileirar(f, tarefa);
        printf("Tarefa %d voltou para o final da fila.\n", tarefa);
    } else printf("Resposta invalida; tarefa nao foi reinserida.\n");
}

int main(void) {
    Fila f; int opcao, tarefa; iniciarFila(&f);
    do {
        printf("\n=== RODIZIO DE TAREFAS ===\n1 Adicionar tarefa\n2 Executar uma rodada\n3 Mostrar fila\n0 Sair\nOpcao: ");
        if (scanf("%d", &opcao) != 1) return 1;
        switch (opcao) {
            case 1:
                printf("Identificador da tarefa: "); scanf("%d", &tarefa);
                if (enfileirar(&f, tarefa)) printf("Tarefa adicionada.\n");
                else printf("Fila cheia. Tarefa nao adicionada.\n");
                break;
            case 2: executarRodada(&f); break;
            case 3: mostrarFila(&f); break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
    return 0;
}
/* Exemplo: 1,2,3; tarefa 1 nao concluida -> 2,3,1.
   Depois tarefa 2 concluida -> 3,1. */

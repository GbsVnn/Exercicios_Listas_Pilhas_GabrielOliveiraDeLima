#include <stdio.h>
#define MAX 5

typedef struct { int itens[MAX]; int topo; } Pilha;

void iniciarPilha(Pilha *p) { p->topo = -1; }

int empilhar(Pilha *p, int valor) {
    if (p->topo == MAX - 1) return 0;
    p->itens[++p->topo] = valor;
    return 1;
}

int desempilhar(Pilha *p, int *valor) {
    if (p->topo == -1) return 0;
    *valor = p->itens[p->topo--];
    return 1;
}

int main(void) {
    Pilha historico; int atual = 0, novo, anterior, opcao;
    iniciarPilha(&historico);
    do {
        printf("\nValor atual: %d\n1 Alterar valor\n2 Desfazer\n3 Consultar\n0 Sair\nOpcao: ", atual);
        if (scanf("%d", &opcao) != 1) return 1;
        switch (opcao) {
            case 1:
                printf("Novo valor: "); scanf("%d", &novo);
                /* So altera depois de conseguir guardar o valor anterior. */
                if (empilhar(&historico, atual)) { atual = novo; printf("Valor alterado.\n"); }
                else printf("Historico cheio: alteracao rejeitada.\n");
                break;
            case 2:
                if (desempilhar(&historico, &anterior)) { atual = anterior; printf("Alteracao desfeita.\n"); }
                else printf("Nao ha historico para desfazer.\n");
                break;
            case 3:
                printf("Valor atual: %d\n", atual);
                printf("Alteracoes disponiveis para desfazer: %d\n", historico.topo + 1);
                break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
    return 0;
}

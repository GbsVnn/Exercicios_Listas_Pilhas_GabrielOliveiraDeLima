#include <stdio.h>
#define MAX 5

typedef struct {
    int itens[MAX];
    int topo; // Indice do ultimo elemento; -1 indica pilha vazia.
} Pilha;

void iniciarPilha(Pilha *p) { p->topo = -1; }

void empilhar(Pilha *p, int valor) {
    if (p->topo == MAX - 1) printf("A pilha esta cheia!\n");
    else { p->itens[++p->topo] = valor; printf("%d empilhado.\n", valor); }
}

void desempilhar(Pilha *p) {
    if (p->topo == -1) printf("A pilha esta vazia!\n");
    else printf("%d desempilhado.\n", p->itens[p->topo--]);
}

void consultarTopo(Pilha *p) {
    if (p->topo == -1) printf("A pilha esta vazia.\n");
    else printf("Topo: %d\n", p->itens[p->topo]);
}

void mostrarQuantidade(Pilha *p) {
    printf("Quantidade de elementos: %d\n", p->topo + 1);
}

void mostrarPilha(Pilha *p) {
    if (p->topo == -1) { printf("A pilha esta vazia.\n"); return; }
    printf("Topo -> ");
    for (int i = p->topo; i >= 0; i--) printf("%d ", p->itens[i]);
    printf("<- Base\n");
}

int main(void) {
    Pilha p; int opcao, valor;
    iniciarPilha(&p);
    do {
        printf("\n1 Empilhar\n2 Desempilhar\n3 Mostrar pilha\n4 Consultar topo\n5 Quantidade\n0 Sair\nOpcao: ");
        if (scanf("%d", &opcao) != 1) return 1;
        switch (opcao) {
            case 1: printf("Valor: "); scanf("%d", &valor); empilhar(&p, valor); break;
            case 2: desempilhar(&p); break;
            case 3: mostrarPilha(&p); break;
            case 4: consultarTopo(&p); break;
            case 5: mostrarQuantidade(&p); break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
    return 0;
}

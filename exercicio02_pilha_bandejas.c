#include <stdio.h>
#define MAX 5

typedef struct { int itens[MAX]; int topo; } Pilha;

void iniciarPilha(Pilha *p) { p->topo = -1; }

void adicionarBandeja(Pilha *p, int numero) {
    if (p->topo == MAX - 1) printf("Nao ha espaco: pilha de bandejas cheia.\n");
    else { p->itens[++p->topo] = numero; printf("Bandeja %d colocada no topo.\n", numero); }
}

void retirarBandeja(Pilha *p) {
    if (p->topo == -1) printf("Nao ha bandejas para retirar.\n");
    else printf("Bandeja %d retirada.\n", p->itens[p->topo--]);
}

void consultarBandeja(Pilha *p) {
    if (p->topo == -1) printf("Nao ha bandeja disponivel.\n");
    else printf("Proxima bandeja: %d\n", p->itens[p->topo]);
}

void mostrarBandejas(Pilha *p) {
    if (p->topo == -1) { printf("Nao ha bandejas empilhadas.\n"); return; }
    printf("Bandejas do topo ate a base: ");
    for (int i = p->topo; i >= 0; i--) printf("%d ", p->itens[i]);
    printf("\n");
}

int main(void) {
    Pilha p; int opcao, numero;
    iniciarPilha(&p);
    do {
        printf("\n=== BANDEJAS ===\n1 Adicionar bandeja\n2 Retirar bandeja\n3 Consultar proxima\n4 Listar bandejas\n0 Sair\nOpcao: ");
        if (scanf("%d", &opcao) != 1) return 1;
        switch (opcao) {
            case 1: printf("Numero da bandeja: "); scanf("%d", &numero); adicionarBandeja(&p, numero); break;
            case 2: retirarBandeja(&p); break;
            case 3: consultarBandeja(&p); break;
            case 4: mostrarBandejas(&p); break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
    return 0;
}
/* Teste: adicionar 101, 102 e 103; retirar duas vezes.
   Retiradas: 103 e 102. Permanece: 101. */

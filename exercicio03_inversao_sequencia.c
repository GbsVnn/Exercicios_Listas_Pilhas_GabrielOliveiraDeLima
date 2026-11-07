#include <stdio.h>
#define MAX 100

typedef struct { int itens[MAX]; int topo; } Pilha;

void iniciarPilha(Pilha *p) { p->topo = -1; }

int empilhar(Pilha *p, int valor) {
    if (p->topo == MAX - 1) return 0;
    p->itens[++p->topo] = valor;
    return 1;
}

/* Retorna 1 se conseguiu retirar; o valor e devolvido por meio de valor. */
int desempilhar(Pilha *p, int *valor) {
    if (p->topo == -1) return 0;
    *valor = p->itens[p->topo--];
    return 1;
}

int main(void) {
    Pilha p; int quantidade, valor;
    iniciarPilha(&p);
    do {
        printf("Quantidade de numeros (1 a %d): ", MAX);
        if (scanf("%d", &quantidade) != 1) return 1;
        if (quantidade < 1 || quantidade > MAX) printf("Quantidade invalida.\n");
    } while (quantidade < 1 || quantidade > MAX);

    for (int i = 0; i < quantidade; i++) {
        printf("Digite o %do numero: ", i + 1);
        if (scanf("%d", &valor) != 1) return 1;
        empilhar(&p, valor);
    }

    printf("Sequencia inversa: ");
    while (desempilhar(&p, &valor)) printf("%d ", valor);
    printf("\nPilha vazia ao final.\n");
    return 0;
}

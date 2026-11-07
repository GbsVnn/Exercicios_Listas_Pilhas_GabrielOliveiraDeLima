#include <stdio.h>
#define MAX (sizeof(unsigned long long) * 8)

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
    Pilha p;
    unsigned long long numero;
    int resto;
    iniciarPilha(&p);

    /* Le como texto assinado para conseguir rejeitar numeros negativos. */
    long long entrada;
    printf("Digite um numero inteiro nao negativo: ");
    if (scanf("%lld", &entrada) != 1 || entrada < 0) {
        printf("Entrada invalida: informe um numero nao negativo.\n");
        return 1;
    }
    numero = (unsigned long long) entrada;

    if (numero == 0) empilhar(&p, 0);
    else {
        while (numero > 0) {
            empilhar(&p, numero % 2);
            numero /= 2;
        }
    }

    printf("Representacao binaria: ");
    while (desempilhar(&p, &resto)) printf("%d", resto);
    printf("\n");
    return 0;
}

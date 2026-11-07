#include <stdio.h>
#define MAX 5

typedef struct { int itens[MAX]; int inicio; int fim; } Fila;

void iniciarFila(Fila *f) { f->inicio = 0; f->fim = 0; }

int gerarSenha(Fila *f, int *proximaSenha) {
    if (f->fim == MAX) { printf("Fila cheia. Nao foi gerada uma senha.\n"); return 0; }
    f->itens[f->fim++] = *proximaSenha;
    printf("Senha gerada: %d\n", *proximaSenha);
    (*proximaSenha)++;
    return 1;
}

void chamarSenha(Fila *f) {
    if (f->inicio == f->fim) printf("Nao ha pessoas aguardando.\n");
    else printf("Senha chamada: %d\n", f->itens[f->inicio++]);
}

void consultarSenha(Fila *f) {
    if (f->inicio == f->fim) printf("Nao ha senhas aguardando.\n");
    else printf("Proxima senha: %d\n", f->itens[f->inicio]);
}

void listarSenhas(Fila *f) {
    if (f->inicio == f->fim) { printf("Fila vazia.\n"); return; }
    printf("Senhas aguardando: ");
    for (int i = f->inicio; i < f->fim; i++) printf("%d ", f->itens[i]);
    printf("\n");
}

int main(void) {
    Fila f; int opcao, proximaSenha = 1; iniciarFila(&f);
    do {
        printf("\n=== ATENDIMENTO ===\n1 Gerar senha\n2 Chamar proxima\n3 Consultar proxima\n4 Listar aguardando\n0 Sair\nOpcao: ");
        if (scanf("%d", &opcao) != 1) return 1;
        switch (opcao) {
            case 1: gerarSenha(&f, &proximaSenha); break;
            case 2: chamarSenha(&f); break;
            case 3: consultarSenha(&f); break;
            case 4: listarSenhas(&f); break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
    return 0;
}
/* Teste com tres senhas: chamadas 1 e 2; permanece aguardando a senha 3. */

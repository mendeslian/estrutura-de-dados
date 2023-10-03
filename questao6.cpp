#include <stdio.h>

#define MENU "\n0-Encerrar\n1-Inserir Inicio\n2-Inserir Fim\n3-Listar\n4-Buscar\n5-Alterar\nOpcao:"

struct No {
    int num;
    struct No* prox;
} * inicio = NULL;

int menu() {
    int op;
    printf(MENU);
    scanf("%d", &op);
    return op;
}

int inserirIni(int numero) {
    struct No* novo;
    novo = new struct No;
    novo->prox = inicio;
    novo->num = numero;
    inicio = novo;
    return 0;
}

int inserirFim(int numero) {
    struct No* novo;
    novo = new struct No;
    struct No* aux;

    if (inicio == NULL) {
        inicio = novo;
        novo->num = numero;
        novo->prox = NULL;
    } else {
        aux = inicio;
        novo->num = numero;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = NULL;
    }
    return 0;
}

int listar() {
    struct No* aux;
    aux = inicio;

    if (aux == NULL)
        printf("Lista Vazia!\n");

    while (aux != NULL) {
        printf("%d| ", aux->num);
        aux = aux->prox;
    }
    return 0;
}

struct No* buscar(int busca) {
    struct No* aux;
    aux = inicio;

    while (aux != NULL) {
        if (busca == aux->num) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

int alterar(struct No* end, int outro) {
    struct No* aux;

    aux = end;
    aux->num = outro;
    return 0;
}

int main() {
    int op, num;
    struct No* pos;
    op = menu();

    while (op != 0) {
        switch (op) {
        case 1:
            printf("Informe um numero:");
            scanf("%d", &num);
            inserirIni(num);
            printf("Inserido com sucesso!\n");
            break;

        case 2:
            printf("Informe um numero:");
            scanf("%d", &num);
            inserirFim(num);
            printf("Inserido com sucesso!\n");
            break;

        case 3:
            printf("\nListar:\n");
            listar();
            break;

        case 4:
            printf("\nBuscar:\n");
            listar();
            printf("Informe um numero para buscar: ");
            scanf("%d", &num);
            pos = buscar(num);

            if (pos == NULL)
                printf("Nao achei!\n");
            else
                printf("\nEND: %p\n\n", (void*)pos);

            break;

        case 5:
            printf("Informe um numero para alterar:");
            scanf("%d", &num);
            pos = buscar(num);

            if (pos == NULL) {
                printf("Nao achei!\n");
            } else {
                printf("Informe um novo numero:");
                scanf("%d", &num);
                alterar(pos, num);
                printf("Alterado com sucesso!\n");
            }

            break;
        }
        op = menu(); // Atualize a opção dentro do loop
    }

    return 0;
}


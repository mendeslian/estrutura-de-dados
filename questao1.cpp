#include <iostream>

#define MENU "\nEscolha------\n0-Encerrar; \n1-Inserir Inicio; \n2-Inserir Fim; \n3-Listar; \n4-Buscar; \n5-Alterar; \n6-Excluir um elemento; \n7-Excluir TODA lista; \nOpcao: "

struct No {
    int num;
    struct No *ant, *prox;
} *inicio = NULL, *fim = NULL;

int menu() {
    int op;
    printf(MENU);
    scanf("%d", &op);
    return op;
}

int inserirIni(int numero) {
    struct No *novo;
    struct No *aux;
    novo = new struct No;

    if (inicio == NULL) {
        inicio = novo;
        fim = novo;
        novo->num = numero;
        novo->ant = NULL;
        novo->prox = NULL;
        return 0;
    }
    aux = inicio;
    inicio = novo;
    novo->num = numero;
    novo->ant = NULL;
    novo->prox = aux;
    aux->ant = novo;
    return 0;
}

int inserirFim(int numero) {
    struct No *novo;
    struct No *aux;
    novo = new struct No;

    if (fim == NULL) {
        inicio = novo;
        fim = novo;
        novo->num = numero;
        novo->ant = NULL;
        novo->prox = NULL;
        return 0;
    }
    aux = fim;
    fim = novo;
    novo->num = numero;
    novo->ant = aux;
    novo->prox = NULL;
    aux->prox = novo;
    return 0;
}

int listar() {
    struct No *aux;

    if (inicio == NULL) {
        printf("Lista Vazia!");
        return 0;
    }
    aux = inicio;
    printf("|");
    while (aux != NULL) {
        printf(" %d |", aux->num);
        aux = aux->prox;
    }
    return 0;
}

struct No *buscar(int numero) {
    struct No *comeco;
    struct No *final;
    comeco = inicio;
    final = fim;

    if (inicio == NULL) {
        printf("Lista Vazia!\n");
        return NULL;
    }

    while (comeco->ant != final) {
        if (comeco->num == numero) {
            return comeco;
        }
        if (final->num == numero) {
            return final;
        }
        if (comeco == final) {
            printf("O numero digitado nao foi encontrado!\n");
            return NULL;
        }
        comeco = comeco->prox;
        final = final->ant;
    }
    printf("O numero digitado nao foi encontrado!\n");
    return NULL;
}

int alterar(struct No *end, int numero) {
    struct No *aux;
    aux = end;
    aux->num = numero;
    printf("Numero alterado com SUCESSO!\n");
    return 0;
}

int excluir_one(struct No *end) {
    struct No *aux;
    struct No *del;

    del = end;

    if (del == inicio) {
        inicio = del->prox;
        aux = del->prox;
        aux->ant = NULL;
        delete del;
        printf("Deletado com SUCESSO!\n");
        return 0;
    }

    if (del == fim) {
        fim = del->ant;
        aux = del->ant;
        aux->prox = NULL;
        delete del;
        printf("Deletado com SUCESSO!\n");
        return 0;
    }

    aux = del->ant;
    aux->prox = del->prox;
    aux = del->prox;
    aux->ant = del->ant;
    delete del;
    printf("Deletado com SUCESSO!\n");
    return 0;
}

int excluir_all() {
    struct No *comeco;
    struct No *final;
    comeco = inicio;
    final = fim;

    while (comeco->prox != final && comeco != final) {
        inicio = comeco->prox;
        fim = final->ant;
        delete final;
        delete comeco;
        comeco = inicio;
        final = fim;
    }

    if (comeco == final) {
        delete comeco;
    } else {
        delete comeco;
        delete final;
    }
    inicio = NULL;
    fim = NULL;
    printf("Lista deletada com sucesso.\n");
    return 0;
}

int main() {
    int num = 0;
    int op;
    struct No *pos;
    op = menu();

    while (op != 0) {

        switch (op) {
        case 1:
            printf("Informe um numero:");
            scanf("%d", &num);
            inserirIni(num);
            break;

        case 2:
            printf("Informe um numero:");
            scanf("%d", &num);
            inserirFim(num);
            break;

        case 3:
            printf("\nlistar:\n");
            listar();
            break;

        case 4:
            printf("\nlistar:\n");
            printf("Informe um numero para buscar:");
            scanf("%d", &num);
            pos = buscar(num);

            if (pos == NULL)
                printf("NAO achei!\n");
            else
                printf("\nEND: %p\n\n", pos);
            break;

        case 5:
            printf("Informe um numero para alterar:");
            scanf("%d", &num);
            pos = buscar(num);

            if (pos == NULL)
                printf("NAO achei!");
            else {
                printf("Informe um novo numero:");
                scanf("%d", &num);
                alterar(pos, num);
            }
            break;

        case 6:
            printf("Informe um numero para excluir:");
            scanf("%d", &num);
            pos = buscar(num);

            if (pos == NULL)
                printf("NAO achei!");
            else {
                excluir_one(pos);
            }
            break;

        case 7:
            excluir_all();
            break;

        default:
            printf("Opcao invalida.... Tente novamente!\n");
            break;
        }
        op = menu();
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct num
{
    int num;
    struct num *prox;
};
typedef struct num num;

int tam;

void inicia(num *LISTA);
int menu(void);
void opcao(num *LISTA, int op);
num *criaNo();
void insereFim(num *LISTA);
void insereInicio(num *LISTA);
void exibe(num *LISTA);
void libera(num *LISTA);
void insere(num *LISTA);
num *retiraInicio(num *LISTA);
num *retiraFim(num *LISTA);
num *retira(num *LISTA);

int main(void)
{
    num *LISTA = (num *)malloc(sizeof(num));
    if (!LISTA)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else
    {
        inicia(LISTA);
        int opt;

        do
        {
            opt = menu();
            opcao(LISTA, opt);
        } while (opt);

        free(LISTA);
        return 0;
    }
}

void inicia(num *LISTA)
{
    LISTA->prox = NULL;
    tam = 0;
}

int menu(void)
{
    int opt;

    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Zerar lista\n");
    printf("2. Exibir lista\n");
    printf("3. Adicionar numero no inicio\n");
    printf("4. Adicionar numero no final\n");
    printf("5. Escolher onde inserir\n");
    printf("6. Retirar do inicio\n");
    printf("7. Retirar do fim\n");
    printf("8. Escolher de onde tirar\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}

void opcao(num *LISTA, int op)
{
    num *tmp;
    switch (op)
    {
    case 0:
        libera(LISTA);
        break;

    case 1:
        libera(LISTA);
        inicia(LISTA);
        break;

    case 2:
        exibe(LISTA);
        break;

    case 3:
        insereInicio(LISTA);
        break;

    case 4:
        insereFim(LISTA);
        break;

    case 5:
        insere(LISTA);
        break;

    case 6:
        tmp = retiraInicio(LISTA);
        printf("Retirado: %3d\n\n", tmp->num);
        break;

    case 7:
        tmp = retiraFim(LISTA);
        printf("Retirado: %3d\n\n", tmp->num);
        break;

    case 8:
        tmp = retira(LISTA);
        printf("Retirado: %3d\n\n", tmp->num);
        break;

    default:
        printf("Comando invalido\n\n");
    }
}

int vazia(num *LISTA)
{
    if (LISTA->prox == NULL)
        return 1;
    else
        return 0;
}

num *aloca()
{
    num *novo = (num *)malloc(sizeof(num));
    if (!novo)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else
    {
        printf("Novo Número: ");
        scanf("%d", &novo->num);
        return novo;
    }
}

void insereFim(num *LISTA)
{
    num *novo = aloca();
    novo->prox = NULL;

    if (vazia(LISTA))
        LISTA->prox = novo;
    else
    {
        num *tmp = LISTA->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
    tam++;
}

void insereInicio(num *LISTA)
{
    num *novo = aloca();
    num *oldHead = LISTA->prox;

    LISTA->prox = novo;
    novo->prox = oldHead;

    tam++;
}

void exibe(num *LISTA)
{
    system("clear");
    if (vazia(LISTA))
    {
        printf("Lista vazia!\n\n");
        return;
    }

    num *tmp;
    tmp = LISTA->prox;
    printf("Lista:");
    while (tmp != NULL)
    {
        printf("%5d", tmp->num);
        tmp = tmp->prox;
    }
    printf("\n        ");
    int count;
    for (count = 0; count < tam; count++)
        printf("  ^  ");
    printf("\nOrdem:");
    for (count = 0; count < tam; count++)
        printf("%5d", count + 1);

    printf("\n\n");
}

void libera(num *LISTA)
{
    if (!vazia(LISTA))
    {
        num *proxnum,
            *atual;

        atual = LISTA->prox;
        while (atual != NULL)
        {
            proxnum = atual->prox;
            free(atual);
            atual = proxnum;
        }
    }
}

void insere(num *LISTA)
{
    int pos,
        count;
    printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
    scanf("%d", &pos);

    if (pos > 0 && pos <= tam)
    {
        if (pos == 1)
            insereInicio(LISTA);
        else
        {
            num *atual = LISTA->prox,
                *anterior = LISTA;
            num *novo = aloca();

            for (count = 1; count < pos; count++)
            {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = novo;
            novo->prox = atual;
            tam++;
        }
    }
    else
        printf("Número invalido\n\n");
}

num *retiraInicio(num *LISTA)
{
    if (LISTA->prox == NULL)
    {
        printf("Lista ja esta vazia\n");
        return NULL;
    }
    else
    {
        num *tmp = LISTA->prox;
        LISTA->prox = tmp->prox;
        tam--;
        return tmp;
    }
}

num *retiraFim(num *LISTA)
{
    if (LISTA->prox == NULL)
    {
        printf("Lista ja vazia\n\n");
        return NULL;
    }
    else
    {
        num *ultimo = LISTA->prox,
            *penultimo = LISTA;

        while (ultimo->prox != NULL)
        {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }

        penultimo->prox = NULL;
        tam--;
        return ultimo;
    }
}

num *retira(num *LISTA)
{
    int opt,
        count;
    printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
    scanf("%d", &opt);

    if (opt > 0 && opt <= tam)
    {
        if (opt == 1)
            return retiraInicio(LISTA);
        else
        {
            num *atual = LISTA->prox,
                *anterior = LISTA;

            for (count = 1; count < opt; count++)
            {
                anterior = atual;
                atual = atual->prox;
            }

            anterior->prox = atual->prox;
            tam--;
            return atual;
        }
    }
    else
    {
        printf("Número invalido\n\n");
        return NULL;
    }
}
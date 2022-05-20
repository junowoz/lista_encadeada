#include <stdio.h>
#include <stdlib.h>

// CODIGO ANTIGO
/* Estrutura que será usada para criar os nós da lista */

typedef struct aluno
{
    int matricula;
    char nome;
    struct aluno *proximo;
}

Faluno;

/* Estrutura que será usada para criar os nós da lista */

void inserir(Faluno **cabeca);
void listar(Faluno *cabeca);

int main()
{

    Faluno cabeca = NULL; // Ponteiro para a cabeca da lista
    Faluno noatual;       // Ponteiro a ser usado para percorrer a lista no momento de desalocar seus elementos/
    int n;                /* Caractere para receber a opcao do usuario */

    // Iniciando a estrutura de repetição/
    do
    {
        printf("\n\nOpcoes: \n1 -> para inserir novo Aluno;\n2 -> para listar os Alunos; \n0 -> para sair \nEscolha sua opcao:");
        scanf("%d", &n); /* Ler a opcao do usuario */
        switch (n)
        {
        case 1:
            inserir(&cabeca);
            break;
        case 2:
            listar(cabeca);
            break;
        case 0:
            break;
        default:
            printf("\n\n Opcao nao valida");
        }
    } while (n != '0');

    // Desaloca a memoria alocada para os elementos da lista
    noatual = cabeca;
    while (noatual != NULL)
    {
        cabeca = noatual->proximo;
        free(noatual);
        noatual = cabeca;
    }
}
// Lista todos os elementos presentes na lista encadeada */
void listar(Faluno noatual)
{
    int i = 0;
    while (noatual != NULL) // Enquanto nao chega no fim da lista /
    {

        i++;
        printf("\n\nAluno numero %d\nMatricula: %c \nNome", i, noatual->matricula, noatual->nome);
        noatual = noatual->proximo; // Faz noatual apontar para o proximo no */
    }
}

/* Funcao para inserir um novo no, ao final da lista */

void inserir(Faluno **cabeca)
{
    Faluno *noatual, *novono;
    int matricula;
    char nome;
    printf("\n Nova matricula: ");
    scanf("%d", &matricula);
    printf("\n Nome do aluno");
    scanf("%c", &nome);
    if (cabeca == NULL) // Se ainda nao existe nenhum produto na lista /
    {

        // cria o no cabeca */
        *cabeca = (Faluno *)malloc(sizeof(Faluno));
        (*cabeca)->matricula = matricula;
        (*cabeca)->nome = nome;
        (cabeca)->proximo = NULL;
    }
    else
    {
        // Se ja existem elementos na lista, deve percorre-la ate' o seu final e inserir o novo elemento */
        noatual = cabeca;
        while (noatual->proximo != NULL)
            noatual = noatual->proximo;          // Ao final do while, noatual aponta para o ultimo no */
        novono = (Faluno)malloc(sizeof(Faluno)); // Aloca memoria para o novo no /
        novono->matricula = matricula;
        novono->nome = nome;
        novono->proximo = NULL;
        noatual->proximo = novono; // Faz o ultimo no apontar para o novo no */
    }
}

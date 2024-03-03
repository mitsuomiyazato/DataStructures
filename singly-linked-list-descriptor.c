#include <stdio.h>
#include <stdlib.h>

typedef struct mylist
{
    int elemento;
    struct mylist * proximo;
} Lista;

typedef struct mydescritor
{
    int tam;
    struct mylist *primeiro;
    struct mylist *ultimo;
} Descritor;

int inicializar(Descritor *descritorteste);
int mostrarValores(Descritor descritorteste);
int inserirInicio(Descritor *descritorteste, int val);
int copiarLista(Descritor *d1, Descritor *d2);

int main()
{

    int resp, erro, valor;

    Descritor desc, desc2;

    erro = inicializar(&desc);

    do
    {
        printf("\nLista Encadeada Simples:\n\n");
        printf("0 - SAIR\n");
        printf("1 - Mostrar valores\n");
        printf("2 - Inserir no inicio\n");
        printf("3 - Copiar lista\n");
        printf("4 - Mostrar Lista 2\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &resp);

        switch (resp)
        {
        case 1: erro = mostrarValores(desc);
            if(erro == 1)
                printf("\nLista Vazia!\n");
            break;
        case 2:
            printf("Digite o valor a inserir: \n");
            scanf("%d", &valor); 
            erro = inserirInicio(&desc, valor);
            if(erro == 0)
            {
                printf("\nValor inserido com sucesso!\n");
            }
            break;  
        case 3:
            erro = copiarLista(&desc, &desc2);
            if(erro == 1)
            {
                printf("\nLista vazia!\n");
            }
            printf("\nLista copiada\n");
            break;     
        case 4: erro = mostrarValores(desc2);
            if(erro == 1)
                printf("\nLista Vazia!\n");
            break;
        default:
            break;

        
        }
    } while (resp != 0);

    return 0;

}

int inicializar(Descritor *descritorteste)
{
    descritorteste->tam == 0;
    descritorteste->primeiro = NULL;
    descritorteste->ultimo = NULL;

    return 0;
}

int inserirInicio(Descritor *descritorteste, int val)
{
    Lista *listaAuxiliar;
    listaAuxiliar = (Lista*) malloc (sizeof(Lista));
    listaAuxiliar->elemento = val;

    if(descritorteste->tam == 0)
    {
        descritorteste->primeiro = listaAuxiliar;
        descritorteste->ultimo = listaAuxiliar;
        descritorteste->tam = 1;
    }
    else
    {
        Lista *aux;

        aux = descritorteste->primeiro;
        listaAuxiliar->proximo = aux;
        descritorteste->primeiro = listaAuxiliar;
        descritorteste->tam += 1;
    }
    
    return 0;
}

int mostrarValores(Descritor descritorteste)
{
    if(descritorteste.tam == 0)
    {
        return 1;       
    }

    Lista *percorre;
    
    percorre = descritorteste.primeiro;

    printf("Lista:: ");
    while(percorre != NULL)
    {
        printf("%d ", percorre->elemento);
        percorre = percorre->proximo;
    }
    printf("\n");

    return 0;
}

int copiarLista(Descritor *d1, Descritor *d2)
{

    d2->tam = 0;
    d2->primeiro = NULL;
    d2->ultimo = NULL;

    if(d1->tam == 0) {return 1;}

    Lista *percorre;
    
    percorre = d1->primeiro;

    while(percorre != NULL)
    {
        Lista *listaAuxiliar;
        listaAuxiliar = (Lista *) malloc (sizeof(Lista));
        listaAuxiliar->elemento = percorre->elemento;
        listaAuxiliar->proximo = NULL;
        
        if(d2->tam == 0)
        {
            d2->primeiro = listaAuxiliar;
            d2->ultimo = listaAuxiliar;
            d2->tam = 1;
        }

        Lista *aux;

        aux = d2->ultimo;
        d2->ultimo = listaAuxiliar;
        aux->proximo = listaAuxiliar;
        d2->tam += 1;

        percorre = percorre->proximo;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>


typedef struct mydoublelist{
    int elemento;
    struct mydoublelist *proximo, *anterior;
    
} ListaDupla;

int inicializarLD (ListaDupla **lista);
int inicializarLD2(ListaDupla **lista);
int inserirInicio(ListaDupla **lista, int val);
int mostrarLista(ListaDupla *lista);
int inserirFinal(ListaDupla **lista, int val);
int removerInicio(ListaDupla **lista);
int obterTamanho(ListaDupla **lista);
int removerMetade(ListaDupla **lista);

int main(void)
{

    ListaDupla *inicio;

    int resposta, erro, valor, tamanho;

    erro = inicializarLD(&inicio);
    
    do
    {
        erro = 0;
        printf("\nLISTA ENCADEADA DUPLA\n");
        printf("1 - Mostrar lista\n");
        printf("2 - Inserir inicio\n");
        printf("3 - Inserir fim\n");
        printf("4 - Remover Inicio\n");
        printf("5 - Inicializar (versão 2)\n");
        printf("6 - Mostrar tamanho lista\n");
        printf("7 - Remover metade\n");
        printf("\nDigite a opcao desejada:\n");
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            erro = mostrarLista(inicio);
            if(erro == 1)
            {
                printf("Não foi possível mostrar a lista. Lista vazia\n");
            }
            break;
        case 2: 
            printf("Digite o valor que deseja inserir:\n");
            scanf("%d", &valor);
            inserirInicio(&inicio, valor);
            break;
        case 3:
            printf("Digite o valor que deseja inserir:\n");
            scanf("%d", &valor);
            inserirFinal(&inicio, valor);
            break;
        case 4: erro = removerInicio(&inicio);
            if(erro == 1)
            {
                printf("Não foi possível excluir. Lista vazia\n");
            }
            break;
        case 5:
            inicializarLD2(&inicio);
            printf("Lista inicializada com sucesso\n");
            break;
        case 6:
            tamanho = obterTamanho(&inicio);
            printf("O tamanho da lista é: %d\n", tamanho);
            break;
        case 7: erro = removerMetade(&inicio);
            if(erro == 1)
            {
                printf("Não foi possível remover. Lista vazia.\n");
            }
            if(erro == 2)
            {
                printf("A lista só possui um elemento, não é possível excluir.");
            }
            break;
        default:
            break;
        }
        
    } while (resposta != 8);

    return 0;
}

int inicializarLD(ListaDupla **lista)
{
    *lista = NULL;
    return 0;
}

int inicializarLD2(ListaDupla **lista)
{
    if(*lista == NULL)
    {
        inicializarLD(lista);
    }
    else
    {
        ListaDupla *percorre, *aux;
        percorre = *lista;
        
        while(percorre->proximo != NULL)
        {
            aux = percorre;
            percorre = percorre->proximo;
            free(aux);
        }
        *lista = NULL;
    }
    return 0;
}

int inserirInicio(ListaDupla **lista, int val)
{
    ListaDupla *listaAuxiliar;

    listaAuxiliar = (ListaDupla *)malloc (sizeof(ListaDupla));
    listaAuxiliar->elemento = val;

    if(*lista == NULL)
    {
        listaAuxiliar->proximo = NULL;
        *lista = listaAuxiliar;
        listaAuxiliar->anterior = NULL;
    }
    else{
        listaAuxiliar->proximo = *lista;
        listaAuxiliar->anterior = NULL;
        (*lista)->anterior = listaAuxiliar;
        *lista = listaAuxiliar;
    }

    return 0;
}

int inserirFinal(ListaDupla **lista, int val)
{
    ListaDupla *listaAuxiliar;

    listaAuxiliar = (ListaDupla *)malloc(sizeof(ListaDupla));
    listaAuxiliar->elemento = val;
    listaAuxiliar->proximo = NULL;

    if(*lista == NULL)
    {
        *lista = listaAuxiliar;
        listaAuxiliar->anterior = NULL;
    }
    else
    {
        ListaDupla *percorre;
        percorre = *lista;

        while(percorre->proximo != NULL)
        {
            percorre = percorre->proximo;
        }

        percorre->proximo = listaAuxiliar;
        listaAuxiliar->anterior = percorre;
    }
    return 0;
}

int removerInicio(ListaDupla **lista)
{
    if(*lista == NULL)
    {
        return 1;
    }
    else
    {

        ListaDupla *listaAuxiliar;
        
        listaAuxiliar = *lista;
        *lista = (*lista)->proximo;
        (*lista)->anterior = NULL;
        free(listaAuxiliar);
    }

    return 0;
    
}

int removerMetade(ListaDupla **lista)
{
    int tam = obterTamanho(lista);
    
    if(tam == 0)
    {
        return 1;
    }
    if(tam == 1)
    {
        return 2;
    }

    ListaDupla *percorre, *aux;
    int pos = 0;
    percorre = *lista;
    while(pos < (tam/2))
    {
        aux = percorre;
        percorre = percorre->proximo;
        free(aux);
        pos = pos+1;
    }
    
    *lista = percorre;
    
    return 0;
}

int mostrarLista(ListaDupla *lista)
{
    if(lista == NULL)
    {
        return 1;
    }
        
    printf("Lista:: ");
    while(lista != NULL)
    {
        printf("%d ", lista->elemento);
        lista = lista->proximo;
    }

    printf("\n");
    return 0;
}

int obterTamanho(ListaDupla **lista)
{
    int tam = 0;
    if(*lista == NULL)
    {
        return tam;
    }
    else
    {
        ListaDupla *percorre;
        percorre = *lista;

        while(percorre->proximo != NULL)
        {
            tam = tam+1;
            percorre = percorre->proximo;
        }
        tam = tam+1;
    }

    return tam;
}

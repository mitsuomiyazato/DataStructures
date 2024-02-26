#include <stdio.h>
#include <stdlib.h>

typedef struct mylist
{
    int elemento;
    struct mylist * proximo;
} Lista;

int inicializar2(Lista **listateste);
int inicializar(Lista **listateste);
int mostrarValores(Lista *listateste);
int inserirInicio(Lista **listateste, int val);
int inserirFinal(Lista **listateste, int val);
int inserirMeio(Lista **listateste, int val, int pos);
int inverter(Lista **listateste);
int removerMeio(Lista **listateste, int pos);
int removerFim(Lista **listateste);
int verRepetido (Lista *listateste, int val, int *resp);
int maiorQtd (Lista *listateste, int val, int *quant);

int main()
{

    int resp, erro, valor, posicao, existe, quantidade;

    Lista *inicio;

    erro = inicializar(&inicio);

    do
    {
        existe = 0;
        printf("\nLista Encadeada Simples:\n\n");
        printf("0 - SAIR\n");
        printf("1 - Mostrar valores\n");
        printf("2 - Inserir no inicio\n");
        printf("3 - Inserir no final\n");
        printf("4 - Inserir no meio\n");
        printf("5 - Inicializar (versão 2)\n");
        printf("6 - Inverter Lista\n");
        printf("7 - Remover meio\n");
        printf("8 - Remover fim\n");
        printf("9 - Verificar dado\n");
        printf("10 - Verificar maior\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &resp);

        switch (resp)
        {
        case 1: erro = mostrarValores(inicio);
            if(erro == 1)
                printf("\nLista Vazia!\n");
            break;
        case 2:
            printf("Digite o valor a inserir: \n");
            scanf("%d", &valor); 
            erro = inserirInicio(&inicio, valor);
            if(erro == 0)
            {
                printf("\nValor inserido com sucesso!\n");
            }
            break;
        case 3:
            printf("Digite o valor a inserir: \n");
            scanf("%d", &valor);
            erro = inserirFinal(&inicio, valor);
            if(erro == 0)
            {
                printf("\nValor inserido com sucesso!\n");
            }
            break;
        case 4:
            printf("Digite o valor a inserir:\n");
            scanf("%d", &valor);
            printf("Digite a posicao desejada:\n");
            scanf("%d", &posicao);
            erro = inserirMeio(&inicio, valor, posicao);
            if(erro == 0)
            {
                printf("\nValor inserido com sucesso!\n");
            }
            else
            {
                printf("\nValor Inválido. Tente novamente!\n");
            }
            break;
        case 5: erro = inicializar2(&inicio);
            if(erro == 1)
            {
                printf("\nA lista já está vazia\n");
            }
            else
            {
                printf("\nLista inicializar com sucesso!\n");
            }    
            break;
        case 6: erro = inverter(&inicio);
            if (erro == 1)
            {
                printf("\nLista vazia ou com apenas um elemento\n");
            }
            else
            {
                printf("\nInversão realizada com sucesso!\n");
            }
            break;
        case 7: 
            printf("Digite a posição que deseja excluir:\n");
            scanf("%d", &posicao);
            erro = removerMeio(&inicio, posicao);
            if(erro == 1)
            {
                printf("\nLista vazia ou posição inválida!\n");
            }
            break;
        case 8: erro = removerFim(&inicio);
            if(erro == 1)
            {
                printf("\nLista vazia\n");
            }
            break;
        case 9: 
        printf("Digite o valor que deseja verificar:\n");
        scanf("%d", &valor);
        erro = verRepetido(inicio, valor, &existe);
        if (erro == 1)
        {
            printf("\nLista vazia\n");
        }
        else
        {
            if (existe == 0)
            {
                printf("O dado não existe na lista!\n");
            }
            else
            {
                printf("O dado está na lista!\n");
            }
        }
            break;
        case 10:
            printf("Digite o valor para avaliar:\n");
            scanf("%d", &valor);
            erro = maiorQtd(inicio, valor, &quantidade);
            if (erro == 1)
            {
                printf("\nLista vazia!\n");
            }
            else
            {
                printf("A quantidade de valores maiores na lista é: %d\n", quantidade);
            }
            
        default:
            break;

        
        }
    } while (resp != 0);

    return 0;

}

int inicializar(Lista **listateste)
{
    *listateste = NULL;
    return 0;
}
int inicializar2(Lista **listateste)
{
    Lista *aux, *percorre;
    
    if(*listateste != NULL)
    {
        percorre = *listateste;
        while(percorre != NULL)
        {
            aux = percorre;
            percorre = percorre->proximo;
            free(aux);
        }
    }
    else
    {
        return 1;
    }

    return 0;
}

int obterTamanho(Lista *listateste)
{
    int tam = 0;

    Lista *percorre;

    if(listateste = NULL)
    {
        return tam;
    }
    else
    {
        percorre = listateste;
        while (percorre != NULL)
        {
            percorre = percorre->proximo;
            tam++; 
        }
        return tam;
    }
}

int inserirInicio(Lista **listateste, int val)
{
    Lista *listaAuxiliar;
    listaAuxiliar = (Lista *) malloc(sizeof(Lista));

    listaAuxiliar->elemento = val;
    
    if(*listateste != NULL)
    {
        listaAuxiliar->proximo = *listateste;
        *listateste = listaAuxiliar;
    }
    else
    {
        listaAuxiliar->proximo = NULL;
        *listateste = listaAuxiliar;
    }

    return 0;
}

int inserirFinal(Lista **listateste, int val)
{
    Lista *listaAuxiliar, *percorre;
    
    listaAuxiliar = (Lista *) malloc (sizeof(Lista));
    listaAuxiliar->elemento = val;
    listaAuxiliar->proximo = NULL;

    if(*listateste == NULL)
    {
        *listateste = listaAuxiliar;
    }
    else
    {
        percorre = *listateste;

        while(percorre->proximo != NULL)
        {
            percorre = percorre->proximo;
        }
        percorre->proximo = listaAuxiliar;
    }

    return 0;
}

int inserirMeio(Lista **listateste, int val, int pos)
{
    if (*listateste == NULL)
    {
        inserirInicio(listateste, val);
    }
    else
    {
        int tamanho = 0;
        Lista *listaAuxiliar, *percorre;

        listaAuxiliar = (Lista *) malloc (sizeof(Lista));
        listaAuxiliar->elemento = val;
    
        if (pos <= 0)
        {
            return 1;
        }
        
        tamanho = obterTamanho(*listateste);
        
        if(pos == 1)
        {
            inserirInicio(listateste, val);
            return 0;
        }
        else if(pos == tamanho + 1)
        {
            inserirFinal(listateste, val);
            return 0;
        }
        else
        {
            percorre = *listateste;
            int i = 1;
            while (i != pos-1)
            {
                percorre = percorre->proximo;
                i++;
            }
            listaAuxiliar->proximo = percorre->proximo;
            percorre->proximo = listaAuxiliar;
        }
    }
    return 0;
}
int inverter(Lista **listateste)
{
    Lista *percorre, *aux1, *aux2, *aux3;
    percorre = *listateste;
    if(percorre == NULL)
    {
        return 1;
    }
    else if(percorre->proximo == NULL)
    {
        return 1;
    }
    else
    {

        aux1 = *listateste;
        aux2 = aux1->proximo;
        aux3 = aux2->proximo;
        aux1->proximo = NULL;
        aux2->proximo = aux1;

        while (aux3 != NULL)
        {
            aux1 = aux2;
            aux2 = aux3;
            aux3 = aux3->proximo;
            aux2->proximo = aux1;
        }

        *listateste = aux2;
    }

    return 0;
}

int removerMeio(Lista **listateste, int pos)
{
    Lista *percorre, *aux, *aux2;
    
    if(*listateste == NULL)
    {
        return 1;
    }
    else
    {
        int tamanho = obterTamanho(*listateste);

        percorre = *listateste;
        int i = 1;

        while(i < pos -1)
        {
            percorre = percorre->proximo;
            i++;
        }
        aux = percorre->proximo;
        aux2 = aux->proximo;
        percorre->proximo = aux2;
        free(aux);
    }

    return 0;
}

int removerFim(Lista **listateste)
{
    if (*listateste == NULL)
    {
        return 1;
    }
    else
    {
        Lista *percorre, *aux, *aux2;
        percorre = *listateste;
        aux = percorre->proximo;

        while(aux->proximo != NULL)
        {
            aux = aux->proximo;
            percorre = percorre->proximo;
        }
        aux2 = aux;
        percorre->proximo = aux->proximo;
        free(aux2);
    }
    return 0;
}

int mostrarValores(Lista *listateste)
{
    if(listateste == NULL) { return 1; }
    else
    {
        printf("Lista: ");
        do
        {
            printf("%d ", listateste->elemento);
            listateste = listateste->proximo;
        }while(listateste != NULL);
    }
    printf("\n");
    return 0;
}

int verRepetido (Lista *listateste, int val, int *resp)
{
    if (listateste == NULL)
    {
        return 1;
    }
    else
    {
        do
        {
            if(listateste->elemento == val)
            {
                *resp = 1;
                break;
            }
            else
            {
                listateste = listateste->proximo;
                *resp = 0;
            }
        } while (listateste != NULL);
    }
    return 0;
}

int maiorQtd (Lista *listateste, int val, int *quant)
{
    *quant = 0;
    if (listateste == NULL)
    {
        return 1;
    }
    else
    {
        do
        {
            if(listateste->elemento > val)
            {
                *quant= *quant+1;
            }
            listateste = listateste->proximo;
        } while (listateste != NULL);
    }

    return 0;
}
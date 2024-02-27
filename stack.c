#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int items[10];
} Pilha;

int initialize(Pilha *pilhateste)
{
    pilhateste->top = -1;
    return 0;
}

int isFull(Pilha *pilhateste)
{
    if(pilhateste->top == 9)
    {
        return 1;
    }
    
    return 0;
}

int isEmpty(Pilha *pilhateste)
{
    if(pilhateste->top == -1)
    {
        return 1;
    }

    return 0;
}

int push(Pilha *pilhateste, int val)
{
    if(isFull(pilhateste) == 1)
    {
        return 1;
    }
    pilhateste->top++;
    pilhateste->items[pilhateste->top] = val;    
}

int pop(Pilha *pilhateste)
{
    if(isEmpty(pilhateste) == 1)
    {
        return 1;
    }

    pilhateste->top--;
        
    return 0;
}

int peek(Pilha *pilhateste)
{
    if(isEmpty(pilhateste) == 1)
    {
        return 1;
    }

    printf("\nO item no topo da lista é %d\n", pilhateste->items[pilhateste->top]);

    return 0;
}

int main()
{
    Pilha pilha;

    int opcao, erro, valor;

    erro = initialize(&pilha);

    printf("\nPilha Estática\n");

    do
    {   
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Peek\n");
        printf("Digite a opcao:\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: 
            printf("Digite o valor para inserir:\n");
            scanf("%d", &valor);
            erro = push(&pilha, valor);
            if(erro == 1) 
                {printf("\nA pilha está cheia.\n");}
            break;
        case 2: 
            erro = pop(&pilha);
            if(erro == 1) {printf("\nA pilha está vazia.\n");}
            break;
        case 3: 
            erro = peek(&pilha);
            if(erro == 1) {printf("\nA pilha está vazia.\n");}
            break;
        default:
            break;
        }

    }while(opcao != 0);
    
    return 0;
}
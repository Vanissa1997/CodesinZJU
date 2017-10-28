#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
// typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );

// int GetOp();  /* details omitted */
void PrintStack( Stack S, int Stacknum ); /* details omitted */

int main()
{
    int N, Sn, X;
    Stack S;
    int done = 0;
    int a;

    scanf("%d", &N);
    S = CreateStack(N);
    
    // printf("alive");
    // printf("%c",a);
    while ( !done ) {
        scanf("%d", &a);
        switch( a ) {
        case 111: 
            scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
            break;
        case 222:
            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Sn);
            break;
        case 333:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

Stack CreateStack( int MaxElements )
{
    Stack p=(Stack)malloc(sizeof(struct StackRecord));
    p->Capacity=MaxElements;
    p->Top1=-1;
    p->Top2=MaxElements;
    p->Array=(ElementType*)malloc(sizeof(ElementType)*MaxElements);
    return p;
}

int IsEmpty( Stack S, int Stacknum )
{
    if(Stacknum==1)
    {
        if(S->Top1==-1)  return 1;
        else  return 0;
    }
    else if(Stacknum==2)
    {
        if(S->Top2==S->Capacity)   return 1;
        else return 0;
    }
}

int IsFull( Stack S )
{
    int a;
    a=S->Top2-S->Top1;
    if(a==1) return 1;
    else return 0;
}

int Push( ElementType X, Stack S, int Stacknum )
{
    if(Stacknum==1)
    {
        if (IsFull(S)) return 0;
        S->Top1++;
        S->Array[S->Top1]=X;
        return 1;
    }
    else
    {
        if (IsFull(S)) return 0;
        S->Top2--;
        S->Array[S->Top2]=X;
        return 1;
    }
}

ElementType Top_Pop( Stack S, int Stacknum )
{   
    if(Stacknum==1)
    {
        if (IsEmpty(S,Stacknum)) return ERROR;
        S->Top1--;
        return S->Array[S->Top1+1];
        
    }
    if(Stacknum==2)
    {
        if (IsEmpty(S,Stacknum)) return ERROR;
        S->Top2++;
        return S->Array[S->Top2-1];
        
    }  
}


void PrintStack( Stack S, int Stacknum )
{
    int i;
    if(Stacknum==1)
    {
        printf("Pop from Stack 1: ");
        for(i=S->Top1-1;i>=0;i--)
        {
            printf("%d ",S->Array[i]);
        }
    }
    if(Stacknum==2)
    {
        printf("Pop from Stack 2: ");
        for(i=S->Top2+1;i<S->Capacity;i++)
        {
            printf("%d ",S->Array[i]);
        }
    }
}
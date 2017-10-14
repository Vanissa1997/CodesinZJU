#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};

Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

//Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;
    int a;

    D = CreateDeque();
    while (!done) {
        scanf("%d",&a);
        switch(a) {
        case 111: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case 222:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case 333: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case 444:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case 555:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

Deque CreateDeque()
{
    Deque p=(Deque)malloc(sizeof(struct DequeRecord));
    p->Front=(PtrToNode)malloc(sizeof(struct Node));
    p->Front->Last=NULL;
    p->Rear=p->Front;
    p->Rear->Next=NULL;
    return p;
}
int Push( ElementType X, Deque D )
{
    PtrToNode k=(PtrToNode)malloc(sizeof(struct Node));
    if(k==NULL) return 0;
    k->Element=X;
    if(D->Front==D->Rear)//empty list
    {
        D->Rear=k;
        D->Front->Next=
        k->Last=D->Front;
        k->Next=NULL;
        return 1;
    }
    else
    {
        k->Next=D->Front->Next;
        D->Front->Next->Last=k;
        k->Last=D->Front;
        D->Front->Next=k;
        return 1;
    }
    
}

ElementType Pop( Deque D )
{
    if(D->Front==D->Rear)//empty list
        return ERROR;
    PtrToNode k=D->Front->Next;
    ElementType tmp=k->Element; 
    if(D->Front->Next==D->Rear)
    {
        D->Rear=D->Front;
        D->Front->Next=NULL;
        free(k);
        return tmp;
    }
    D->Front->Next=D->Front->Next->Next;
    D->Front->Next->Last=D->Front;
    free(k);
    return tmp;
}

int Inject( ElementType X, Deque D )
{  
    PtrToNode k=(PtrToNode)malloc(sizeof(struct Node));
    if(k==NULL) return 0;
        k->Element=X;
        k->Next=NULL;
    if(D->Front==D->Rear)//empty list
    {
        D->Front->Next=k;
        k->Last=D->Front;
        D->Rear=k;
        return 1;
    }else
    {
        k->Last=D->Rear;
        D->Rear->Next=k;
        D->Rear=k; 
        return 1;
    }  
}

ElementType Eject( Deque D )
{
    if(D->Front==D->Rear)//empty list
        return ERROR;
    PtrToNode k;
    k=D->Rear;
    ElementType tmp=k->Element;
    D->Rear=D->Rear->Last;
    D->Rear->Next=NULL;
    free(k);
    return tmp;
}

void PrintDeque( Deque D )
{
    PtrToNode p=D->Front->Next;
    while(p!=NULL)
    {
        printf("%d ",p->Element);
        p=p->Next;
    }
}
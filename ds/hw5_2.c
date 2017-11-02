#include <stdio.h>
#include <stdlib.h>

typedef struct Node* PNode; 
struct Node
{
    int id;
    PNode Left;
    PNode Right;
};

void intorder(PNode T,int a[],int* p);
void buildtree(PNode T,int l[],int r[],int* p1,int* p2);
void bubble_sort(int a[],int n);
void Level_order ( PNode T ,int* b);

int main()
{
    int N,i,t=0,m1=0,m2=0;
    int* p;
    int* p1;
    int* p2;
    p1=&m1;
    p2=&m2;
    PNode T;
    T=(PNode)malloc(sizeof(struct Node));
    T->id=0;

    scanf("%d",&N);

    int b[N],a[N],c[N],l[N],r[N];
    int num[N];

    for(i=0;i<N;i++)
    {
        scanf("%d %d",&l[i],&r[i]);
    }
    buildtree(T,l,r,p1,p2);
    //intorder(T,a,p);
    // for(i=0;i<N;i++)
    // {
    //     scanf("%d",&num[i]);
    // }
    // bubble_sort(num,N);
    // for(i=0;i<N;i++)
    // {
    //     b[a[i]]=num[i];
    // }
    // Level_order(T,c);
    // for(i=0;i<N-1;i++)
    // {
    //     printf("%d ",b[c[i]]);
    // }
    // printf("%d ",b[c[i]]);
    // printf("\n");
}

void buildtree(PNode T,int l[],int r[],int* p1,int* p2)
{
    int a,b;
    // T=(PNode)malloc(sizeof(struct Node));
    // T->id=0;

    a=l[*p1];
    b=r[*p2];
    if(a!=-1)
    {
        T->Left=(PNode)malloc(sizeof(struct Node));
        T->Left->id=a;
        (*p1)++;
        buildtree(T->Left,l,r,p1,p2);
    }
    else 
    {
        T->Left=NULL;
        (*p1)++;
    }
    if(b!=-1)
    {
        T->Right=(PNode)malloc(sizeof(struct Node));
        T->Right->id=b;
        (*p2)++;
        buildtree(T->Left,l,r,p1,p2);
    }
    else 
    {
        T->Right=NULL;
        (*p2)++;
    }
}

void Level_order ( PNode T ,int* b)
{
    int Maxsize=100;
    PNode a[Maxsize];
    int Front=0,Rear=0,i=0;
    PNode p=T;
    if(T==NULL)
        return;
    a[Front]=p;

    while(1)
    {       
        if(a[i]->Left)
        {
             Rear++;
             a[Rear]=a[i]->Left;         
        }
        if(a[i]->Right)
        {
            Rear++;
            a[Rear]=a[i]->Right;  
        }
        i++;
        if(i>Rear)
            break;
    } 
    for(i=0;i<=Rear;i++)
        b[i]=a[i]->id;
}       

void intorder(PNode T,int a[],int* p)
{
    if(T!=NULL)
    {
        intorder(T->Left,a,p);
        a[(*p)++]=T->id;
        intorder(T->Right,a,p);  
    }
    
}

void bubble_sort(int a[],int n)
{
    int i,j,temp;
    for (j=0;j<n-1;j++)
        for (i=0;i<n-1-j;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
}
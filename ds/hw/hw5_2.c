#include <stdio.h>
#include <stdlib.h>

typedef struct node Node; 
struct node
{
    int x;
    int Left;
    int Right;
};

void bubble_sort(int a[],int n);
void level_order(Node num[]);
void inorder(Node num[],int key[],int *p,int i);

int main ()
{
    Node num[100];
    int i,N,t=0;
    int*p;
    p=&t;
    scanf("%d",&N);
    int key[N];

    
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&num[i].Left,&num[i].Right);
    }
    for(i=0;i<N;i++)
    {
        scanf("%d",&key[i]);
    }
    bubble_sort(key,N);
    inorder(num,key,p,0);
    level_order(num);
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

void inorder(Node num[],int key[],int *p,int i)
{
    if(num[i].Left!=-1)
    {
        inorder(num,key,p,num[i].Left);
    }
    num[i].x=key[(*p)++];
    if(num[i].Right!=-1)
    {
        inorder(num,key,p,num[i].Right);
    }
}

void level_order(Node num[])
{
    int a[100];
    int i=0,Front=0,Rear=0;
    
    a[Front]=i;
    while(1)
    {
        if(num[a[i]].Left!=-1)
        {
            Rear++;
            a[Rear]=num[a[i]].Left;
        }
        if(num[a[i]].Right!=-1)
        {
            Rear++;
            a[Rear]=num[a[i]].Right;
        }
        i++;
        if(i>Rear)
            break;
    }
    for(i=0;i<Rear;i++)
       printf("%d ",num[a[i]].x);
    printf("%d\n",num[a[i]].x);
    return;
}


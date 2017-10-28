#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct Node* PNode;
struct Node
{
    int Element;
    PNode Left;
    PNode Right;
};
int a[100],b[100],stack[100];

PNode buildtree(int prel,int prer,int inl,int inr);
void postorder(PNode T);

int main()
{
    int N,cpush=0,cpop=0,i,x;
    int top1=-1,top2=-1,top=-1;
    char s[10];
    PNode Tree;

    scanf("%d",&N);
    while(cpop<N)
    {
        scanf("%s",&s);
        if(strlen(s)==3)//pop  
        {
            b[++top2]=stack[top];
            top--;
            cpop++;
        }else if(strlen(s)==4)//push
        {
            scanf("%d",&x);
            a[++top1]=x;
            stack[++top]=x;
            //cpush++;
        }   
    }
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]); 
    }
    printf("\n");
    for(i=0;i<N;i++)
    {
        printf("%d ",b[i]); 
    }
    printf("\n");
    Tree=buildtree(0,N-1,0,N-1);
    postorder(Tree);
    //printf("\b");
    printf("\n");
}

PNode buildtree(int prel,int prer,int inl,int inr)
{
    PNode T;
    int i,t;
    
    if(prel>prer)
    {
        T=NULL;
        return T;
    }
    T=(PNode)malloc(sizeof(struct Node));
    T->Element=a[prel];
    if(prel==prer)
    {
        //T=(PNode)malloc(sizeof(struct Node));
        T->Left=T->Right=NULL;
        return T;
    }
    
     //T->Left=T->Right=NULL;
    // for(i=inl;i<=inr;i++)
    // {
    //     if(a[i]==b[i])
    //     {
    //         t=i;
    //         break;
    //     }    
    // }
    for(t=inl;t<=inr;t++)
    {
        if(a[prel]==b[t])  break;
    }
    T->Left=buildtree(prel+1,prel+t-inl,inl,t-1);
    T->Right=buildtree(prel+t-inl+1,prer,t+1,inr);
    return T;
}

void postorder(PNode T)
{
    if(T!=NULL)
    {
        postorder(T->Left);
        postorder(T->Right);
        printf("%d ",T->Element);
    }
}
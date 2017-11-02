#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
struct TNode{
    int Key;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* details omitted */
int CheckBST ( BinTree T, int K );
int height(BinTree T);
void intorder(BinTree T,int a[],int *p);
BinTree create_tree(int a[],int l,int r);

int main()
{
    BinTree T;
    int K, out;
    int a[100];
    int t=0,i,h;
    int *p;
    p=&t;

   // int s[]={4,5,1,3,6,7};
    int s[]={6,5,4,10,3,2};
    //int s[]={4,3,1,2,5,7,6,8};

    T= create_tree(s,0,5);
    //T= create_tree(s,0,7);
    scanf("%d", &K);

    intorder(T,a,&t);

    out = CheckBST(T, K);
    
    if ( out < 0 )
        printf("No.  Height = %d\n", -out);
    else
        printf("Yes.  Key = %d\n", out);

    return 0;
}


BinTree create_tree(int a[],int l,int r)      //create a tree using the number from a[l] to a[r]
{
    int i,t;
    BinTree root;

    root=(BinTree)malloc(sizeof(struct TNode));//create a root which stores a[l]
    root->Key=a[l];                     

    if(l>r) return NULL;                    //the left subtree or the right subtree is empty
    if(l==r)                                //the left subtree or the right subtree has only a TNode
    {
        root=(BinTree)malloc(sizeof(struct TNode));
        root->Key=a[l];                        //if the number is positive, then the TNode is black
        root->Left=root->Right=NULL;
        return root;
    }
    for(i=l+1;i<=r;i++)                     //look for the subscript "t" which guarantees a[t]>a[l]
    {
        if(a[i]>a[l])
            break;
    }
    t=i;                                    //if there is no such t, then t=r+1, return to the case "l>r"
    root->Left=create_tree(a,l+1,t-1);      //recursive left subtree
    root->Right=create_tree(a,t,r);         //recursive right subtree
    return root;
}

int CheckBST ( BinTree T, int K )
{
    int a[100];
    int t=0,i,h;
    int *p;
    p=&t;
    intorder(T,a,p);
    // for(i=0;i<t;i++)
    // printf("%d ",a[i]);
    if(t==0) return 0;
    if(t==1) 
    {
        if(t-K>=0)
            return a[t-K];
    }
    for(i=0;i<t-1;i++)
    {
        if(a[i]>=a[i+1])
            return (-1)*(height(T)-1);
    }
    if(t-K>=0)
        return a[t-K];
}

void intorder(BinTree T,int a[],int* p)
{
    if(T!=NULL)
    {
        intorder(T->Left,a,p);
        a[(*p)++]=T->Key;
        intorder(T->Right,a,p);  
    }
    
}

int height(BinTree T)
{
    int L,R;
    if(!T) return 0;
    L=height(T->Left);
    R=height(T->Right);
    if(L>R)
    {
        L++;
        return L;
    }        
    else 
    {
        R++;
        return R;
    }
}
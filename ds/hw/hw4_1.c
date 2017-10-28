#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */
void PrintNode( Tree NodePtr )
{
   printf(" %d", NodePtr->Element);
}

void Level_order ( Tree T, void (*visit)(Tree ThisNode) );

int main()
{
    Tree T = BuildTree();
    printf("Level-order:");
    Level_order(T, PrintNode);
    return 0;
}



void Level_order ( Tree T, void (*visit)(Tree ThisNode) )
{
    int Maxsize=1000;
    Tree a[Maxsize];
    int Front=0,Rear=0,i=0;
    Tree p=T;
    if(T==NULL)
    {
        return;
    }
   // a[Front]=(Tree)malloc(sizeof(struct TreeNode)); 
    a[Front]=p;

    while(1)
    {       
        if(a[i]->Left)
        {
             //Rear=(Rear+1)%Maxsize;
             Rear++;
             a[Rear]=a[i]->Left;         
        }
        if(a[i]->Right)
        {
            //Rear=(Rear+1)%Maxsize;
            Rear++;
            a[Rear]=a[i]->Right;  
        }
        //Front=(Front+1)/Maxsize;
        i++;
        if(i>Rear)
            break;
    } 
    for(i=0;i<=Rear;i++)
        (*visit)(a[i]);
    return;
}       
    
Tree BuildTree()
{
    Tree T;
    T=(Tree)malloc(sizeof(struct TreeNode)); 
    T->Element=3;
    T->Left=(Tree)malloc(sizeof(struct TreeNode));
    T->Left->Element=5;
    T->Left->Left=(Tree)malloc(sizeof(struct TreeNode));
    T->Left->Left->Element=1;
    T->Left->Right=(Tree)malloc(sizeof(struct TreeNode));
    T->Left->Right->Element=8;
    T->Left->Right->Left=(Tree)malloc(sizeof(struct TreeNode));
    T->Left->Right->Left->Element=9;
    T->Right=(Tree)malloc(sizeof(struct TreeNode));
    T->Right->Element=6;
    T->Right->Right=(Tree)malloc(sizeof(struct TreeNode));
    T->Right->Right->Element=10;
    return T;
}
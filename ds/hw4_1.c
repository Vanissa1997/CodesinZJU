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
    Tree T;
    T->Element=3;
    T->Left->Element=5;
    T->Left->Left->Element=1;
    T->Left->Right->Element=8;
    T->Left->Right->Left->Element=9;
    T->Right->Element=6;
    T->Right->Right->Element=10;
    //Tree T = BuildTree();
    printf("Level-order:");
    Level_order(T, PrintNode);
    return 0;
}

void Level_order ( Tree T, void (*visit)(Tree ThisNode) )
{
    int Maxsize=1000;
    Tree a[Maxsize];
    int Front=0,Rear=0;
    Tree p=T;
    a[Rear]=p;

    while(1)
    {       
        if(a[Front]->Left!=NULL)
        {
             Rear=(Rear+1)/Maxsize;
             a[Rear]=a[Rear-1]->Left;         
        }
        if(a[Front]->Right!=NULL)
        {
            Rear=(Rear+1)/Maxsize;
            a[Rear]=a[Rear-1]->Right;  
        }
        (*visit)(a[Front]);
        Front=(Front+1)/Maxsize;
        if(Front==Rear)
        break;
    } 
}
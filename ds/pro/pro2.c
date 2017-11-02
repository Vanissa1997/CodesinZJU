#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RED 1
#define BLACK 0
#define MAXSIZE 30           //the max length of array

typedef struct Node* PNode;  //the point which points to the node
struct Node
{
    int key;                 //the element                        
    PNode Left;              //the point which points to its left child
    PNode Right;             //the point which points to its right child
    int color;               //the color of the node
};

PNode create_tree(int a[],int l,int r);   //create a binary tree, and return the root
int is_root_black(PNode T);               //(2) to judge whether the root is black
int red_single(PNode T);                  //(3) to judge whether a red node's father and children are red
int same_black(PNode T);                  //(5) to judge whether all simple path contains same number of black nodes
int count_black(PNode T,int count,int n); //subfunction of same_black
void is_BRT(PNode T);                     //to judge 5 properties

int main()
{
    int looptimes,i,j,N;
    int a[MAXSIZE];
    PNode BT;

    scanf("%d",&looptimes);
    for(i=0;i<looptimes;i++)
    {
        scanf("%d",&N);
        for(j=0;j<N;j++)
            scanf("%d",&a[j]);              //to store the numbers into an array
        BT=create_tree(a,0,N-1);
        is_BRT(BT);
    }  
}

PNode create_tree(int a[],int l,int r)      //create a tree using the number from a[l] to a[r]
{
    int i,t;
    PNode root;

    root=(PNode)malloc(sizeof(struct Node));//create a root which stores a[l]
    if(a[l]>0)
    {
        root->key=a[l];                     //if the number is positive, then the node is black
        root->color=BLACK;
    }
    else if(a[l]<0)
    {
        root->key=-a[l];                    //if the number is negative, then the node is red
        root->color=RED;
    }

    if(l>r) return NULL;                    //the left subtree or the right subtree is empty
    
    for(i=l+1;i<=r;i++)                     //look for the subscript "t" which guarantees a[t]>a[l]
    {
        if(abs(a[i])>abs(a[l]))
            break;
    }
    t=i;                                    //if there is no such t, then t=r+1, return to the case "l>r"
    root->Left=create_tree(a,l+1,t-1);      //recursive left subtree
    root->Right=create_tree(a,t,r);         //recursive right subtree
    return root;
}

int is_root_black(PNode T)
{
    if(!T)  return 1;                       //empty tree also meets the requirements
    if(T)
    {
        if(T->color==BLACK) return 1;
        else return 0;
    }
}

int red_single(PNode T)
{
    PNode P=T;
    if(!T)  return 1;                      //empty tree also meets the requirements                     
    if(P->color==RED)
    {
        if(P->Left&&P->Left->color==RED) return 0;
        if(P->Right&&P->Right->color==RED) return 0;
    }
    return (red_single(P->Left)&&red_single(P->Right));
    return 1;                              //if there is no chance to return 0, then return 1          
}

int same_black(PNode T)
{
    PNode P=T;
    int num_of_black=0;                    //the the number of black nodes which contained by a very path

    if(!P)  return 1;                      //empty tree also meets the requirements
    if(P->color==RED) return 0;            //fails to meet requirement (3)
    if(P->color==BLACK)
    {
        num_of_black++;
        P=P->Left;                         //here we choose the leftmost path to be the standard
        while(P)
        {           
            if(P->color==BLACK)
                num_of_black++;  
            P=P->Left;
        }
    }
    num_of_black++;                        //add 1 for the node "NULL"
    return count_black(T,0,num_of_black);
}

int count_black(PNode T,int count,int num_of_black)
{
    if(!T)
    {
        count++;                           //count++ for node "NULL"
        if(count!=num_of_black) return 0;  //if count != standard number, return 0
        else return 1;
    }
    if(T->color==BLACK)
        count++;
    return (count_black(T->Left,count,num_of_black)&&
            count_black(T->Right,count,num_of_black));
}

void is_BRT(PNode T)
{
    if (is_root_black(T)&&red_single(T)&&same_black(T))
        printf("Yes\n");
    else printf("No\n");
}
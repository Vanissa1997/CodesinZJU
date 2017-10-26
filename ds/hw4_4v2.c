#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countlevel(int dad[],int t);
void countleaves(int dad[],int has[],int M,int N);
// int result[100][100];
// int flag=0;

int main()
{
    int i,j,noc,num,id,M,N,k;   
   
    int dad[100];
    int has[100];

    while(scanf("%d",&M)==1)
    {
        if(M==0) break;
        for(i=0;i<100;i++)
        {
            dad[i]=has[i]=0;
        }
        scanf("%d",&N);
        //scanf("%d %d",&M,&N);
        for(i=0;i<N;i++)
        {
            scanf("%d",&id);
            has[id-1]=1;
            scanf("%d",&noc);
            for(j=0;j<noc;j++)
            {
                scanf("%d",&num);
                dad[num-1]=id;
            } 
        }
        countleaves(dad,has,M,N);
    }
    // for(i=0;i<flag;i++)
    // {
    //     for(j=1;j<result[i][0]+1;j++)
    //     {
    //         printf("%d ",result[i][j]);
    //     }
    //     printf("%d",result[i][j]);//最后不能有空格
    //     printf("\n");
    // }
}

void countleaves(int dad[],int has[],int M,int N)
{
    int level[M];
    int count[N];
    int i,j,l=0;

    for(i=0;i<M;i++)
    {
        level[i]=count[i]=0;
    }
    if(M==0)
    {
        return;
    }
    if(M==1)
    {
        printf("1\n");
        //count[0]=0;
        // result[flag][0]=0;
        // result[flag][1]=1;
        // flag++;
        return;
    }
    for(i=0;i<M;i++)
    {
        level[i]=countlevel(dad,i);
    }
    for(i=0;i<M;i++)
    {
        if(l<level[i])
            l=level[i];//l:max level
    }
    for(j=0;j<M;j++)
    {
        if(has[j]==0)
        {
            count[level[j]]++;
        } 
    }
    for(j=0;j<l;j++)
    {
        printf("%d ",count[j]);
    }
    printf("%d",count[j]);
    printf("\n");
    // result[flag][0]=l;//先把结果存起来 最后一起输出
    // for(j=1;j<=l+1;j++)
    // { 
    //     result[flag][j]=count[j-1];
    // }
    // flag++;
}

int countlevel(int dad[],int t)//count the level of NO.(t-1)
{
    int level=0;
    int tmp=dad[t];
    int k;

    if(dad[t]==0)
        return 0;
    else
    {
        while(tmp!=0)
        {
            k=tmp-1;
            tmp=dad[k];
            level++;
        }
        return level;
    }
}
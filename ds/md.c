#include <stdio.h>

int main()
{
    int M,N,K;
    int i,loop,a,top=-1,j,n=0;
    int now;

    scanf("%d %d %d",&M,&N,&K);
    for(i=0;i<N;i++)
        num[i]=i+1;   
    int stack[M];
    for(loop=0;loop<K;loop++)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&a);
            if(top==-1)
            {
                for(j=0;j<a;j++)
                {
                    stack[++top]=top+1;
                }
                flag[a-1]=1;
                top--;
                if(top>M)
                {
                    printf("NO");
                    break;
                }
            }
            else if(top>-1)
            {
                if(a>stack[top])//push
                {      
                    
                    if(top>=M-1)
                    {
                        printf("NO");
                        break;
                    }else
                    {
                        for(j=num[now];j<=a;j++)
                        {
                            top++;
                            stack[top]=j;
                        }
                        top--;
                        now=a;
                        flag[now-1]=1;
                    }               
                }  
                if(a==stack[top])
                {

                }
            }
        }
    }

}
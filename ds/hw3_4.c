#include <stdio.h>

int main()
{
    int M,N,K;
    int i,loop,a,top=-1,j,n=0;
    int now;

    scanf("%d %d %d",&M,&N,&K);
    int num[N];
    int flag[N];
    for(i=0;i<N;i++)
        num[i]=i+1;   
    int stack[M];
    for(loop=0;loop<K;loop++)
    {
        now=0;
        for(i=0;i<N;i++)
        {          
            scanf("%d",&a);
            
                if(now<N&&a==num[now])
                {
                    now++;
                }
                else if(now<N&&a>num[now])
                {
                    for(j=now;j<=a-1;j++)
                    {
                        top++;
                        stack[top]=num[j];
                    }
                    now=j;
                    if(top>M-1)
                    {
                        printf("NO");
                        break;
                    }
                    top--;
                }
                else if(now<N&&a<num[now])
                {
                    if(top>-1&&a==stack[top])
                    {
                        top--;
                    }
                    else
                    {
                        printf("NO");
                        break;
                    }
                }else if(a==stack[top])
                {
                    top--;
                }else
                {
                    printf("NO");
                    break;
                }
        }
        if(i==N-1)
            printf("YES");
    }
}

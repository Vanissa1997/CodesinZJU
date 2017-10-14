#include <stdio.h>

int main()
{
    int M,N,K;
    int i,loop,a,top,j,n=0;
    int now;

    scanf("%d %d %d",&M,&N,&K);
    int num[N];
    for(i=0;i<N;i++)
        num[i]=i+1;   
    int stack[M];  
    for(loop=0;loop<K;loop++)
    {
        top=-1;
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
                        printf("NO\n");
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
                        printf("NO\n");
                        break;
                    }
                }else if(a==stack[top])
                {
                    top--;
                }else
                {
                    printf("NO\n");
                    break;
                }
        }
        if(i==N)
            printf("YES\n");
            for(i++;i<N;i++) scanf("%d",&a);
    }
}

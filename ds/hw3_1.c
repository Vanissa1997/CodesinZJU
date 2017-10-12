#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );

int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

double cal_tmp(int* tmp,int k);//change an array into a decimals
double power(int a, int b);//a*10^b

double power(int a, int b)
{
    int i;
    double p,ret=(double)a;
    if(b>=0) p=10;
    else 
    {
        p=0.1;
        b=b*(-1);
    }
    for(i=0;i<b;i++)
    {
        ret*=p;
    }
    return ret;
}

double cal_tmp(int* tmp,int k)
{
    int i=0,j,m=k;//m:record where the dot is
    double a=0;//a:integer part
    double b=0;//b:fractional part
    while(i<k)
    {
        if(tmp[i]==-1)  m=i;//find the dot
        i++;
    }
    for(j=m+1;j<k;j++)//calculate b
    {
        b+=power(tmp[j],m-j);
    }
    for(j=0;j<m;j++)//calculate a
    {
        a+=power(tmp[j],m-j-1);
    }
    return a+b;  
}

ElementType EvalPostfix( char *expr )
{
    double num;//the operands
    int i=0,k,t=0,flag=0;//k:the length of the tmp[]
    char ch,tch;
    ElementType s[Max_Expr];//store the operands
    int tmp[100];//an array represents a demical
    ElementType ret;
    
    while(expr[i]!='\0')
    {
        ch=expr[i];
        if(expr[1]=='\0'&&ch<='9'&&ch>='0') return expr[0]-'0';//only one operand which is an integer
        if(expr[i+1]==' '||expr[i+1]=='\0')    flag=1;//single operand or operator

        if(flag==0)//save a decimal into the stack s
        {           
            if(ch<='9'&&ch>='0')
            {
                k=0;
                while(expr[i]!=' '&&expr[i]!='\0')//when expr[i]=='\0', there is only one element
                {
                    tch=expr[i];
                    if(tch=='.')    tch='0'-1;
                    tmp[k]=tch-'0';
                    k++;
                    i++;
                }
                num=cal_tmp(tmp,k);
                s[t]=num;
            }
            else if(ch=='-')//if the decimal is negative
            {
                k=0;
                i++;
                while(expr[i]!=' '&&expr[i]!='\0')//when expr[i]=='\0', there is only one element
                {
                    tch=expr[i];
                    if(tch=='.')    tch='0'-1;
                    tmp[k]=tch-'0';
                    k++;
                    i++;
                }
                num=cal_tmp(tmp,k);
                s[t]=(-1)*num;               
            }
            else return Infinity;//wrong input
            t++;
            i--;
        }
        if(flag==1)
        {     
            switch (ch)
            {
                case '*':
                    if(t<2) return Infinity;
                    s[t-2]=s[t-2]*s[t-1];
                    t--;flag=0;
                    break;
                case '/':
                    if(t<2) return Infinity;
                    if(s[t-1]==0)   return Infinity;//the dividend can not be zero
                    s[t-2]=s[t-2]/s[t-1];
                    t--;flag=0;
                    break;
                case '+':
                    if(t<2) return Infinity;
                    s[t-2]=s[t-2]+s[t-1];
                    t--;flag=0;
                    break;
                case '-':
                    if(t<2) return Infinity;
                    s[t-2]=s[t-2]-s[t-1];
                    t--;flag=0;
                    break;
                default:
                    if(ch<='9'&&ch>='0')
                    {
                        s[t]=ch-'0';
                        t++;flag=0;
                    }
                    else return Infinity;
                    break;
            }   
        }
        i++;
        if(expr[i]=='\0') goto end;//in case i overflow
        i++;//skip the space    
    }
    end:
    if(t==1) return s[0];
    else return Infinity;
}
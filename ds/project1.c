#include <stdio.h>
#include <time.h>

void BSi(int K,int N,int* array);//Binary Search (iterative version) function
void BSr(int K,int N,int* array);//Binary Search (recursive version) function
void SSi(int K,int N,int* array);//Sequential Search (iterative version) function
void SSr(int K,int N,int* array);//Sequential Search (recursive version) function
void BSr_implementation(int begin,int end,int N,int* array);//the recusive function for BSr
void SSr_implementation(int begin,int N,int* array);//the recursive function for SSr

int main(){
    clock_t start, stop;
    int K; //repeat for K iterations
    int version;//the version number  decide which function to be tested
    int Ticks = CLK_TCK;// CLK_TCK is a build-in constant
    int N;//the length of this sequence
    double duration;
    double TotalTime;

    printf("Enter the sequence's length(N):\n");
    scanf("%d",&N);
    int i;
    int array[N];
    for(i = 0;i < N;i++)
    array[i] = i;

    printf("Choose a mode for test:\n");
    printf( "1:Binary Search (iterative version)\n"
            "2:Binary Search (recursive version)\n"
            "3:Sequential Search (iterative version)\n"
            "4:Sequential Search (recursive version)\n");
    scanf("%d",&version);
    printf("Enter the iteration times:\n");
    scanf("%d",&K);
    switch(version){
        case 1:
            start = clock(); /* records the ticks at the beginning of the function call */
            BSi(K,N,array);
            stop = clock(); /* records the ticks at the end of the function call */
            break;
        case 2:
            start = clock(); /* records the ticks at the beginning of the function call */        
            BSr(K,N,array);
            stop = clock(); /* records the ticks at the end of the function call */
            break;
        case 3:
            start = clock(); /* records the ticks at the beginning of the function call */        
            SSi(K,N,array);
            stop = clock(); /* records the ticks at the end of the function call */
            break;
        case 4:
            start = clock(); /* records the ticks at the beginning of the function call */
            SSr(K,N,array);
            stop = clock(); /* records the ticks at the end of the function call */
            break;
    }
    TotalTime =  ((double)(stop - start))/Ticks; 
    duration = TotalTime/K;

    printf("The Ticks in this computer is %d\n",Ticks);
    printf("Iteration times:%d\n",K);
    printf("Total Time:%.10f(s)\n",TotalTime);
    printf("Duration:%.10f(s)\n",duration);

    return 0;
}

void BSi(int K,int N,int* array){
    int begin,middle,end;
    int i;

    for(i = 0;i < K;i++){
        begin =0;
        end = N - 1;
        while(begin <= end){
            middle = (begin+end)/2;
            if(array[middle] < N)
                begin = middle+1;
            if(array[middle] > N)
                end = middle-1;
        }
    }
}

void BSr(int K,int N,int* array){
    int begin,end;
    begin = 0;
    end = N;
    int i;
    for(i = 0;i < K;i++)
        BSr_implementation(begin,end,N,array);
}

void BSr_implementation(int begin,int end,int N,int* array){
    int middle;
    if(begin <= end){
        middle = (begin+end)/2;
        if(array[middle] < N)
            BSr_implementation(middle+1,end,N,array);
        if(array[middle] > N)
            BSr_implementation(begin,middle-1,N,array);
    }
}

void SSi(int K,int N,int* array){
    int i,j;
    for(i = 0;i < K;i++)
        for(j = 0;j < N;j++)
            if(array[j] == N)
                break;
}

void SSr(int K,int N,int* array){
    int i;
    for(i = 0;i < K;i++)
        SSr_implementation(0,N,array);
}

void SSr_implementation(int begin,int N,int* array){
    if((array[begin] != N) && (begin != N-1))
        SSr_implementation(begin+1,N,array);
}
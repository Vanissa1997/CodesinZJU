/*
  programmer: 
  tester:
  report writer:
  Group 16
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void BSi(int K, int N, int *array);                             //Binary Search (iterative version) function
void BSr(int K, int N, int *array);                             //Binary Search (recursive version) function
void SSi(int K, int N, int *array);                             //Sequential Search (iterative version) function
void SSr(int K, int N, int *array);                             //Sequential Search (recursive version) function
void BSr_implementation(int begin, int end, int N, int *array); //the recusive function for BSr
void SSr_implementation(int begin, int N, int *array);          //the recursive function for SSr

int main()
{
    clock_t start, stop;
    int K;            //repeat for K iterations
    int version;      //the version number  decide which function to be tested
    int Ticks;        //Ticks=stop-start
    int N;            //the length of this sequence
    double duration;  //the time that runs once cost
    double TotalTime; //the total time that used

    printf("Enter the sequence's length(N):\n");
    scanf("%d", &N);
    int i;
    int array[N];
    for (i = 0; i < N; i++) //initialize the array.
        array[i] = i;

    printf("Choose a mode for test:\n");
    printf("1:Binary Search (iterative version)\n"
           "2:Binary Search (recursive version)\n"
           "3:Sequential Search (iterative version)\n"
           "4:Sequential Search (recursive version)\n");
    scanf("%d", &version);
    printf("Enter the iteration times:\n");
    scanf("%d", &K);
    switch (version)
    { //select a function to run.
    case 1:
        start = clock(); /* records the ticks at the beginning of the function call */
        BSi(K, N, array);
        stop = clock(); /* records the ticks at the end of the function call */
        break;
    case 2:
        start = clock();
        BSr(K, N, array);
        stop = clock();
        break;
    case 3:
        start = clock();
        SSi(K, N, array);
        stop = clock();
        break;
    case 4:
        start = clock();
        SSr(K, N, array);
        stop = clock();
        break;
    }
    Ticks = stop - start;
    TotalTime = ((double)(stop - start)) / CLK_TCK;
    // CLK_TCK is a build-in constant, in the tester's computer, CLK_TCK is 1000
    duration = TotalTime / K;

    printf("The Ticks in this computer is %d\n", Ticks);
    printf("Iteration times:%d\n", K);
    printf("Total Time:%.10f(s)\n", TotalTime);
    printf("Duration:%.10f(s)\n", duration);
    system("pause");
    return 0;
}

void BSi(int K, int N, int *array)
{
    int begin, middle, end;
    int i;

    for (i = 0; i < K; i++)
    {
        begin = 0;
        end = N - 1; //initialize begin and end
        while (begin <= end)
        {
            middle = (begin + end) / 2;
            if (array[middle] < N) //if array[middle] < N,flash the begin value
                begin = middle + 1;
            if (array[middle] > N)
                end = middle - 1;
            if (array[middle] == N)
                return;
        }
    }
}

void BSr(int K, int N, int *array)
{
    int begin, end;
    begin = 0; //initialize the begin and end value
    end = N;
    int i;
    for (i = 0; i < K; i++)
        BSr_implementation(begin, end, N, array); //call the recursive function.
}

void SSi(int K, int N, int *array)
{
    int i, j;
    for (i = 0; i < K; i++) //run for K times
        for (j = 0; j < N; j++)
            if (array[j] == N)
                break;
}

void SSr(int K, int N, int *array)
{
    int i;
    for (i = 0; i < K; i++)
        SSr_implementation(0, N, array); //call the recursive function.
}

void BSr_implementation(int begin, int end, int N, int *array)
{
    int middle;
    if (begin <= end)
    {
        middle = (begin + end) / 2;
        if (array[middle] < N) //if array[middle] < N,flash the begin value and call the recusive function.
            BSr_implementation(middle + 1, end, N, array);
        if (array[middle] > N)
            BSr_implementation(begin, middle - 1, N, array);
        if (array[middle] == N)
            return;
    }
}

void SSr_implementation(int begin, int N, int *array)
{
    if ((array[begin] != N) && (begin != N - 1)) //if haven't find the value and reach the array'end
        SSr_implementation(begin + 1, N, array);
}
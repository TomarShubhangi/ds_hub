#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//swap
void swap(long int* a, long int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
//bubble sort
void bubbleSort(long int a[], long int n)
{
	long int i,j;
	for(i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - 1 - i; j++) 
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}
int main()
{
    int i;
    double tim1[10];
    FILE*fp;
    fp=fopen("plot1.txt","w");
    printf("A_size, Bubble\n");
    for(i=1;i<4;i++)
    {   
        fprintf(fp,"table %d %s",i,"\n");
        printf("table %d \n",i);
        // Performs 10 iterations
        int it=0;
        long int n=10000;
        while (it++ < 10)
        {
            long int a[n],i;
            // generating n random numbers
            for (i = 0; i < n; i++) 
            {
                long int no = rand() % n + 1;
                a[i] = no;
            }
  
            // using clock_t to store time
            clock_t start, end;
  
            // Bubble sort
            start = clock();
            bubbleSort(a, n);
            end = clock();
  
            tim1[it] = ((double)(end - start));
            // type conversion to long int
            fprintf(fp,"%d %s %f %s",n," ",tim1[it],"\n");
            printf("%li, %li\n",n,(long int)tim1[it]);
            // increases the size of array by 10000
            n += 10000;
        }
    }
    return 0;
}

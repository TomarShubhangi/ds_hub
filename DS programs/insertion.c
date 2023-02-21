#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionSort(long int arr[], long int n)
{
    long int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int i;
    double tim1[10];
    FILE*fp;
    fp=fopen("plot.txt","w");
    printf("A_size, insertion\n");
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
  
            // insertion sort
            start = clock();
            insertionSort(a, n);
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

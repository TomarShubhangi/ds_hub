#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void permutation(int arr[],int n)
{
    int i,t;
    for( i = n-1; i > 0; i--)
	{
        t=rand() % (i + 1);
        swap(arr,i,t);
    }
    printf("\nPermutation of array :");
    for(i=0;i<n;i++)
	{
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 

        } 
        arr[j + 1] = key; 
    } 
    printf("\nSorted  Array :");
    for(i=0;i<n;i++)
	{
        printf("%d ",arr[i]);
    }
    printf("\n");
} 

int main()
{
    FILE * file;
    file = fopen("time.txt", "a+");
    if (file = fopen("time.txt", "a+"))
    {
	    printf("File opened successfully \n");
    }
    else
    {
        printf("Error!");
    }
    int n,i,m=3;
    clock_t t;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int randArray[n];
    for(i=0;i<n;i++)
    {
	    randArray[i]=rand()%100;  
    }
    printf("\nElements of the array are:");
    for(i=0;i<n;i++)
	{
	    printf("%d ",randArray[i]);
    }
	printf("\n");
    while(m--)
	{
	    permutation(randArray,n);
        t = clock();
        insertionSort(randArray, n) ;
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("insertionSort() took %f seconds to execute \n", time_taken);
        fprintf(file, "%d %f  \n",n,time_taken);

    }
    fclose(file);
    return 0;
}

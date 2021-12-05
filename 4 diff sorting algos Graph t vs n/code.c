#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void bubbleSort(int arr[], int n)
{
    for (int i = 0 ; i < n - 1; i++)
    {
        for (int j = 0 ; j < n - i - 1; j++)
        { 
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void InsertionSort(int arr[], int n)
{
     for (int i = 1 ; i <= n - 1; i++)
    {
	    int j = i;
            while ( j > 0 && arr[j-1] > arr[j])
            {	        
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
    }
}

void selection(int arr[], int n)
{
    for (int i = 0 ; i < n; i++)
    {
        int pos=i;
        for (int j=i+1 ; j<n; j++)
        { 
            if (arr[j]<arr[pos])
            {
                pos= j;
            }
        }
        int temp = arr[pos];
        arr[pos] = arr[i];
        arr[i] = temp;
    }
    
}
 

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d",arr[i]);
        printf(" ");
    }
    printf("\n");
}
 

int main()
{
    int* arr1, *arr2, *arr3;
    int n,k,a,j=0;
    int *size; double *Stime, *Itime, *Btime;
    printf("Enter the number of times you want to run the program: ");
    scanf("%d", &k);
    size = (int*)malloc(k * sizeof(int));
    Stime = (double*)malloc(k * sizeof(double));
    Itime = (double*)malloc(k * sizeof(double));
    Btime = (double*)malloc(k * sizeof(double));
    a=k;
    while(k--)
    {
    clock_t b1,e1,b2,e2,b3,e3;
    double time_spent1 = 0.0;
    double time_spent2 = 0.0;
    double time_spent3 = 0.0;

    printf("\nEnter number of elements:");
    scanf("%d",&n);
    size[j]=n;
    arr1 = (int*)malloc(n * sizeof(int));
    arr2 = (int*)malloc(n * sizeof(int));
    arr3 = (int*)malloc(n * sizeof(int));
    
    if (arr1 == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Enter the elements in array:\n");
 
        for (int i = 0; i < n; ++i) {
            arr1[i]= rand();
        }
 
        
    }
    for(int i=0; i<n; i++)
    {
        arr2[i]=arr1[i];
        arr3[i]=arr1[i];
    }
    
    b1=clock();
    bubbleSort(arr1, n);
    e1=clock();
   
    b2=clock();
    InsertionSort(arr2, n);
    e2=clock();
    
    b3=clock();
    selection(arr3, n);
    e3=clock();
    
    //printf("\nSorted array: \n");
    //printArray(arr1, n);
    
    time_spent1 = (double)(e1 - b1) / CLOCKS_PER_SEC;
    time_spent2 = (double)(e2 - b2) / CLOCKS_PER_SEC;
    time_spent3 = (double)(e3 - b3) / CLOCKS_PER_SEC;
    
    Btime[j]= time_spent1;
    Itime[j]= time_spent2;
    Stime[j]= time_spent3;
 
    printf("\nElapsed time\n");
    printf("Bubble Sort: %f seconds\n", time_spent1);
    printf("Insertion Sort: %f seconds\n", time_spent2);
    printf("Selection Sort: %f seconds\n", time_spent3);
    printf("---------------------------------------------\n");
    j++;
    }
    
    printf("\nSize\t\tBubble\t\tSelection\t\tInsertion\n");
    for(int i=0; i<a; i++)
    {
       printf("%d\t\t%f\t%f\t\t%f\n", size[i], Btime[i], Stime[i], Itime[i]);  
    }
    return 0;
}

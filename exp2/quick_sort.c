#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    int j;
    for(j=low;j<high;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}
void quickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}
int main()
{
    int n,i;
    int *randomArr,*sortedArr,*reverseArr;
    clock_t start,end;
    double randomTime, sortedTime, reverseTime;
    printf("Enter the number of parcels: ");
    scanf("%d",&n);
    randomArr=(int *)malloc(n*sizeof(int));
    sortedArr=(int *)malloc(n*sizeof(int));
    reverseArr=(int *)malloc(n*sizeof(int));
    if(randomArr==NULL || sortedArr==NULL || reverseArr==NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        randomArr[i]=rand()%100000;
        sortedArr[i]=i+1;
        reverseArr[i]=n-i;
    }
    start=clock();
    quickSort(randomArr,0,n-1);
    end=clock();
    randomTime=(double)(end-start)/CLOCKS_PER_SEC;
    start=clock();
    quickSort(sortedArr,0,n-1);
    end=clock();
    sortedTime=(double)(end-start)/CLOCKS_PER_SEC;
    start=clock();
    quickSort(reverseArr,0,n-1);
    end=clock();
    reverseTime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n-----------------------------------\n");
    printf("    QUICK SORT TIME COMPARISON\n");
    printf("-----------------------------------\n");
    printf("Input Type       Time (seconds)\n");
    printf("-----------------------------------\n");
    printf("Random           %f\n", randomTime);
    printf("Sorted           %f\n", sortedTime);
    printf("Reverse Sorted   %f\n", reverseTime);
    printf("-----------------------------------\n");
    printf("\nQuick Sort Time Complexity\n");
    printf("Best Case    = O(n log n)\n");
    printf("Average Case = O(n log n)\n");
    printf("Worst Case   = O(n^2)\n");
    printf("Space Complexity = O(log n) average\n");
    printf("Space Complexity = O(n) worst case\n");
    free(randomArr);
    free(sortedArr);
    free(reverseArr);
    return 0;
}

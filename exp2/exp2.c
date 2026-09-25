#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int A[],int low,int mid,int high)
{
    int i,j,k;
    int *temp;
    i = low;
    j = mid+1;
    k = 0;
    temp=(int *)malloc((high - low + 1) * sizeof(int));
    while(i<=mid && j<=high)
    {
        if (A[i]<=A[j])
            temp[k++]=A[i++];
        else
            temp[k++]=A[j++];
    }
    while(i<= mid)
        temp[k++]=A[i++];
    while(j<=high)
        temp[k++]=A[j++];
    for(i=low,k=0;i<=high;i++,k++)
        A[i]=temp[k];
    free(temp);
}
void mergeSort(int A[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}
void generateRandom(int A[],int n)
{
    int i;
    for (i=0;i<n;i++)
        A[i]=rand();
}
void copyArray(int A[],int B[],int n)
{
    int i;
    for(i=0;i<n;i++)
        B[i]=A[i];
}
void reverseArray(int A[],int n)
{
    int i,temp;
    for(i=0;i<n/2;i++)
    {
        temp=A[i];
        A[i]= A[n-i-1];
        A[n-i-1]=temp;
    }
}

int main()
{
    int n;
    int *randomInput;
    int *sortedInput;
    int *reverseInput;
    clock_t start, end;
    double randomTime;
    double sortedTime;
    double reverseTime;
    printf("Enter number of parcels: ");
    scanf("%d", &n);
    randomInput=(int *)malloc(n * sizeof(int));
    sortedInput=(int *)malloc(n * sizeof(int));
    reverseInput=(int *)malloc(n * sizeof(int));
    srand(time(NULL));
    generateRandom(randomInput,n);
    copyArray(randomInput,sortedInput,n);
    mergeSort(sortedInput,0,n-1);
    copyArray(sortedInput,reverseInput,n);
    reverseArray(reverseInput,n);   
    start=clock();
    mergeSort(randomInput,0,n-1);
    end=clock();
    randomTime=(double)(end-start)/CLOCKS_PER_SEC;  
    start=clock();
    mergeSort(sortedInput,0,n-1);
    end = clock();
    sortedTime=(double)(end-start)/CLOCKS_PER_SEC;  
    start=clock();
    mergeSort(reverseInput,0,n-1);
    end=clock();
    reverseTime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nMERGE SORT PERFORMANCE ANALYSIS\n");
    printf("\nInput Type              Execution Time\n");
    printf("Random Input            %.6f seconds\n", randomTime);
    printf("Sorted Input            %.6f seconds\n", sortedTime);
    printf("Reverse Sorted Input    %.6f seconds\n", reverseTime);
    printf("\nTime Complexity:\n");
    printf("Random Input            O(n log n)\n");
    printf("Sorted Input            O(n log n)\n");
    printf("Reverse Sorted Input    O(n log n)\n");
    printf("\nSpace Complexity: O(n)\n");
    free(randomInput);
    free(sortedInput);
    free(reverseInput);
    return 0;
}

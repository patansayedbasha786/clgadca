#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i;
int linearsearch(int a[],int n,int key)
{
    for(i=0;i<n;i++)
    {
        if (a[i]==key)
        return -1;
    }
    return 0;
}
int binarysearch(int a[],int n,int key)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (a[mid]==key)
            return mid;
        else
        { if (a[mid]<key)
        low=mid+1;
           
        else
            high=mid-1;
        }
    }
        return -1;
}
   
   
   
   
   
int main()
{
    int n,key;
    int *a;
    printf("Enter the number of products:");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    printf("\n input size  are: %d\n",n);
    printf("\nsearch key\tlinear\t\tbinary\n");
    key=a[0];
    clock_t start=clock();
    linearsearch(a,n,key);
    clock_t end=clock();
    double Lineartime =(double)(end-start)/CLOCKS_PER_SEC;
    start=clock();
    binarysearch(a,n,key);
    end=clock();
    double binarytime =(double)(end-start)/CLOCKS_PER_SEC;   
    printf("%d\t\t%.8f\t%.8f\n",key,Lineartime,binarytime);
    key=a[n/2];
    start=clock();
    linearsearch(a,n,key);
    end=clock();
    Lineartime=(double)(end-start)/CLOCKS_PER_SEC;
    start=clock();
    binarysearch(a,n,key);
    end=clock();
    binarytime =(double)(end-start)/CLOCKS_PER_SEC;
    printf("%d\t\t%.8f\t%.8f\n",key,Lineartime,binarytime);
    key=n+1;
    start=clock();
    linearsearch(a,n,key);
    end=clock();
    Lineartime=(double)(end-start)/CLOCKS_PER_SEC;   
    start=clock();
    binarysearch(a,n,key);
    end=clock();
    binarytime =(double)(end-start)/CLOCKS_PER_SEC;
    printf("%d\t\t%.8f\t%.8f\n\n",key,Lineartime,binarytime);
    printf("Linear search: Best= O(1);Average= O(n); Worst= O(n)\n");
    printf("Binary search: Best= O(1);Average= O(log n); Worst= O(log n)\n");
    return 0;
}

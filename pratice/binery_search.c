#include <stdio.h>

int main()
{
    int a[50];
    int low,high,mid;
    int n,i,key;
    printf("Enter the array size: ");
    scanf("%d",&n);
    printf("Enter the array elements in sorted order:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the key value: ");
    scanf("%d",&key);
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            printf("The key is found at position %d\n",mid+1);
            return 0;
        }
        else if(key>a[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    printf("Key not found\n");
    return 0;
}

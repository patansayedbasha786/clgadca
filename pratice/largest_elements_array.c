#include <stdio.h>
int main()
{
    int a[50];
    int n, i, largest;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    largest = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }
    printf("The largest element is: %d\n", largest);
    return 0;
}

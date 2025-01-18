#include <stdio.h>
void quick_sort(int arr[], int l, int h)
{
    int ei = h, si = l, pivot = arr[l];
    while (ei > si)
    {
        while (arr[si] <= pivot && si < h)
        {
            si++;
        }
        while (arr[ei] >= pivot && ei > l)
        {
            ei--;
        }
        if (ei > si)
        {
            int temp = arr[si];
            arr[si] = arr[ei];
            arr[ei] = temp;
        }
    }
    int temp = arr[l];
    arr[l] = arr[ei];
    arr[ei] = temp;
    if(ei>l)
    {
        quick_sort(arr,l,ei-1);
    }
    else if (ei<h)
    {
        quick_sort(arr,ei+1,h);
    }
    return;
}
int main()
{
    int n;
    printf("Enter number of Elements : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
// merge sort
#include <stdio.h>
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l+1, n2 = r - m;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l+i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + i + 1];
    int i1 = 0, j1 = 0, k = l;
    while (i1 < n1 && j1 < n2)
    {
        if (L[i1] > R[j1])
        {
            arr[k] = R[j1];
            k++, j1++;
        }
        else
        {
            arr[k] = L[i1];
            k++, i1++;
        }
    }
	while(i1<n1)
	{
		arr[k++]=R[i1++];
	}
	while(j1<n2)
	{
		arr[k++]=L[j1++];
	}
}
void split(int arr[], int l, int r, int size)
{
    size = r - l + 1;
    if (size > 1)
    {
        int mid = (l+r) / 2;
        split(arr, l, mid, size);
        split(arr, mid + 1, r, size);
        merge(arr, l, mid, r);
    }
}
int main()
{
    int n;
    printf("Enter the size of array");
	scanf("%d",&n);
    int array[n];
    printf("enter the elements of array");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    split(array, 0, n - 1, 0);
    printf("Sorted array");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
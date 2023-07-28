#include <stdio.h>

int flag = 0;

void combination(int ind, int n, int arr[], int target, int ds[], int ds_size)
{
    if (target == 0)
    {
        flag = 1;
        printf("{");
        for (int i = 0; i < ds_size; i++)

            printf("%d ", ds[i]);
        printf("}");
        printf("\n");
        return;
    }
    for (int i = ind; i < n; i++)
    {
        if (arr[i] > target)
            break;
        ds[ds_size] = arr[i];
        combination(i + 1, n, arr, target - arr[i], ds, ds_size + 1);
    }
}

int main()
{
    int n, target;
    printf("enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements in increasing order:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("enter target: ");
    scanf("%d", &target);
    int ds[n];
    combination(0, n, arr, target, ds, 0);
    if (flag == 0)
        printf("no solution\n");

    return 0;
}

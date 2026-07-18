#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(long int a[], long int low, long int mid, long int high) {
    long int i = low, j = mid + 1, k = 0;
    long int *temp = malloc((high - low + 1) * sizeof(long int));
    while (i <= mid && j <= high)
        temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];
    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
    free(temp);
}
void mergeSort(long int a[], long int low, long int high) {
    if (low < high) {
        long int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main() {
    long int n = 10000, i;
    int it;
    printf("A_size,Merge\n");
    for (it = 0; it < 10; it++, n += 10000) {
        long int *a = malloc(n * sizeof(long int));
        clock_t start, end;
        for (i = 0; i < n; i++)
            a[i] = rand() % n + 1;
        start = clock();
        mergeSort(a, 0, n - 1);
        end = clock();
        printf("%li,%f\n", n, (double)(end - start) / CLOCKS_PER_SEC);
        free(a);
    }
    return 0;
}

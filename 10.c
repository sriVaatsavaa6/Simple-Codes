#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(long int *a, long int *b) {
    long int t = *a;
    *a = *b;
    *b = t;
}
int partition(long int a[], int low, int high) {
    long int pivot = a[high];
    int i = low - 1, j;
    for (j = low; j < high; j++)
        if (a[j] <= pivot)
            swap(&a[++i], &a[j]);
    swap(&a[i + 1], &a[high]);
    return i + 1;
}
void quickSort(long int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
int main() {
    long int n = 10000, i;
    int it;
    printf("a_size,quick\n");
    for (it = 0; it < 10; it++, n += 10000) {
        long int *a = malloc(n * sizeof(long int));
        clock_t start, end;
        for (i = 0; i < n; i++)
            a[i] = rand() % n + 1;
        start = clock();
        quickSort(a, 0, n - 1);
        end = clock();
        printf("%li %f\n", n, (double)(end - start) / CLOCKS_PER_SEC);
        free(a);
    }
    return 0;
}

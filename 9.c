#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(long int a[], long int n) {
    long int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main() {
    long int n = 5000, i;
    int it;
    printf("A_size, Selection\n");
    for (it = 0; it < 10; it++, n += 500) {
        long int *a = malloc(n * sizeof(long int));
        clock_t start, end;
        for (i = 0; i < n; i++)
            a[i] = rand() % n + 1;
        start = clock();
        selectionSort(a, n);
        end = clock();
        printf("%li, %f\n", n, (double)(end - start) / CLOCKS_PER_SEC);
        free(a);
    }
    return 0;
}

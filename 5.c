#include <stdio.h>
#define MAX 20
int main() {
    int a[MAX][MAX], indeg[MAX] = {0}, order[MAX];
    int n, i, j, k = 0;
    printf("\nEnter the n value : ");
    scanf("%d", &n);
    printf("\n Enter the graph data : \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j])
                indeg[j]++;
        }
    while (k < n) {
        for (i = 1; i <= n; i++)
            if (indeg[i] == 0)
                break;
        if (i > n)
            break;
        order[k++] = i;
        indeg[i] = -1;
        for (j = 1; j <= n; j++)
            if (a[i][j])
                indeg[j]--;
    }
    if (k != n)
        printf("\nTopological ordering not possible ");
    else {
        printf("\nTopological ordering is : ");
        for (i = 0; i < k; i++)
            printf("%d ", order[i]);
    }
    return 0;
}

#include <stdio.h>
#define MAX 100
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int n, W, val[MAX], wt[MAX], dp[MAX][MAX];
    int i, w;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the values and weights of %d items:\n", n);
    for (i = 1; i <= n; i++) {
        printf("Enter value and weight for item %d: ", i);
        scanf("%d %d", &val[i], &wt[i]);
    }
    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i] <= w)
                dp[i][w] = max(val[i] + dp[i - 1][w - wt[i]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    printf("Maximum value that can be obtained: %d\n", dp[n][W]);
    return 0;
}

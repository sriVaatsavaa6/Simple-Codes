#include <stdio.h>
#define INF 999
#define MAX 20
int main() {
    int n, s, cost[MAX][MAX], dist[MAX], visited[MAX] = {0};
    int i, j, count;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the weighted matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    for (i = 0; i < n; i++)
        dist[i] = cost[s][i];
    dist[s] = 0;
    visited[s] = 1;
    for (count = 1; count < n; count++) {
        int min = INF, u = -1;
        for (i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        if (u == -1)
            break;
        visited[u] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i] && cost[u][i] != INF &&
                dist[u] + cost[u][i] < dist[i])
                dist[i] = dist[u] + cost[u][i];
    }
    printf("The shortest path between source %d to remaining vertices are:\n", s);
    for (i = 0; i < n; i++)
        if (i != s)
            printf("%d -> %d = %d\n", s, i, dist[i]);
    return 0;
}

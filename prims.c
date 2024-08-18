#include <stdio.h>

#define INFINITY 999

int prime(int cost[10][10], int source, int n) {
    int visited[10] = {0}, cmp[10], vertex[10], sum = 0;

    for (int i = 1; i <= n; i++) {
        cmp[i] = cost[source][i];
        vertex[i] = source;
    }
    visited[source] = 1;

    for (int i = 1; i < n; i++) {
        int min = INFINITY, u = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && cmp[j] < min) {
                min = cmp[j];
                u = j;
            }
        }
        if (u == -1) break; // Exit if no connected vertex is found

        visited[u] = 1;
        sum += cmp[u];
        printf("\n %d -> %d sum = %d", vertex[u], u, cmp[u]);

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && cost[u][v] < cmp[v]) {
                cmp[v] = cost[u][v];
                vertex[v] = u;
            }
        }
    }
    return sum;
}

int main() {
    int a[10][10], n, source;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix (0 for self-loop and 999 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if ((i == j && a[i][j] != 0) || (i != j && a[i][j] != a[j][i])) {
                printf("\nInvalid entry\nCost matrix should be symmetrical & diagonal elements should be zero.");
                return 1;
            }
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &source);

    int totalCost = prime(a, source, n);
    printf("\n\nTotal cost = %d", totalCost);

    return 0;
}

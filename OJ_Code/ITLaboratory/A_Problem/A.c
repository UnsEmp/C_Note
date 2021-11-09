#include <stdio.h>
#define MAX 301

int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int (*grid)[MAX], int x, int y, int n, int m) {
    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return ;
    for(int i = 0;i < 4;i++) {
        grid[x][y] = 0;
        dfs(grid, x + direction[i][0], y + direction[i][1], n, m);
    }
}
int numIslands(int (*grid)[MAX], int n, int m) {
    int count = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(grid[i][j] == 1) {
                dfs(grid, i, j, n, m);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int arr[MAX][MAX];
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d\n", numIslands(arr, n, m));  
    return 0;
}
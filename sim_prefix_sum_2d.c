#include <stdio.h>
#include <malloc.h>

int main() {
    int a1, a2, b1, b2, c, m, **mat, **memory, n;

    scanf("%d %d", &n, &m);
    mat = (int**)calloc(n + 1, sizeof(int*));
    memory = (int**)calloc(n + 1, sizeof(int*));

    // mat[0] = new int[m + 1];
    mat[0] = (int*)calloc(m + 1, sizeof(int));
    memory[0] = (int*)calloc(m + 1, sizeof(int));
    for (int i = 0; i <= m; i++)
    {
        mat[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        mat[i] = (int*)calloc(m + 1, sizeof(int));
        memory[i] = (int*)calloc(m + 1, sizeof(int));
        mat[i][0] = 0;
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", *(memory + i) + j);
            mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + memory[i][j];
        }
    }  

    scanf("%d", &c);
    for (int i = 0; i < c; i++)
    {
        // cin >> a1 >> b1 >> a2 >> b2;
        scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
        printf("%d\n", mat[a2][b2] - mat[a1 - 1][b2] - mat[a2][b1 - 1] + mat[a1 - 1][b1 - 1]);
    }
    
    return 0;
}
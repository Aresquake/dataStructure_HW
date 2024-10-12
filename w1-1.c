#include <stdio.h>
#include <stdlib.h>

void allocArray(int ***p, int m, int n) {
    // 為行指標分配記憶體
    *p = (int **)malloc(m * sizeof(int *));
    // 分配一塊連續的記憶體
    int *data = (int *)malloc(m * n * sizeof(int));
    
    for (int i = 0; i < m; i++) {
        // 將每一行指向連續記憶體中的對應位置
        (*p)[i] = data +  i * n;
    }
}

int main() {
    int **array;
    int j, k;
    allocArray(&array, 5, 10);
    for (j = 0; j < 5; j++)
        for (k = 0; k < 10; k++)
            array[j][k] = j * 10 + k;

    for (j = 0; j < 5; j++)
        for (k = 0; k < 10; k++)
            printf("%p ", &(array[j][k]));

    // 釋放記憶體
    free(array[0]);  // 釋放連續的記憶體
    free(array);     // 釋放行指標

    return 0;
}

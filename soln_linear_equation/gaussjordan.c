#include <stdio.h>

int main() {
    int num;
    printf("Enter the number of unknowns you want to find: ");
    scanf("%d", &num);

    float arr[num][num + 1];
    float b[num];

    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= num; j++) {
            printf("Enter the element a[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &arr[i][j]);
        }
    }

    printf("\nThe augmented matrix is:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= num; j++) {
            printf("%f\t", arr[i][j]);
        }
        printf("\n");
    }

    for (int j = 0; j < num; j++) {
        if (arr[j][j] == 0) {
            printf("This system cannot be solved by Gauss-Jordan method because of a zero pivot.\n");
            return -1;
        }

        float pivot = arr[j][j];
        for (int k = 0; k < num + 1; k++) {
            arr[j][k] /= pivot;
        }

        for (int i = 0; i < num; i++) {
            if (i != j) {
                float ratio = arr[i][j];
                for (int k = 0; k < num + 1; k++) {
                    arr[i][k] -= ratio * arr[j][k];
                }
            }
        }
    }

    printf("\nMatrix after Gauss-Jordan Operation:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= num; j++) {
            printf("%f\t", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < num; i++) {
        b[i] = arr[i][num];
    }

    printf("\nThe solutions are:\n");
    for (int i = 0; i < num; i++) {
        printf("x[%d] = %.2f\n", i + 1, b[i]);
    }

    return 0;
}
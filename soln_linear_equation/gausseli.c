#include <stdio.h>

int main() {
    int n;
    float factor;
    float mat[10][10];
    float soln[10];
    float sum;

    printf("Enter the number of unknown variables: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("Enter element a[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (mat[i][i] == 0) {
            printf("The solution does not exist.\n");
            return 0;
        }

        for (int j = 0; j < n; j++) {
            if (i < j) {
                factor = mat[j][i] / mat[i][i];
                for (int k = 0; k <= n; k++) {
                    mat[j][k] = mat[j][k] - factor * mat[i][k];
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += mat[i][j] * soln[j];
        }
        soln[i] = (mat[i][n] - sum) / mat[i][i];
    }

    for (int i = 0; i < n; i++) {
        printf("The value of unknown variable x%d is: %.2f\n", i + 1, soln[i]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);
    
    // Allocate memory for matrices and vectors
    double **A = (double **)malloc(n * sizeof(double *));
    double **L = (double **)malloc(n * sizeof(double *));
    double **U = (double **)malloc(n * sizeof(double *));
    double *B = (double *)malloc(n * sizeof(double));
    double *Y = (double *)malloc(n * sizeof(double));
    double *X = (double *)malloc(n * sizeof(double));
    
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
        L[i] = (double *)malloc(n * sizeof(double));
        U[i] = (double *)malloc(n * sizeof(double));
    }
    
    // Initialize L and U matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            L[i][j] = 0;
            U[i][j] = 0;
        }
        L[i][i] = 1; // Diagonal elements of L are set to 1
    }
    
    // Input coefficients and right-hand side values
    printf("\nEnter the coefficients of the equations:\n");
    for (int i = 0; i < n; i++) {
        printf("Equation %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("Coefficient of x%d: ", j + 1);
            scanf("%lf", &A[i][j]);
        }
        printf("Right-hand side value (b%d): ", i + 1);
        scanf("%lf", &B[i]);
    }
    
    // Display the system of equations
    printf("\nSystem of Equations:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf*x%d ", A[i][j], j + 1);
            if (j < n - 1) printf("+ ");
        }
        printf("= %.2lf\n", B[i]);
    }
    
    // Perform LU factorization using Doolittle's method
    for (int k = 0; k < n; k++) {
        // Upper triangular matrix
        for (int j = k; j < n; j++) {
            double sum = 0;
            for (int s = 0; s < k; s++) {
                sum += L[k][s] * U[s][j];
            }
            U[k][j] = A[k][j] - sum;
        }
        
        // Lower triangular matrix
        for (int i = k + 1; i < n; i++) {
            double sum = 0;
            for (int s = 0; s < k; s++) {
                sum += L[i][s] * U[s][k];
            }
            L[i][k] = (A[i][k] - sum) / U[k][k];
        }
    }
    
    // Display L matrix
    printf("\nL Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.4lf\t", L[i][j]);
        }
        printf("\n");
    }
    
    // Display U matrix
    printf("\nU Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.4lf\t", U[i][j]);
        }
        printf("\n");
    }
    
    // Solve LY = B for Y using forward substitution
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * Y[j];
        }
        Y[i] = B[i] - sum;
    }
    
    // Solve UX = Y for X using backward substitution
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * X[j];
        }
        X[i] = (Y[i] - sum) / U[i][i];
    }
    
    // Display the solution
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.4lf\n", i + 1, X[i]);
    }
    
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(L[i]);
        free(U[i]);
    }
    free(A);
    free(L);
    free(U);
    free(B);
    free(Y);
    free(X);
    
    return 0;
}

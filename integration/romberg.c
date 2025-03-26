#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to be integrated
double f(double x) {
    return x*x + 2*x + 1; // Example: f(x) = x^2 + 2x + 1
}

// Trapezoidal rule implementation (needed for Romberg integration)
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    
    return h * sum;
}

// Romberg integration implementation
void romberg(double a, double b, int max_order, double tolerance) {
    double **R = (double **)malloc((max_order + 1) * sizeof(double *));
    for (int i = 0; i <= max_order; i++) {
        R[i] = (double *)malloc((max_order + 1) * sizeof(double));
    }
    
    // Compute R(0,0)
    R[0][0] = trapezoidal(a, b, 1);
    
    printf("\nRomberg Integration Table:\n");
    printf("R[0][0] = %lf\n", R[0][0]);
    
    for (int i = 1; i <= max_order; i++) {
        // Compute R(i,0) using trapezoidal rule with 2^i intervals
        R[i][0] = trapezoidal(a, b, 1 << i);
        printf("R[%d][0] = %lf\n", i, R[i][0]);
        
        // Compute R(i,j) using Richardson extrapolation
        for (int j = 1; j <= i; j++) {
            R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (pow(4, j) - 1);
            printf("R[%d][%d] = %lf\n", i, j, R[i][j]);
        }
        
        // Check for convergence
        if (i > 0 && fabs(R[i][i] - R[i-1][i-1]) < tolerance) {
            printf("\nConverged at order %d with value %.10lf\n", i, R[i][i]);
            
            // Free memory
            for (int k = 0; k <= max_order; k++) {
                free(R[k]);
            }
            free(R);
            
            return;
        }
    }
    
    printf("\nFinal approximation: %.10lf\n", R[max_order][max_order]);
    
    // Free memory
    for (int i = 0; i <= max_order; i++) {
        free(R[i]);
    }
    free(R);
}

int main() {
    double a, b, tolerance;
    int max_order;
    
    printf("=== Numerical Integration using Romberg Method ===\n");
    printf("This program integrates f(x) = x^2 + 2x + 1\n\n");
    
    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);
    
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);
    
    printf("Enter the maximum order (recommended 4-6): ");
    scanf("%d", &max_order);
    
    printf("Enter the tolerance (e.g., 1e-10): ");
    scanf("%lf", &tolerance);
    
    if (max_order <= 0) {
        printf("Maximum order must be positive!\n");
        return 1;
    }
    
    romberg(a, b, max_order, tolerance);
    
    // For this specific function, we can calculate the exact value
    double exact = (pow(b, 3)/3 + pow(b, 2) + b) - (pow(a, 3)/3 + pow(a, 2) + a);
    printf("Exact value: %.10lf\n", exact);
    
    return 0;
}

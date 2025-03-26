#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.0005 // For 3 decimal place accuracy
#define MAX_ITERATIONS 100

// Description of the Jacobi method
void print_description() {
    printf("======================================================================\n");
    printf("                           JACOBI METHOD\n");
    printf("======================================================================\n");
    printf("The Jacobi method is an iterative algorithm for solving a system of\n");
    printf("linear equations. It works by solving each equation for its diagonal\n");
    printf("variable and using previous iteration values for other variables.\n\n");
    printf("For a system Ax = b, each iteration computes:\n");
    printf("   x_i^(k+1) = (b_i - sum_{j≠i} A_ij * x_j^(k)) / A_ii\n\n");
    printf("For convergence, the system should be diagonally dominant, meaning\n");
    printf("for each row, the diagonal element should be larger in magnitude than\n");
    printf("the sum of magnitudes of all other elements in that row.\n");
    printf("======================================================================\n\n");
}

void display_equation(float *coef, float constant, int n, int eq_num) {
    printf("Equation %d: ", eq_num);
    int first_term = 1;
    
    for (int i = 0; i < n; i++) {
        if (coef[i] == 0) continue;
        
        if (!first_term) {
            printf(coef[i] > 0 ? "+ " : "- ");
        }
        
        float abs_val = fabs(coef[i]);
        if (abs_val == 1) {
            printf("x%d ", i + 1);
        } else {
            printf("%.2f x%d ", abs_val, i + 1);
        }
        
        first_term = 0;
    }
    
    printf("= %.2f\n", constant);
}

int main() {
    int n, i, j, iteration = 0;
    float **A, *b, *x, *x_new;
    
    // Display method description
    print_description();
    
    // Input number of unknowns
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    // Memory allocation
    A = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        A[i] = (float *)malloc(n * sizeof(float));
    }
    b = (float *)malloc(n * sizeof(float));
    x = (float *)calloc(n, sizeof(float)); // Initial guess is zero
    x_new = (float *)malloc(n * sizeof(float));
    
    // Input coefficients with guidance
    printf("\nEnter the coefficients of the equations:\n");
    printf("NOTE: For reliable convergence, please ensure your system is diagonally dominant.\n");
    printf("This means that for each equation, the coefficient of the diagonal term should be\n");
    printf("greater in magnitude than the sum of the magnitudes of all other coefficients.\n\n");
    
    for (i = 0; i < n; i++) {
        printf("\nEquation %d:\n", i + 1);
        for (j = 0; j < n; j++) {
            printf("Coefficient of x%d: ", j + 1);
            scanf("%f", &A[i][j]);
        }
        printf("Constant term: ");
        scanf("%f", &b[i]);
    }

    // Display the equations
    printf("\nThe system of equations is:\n");
    for (i = 0; i < n; i++) {
        display_equation(A[i], b[i], n, i + 1);
    }

    // Check diagonal dominance for convergence
    printf("\nChecking if the system is diagonally dominant...\n");
    int diagonally_dominant = 1;
    for(i = 0; i < n; i++) {
        float sum = 0;
        for(j = 0; j < n; j++) {
            if(i != j) {
                sum += fabs(A[i][j]);
            }
        }
        if(fabs(A[i][i]) <= sum) {
            printf("Warning: The equation %d is not diagonally dominant.\n", i+1);
            printf("For row %d: |A[%d][%d]| = %.2f, Sum of other |coefficients| = %.2f\n", 
                   i+1, i+1, i+1, fabs(A[i][i]), sum);
            diagonally_dominant = 0;
        }
    }
    
    if(diagonally_dominant) {
        printf("The system is diagonally dominant. Convergence is expected.\n");
    } else {
        printf("\nWARNING: The system is not diagonally dominant. Convergence may be slow or fail.\n");
        printf("Do you want to continue anyway? (1 for Yes, 0 for No): ");
        int continue_choice;
        scanf("%d", &continue_choice);
        if(!continue_choice) {
            printf("Calculation aborted. Please revise your coefficients.\n");
            
            // Free memory before exit
            for (i = 0; i < n; i++) {
                free(A[i]);
            }
            free(A);
            free(b);
            free(x);
            free(x_new);
            
            return 0;
        }
    }

    // Jacobi Iterations
    printf("\nJacobi Method Iterations:\n");
    printf("Iteration\t");
    for (i = 0; i < n; i++) {
        printf("x%d\t\t", i + 1);
    }
    printf("\n");
    printf("---------------------------------------------------------------\n");

    int converged = 0;
    while (!converged && iteration < MAX_ITERATIONS) {
        printf("%d\t\t", iteration);
        for (i = 0; i < n; i++) {
            printf("%.6f\t", x[i]);
        }
        printf("\n");

        // Compute next iteration values
        for (i = 0; i < n; i++) {
            float sum = 0;
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * x[j]; // Use previous iteration values
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        // Check for convergence
        converged = 1;
        for (i = 0; i < n; i++) {
            if (fabs(x_new[i] - x[i]) > EPSILON) {
                converged = 0;
                break;
            }
        }

        // Update x for next iteration
        for (i = 0; i < n; i++) {
            x[i] = x_new[i];
        }

        iteration++;
    }

    // Display final result
    printf("\n===================================================================\n");
    if (converged) {
        printf("Solution converged after %d iterations.\n", iteration);
        for (i = 0; i < n; i++) {
            printf("x%d = %.3f\n", i + 1, x[i]);
        }
    } else {
        printf("Solution did not converge within %d iterations.\n", MAX_ITERATIONS);
        for (i = 0; i < n; i++) {
            printf("x%d = %.3f\n", i + 1, x[i]);
        }
    }

    // Free memory
    for (i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);
    free(x_new);

    return 0;
}
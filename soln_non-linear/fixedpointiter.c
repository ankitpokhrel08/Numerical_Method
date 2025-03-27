#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.0001 // For convergence check
#define MAX_ITERATIONS 100

// Original function f(x) = 0
double f(double x) {
    return x*x*x - 4*x - 9; // Example: f(x) = x³ - 4x - 9
}

// Rearranged function g(x) where x = g(x)
double g(double x) {
    return cbrt(4*x + 9); // x = ∛(4x + 9)
}

// Description of the Fixed Point Iteration method
void print_description() {
    printf("======================================================================\n");
    printf("                   FIXED POINT ITERATION METHOD\n");
    printf("======================================================================\n");
    printf("The Fixed Point Iteration method finds a fixed point of a function g(x),\n");
    printf("which corresponds to a solution of the equation x = g(x).\n\n");
    printf("To solve f(x) = 0, we rewrite it as x = g(x) and iterate:\n");
    printf("   x_(n+1) = g(x_n)\n\n");
    printf("For convergence, |g'(x)| < 1 should hold near the solution. If this\n");
    printf("condition is not met, the method may diverge.\n");
    printf("======================================================================\n\n");
}

int main() {
    double x0, x1, f_x0;
    int iteration = 0;
    int converged = 0;
    
    // Display method description
    print_description();
    
    printf("Function: f(x) = x³ - 4x - 9 = 0\n");
    printf("Rearranged as: x = g(x) = ∛(4x + 9)\n\n");
    
    // Get initial guess
    printf("Enter initial guess (x0): ");
    scanf("%lf", &x0);
    
    printf("\nFixed Point Iteration Method Iterations:\n");
    printf("---------------------------------------------------------------\n");
    printf("Iteration\tx_n\t\tf(x_n)\t\tx_(n+1)\n");
    printf("---------------------------------------------------------------\n");
    
    while (!converged && iteration < MAX_ITERATIONS) {
        // Calculate function values
        f_x0 = f(x0);
        x1 = g(x0);  // Next approximation using g(x)
        
        // Print current iteration details
        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\n", 
               iteration, x0, f_x0, x1);
        
        // Check for convergence
        if (fabs(x1 - x0) < EPSILON) {
            converged = 1;
            break;
        }
        
        // Update for next iteration
        x0 = x1;
        iteration++;
    }
    
    printf("---------------------------------------------------------------\n");
    
    if (converged) {
        printf("\nRoot found after %d iterations: %.6lf\n", iteration, x1);
        printf("Function value at root: %.10lf\n", f(x1));
    } else {
        printf("\nMethod did not converge after %d iterations.\n", MAX_ITERATIONS);
        printf("Last approximation: %.6lf\n", x1);
        printf("This might indicate that the iteration is diverging or converging very slowly.\n");
    }
    
    return 0;
}

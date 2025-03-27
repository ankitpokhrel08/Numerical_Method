#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.0001 // For convergence check
#define MAX_ITERATIONS 100

// Function for which we want to find the root
double f(double x) {
    return x*x*x - 4*x - 9; // Example: f(x) = x³ - 4x - 9
}

// Description of the Secant method
void print_description() {
    printf("======================================================================\n");
    printf("                         SECANT METHOD\n");
    printf("======================================================================\n");
    printf("The Secant method is similar to the Newton-Raphson method but does not\n");
    printf("require evaluating the derivative. Instead, it approximates the derivative\n");
    printf("using two previous points.\n\n");
    printf("The iteration formula is:\n");
    printf("   x_n = x_{n-1} - f(x_{n-1}) * (x_{n-1} - x_{n-2}) / (f(x_{n-1}) - f(x_{n-2}))\n\n");
    printf("Unlike Regula Falsi, the two initial points don't need to bracket a root.\n");
    printf("The method typically converges faster than bisection but may diverge in\n");
    printf("some cases.\n");
    printf("======================================================================\n\n");
}

int main() {
    double x0, x1, x2, f_x0, f_x1;
    int iteration = 0;
    int converged = 0;
    
    // Display method description
    print_description();
    
    printf("Function: f(x) = x³ - 4x - 9\n\n");
    
    // Get initial guesses
    printf("Enter two initial guesses:\n");
    printf("x0: ");
    scanf("%lf", &x0);
    printf("x1: ");
    scanf("%lf", &x1);
    
    // Calculate function values
    f_x0 = f(x0);
    f_x1 = f(x1);
    
    printf("\nSecant Method Iterations:\n");
    printf("---------------------------------------------------------------\n");
    printf("Iteration\tx_(n-1)\t\tx_n\t\tf(x_n)\t\tx_(n+1)\n");
    printf("---------------------------------------------------------------\n");
    
    while (!converged && iteration < MAX_ITERATIONS) {
        // Check if the difference in function values is too small
        if (fabs(f_x1 - f_x0) < EPSILON) {
            printf("\nError: Division by near-zero value. Method fails.\n");
            return 1;
        }
        
        // Secant formula
        x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);
        
        // Print current iteration details
        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", 
               iteration, x0, x1, f_x1, x2);
        
        // Check for convergence
        if (fabs(x2 - x1) < EPSILON) {
            converged = 1;
            break;
        }
        
        // Update values for next iteration
        x0 = x1;
        f_x0 = f_x1;
        x1 = x2;
        f_x1 = f(x1);
        
        iteration++;
    }
    
    printf("---------------------------------------------------------------\n");
    
    if (converged) {
        printf("\nRoot found after %d iterations: %.6lf\n", iteration, x2);
        printf("Function value at root: %.10lf\n", f(x2));
    } else {
        printf("\nMethod did not converge after %d iterations.\n", MAX_ITERATIONS);
        printf("Last approximation: %.6lf\n", x2);
    }
    
    return 0;
}

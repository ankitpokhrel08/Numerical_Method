#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.0001 // For convergence check
#define MAX_ITERATIONS 100

// Function for which we want to find the root
double f(double x) {
    return x*x*x - 4*x - 9; // Example: f(x) = x³ - 4x - 9
}

// Derivative of the function
double f_prime(double x) {
    return 3*x*x - 4; // Example: f'(x) = 3x² - 4
}

// Description of the Newton-Raphson method
void print_description() {
    printf("======================================================================\n");
    printf("                      NEWTON-RAPHSON METHOD\n");
    printf("======================================================================\n");
    printf("The Newton-Raphson method is a powerful iterative technique for finding\n");
    printf("a root of a real-valued function. It uses the function and its derivative.\n\n");
    printf("The method works by starting with an initial guess and then iterating:\n");
    printf("   x_(n+1) = x_n - f(x_n)/f'(x_n)\n\n");
    printf("The method converges quadratically when close to a root, but may fail\n");
    printf("if the derivative becomes too small or if the initial guess is far from\n");
    printf("the root.\n");
    printf("======================================================================\n\n");
}

int main() {
    double x0, x1, f_x0, f_prime_x0;
    int iteration = 0;
    int converged = 0;
    
    // Display method description
    print_description();
    
    printf("Function: f(x) = x³ - 4x - 9\n");
    printf("Derivative: f'(x) = 3x² - 4\n\n");
    
    printf("Enter initial guess (x0): ");
    scanf("%lf", &x0);
    
    printf("\nNewton-Raphson Method Iterations:\n");
    printf("---------------------------------------------------------------\n");
    printf("Iteration\tx\t\tf(x)\t\tf'(x)\t\tx_{n+1}\n");
    printf("---------------------------------------------------------------\n");
    
    while (!converged && iteration < MAX_ITERATIONS) {
        f_x0 = f(x0);
        f_prime_x0 = f_prime(x0);
        
        // Check if derivative is too close to zero
        if (fabs(f_prime_x0) < EPSILON) {
            printf("\nError: Derivative too close to zero. Method fails.\n");
            return 1;
        }
        
        // Calculate next approximation
        x1 = x0 - f_x0 / f_prime_x0;
        
        // Print current iteration details
        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", 
               iteration, x0, f_x0, f_prime_x0, x1);
        
        // Check for convergence
        if (fabs(x1 - x0) < EPSILON) {
            converged = 1;
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
    }
    
    return 0;
}

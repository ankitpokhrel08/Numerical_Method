#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.0001 // For convergence check
#define MAX_ITERATIONS 100

// Function for which we want to find the root
double f(double x) {
    return x*x*x - 4*x - 9; // Example: f(x) = x³ - 4x - 9
}

// Description of the Regula Falsi method
void print_description() {
    printf("======================================================================\n");
    printf("                       REGULA FALSI METHOD\n");
    printf("======================================================================\n");
    printf("The Regula Falsi method (False Position method) is a bracketing method\n");
    printf("for finding roots of a function. It combines features of the bisection\n");
    printf("method and the secant method.\n\n");
    printf("Unlike bisection, it uses linear interpolation to find the next point:\n");
    printf("   x_n = (a_n*f(b_n) - b_n*f(a_n))/(f(b_n) - f(a_n))\n\n");
    printf("The method requires an initial interval [a,b] where f(a) and f(b) have\n");
    printf("opposite signs, ensuring that a root exists within the interval.\n");
    printf("======================================================================\n\n");
}

int main() {
    double a, b, c, f_a, f_b, f_c;
    int iteration = 0;
    int converged = 0;
    
    // Display method description
    print_description();
    
    printf("Function: f(x) = x³ - 4x - 9\n\n");
    
    // Get initial guesses
    printf("Enter two initial guesses a and b (where f(a) and f(b) have opposite signs):\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    
    // Calculate function values
    f_a = f(a);
    f_b = f(b);
    
    // Check if root is bracketed
    if (f_a * f_b >= 0) {
        printf("\nError: Function values at a and b must have opposite signs.\n");
        printf("f(%.6lf) = %.6lf, f(%.6lf) = %.6lf\n", a, f_a, b, f_b);
        return 1;
    }
    
    printf("\nRegula Falsi Method Iterations:\n");
    printf("---------------------------------------------------------------\n");
    printf("Iteration\ta\t\tb\t\tc\t\tf(c)\n");
    printf("---------------------------------------------------------------\n");
    
    while (!converged && iteration < MAX_ITERATIONS) {
        // Regula Falsi formula
        c = (a * f_b - b * f_a) / (f_b - f_a);
        f_c = f(c);
        
        // Print current iteration details
        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", 
               iteration, a, b, c, f_c);
        
        // Check for convergence
        if (fabs(f_c) < EPSILON || fabs(b - a) < EPSILON) {
            converged = 1;
            break;
        }
        
        // Update the bracketing interval
        if (f_c * f_a < 0) {
            b = c;
            f_b = f_c;
        } else {
            a = c;
            f_a = f_c;
        }
        
        iteration++;
    }
    
    printf("---------------------------------------------------------------\n");
    
    if (converged) {
        printf("\nRoot found after %d iterations: %.6lf\n", iteration, c);
        printf("Function value at root: %.10lf\n", f_c);
    } else {
        printf("\nMethod did not converge after %d iterations.\n", MAX_ITERATIONS);
        printf("Last approximation: %.6lf with f(c) = %.6lf\n", c, f_c);
    }
    
    return 0;
}

#include <stdio.h>
#include <math.h>

// Define the function for which we are finding the root
double f(double x) {
    return x * x * x - x - 2; // Example function: x^3 - x - 2
}

int main() {
    double a, b, c, tolerance;
    int max_iterations, iteration = 0;

    // Ask the user for the interval [a, b]
    printf("Enter the interval [a, b]:\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);

    // Check if the function values at the interval endpoints have opposite signs
    if (f(a) * f(b) >= 0) {
        printf("The function must have opposite signs at the endpoints a and b.\n");
        return -1;
    }

    // Ask the user for the tolerance
    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    // Calculate the number of iterations needed
    max_iterations = (int)(log(fabs(b - a) / tolerance) / log(2)) + 1;

    printf("Maximum iterations: %d\n", max_iterations);

    // Bisection method
    while (iteration < max_iterations) {
        c = (a + b) / 2.0;
        printf("Iteration %d: c = %.10f\n", iteration + 1, c);

        if (fabs(f(c)) <= tolerance) {
            printf("The root is approximately %.10f with tolerance %.10f\n", c, tolerance);
            return 0;
        }

        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
    }

    printf("The method did not converge within the maximum number of iterations.\n");
    return -1;
}
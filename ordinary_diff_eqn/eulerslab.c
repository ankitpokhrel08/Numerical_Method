#include <stdio.h>

// Function to calculate dy/dx = x + y
double f(double x, double y) {
    return x*x + 2*x - y;
}

int main() {
    double x0, y0, h, xn, x, y, slope;

    // Step 1: Input initial values, step size, and final x value
    printf("Enter the initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter the initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter the step size (h): ");
    scanf("%lf", &h);
    printf("Enter the final value of x (xn): ");
    scanf("%lf", &xn);

    // Step 2: Initialize x and y
    x = x0;
    y = y0;

    // Step 3: Apply Euler's method
    printf("\nUsing Euler's method:\n");
    printf("x\t\ty\n");
    printf("%.4lf\t%.4lf\n", x, y);

    while (x < xn) {
        slope = f(x, y);          // Calculate the slope
        y = y + h * slope;        // Update y
        x = x + h;                // Update x
        printf("%.4lf\t%.4lf\n", x, y);  // Print current x and y
    }

    printf("\nThe approximate solution at x = %.4lf is y = %.4lf\n", x, y);
    return 0;
}

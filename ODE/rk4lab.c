#include <stdio.h>

// Function to calculate dy/dx = x + y
double f(double x, double y) {
    return x*x - y;
}

int main() {
    double x0, y0, h, xn, x, y, k1, k2, k3, k4;

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

    // Step 3: Apply RK-4 method
    printf("\nUsing RK-4 method:\n");
    printf("x\t\ty\n");
    printf("%.4lf\t%.4lf\n", x, y);

    while (x < xn) {
        // Compute the four slopes
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        k4 = h * f(x + h, y + k3);

        // Update y using weighted average of slopes
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;

        // Update x
        x = x + h;

        // Print current x and y
        printf("%.4lf\t%.4lf\n", x, y);
    }

    printf("\nThe approximate solution at x = %.4lf is y = %.4lf\n", x, y);
    return 0;
}

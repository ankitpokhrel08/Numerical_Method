#include <stdio.h>
#include <math.h>

// Function to be integrated
double f(double x) {
    return x*x + 2*x + 1; // Example: f(x) = x^2 + 2x + 1
}

// Trapezoidal rule implementation
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    
    return h * sum;
}

int main() {
    double a, b;
    int n;
    
    printf("=== Numerical Integration using Trapezoidal Rule ===\n");
    printf("This program integrates f(x) = x^2 + 2x + 1\n\n");
    
    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);
    
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);
    
    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Number of intervals must be positive!\n");
        return 1;
    }
    
    double result = trapezoidal(a, b, n);
    
    printf("\nResults:\n");
    printf("Integral approximation: %.10lf\n", result);
    
    // For this specific function, we can calculate the exact value
    double exact = (pow(b, 3)/3 + pow(b, 2) + b) - (pow(a, 3)/3 + pow(a, 2) + a);
    printf("Exact value: %.10lf\n", exact);
    printf("Absolute error: %.10lf\n", fabs(exact - result));
    
    return 0;
}

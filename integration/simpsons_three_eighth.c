#include <stdio.h>
#include <math.h>

// Function to be integrated
double f(double x) {
    return x*x + 2*x + 1; // Example: f(x) = x^2 + 2x + 1
}

// Simpson's 3/8 rule implementation
double simpsons_three_eighth(double a, double b, int n) {
    if (n % 3 != 0) {
        printf("Error: Number of intervals must be a multiple of 3 for Simpson's 3/8 rule.\n");
        return -1;
    }
    
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 3 * f(x);
        }
    }
    
    return (3 * h / 8) * sum;
}

int main() {
    double a, b;
    int n;
    
    printf("=== Numerical Integration using Simpson's 3/8 Rule ===\n");
    printf("This program integrates f(x) = x^2 + 2x + 1\n\n");
    
    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);
    
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);
    
    printf("Enter the number of intervals (n, must be a multiple of 3): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Number of intervals must be positive!\n");
        return 1;
    }
    
    if (n % 3 != 0) {
        printf("Number of intervals must be a multiple of 3 for Simpson's 3/8 rule.\n");
        return 1;
    }
    
    double result = simpsons_three_eighth(a, b, n);
    
    printf("\nResults:\n");
    printf("Integral approximation: %.10lf\n", result);
    
    // For this specific function, we can calculate the exact value
    double exact = (pow(b, 3)/3 + pow(b, 2) + b) - (pow(a, 3)/3 + pow(a, 2) + a);
    printf("Exact value: %.10lf\n", exact);
    printf("Absolute error: %.10lf\n", fabs(exact - result));
    
    return 0;
}

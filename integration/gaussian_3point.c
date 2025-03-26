#include <stdio.h>
#include <math.h>

// Function to be integrated
double f(double x) {
    return x*x + 2*x + 1; // Example: f(x) = x^2 + 2x + 1
}

// Gaussian-Legendre 3-point quadrature
double gaussian_3point(double a, double b) {
    // Gauss-Legendre 3-point abscissas and weights
    const double x1 = -sqrt(3.0/5.0);
    const double x2 = 0.0;
    const double x3 = sqrt(3.0/5.0);
    const double w1 = 5.0/9.0;
    const double w2 = 8.0/9.0;
    const double w3 = 5.0/9.0;
    
    // Transform from [-1,1] to [a,b]
    double mid = (a + b) / 2;
    double len = (b - a) / 2;
    
    // Compute the integral using the Gaussian-Legendre formula
    double result = w1 * f(mid + len * x1) + 
                    w2 * f(mid + len * x2) + 
                    w3 * f(mid + len * x3);
    result *= len;
    
    return result;
}

int main() {
    double a, b;
    
    printf("=== Numerical Integration using Gaussian-Legendre 3-Point Formula ===\n");
    printf("This program integrates f(x) = x^2 + 2x + 1\n\n");
    
    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);
    
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);
    
    double result = gaussian_3point(a, b);
    
    printf("\nResults:\n");
    printf("Integral approximation: %.10lf\n", result);
    
    // For this specific function, we can calculate the exact value
    double exact = (pow(b, 3)/3 + pow(b, 2) + b) - (pow(a, 3)/3 + pow(a, 2) + a);
    printf("Exact value: %.10lf\n", exact);
    printf("Absolute error: %.10lf\n", fabs(exact - result));
    
    return 0;
}

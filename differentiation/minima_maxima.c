#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-6  // Small value to check if derivative is close to zero

// Function to calculate first derivative using central difference
float first_derivative(float x[], float y[], int n, int index, float h) {
    if (index > 0 && index < n-1) {
        // Central difference formula
        return (y[index+1] - y[index-1]) / (2*h);
    } else if (index == 0) {
        // Forward difference
        return (y[index+1] - y[index]) / h;
    } else {
        // Backward difference
        return (y[index] - y[index-1]) / h;
    }
}

// Function to calculate second derivative using central difference
float second_derivative(float x[], float y[], int n, int index, float h) {
    if (index > 0 && index < n-1) {
        // Central difference formula
        return (y[index+1] - 2*y[index] + y[index-1]) / (h*h);
    } else {
        // For endpoints, use first-order approximation
        return 0;
    }
}

int main() {
    int n, i;
    float x[100], y[100], h;
    
    printf("=== Finding Minima and Maxima using Numerical Differentiation ===\n\n");
    
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    printf("\nEnter the data points (x,y):\n");
    for(i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
    
    // Calculate step size (assuming uniform spacing)
    h = x[1] - x[0];
    
    // Find critical points
    printf("\nCritical points (where derivative is approximately zero):\n");
    int found = 0;
    
    for(i = 1; i < n-1; i++) {
        // Calculate first derivative
        float f_prime = first_derivative(x, y, n, i, h);
        
        // Check if derivative is close to zero
        if (fabs(f_prime) < EPSILON) {
            // Calculate second derivative to determine nature of critical point
            float f_double_prime = second_derivative(x, y, n, i, h);
            
            printf("x = %.4f: ", x[i]);
            if (f_double_prime > 0) {
                printf("Local minimum (f(x) = %.4f)\n", y[i]);
            } else if (f_double_prime < 0) {
                printf("Local maximum (f(x) = %.4f)\n", y[i]);
            } else {
                printf("Inflection point or higher-order critical point (f(x) = %.4f)\n", y[i]);
            }
            found = 1;
        }
    }
    
    if (!found) {
        printf("No critical points found in the given data range.\n");
    }
    
    return 0;
}

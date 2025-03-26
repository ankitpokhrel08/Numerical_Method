#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    float x[20], y[20], h, p, diff, term, sum = 0;
    float target_x;
    
    printf("=== Numerical Differentiation using Newton's Backward Difference ===\n\n");
    
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
    
    // Backward difference table
    float backward[n][n];
    
    // First column of difference table
    for(i = 0; i < n; i++) {
        backward[i][0] = y[i];
    }
    
    // Calculate the backward differences
    for(j = 1; j < n; j++) {
        for(i = j; i < n; i++) {
            backward[i][j] = backward[i][j-1] - backward[i-1][j-1];
        }
    }
    
    printf("\nEnter the value of x at which to find the derivative: ");
    scanf("%f", &target_x);
    
    // Find the position
    int pos = 0;
    for(i = 0; i < n-1; i++) {
        if(x[i] <= target_x && target_x <= x[i+1]) {
            pos = i+1;  // We use the right endpoint for backward
            break;
        }
    }
    
    // Calculate the value of p
    p = (target_x - x[pos]) / h;
    
    // First derivative using Newton's backward difference formula
    float first_derivative = 0;
    first_derivative = (backward[pos][1] / h) + 
                       (backward[pos][2] / (2 * h)) * (2 * p + 1) + 
                       (backward[pos][3] / (6 * h)) * (3 * p*p + 6*p + 2);
                        
    // Display the result
    printf("\nThe value of the first derivative at x = %.4f is: %.6f\n", target_x, first_derivative);
    
    return 0;
}

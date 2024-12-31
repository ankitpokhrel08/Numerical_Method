import numpy as np
import matplotlib.pyplot as plt

def gauss_jordan(a, b):
    n = len(b)
    for i in range(n):
        if a[i][i] == 0.0:
            raise ValueError("Divide by zero detected!")
        
        for j in range(n):
            if i != j:
                ratio = a[j][i] / a[i][i]
                for k in range(n):
                    a[j][k] = a[j][k] - ratio * a[i][k]
                b[j] = b[j] - ratio * b[i]
    
    x = np.zeros(n)
    for i in range(n):
        x[i] = b[i] / a[i][i]
    
    return x

def polynomial_curve_fit(x_values, y_values, degree):
    n = len(x_values)
    A = np.zeros((degree + 1, degree + 1))
    B = np.zeros(degree + 1)
    
    for i in range(degree + 1):
        for j in range(degree + 1):
            A[i][j] = sum(x ** (i + j) for x in x_values)
        B[i] = sum(y * (x ** i) for x, y in zip(x_values, y_values))
    
    coefficients = gauss_jordan(A, B)
    return coefficients

def plot_polynomial(x_values, y_values, coefficients):
    plt.scatter(x_values, y_values, color='red', label='Data Points')
    
    x_fit = np.linspace(min(x_values), max(x_values), 1000)
    y_fit = np.polyval(coefficients[::-1], x_fit)
    
    plt.plot(x_fit, y_fit, label='Fitted Polynomial')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend()
    plt.title('Polynomial Curve Fitting')
    plt.grid(True)
    plt.show()

def print_table(x_values, y_values):
    print("x\t\ty")
    for x, y in zip(x_values, y_values):
        print(f"{x:.4f}\t{y:.4f}")

def main():
    while True:
        degree = int(input("Enter the degree of the polynomial: "))
        n = int(input("Enter the number of data points: "))
        x_values = []
        y_values = []
        
        print("Enter the x values:")
        for i in range(n):
            x = float(input(f"x[{i}]: "))
            x_values.append(x)
        
        print("Enter the y values:")
        for i in range(n):
            y = float(input(f"y[{i}]: "))
            y_values.append(y)
        
        coefficients = polynomial_curve_fit(x_values, y_values, degree)
        
        equation = " + ".join([f"{coeff:.4f}*x^{i}" for i, coeff in enumerate(coefficients) if coeff != 0])
        equation = equation.replace("x^0", "").replace("*x^1", "*x")
        equation = equation.replace(" + -", " - ")
        print(f"Polynomial equation: y = {equation}")
        
        plot_polynomial(x_values, y_values, coefficients)
        
        cont = input("Do you want to continue with new values? (yes/no): ")
        if cont.lower() != 'yes':
            break

if __name__ == "__main__":
    main()

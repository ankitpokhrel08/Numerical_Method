import numpy as np
import matplotlib.pyplot as plt

# Differential equation dy/dx = x*x - y
def f(x, y):
    return x*x - y

# Exact solution
def exact_solution(x):
    return x**2 - 2*x + 2 - np.exp(-x)

# Euler's method implementation
def euler_method(f, x0, y0, h, n):
    x = np.zeros(n+1)
    y = np.zeros(n+1)
    x[0], y[0] = x0, y0
    for i in range(1, n+1):
        y[i] = y[i-1] + h * f(x[i-1], y[i-1])
        x[i] = x[i-1] + h
    return x, y

# Ask user for initial conditions and step size
x0 = float(input("Enter initial value of x (x0): "))
y0 = float(input("Enter initial value of y (y0): "))
h = float(input("Enter step size (h): "))
n = int(input("Enter number of steps (n): "))

# Compute Euler's method
x_euler, y_euler = euler_method(f, x0, y0, h, n)

# Compute exact solution
x_exact = np.linspace(x0, x0 + n*h, n+1)
y_exact = exact_solution(x_exact)

# Plotting the results
plt.plot(x_euler, y_euler, label="Euler's Method", marker='o')
plt.plot(x_exact, y_exact, label="Exact Solution", linestyle='--')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.title("Euler's Method vs Exact Solution")
plt.show()
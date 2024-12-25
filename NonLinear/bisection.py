import matplotlib.pyplot as plt
import numpy as np

def f(x):
    # Define the function for which we are finding the root
    return x * np.sin(x) + np.cos(x)

def bisection(a, b, tol):
    if f(a) * f(b) >= 0:
        print("Bisection method fails. The function must have different signs at a and b.")
        return None
    # ...existing code...
    c = a
    iteration = 1
    points = []
    while (b - a) / 2.0 > tol:
        c = (a + b) / 2.0
        points.append(c)
        print(f"Iteration {iteration}: a = {a}, b = {b}, c = {c}, f(c) = {f(c)}")
        if f(c) == 0:
            break
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c
        iteration += 1
    return c, points

def plot_bisection(a, b, tol):
    x = np.linspace(a - 1, b + 1, 400)  # Adjusted to zoom out
    y = f(x)
    
    plt.plot(x, y, label='f(x)')
    plt.axhline(0, color='black',linewidth=0.5)
    plt.axvline(0, color='black',linewidth=0.5)
    plt.grid(color = 'gray', linestyle = '--', linewidth = 0.5)
    
    root, points = bisection(a, b, tol)
    if root is not None:
        plt.plot(root, f(root), 'ro', label='Root')  # Mark the root
        for i, point in enumerate(points):
            plt.plot(point, f(point), 'o', label=f'Iteration {i+1}')
        plt.title(f'Root at x = {root:.6f}')
    else:
        plt.title('No root found in the interval')
    
    plt.legend()
    plt.show()

# Example usage
try:
    a = float(input("Enter the first point a: "))
    b = float(input("Enter the second point b: "))
    tol = float(input("Enter the tolerance: "))
    plot_bisection(a, b, tol)
except ValueError:
    print("Invalid input. Please enter numerical values.")
